#include <QApplication>
#include <QLabel>
#include<QPainter>
#include"GUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Service s=Service();
    GUI gui(s);
    gui.setStyleSheet("QMainWindow {background: 'pink';}");
    gui.show();
    return a.exec();
}
