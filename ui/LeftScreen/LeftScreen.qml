import QtQuick 2.15

Rectangle {
    anchors {
    left: parent.left
    right: rightScreen.left
    top: parent.top
    bottom: bottomBar.top
    }

    // color: "white"

    Image {
        id: carRender
        anchors.centerIn: parent
        width: parent.width * .75
        fillMode: Image.PreserveAspectFit
        source: "qrc:/ui/assets/carRender.jpg"
        }

}
