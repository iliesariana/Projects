#include <QApplication>
#include <QPushButton>
#include "gui.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Repository r=Repository();
    auto *model=new starsModel(r);
    auto s= Service(r);
    for( auto &as:s.getAstronauts())
    {
        auto window=new gui(model,as,s);
        window->show();

    }

    return QApplication::exec();
}
