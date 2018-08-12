#include "qt1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qt1 w;
	w.show();
	return a.exec();
}
