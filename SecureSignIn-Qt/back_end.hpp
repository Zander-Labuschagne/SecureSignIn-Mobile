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


#ifndef BACKEND_HPP
#define BACKEND_HPP

#include <QObject>
#include <QClipboard>

/**
 * @brief The BackEnd class
 * back_end.hpp
 * Purpose: Provides functionality for the GUI(front end), containing the following members along with their accessor and mutator functions where necesarry:
 * password: Holds the original password entered by the user.
 * key: Holds the key entered by the user.
 * compact: Indicate whether the user opted for the compact version of the password.
 * cipher_password: Processed(encrypted) password to be used(output of application).
 * clipboard: Object used to access the system clipboard.
 */
class BackEnd : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString cipher_password READ get_cipher_password WRITE set_cipher_password NOTIFY password_encrypted) //The QProperty declares a property to be accessed from QML
	Q_PROPERTY(QString password READ get_password WRITE set_password NOTIFY password_changed)
	Q_PROPERTY(QString key READ get_key WRITE set_key NOTIFY key_changed)
	Q_PROPERTY(bool compact READ get_compact WRITE set_compact NOTIFY compact_changed)

public:
	explicit BackEnd(QObject *parent = nullptr);
	~BackEnd(); //Default destructor

	void set_password(const QString password);
	QString get_password();
	void set_key(const QString key);
	QString get_key();
	void set_compact(const bool compact);
	bool get_compact();
	QString get_cipher_password();
	QClipboard* get_clipboard();
public slots:
	void encrypt_clicked();
	void copy_clicked();
	void clear();
signals:
	void password_encrypted();
	void password_changed();
	void key_changed();
	void compact_changed();
private:
	QString password;
	QString key;
	bool compact;
	QString cipher_password;
	QClipboard *clipboard;
	void set_cipher_password(const QString &cipher_password);
};

#endif // BACKEND_HPP
