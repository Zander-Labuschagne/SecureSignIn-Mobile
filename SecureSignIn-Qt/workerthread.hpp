#ifndef WORKERTHREAD_HPP
#define WORKERTHREAD_HPP

#include <QThread>

class WorkerThread : public QThread
{
	Q_OBJECT
public:
	WorkerThread(QObject *parent);
	void run() override;
signals:
	void resultReady();

};
#endif // WORKERTHREAD_HPP
