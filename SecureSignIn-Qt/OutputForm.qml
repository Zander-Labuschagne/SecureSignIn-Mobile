import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.3

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
//	    placeholderText: "Password";
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

	Button {
		id: reveal;
		width: 120;
		height: 35;
		x: 10;
		y: password_input.y + password_input.height + 80;
		text: qsTr("Reveal Password");

		contentItem: Text {
			text: reveal.text;
			font: reveal.font;
			color: "#00c4dc";
			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter
			elide: Text.ElideRight;
		    }

		    background: Rectangle {
			border.color: reveal.down ? "#00c4dc" : "#000000";
			border.width: 1;
			radius: 5;
			color: reveal.down ? "#8897f4" : "#1F2127";
		    }
	}

	Button {
		id: copy;
		width: 120;
		height: 35;
		x: reveal.x + reveal.width + 5;
		y: reveal.y;
		text: qsTr("Copy Password");

		contentItem: Text {
			text: copy.text;
			font: copy.font;
			color: "#00c4dc";
			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter
			elide: Text.ElideRight;
		    }

		    background: Rectangle {
			border.color: copy.down ? "#00c4dc" : "#000000";
			border.width: 1;
			radius: 5;
			color: copy.down ? "#8897f4" : "#1F2127";
		    }
	}

	Button {
		id: ok;
		width: 60;
		height: 35;
		x: copy.x + copy.width + 5;
		y: copy.y;
		text: qsTr("Ok");

		contentItem: Text {
			text: ok.text;
			font: ok.font;
			color: "#00c4dc";
			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter
			elide: Text.ElideRight;
		    }

		    background: Rectangle {
			border.color: ok.down ? "#00c4dc" : "#000000";
			border.width: 1;
			radius: 5;
			color: ok.down ? "#8897f4" : "#1F2127";
		    }
	}
}