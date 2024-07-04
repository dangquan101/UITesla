import QtQuick 2.15

Item {
    property string fontColor: "#f0eded"

    Connections {
        target: audioControler
        function onVolumLevelChanged(){
            visibileTimer.stop()
            volumIcon.visible = false
            visibileTimer.start()
        }
    }

    Timer {
        id: visibileTimer
        interval: 1000
        repeat: false
        onTriggered: {
            volumIcon.visible = true
        }
    }

    Rectangle {
        id: decrementButton
        anchors {
            left: parent.left
            top: parent.top
            bottom: parent.bottom
        }

        width: height / 2
        color: "black"

        Text {
            id: decrementText
            color: fontColor
            anchors.centerIn: parent
            text: "<"
            font.pixelSize: 12
        }

    MouseArea {
        anchors.fill: parent
        onClicked: audioControler.incrementVolume( -1 )
    }

    }

    Image {
        id: volumIcon
        anchors {
            left: decrementButton.right
            leftMargin: 15
            top: parent.top
            bottom: parent.bottom
        }

        fillMode: Image.PreserveAspectFit

        source: {
            if(audioControler.volumLevel <= 0 )
                return "qrc:/ui/assets/mute.png"
            else if (audioControler.volumLevel <= 50)
                return "qrc:/ui/assets/medium-volume.png"
            else
                return "qrc:/ui/assets/high-volume.png"
        }

      }

    Text {
        id: volumText
        visible: !volumIcon.visible
        anchors {
            centerIn: volumIcon
        }

        color: fontColor
        font.pixelSize: 24
        text: audioControler.volumLevel
      }


    Rectangle {
        id: incrementButton
        anchors {
            left: volumIcon.right
            leftMargin: 15
            top: parent.top
            bottom: parent.bottom
        }

        width: height / 2
        color: "black"

        Text {
            id: incrementText
            color: fontColor
            anchors.centerIn: parent
            text: ">"
            font.pixelSize: 12
        }

        MouseArea {
            anchors.fill: parent
            onClicked: audioControler.incrementVolume( +1 )
        }
    }
}
