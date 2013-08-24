#include "novint.h"
#include "haptico.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	
	QApplication a(argc, argv);
	novint w;
	w.inicializa(argc, argv);
	w.show();
	

	return a.exec();
}
