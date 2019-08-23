/**
 * Copyright (C) 2019 Zander Labuschagne. All rights reserved.
 * @version 3.0.0 05/04/19
 * @since 3.0.0
 *
 * Authors:
 *         @author Zander Labuschagne <zander.labuschagne@protonmail.ch>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU GPL 2.0 License, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GPL 2.0 License for more details.
 *
 * You should have received a copy of the GNU GPL 2.0 License
 * along with this program; if not, write to the author,
 * contact details above in line 7.
 */


import QtQuick 2.9
import QtQuick.Controls 2.2
//import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.3

/**
 * @brief Shows output view after encrypting the password
 * @since 3.0.0
 * output_view.qml
*/
Page {
	id: output_view;
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
	    id: password_output;
	    x: 10;
	    y: logo.y + logo.height + 60;
	    width: Screen.desktopAvailableWidth - (2 * this.x);
	    height: 35;
	    echoMode: TextInput.Password;
	    readOnly: true;
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
	    topPadding: 2;
	    bottomPadding: 0;
	    text: back_end.cipher_password;
	}

	Button {
		id: reveal;
		width: (Screen.desktopAvailableWidth - (2 * reveal.x) - (2 * 5)) * (3 / 8);
		height: 35;
		x: 10;
		y: password_output.y + password_output.height + 40;
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
		onClicked: {
			if (password_output.echoMode == TextInput.Password) {
				password_output.echoMode = TextInput.Normal;
				reveal.text = "Hide Password";
			}
			else {
				password_output.echoMode = TextInput.Password;
				reveal.text = "Reveal Password";
			}
		}
	}

    Button {
		id: copy;
		width: reveal.width;
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
		onClicked:
		    back_end.copy_clicked();

	}

	Button {
		id: ok;
		width: (Screen.desktopAvailableWidth - (2 * reveal.x) - (2 * 5)) * (2 / 8);
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
		onClicked: {
			stack_view.pop();
		}
	}
}
