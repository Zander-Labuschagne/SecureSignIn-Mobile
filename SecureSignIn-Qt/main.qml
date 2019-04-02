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
		MainForm {
		}
	}
}
