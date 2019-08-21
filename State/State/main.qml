import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true

    MouseArea {
        anchors.fill: parent
        onClicked: {
            textTest.state="blueStates"
        }
        onDoubleClicked: {
            textTest.state = "greenStates"
        }
    }

    Text {
        id:textTest
        states: [
            State {
                name: "redStates"
                PropertyChanges {
                    target: textTest
                    color:"red"
                }
            },//注意这里的逗号
            State {
                name: "blueStates"
                PropertyChanges {
                    target: textTest
                    color:"blue"
                }
            },
            State {
                name: "greenStates"
                PropertyChanges {
                    target: textTest
                    color:"green"
                    font.bold: true
                    font.pixelSize: 18
                }
            }
        ]
        text: qsTr("Hello World")
        anchors.centerIn: parent
        state: "redStates"
    }
}
