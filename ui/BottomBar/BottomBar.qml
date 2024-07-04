import QtQuick 2.15

Rectangle{
    id: bottomBar
    anchors {
        left: parent.left
        right: parent.right
        bottom: parent.bottom
    }
    color: "black"
    height: parent.height / 12

    Image {
        id: carSettingIcon
        anchors{
            left: parent.left
            leftMargin: 30
            verticalCenter: parent.verticalCenter
        }

        height: parent.height * .85
        fillMode: Image.PreserveAspectFit

        source: "qrc:/ui/assets/carIcon.png"
    }

    HVAComponent {
        id: driverHVAControl
        anchors {
            top: parent.top
            bottom: parent.bottom
            left: carSettingIcon.right
            leftMargin: 150

        }

        hvacControler: driverHVAC

    }

    HVAComponent {
        id: passengerHVAControl
        anchors {
            top: parent.top
            bottom: parent.bottom
            right: volumControl.left
            rightMargin: 200

        }

        hvacControler: passengerHVAC

    }

    VolumControlerComponent {
        id: volumControl
        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            rightMargin: 165

        }
    }


}
























