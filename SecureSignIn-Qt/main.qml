import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

ApplicationWindow {
	visible: true
	width: 720
	height: 1280
	title: qsTr("Secure Sign In")

	//signals
	signal encrypt();

	StackView {
		id: stackview
		initialItem:
//		    Pane
//		    {
//			Button
//			{
//			    text: "Open window"
//			    onClicked: stackview.push("qrc:/window.qml")
//			}
//		    }
		MainForm {
		}
	}

//	MainForm {
//	}

//	function createWindows() {
//		var component = Qt.createComponent("OutputForm.qml");
//		console.log("Component Status:", component.status, component.errorString());
//		var window = component.createObject(this, {"x": 100, "y": 300});
//		window.show();
//	}
}
