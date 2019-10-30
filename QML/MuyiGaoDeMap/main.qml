import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtLocation 5.5
import QtPositioning 5.5

Window {
    visible: true

    Plugin {
        id: somePlugin
        name:"QCowis"

    }
    Map{
        anchors.fill:  parent
        id: map

        plugin:somePlugin

        activeMapType: map.supportedMapTypes[0]

        center {
            latitude: 31.144
            longitude: 117.234
        }
        zoomLevel: 10

        gesture.enabled: true

        Button{
           anchors.top: parent.top
           anchors.topMargin: 10
           anchors.left: parent.left
           anchors.leftMargin: 10
            id:gaodeMap
            text: "高德地图"
            onClicked: {
                map.activeMapType = map.supportedMapTypes[1]
            }
        }

        Button{
            anchors.top: gaodeMap.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
            id:gaodeSate
            text: "高德卫星地图"
            onClicked: {
                map.activeMapType = map.supportedMapTypes[0];
            }
        }

    }





}

