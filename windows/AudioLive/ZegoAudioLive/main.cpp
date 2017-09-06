#include "ZegoMainDialog.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	ZegoAudioLive w;
	w.initDialog();
	w.show();
	return app.exec();
}
