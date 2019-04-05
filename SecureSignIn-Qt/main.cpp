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

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QObject>
#include <QQmlComponent>
#include <QQmlContext>

#include "back_end.hpp"

/**
 * @brief The Main class and function.
 * main.cpp
 * Purpose: C++/Qt/QML Program entry point.
 * @since 3.0.0
 */
int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QQuickStyle::setStyle("Imagine");

	QGuiApplication app(argc, argv);

	qmlRegisterType<BackEnd>("Cryogen.BackEnd", 1, 0, "BackEnd"); //Registers the MainForm class to be accessible in the QML class by importing <cryogen.BackEnd 1.0>

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}
