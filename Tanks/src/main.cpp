#include <QGuiApplication>
#include <QQuickView>
#include "inc/boardtypesregisterer.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView      view;

    BoardTypesRegisterer boardTypesRegisterer;
    boardTypesRegisterer.registerBoardTypes();

    QUrl path = QUrl::fromLocalFile("/Users/andreiz/code/telenav/1on1/Tanks/resources/main.qml");
    view.setSource(path);
    view.show();

    return app.exec();
}
