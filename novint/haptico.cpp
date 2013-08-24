#include "haptico.h"


//CONSTANTES
const int WINDOW_SIZE_W         = 20;
const int WINDOW_SIZE_H         = 20;

const int OPTION_FULLSCREEN     = 1;
const int OPTION_WINDOWDISPLAY  = 2;

//VARIABLES

cWorld* world;
cCamera* camera;
cLight *light;
int displayW  = 0;
int displayH  = 0;
int lapso=0;
int lapsoMax=10;
double workspaceScaleFactor;
cHapticDeviceHandler* handler;
cGeneric3dofPointer* tool;
cShapeSphere* object0;
bool simulationRunning = false;
string resourceRoot;
bool simulationFinished = false;
double posNx, posNy, posNz;

// MIS VARIABLES CREADAS
cGenericHapticDevice* hapticDevice;
double x=0.0, y=0, z=0.0;
int cont=0;
double incremento=0.002;
bool boton=false,inicioMov=false;
bool boton2=false;
//double letA[4][3]={{-0.5,-0.5,0},{-0.5,0.5,0},{0.5,-0.5,0},{0.5,0.5,0}};
double letA[100][3];
int tam=0;

haptico::haptico(void)
{
}


haptico::~haptico(void)
{
}

void close(void)
{
    // stop the simulation
    simulationRunning = false;

    // wait for graphics and haptics loops to terminate
    while (!simulationFinished) { cSleepMs(100); }

    // close haptic device
    tool->stop();
}
void resizeWindow(int w, int h)
{
    // update the size of the viewport
    displayW = w;
    displayH = h;
    glViewport(0, 0, displayW, displayH);
}

void keySelect(unsigned char key, int x, int y)
{
    if ((key == 27) || (key == 'x'))
    {
        // close everything
        close();

        // exit application
        exit(0);
    }
}


void menuSelect(int value)
{
    switch (value)
    {
        // enable full screen display
        case OPTION_FULLSCREEN:
            glutFullScreen();
            break;

        // reshape window to original size
        case OPTION_WINDOWDISPLAY:
            glutReshapeWindow(WINDOW_SIZE_W, WINDOW_SIZE_H);
            break;
    }
}

void updateGraphics(void)
{
    // render world
    camera->renderView(displayW, displayH);

    // Swap buffers
    glutSwapBuffers();

    // check for any OpenGL errors
    GLenum err;
    err = glGetError();
    if (err != GL_NO_ERROR) printf("Error:  %s\n", gluErrorString(err));

    // inform the GLUT window to call updateGraphics again (next frame)
    if (simulationRunning)
    {
        glutPostRedisplay();
    }

    // MOVIMIENTO --------------------
	
	hapticDevice->getUserSwitch(0, boton);
	if(boton){
		inicioMov=true;
		//qDebug() <<"botón1: ";
	}
	hapticDevice->getUserSwitch(1, boton2);
	if(boton2){
		inicioMov=false;
		//qDebug() <<"boton2: ";
	}
	if(inicioMov){
		if(cont<(tam-1)){
			if((abs(x-letA[cont+1][0])>0.001)||((abs(y-letA[cont+1][1]))>0.001)||(abs(z-letA[cont+1][2])>0.001)){
				if(x!=letA[cont+1][0]){
					if(x<letA[cont+1][0])
						x=x+incremento;
					else
						x=x-incremento;
					sizeof(letA);
				}
				if(y!=letA[cont+1][1]){
					if(y<letA[cont+1][1])
						y=y+incremento;
					else
						y=y-incremento;
				}
				if(z!=letA[cont+1][2]){
					if(z<letA[cont+1][2])
						z=z+incremento;
					else
						z=z-incremento;
				}
			}
			else{
				cont=cont+1;
				x=letA[cont][0];
				y=letA[cont][1];
				z=letA[cont][2];
				//std::cout<<"punto "<<cont<<"  x: "<<x<<"  y: "<<y<<"  z: "<<z<<std::endl;
				//getchar();
			}
		}
		object0->setPos(x,y,z);
	}
}

void updateHaptics(void)
{
    // main haptic simulation loop
	cVector3d pos, vel;
	cMatrix3d rotation;
    while(simulationRunning)
    {
		// compute global reference frames for each object
        world->computeGlobalPositions(true);

        // update position and orientation of tool
		hapticDevice->getPosition(pos);
		lapso++;
		if(lapso>lapsoMax){
			//qDebug() <<"pos:  "<<pos.x*workspaceScaleFactor<<","<<pos.y*workspaceScaleFactor<<","<<pos.z*workspaceScaleFactor;
			posNx=pos.x*workspaceScaleFactor;
			posNy=pos.y*workspaceScaleFactor;
			posNz=pos.z*workspaceScaleFactor;
			lapso=0;
			//emit posEnviar(pos.x*workspaceScaleFactor,pos.y*workspaceScaleFactor,pos.z*workspaceScaleFactor);
		}
		hapticDevice->getRotation(rotation);
		hapticDevice->getLinearVelocity(vel);
        //std::cout<<"vel:  "<<vel.x<<","<<vel.y<<","<<vel.z<<std::endl;
		tool->updatePose(pos,vel,rotation);
		
        // compute interaction forces
        tool->computeInteractionForces();

        // send forces to device
        tool->applyForces();
    }
    
    // exit haptics thread
    simulationFinished = true;
}

int haptico::inicializacion(int argc, char* argv[])
{
    // INITIALIZATION
    qDebug() <<"entro a inicializacion";

    // parse first arg to try and locate resources
    resourceRoot = string(argv[0]).substr(0,string(argv[0]).find_last_of("/\\")+1);

    // 3D - SCENEGRAPH

    // create a new world.
    world = new cWorld();

    // set the background color of the environment the color is defined by its (R,G,B) components.
    world->setBackgroundColor(0.0, 0.0, 0.0);

    // create a camera and insert it into the virtual world
    camera = new cCamera(world);
    world->addChild(camera);

    // position and oriente the camera
    camera->set( cVector3d (3.0, 0.0, 0.0),    // camera position (eye)
                 cVector3d (0.0, 0.0, 0.0),    // lookat position (target)
                 cVector3d (0.0, 0.0, 1.0));   // direction of the "up" vector

    // set the near and far clipping planes of the camera anything in front/behind these clipping planes will not be rendered
    camera->setClippingPlanes(0.01, 10.0);

    // enable higher quality rendering for transparent objects
    camera->enableMultipassTransparency(true);

    // create a light source and attach it to the camera
    light = new cLight(world);
    camera->addChild(light);                   // attach light to camera
    light->setEnabled(true);                   // enable light source
    light->setPos(cVector3d( 2.0, 0.5, 1.0));  // position the light source
    light->setDir(cVector3d(-2.0, 0.5, 1.0));  // define the direction of the light beam


    //-----------------------------------------------------------------------
    // HAPTIC DEVICES / TOOLS
    //-----------------------------------------------------------------------

    // create a haptic device handler
    handler = new cHapticDeviceHandler();

    // get access to the first available haptic device
    handler->getDevice(hapticDevice, 0);

    // retrieve information about the current haptic device
    cHapticDeviceInfo info;
    if (hapticDevice)
    {
        info = hapticDevice->getSpecifications();
    }

    // create a 3D tool and add it to the world
    tool = new cGeneric3dofPointer(world);
    world->addChild(tool);

    // connect the haptic device to the tool
    tool->setHapticDevice(hapticDevice);

    // initialize tool by connecting to haptic device
    tool->start();

    // map the physical workspace of the haptic device to a larger virtual workspace.
    tool->setWorkspaceRadius(1.0);

    // define a radius for the tool
    tool->setRadius(0.03);

    // read the scale factor between the physical workspace of the haptic device and the virtual workspace defined for the tool
    workspaceScaleFactor = tool->getWorkspaceScaleFactor();
	//qDebug() <<"factor escala "<<workspaceScaleFactor;

    // define a maximum stiffness that can be handled by the current haptic device. The value is scaled to take into account the workspace scale factor
    double stiffnessMax = info.m_maxForceStiffness / workspaceScaleFactor;
    double forceMax = info.m_maxForce;

    // define the maximum damping factor that can be handled by the current haptic device. The The value is scaled to take into account the workspace scale factor
    double dampingMax = info.m_maxLinearDamping / workspaceScaleFactor; 


    //-----------------------------------------------------------------------
    // COMPOSE THE VIRTUAL SCENE
    //-----------------------------------------------------------------------

    // temp variable
    cGenericEffect* newEffect;

    // create a sphere and define its radius
    object0 = new cShapeSphere(0.03);

    // add object to world
    world->addChild(object0);

    // set the position of the object at the center of the world
	/*x=letA[cont][0];
	y=letA[cont][1];
	z=letA[cont][2];
    object0->setPos(x, y, z);*/

    // set graphic properties
    object0->m_texture = new cTexture2D();

    //object0->m_texture->setSphericalMappingEnabled(true);
    object0->m_material.m_ambient.set(0.1, 0.1, 0.4);
    object0->m_material.m_diffuse.set(0.0, 0.5, 1.0);
    object0->m_material.m_specular.set(1.0, 1.0, 1.0);
    object0->m_material.setShininess(100);
    object0->setUseTexture(true);

	 // set haptic properties // PRECAUCIÓN!!!!
    object0->m_material.setStiffness(0.1 * stiffnessMax);//0.4
    object0->m_material.setMagnetMaxForce(0.4*forceMax);//0.4
    object0->m_material.setMagnetMaxDistance(1);//0.12
    //object0->m_material.setViscosity(1 * dampingMax);//0.2

    // create a haptic surface effect
    //newEffect = new cEffectSurface(object0);
    //object0->addEffect(newEffect);

    // create a haptic magnetic effect
    newEffect = new cEffectMagnet(object0);
    object0->addEffect(newEffect);

    //-----------------------------------------------------------------------
    // OPEN GL - WINDOW DISPLAY
    //-----------------------------------------------------------------------

    // initialize GLUT
    glutInit(&argc, argv);

    // retrieve the resolution of the computer display and estimate the position
    // of the GLUT window so that it is located at the center of the screen
    //int screenW =glutGet(GLUT_SCREEN_WIDTH);
    //int screenH =glutGet(GLUT_SCREEN_HEIGHT);
    int windowPosX =0;// (screenW - WINDOW_SIZE_W) / 2;
    int windowPosY =0;// (screenH - WINDOW_SIZE_H) / 2;

    // initialize the OpenGL GLUT window
    glutInitWindowPosition(windowPosX, windowPosY);
    glutInitWindowSize(WINDOW_SIZE_W, WINDOW_SIZE_H);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(updateGraphics); //PRINCIPAL DE MOVIMIENTO
    glutKeyboardFunc(keySelect); 
    glutReshapeFunc(resizeWindow);
    glutSetWindowTitle("CHAI 3D");

    // create a mouse menu (right button) //OPCIONAL
	glutCreateMenu(menuSelect);
    glutAddMenuEntry("full screen", OPTION_FULLSCREEN);
    glutAddMenuEntry("window display", OPTION_WINDOWDISPLAY);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    return (0);
}

int haptico::movimiento(){ //inicia simulación de movimiento

	x=letA[cont][0];
	y=letA[cont][1];
	z=letA[cont][2];
    object0->setPos(x, y, z);

    // simulation in now running
    simulationRunning = true;

    // create a thread which starts the main haptics rendering loop
    cThread* hapticsThread = new cThread();
    hapticsThread->set(updateHaptics, CHAI_THREAD_PRIORITY_HAPTICS);

    // start the main graphics rendering loop
    glutMainLoop();

	return 0;
}

void haptico::finHaptico(){  //cerrar haptico
	 close();
	 exit(0);
}

void haptico::pasarLetra(double coord[100][3],int c){
	for(int k=0;k<c;k++){
		for(int j=0;j<3;j++){
				letA[k][j]=coord[k][j];
				qDebug()<<letA[k][j]<<"-->"<<k;
		}
	}
	tam=c;
}

double haptico::getposNx(){
	return posNx;
}
double haptico::getposNy(){
	return posNy;
}
double haptico::getposNz(){
	return posNz;
}