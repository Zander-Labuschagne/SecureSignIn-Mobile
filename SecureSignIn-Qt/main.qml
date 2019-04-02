import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

ApplicationWindow {
	visible: true
	width: 720
	height: 1280
	title: qsTr("Secure Sign In")

	//signals
	signal encrypt(string password, string key, bool compact);

	//slots
	function on_encrypted(password)
	{
		console.log('DONE!');
//		OutputForm.password = s;
//		output_form.password = password;
		output_form.password_output.text = password;
		stackview.push("qrc:/OutputForm.qml");
	}


	StackView {
		id: stackview
		initialItem:
		MainForm {
		}
	}
}
