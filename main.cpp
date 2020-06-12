#include <QtWidgets/QApplication>
#include "ui/OrderManagerMainView.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    OrderManagerMainView orderManagerMainView;
    orderManagerMainView.show();
    return QApplication::exec();
}
