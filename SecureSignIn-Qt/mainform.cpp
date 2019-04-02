#include "mainform.hpp"

#include <QQmlApplicationEngine>

#include <QDebug>

MainForm::MainForm()
{
}

void MainForm::encrypt_clicked()
{
//	QQmlApplicationEngine engine;
//	engine.load(QUrl(QStringLiteral("qrc:/OutputForm.qml")));
//	if (engine.rootObjects().isEmpty())
//		return;
	qDebug() << "hier";
}

MainForm::~MainForm()
{

}
