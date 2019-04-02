import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.3
import QtQuick.Dialogs 1.2

Page {

	width: Screen.desktopAvailableWidth;
	height: Screen.desktopAvailableHeight;
	visible: true;
	background: Rectangle {
		   color: "#282a36";
		   width: parent.width;
		   height: parent.height;
	}
	Image {
		id: logo;
		fillMode: Image.PreserveAspectFit;
		width: 280;
		x: (parent.width - width) / 2;
		y: 0;
		source: "res/cryogen_blue_portrait_dark_theme.png";
		visible: true;
	}

	TextField {
	    id: password_input;
	    x: 10;
	    y: logo.y + logo.height + 20;
	    width: Screen.desktopAvailableWidth - (2 * this.x);
	    height: 35;
	    placeholderText: "Password";
	    echoMode: TextInput.Password;
	    color: "#00c4dc";
	    background: Rectangle {
			radius: 12;
			border.color: "#00c4dc";
			border.width: 1;
			color: "#1F2127";
		    }
	    padding: 0;
	    leftPadding: 12
	    rightPadding: 12;
	    topPadding: length > 0 ? 10 : 5;
	    bottomPadding: 5;
	}

	TextField {
	    id: key_input;
	    x: 10;
	    y: password_input.y + password_input.height + 10;
	    width: Screen.desktopAvailableWidth - (2 * this.x);
	    height: 35;
	    placeholderText: "Password Key";
	    echoMode: TextInput.Password;
	    color: "#00c4dc";
	    background: Rectangle {
			radius: 12;
			border.color: "#00c4dc";
			border.width: 1;
			color: "#1F2127";
		    }
	    padding: 0;
	    leftPadding: 12
	    rightPadding: 12;
	    topPadding: length > 0 ? 10 : 5;
	    bottomPadding: 5;
	}

	SwitchDelegate {
		id: compact_switch;
		x: Screen.desktopAvailableWidth - width - password_input.x;
		y: key_input.y + key_input.height + 40;
		text: qsTr("Compact Password");
		background: Rectangle {
			implicitHeight: 40;
			visible: false;
		}
		contentItem: Text {
			rightPadding: compact_switch.indicator.width + compact_switch.spacing;
			text: compact_switch.text;
			font: compact_switch.font;
			opacity: enabled ? 1.0 : 0.3;
			color: "#00c4dc";
			elide: Text.ElideRight;
			verticalAlignment: Text.AlignVCenter;
		}
		indicator: Rectangle {
			id: compact_switch_groove;
			implicitWidth: 48;
			implicitHeight: 26;
			x: compact_switch.width - width - compact_switch.rightPadding;
			y: parent.height / 2 - height / 2;
			radius: 13;
//			color: compact_switch.checked ? "#8897f4" : "#1F2127";
			color: "#1F2127";
			border.color: "#00c4dc";
			Rectangle {
				id: compact_switch_handle;
				x: 4;
				y: 4;
				width: 18;
				height: 18;
				radius: 9;
				color: "#00c4dc";
			}
		}
		antialiasing: true;
		wheelEnabled: true;
		SequentialAnimation {
			    id: switch_off;
			    PropertyAnimation {
				target: compact_switch_handle;
				property: "x";
				to: "4";
				duration: 100;
			    }
			    PropertyAnimation {
				target: compact_switch_groove;
				property: "color";
				to: "#1F2127";
				duration: 200;
			    }
		}
		SequentialAnimation {
			id: switch_on;
			PropertyAnimation {
				target: compact_switch_handle;
				property: "x";
				to: "25";
				duration: 100;
			}
			PropertyAnimation {
			    target: compact_switch_groove;
			    property: "color";
			    to: "#8897f4";
			    duration: 200;
			}
		}
		onClicked: {
			if (!compact_switch.checked)
				switch_off.running = true;
			else
				switch_on.running = true;
		}
	}

	Button {
		id: encrypt_button;
		width: 350;
		height: 35;
		x: (Screen.desktopAvailableWidth - width) / 2;
		y: compact_switch.y + compact_switch.height + 80;
		text: qsTr("Encrypt Password");

		contentItem: Text {
			text: encrypt_button.text;
			font: encrypt_button.font;
			color: "#00c4dc";
			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter
			elide: Text.ElideRight;
		}

		background: Rectangle {
			border.color: encrypt_button.down ? "#00c4dc" : "#000000";
			border.width: 1;
			radius: 5;
			color: encrypt_button.down ? "#8897f4" : "#1F2127";
		    }
		onClicked: {
			if (password_input.length > 1 && key_input.length > 1) {
				encrypt(password_input.text, key_input, compact_switch.checked);
				//stackview.push("qrc:/OutputForm.qml");
			} else if (password_input.length > 1) {
				key_error.visible = true;
			} else {
				password_error.visible = true;
			}
		}
	}

	MessageDialog {
		id: password_error;
		title: "Password Error";
		icon: StandardIcon.Warning;
		text: "Please enter a password containing at least 2 characters";
		//detailedText: "To replace a file means that its existing contents will be lost. " +
		//"The file that you are copying now will be copied over it instead."
//		standardButtons: StandardButton.Yes | StandardButton.YesToAll | StandardButton.No | StandardButton.NoToAll | StandardButton.Abort
		standardButtons: standardButtons.Ok;
		//Component.onCompleted: visible = true
		//onYes: console.log("copied")
		//onNo: console.log("didn't copy")
		//onRejected: console.log("aborted")
	}

	MessageDialog {
		id: key_error;
		title: "Key Error";
		icon: StandardIcon.Warning;
		text: "Please enter a key containing at least 2 characters";
		standardButtons: standardButtons.Ok;
	}
}
