#ifndef NOVINT_H
#define NOVINT_H

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QtGui>
#include "ui_novint.h"
#include <opencv2/opencv.hpp>
using namespace cv;

#include "chai3d.h"
#include "haptico.h"


class novint : public QMainWindow
{
	Q_OBJECT

public:
	novint(QWidget *parent = 0, Qt::WFlags flags = 0);
	~novint();
	void inicializa(int argc, char *argv[]);

private:
	int co;
	double coordenadas[100][3];
	haptico hap;
	Mat img;
	Ui::novintClass ui;
	QImage mat2qimage(Mat& mat);
	QString fileName;


	private slots:
		void mostrar();
		void pathDialog();
		void novintMov();
		void novintIni();
		void cargarLetra();
		void updateposN();
};

#endif // NOVINT_H
