#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QObject>
#include <QQmlComponent>
#include <QQmlContext>

#include "mainform.hpp"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QQuickStyle::setStyle("Imagine");

	QGuiApplication app(argc, argv);

	qmlRegisterType<MainForm>("Cryogen.MainForm", 1, 0, "Main_Form"); //Registreer die MainForm klas sodat hy toeganklik is in QML deur <cryogen.main_form 1.0> te import

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}
