import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15
import System 1.0

Rectangle {
    id: rightScreen

    anchors {
        top: parent.top
        bottom: parent.bottom
        right: parent.right
    }

    Plugin {
        id: mapPlugin
        name: "osm"
    }
    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(11.927938, 108.150785) // Some coordinates
        zoomLevel: 14
        property var startCentroid

        PinchHandler {
            id: pinch
            target: null
            onActiveChanged: if (active) {
                map.startCentroid = map.toCoordinate(pinch.centroid.position, false)
            }
            onScaleChanged: (delta) => {
                map.zoomLevel += Math.log2(delta)
                map.alignCoordinateToPoint(map.startCentroid, pinch.centroid.position)
            }
            onRotationChanged: (delta) => {
                map.bearing -= delta
                map.alignCoordinateToPoint(map.startCentroid, pinch.centroid.position)
            }
            grabPermissions: PointerHandler.TakeOverForbidden
        }
        WheelHandler {
            id: wheel
            acceptedDevices: Qt.platform.pluginName === "cocoa" || Qt.platform.pluginName === "wayland"
                            ? PointerDevice.Mouse | PointerDevice.TouchPad
                            : PointerDevice.Mouse
            rotationScale: 1/120
            property: "zoomLevel"
        }
        DragHandler {
            id: drag
            target: null
            onTranslationChanged: (delta) => map.pan(-delta.x, -delta.y)
        }
        Shortcut {
            enabled: map.zoomLevel < map.maximumZoomLevel
            sequence: StandardKey.ZoomIn
            onActivated: map.zoomLevel = Math.round(map.zoomLevel + 1)
        }
        Shortcut {
            enabled: map.zoomLevel > map.minimumZoomLevel
            sequence: StandardKey.ZoomOut
            onActivated: map.zoomLevel = Math.round(map.zoomLevel - 1)
        }
    }

    System {
        id: mySystem
    }

    Image {
        id: lockIcon
        anchors {
            left: parent.left
            top: parent.top
            margins: 20
        }

        width: parent.width / 40
        fillMode: Image.PreserveAspectFit

        source: (mySystem.carLock ? "qrc:/ui/assets/lock.png" : "qrc:/ui/assets/unlock.png")
        MouseArea {
            anchors.fill: parent
            onClicked: mySystem.setCarLock(!mySystem.carLock)
        }
    }

    Text {
        id: dateTimeDisplay
        anchors {
            left: lockIcon.right
            leftMargin: 40
            bottom: lockIcon.bottom
        }

        font.pixelSize: 12
        font.bold: true
        color: "black"

        text: mySystem.currentTime
    }

    Text {
        id: outdoorTemperatureDisplay
        anchors {
            left: dateTimeDisplay.right
            leftMargin: 40
            bottom: dateTimeDisplay.bottom
        }

        font.pixelSize: 12
        font.bold: true
        color: "black"

        text: mySystem.outDoorTemp + "°F"
    }

    Text {
        id: userNameDisplay
        anchors {
            left: outdoorTemperatureDisplay.right
            leftMargin: 40
            bottom: outdoorTemperatureDisplay.bottom
        }

        font.pixelSize: 12
        font.bold: true
        color: "black"

        text: mySystem.userName
    }

    NavigationSearchBox {
        id: navSearchBox

        width: parent.width * 1/3
        height: parent.height * 1/12

        anchors {
            left: lockIcon.left
            top: lockIcon.bottom
            topMargin: 15
        }
    }


    width: parent.width * 2 / 3
}
