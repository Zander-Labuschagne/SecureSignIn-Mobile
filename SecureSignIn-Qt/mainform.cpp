#include "mainform.hpp"

#include <QDebug>

#include <secure_sign_in.hpp>
#include <workerthread.hpp>

MainForm::MainForm(QObject *parent) : QObject(parent)
{
}

void MainForm::encrypt_clicked()
{
	qDebug() << "hier";
	qDebug() << get_password();

	SecureSignIn ssi;
//	char *cipher_password;

//	if (get_compact())
//		this->cipher_password =  ssi.encrypt(&(password.toStdString().c_str()[0]), &(key.toStdString().c_str()[0]), 12);
//	else
//		this->cipher_password =  ssi.encrypt(&(password.toStdString().c_str()[0]), &(key.toStdString().c_str()[0]), 32);

	set_cipher_password("...");

	//output_window = new OutputWindow(this, cipher_password, clipboard);
	emit password_encrypted();
	//output_window->setFixedSize(420, 130);
	//output_window->setWindowTitle("Secure Sign In v4.0");
	//wait 8sec on new thread
//	WorkerThread *workerThread = new WorkerThread(this);
//	connect(workerThread, &WorkerThread::resultReady, this, &MainForm::clear);
//	connect(workerThread, &WorkerThread::finished, workerThread, &QObject::deleteLater);
//	workerThread->start();
}

void MainForm::clear()
{
	clipboard->clear();
//	free(cipher_password);
	this->cipher_password = "";
	free(clipboard);
}

void MainForm::set_password(const QString password)
{
	if (this->password == password)
		return;

	this->password = password;
//	emit password_changed();
}

QString MainForm::get_password()
{
	return this->password;
}

void MainForm::set_key(const QString key)
{
	if (this->key == key)
		return;

	this->key = key;
//	emit password_encrypted();
}

QString MainForm::get_key()
{
	return this->key;
}

void MainForm::set_compact(const bool compact)
{
	if (this->compact == compact)
		return;

	this->compact = compact;
//	emit passw;
}

bool MainForm::get_compact()
{
	return this->compact;
}

void MainForm::set_cipher_password(const QString &cipher_password)
{
	if (this->cipher_password == cipher_password)
		return;

	this->cipher_password = cipher_password;
	emit password_encrypted();
}

QString MainForm::get_cipher_password()
{
	return this->cipher_password;
}


MainForm::~MainForm()
{

}
