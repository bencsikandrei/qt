#include <QGuiApplication>
#include <QDir>
#include <QQuickView>
#include <iostream>
#include "pathsregistry.h"

int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);

    QString qmlPath = QCoreApplication::applicationDirPath() + PathsRegistry::mainQmlPath();

    QDir::setCurrent(QCoreApplication::applicationDirPath());

    QQuickView view;
    view.setSource(QUrl::fromLocalFile(qmlPath));
    view.show();

    return app.exec();
}
