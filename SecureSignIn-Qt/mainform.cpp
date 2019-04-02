#include "mainform.hpp"

#include <QDebug>

#include <secure_sign_in.hpp>
#include <workerthread.hpp>

MainForm::MainForm()
{
}

void MainForm::encrypt_clicked(QString password, QString key, bool compact)
{
//	qDebug() << "hier";
//	qDebug() << compact;

	SecureSignIn ssi;
//	char *cipher_password;

	if (compact)
		cipher_password =  ssi.encrypt(&(password.toStdString().c_str()[0]), &(key.toStdString().c_str()[0]), 12);
	else
		cipher_password =  ssi.encrypt(&(password.toStdString().c_str()[0]), &(key.toStdString().c_str()[0]), 32);

	//output_window = new OutputWindow(this, cipher_password, clipboard);
	emit encrypted(QString(cipher_password));
	//output_window->setFixedSize(420, 130);
	//output_window->setWindowTitle("Secure Sign In v4.0");
	//wait 8sec on new thread
	WorkerThread *workerThread = new WorkerThread(this);
	connect(workerThread, &WorkerThread::resultReady, this, &MainForm::clear);
	connect(workerThread, &WorkerThread::finished, workerThread, &QObject::deleteLater);
	workerThread->start();
}

void MainForm::clear()
{
	clipboard->clear();
	free(cipher_password);
	free(clipboard);
}

MainForm::~MainForm()
{

}
