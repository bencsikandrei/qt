#pragma once

#include <QString>

// move to a separate header file
const QString RESOURCE_RELATIVE_PATH = "resources";
const QString QML_RELATIVE_PATH      = "qml";

class PathsRegistry
{
public:
    static const QString qmlPath();
};
