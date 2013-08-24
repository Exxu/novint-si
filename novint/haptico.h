#ifndef HAPTICO_H
#define HAPTICO_H

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chai3d.h"
#include <QtGui>

class haptico
{

public:
	haptico(void);
	~haptico(void);
	int inicializacion(int argc, char* argv[]);
	int movimiento();
	void finHaptico();
	void pasarLetra(double coord[100][3],int c);
	double getposNx();
	double getposNy();
	double getposNz();

signals:
	void posEnviar(double,double,double);

private:
	//MACROS
	#define RESOURCE_PATH(p)    (char*)((resourceRoot+string(p)).c_str())

	//FUNCIONES
	/*void resizeWindow(int w, int h);
	void keySelect(unsigned char key, int x, int y);
	void menuSelect(int value);
	void close(void);
	void updateGraphics(void);
	void updateHaptics(void);*/

};
#endif

