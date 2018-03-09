#include "pathsregistry.h"

const QString PathsRegistry::qmlPath()
{
    return QString("/" + RESOURCE_RELATIVE_PATH + "/" + QML_RELATIVE_PATH + "/main.qml");
}
