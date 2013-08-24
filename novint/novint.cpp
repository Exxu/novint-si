#include "novint.h"

int argcN;
char *argvN[]={NULL};
int xL=400; //igual al tamaño de la imagen y label correspondiente
int yA=400;

novint::novint(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(mostrar()));
	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(novintIni()));
	connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(novintMov()));
	connect(ui.pushButton_2,SIGNAL(clicked()),this,SLOT(pathDialog()));
	connect(ui.commandLinkButton_2,SIGNAL(clicked()),this,SLOT(cargarLetra()));
	QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateposN()));
    timer->start(10);
}

novint::~novint()
{
	hap.finHaptico();
}

void novint::mostrar(){
	img=Mat::zeros(xL, yA, CV_8U);
	ui.label_7->setPixmap(QPixmap::fromImage(mat2qimage(img)));

}
void novint::pathDialog(){
	fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
		"/home",
		tr("Text File (*.txt)"));

	ui.label_6->setText(fileName);
}


QImage novint::mat2qimage(Mat& mat) {

	// 8-bits unsigned, NO. OF CHANNELS=1
    if(mat.type()==CV_8UC1){
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));

        const uchar *qImageBuffer = (const uchar*)mat.data;
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    if(mat.type()==CV_8UC3){
        const uchar *qImageBuffer = (const uchar*)mat.data;
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else{
        qDebug() << "No puede transformarse este Mat en QImage";
        return QImage();
    }
}
void novint::inicializa(int argc, char *argv[]){
	argcN=argc;
	*argvN=*argv;
	qDebug() << "paso";
}

void novint::novintIni(){
	hap.inicializacion(argcN,argvN);
}

void novint::novintMov(){
	hap.movimiento();
}

void novint::cargarLetra(){
	QFile file(fileName);	

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
		QMessageBox msgBox;
		msgBox.setText("No se encuentra el archivo");
		msgBox.exec();
	}else{
		QTextStream stream(&file);
		QString line;
		QStringList list1;
		co=0;

		do {
			line = stream.readLine();
			//qDebug()<<line;
			if(line!=""){
				list1 = line.split(",");
				coordenadas[co][0]=list1.at(0).toDouble();
				coordenadas[co][1]=list1.at(1).toDouble();
				coordenadas[co][2]=list1.at(2).toDouble();
				//qDebug()<<coordenadas[co][0]<<"  "<<coordenadas[co][1]<<"  "<<coordenadas[co][2]<<"  -->"<<co;
				co++;
				//ui.pushButton->setText("hola");
			}
		} while (!line.isNull());
		qDebug() <<co;

		hap.pasarLetra(coordenadas,co);
	}
}

void novint::updateposN(){
	ui.lineEdit->setText(QString::number(hap.getposNx()));
	ui.lineEdit_2->setText(QString::number(hap.getposNy()));
	ui.lineEdit_3->setText(QString::number(hap.getposNz()));
}
