#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QObject>

#include "mainform.hpp"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QQuickStyle::setStyle("Imagine");

	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	MainForm main_form;
	QObject::connect(engine.rootObjects().at(0), SIGNAL(encrypt(QString, QString, bool)), &main_form, SLOT(encrypt_clicked(QString, QString, bool)));
	QObject::connect(&main_form, SIGNAL(encrypted(QString)),(QObject *)engine.rootObjects().at(0), SLOT(on_encrypted(QString)));

	return app.exec();
}
