import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import Cryogen.MainForm 1.0

ApplicationWindow {
	id: secure_sign_in_mobile_app;
	visible: true;
	width: 720;
	height: 1280;
	title: qsTr("Secure Sign In");

	Main_Form {
		id: main_form;
	}

	//signals
	signal encrypt();

//	Binding {
//		target: main_form;
//		property: "password";
//		value: password_input.text;
//	}
//	Binding {
//		target: main_form
//		property: "key";
//		value: key_input.text;
//	}
//	Binding {
//		target: main_form;
//		property: "cipher_password";
//		value: password_output.text;
//	}

	//slots
//	function on_encrypted(password)
//	{
//		console.log('DONE!');
////		OutputForm.password = s;
////		output_form.password = password;
//		output_form.password_output.text = password;
//		stackview.push("qrc:/OutputForm.qml");
//	}


	StackView {
		id: stackview;
		initialItem:
		MainForm {
		}
	}
}
