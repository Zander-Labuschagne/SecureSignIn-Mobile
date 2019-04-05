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

#ifndef WORKERTHREAD_HPP
#define WORKERTHREAD_HPP

#include <QThread>

/**
 * @brief Class to handle all threads of SecureSignIn, extends QThread class
 * @since 3.0.0
 * worker_thread.hpp
*/
class WorkerThread : public QThread
{
	Q_OBJECT
public:
	WorkerThread(QObject *parent);
	void run() override;
signals:
	void done_waiting(); // Fires when thread is done executing

};
#endif // WORKERTHREAD_HPP
