import QtQuick 2.6

Rectangle
{
    width: 800
    height: 600
    color: "black"

    Rectangle {
        id: body
        anchors.centerIn: parent

        color: "pink"
        width: 100
        height: 500
        radius: width / 2

    }

    Rectangle {
        id: leftTesticle
        anchors.bottom: body.bottom
        anchors.right: body.horizontalCenter
        width: 100
        height: width
        color: "pink"
        radius: height
    }

    Rectangle {
        id: rightTesticle
        anchors.bottom: body.bottom
        anchors.left: body.horizontalCenter
        width: 100
        height: width
        color: "pink"
        radius: height
    }
}
