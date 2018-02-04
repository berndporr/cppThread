#ifndef __CPP_THREAD_H_
#define __CPP_THREAD_H_

/**
 * GNU GENERAL PUBLIC LICENSE
 * Version 3, 29 June 2007
 *
 * (C) 2018, Bernd Porr <mail@bernporr.me.uk>
 **/

#ifdef __linux__
#include <pthread.h>
#include <string.h>
#endif

#ifdef _WIN32
#include <windows.h>
#endif


// abstract thread which contains the inner workings of the thread model
class CppThread {

private:
	
#ifdef __linux__
	pthread_t id = 0;
#endif

#ifdef _WIN32
	DWORD id = 0;
	HANDLE hThread = 0;
#endif

#ifdef __linux__
	static void *exec(void *thr) {
		reinterpret_cast<CppThread *> (thr)->run();
		return NULL;
	}
#endif

#ifdef _WIN32
	static DWORD WINAPI exec(LPVOID thr) {
		reinterpret_cast<CppThread *> (thr)->run();
		return 0;
	}
#endif


public:
	CppThread() {};
	
	virtual ~CppThread() {
#ifdef _WIN32
		CloseHandle(hThread);
#endif
	}
	
	void start() {
#ifdef __linux__
		int ret;
		if ((ret = pthread_create(
			     &id,
			     NULL,
			     &CppThread::exec,
			     this)) != 0) {
			throw "Cannot create thread"; 
		}
#endif
#ifdef _WIN32
		if ((hThread = CreateThread(
			NULL,
			0,
			&CppThread::exec,
			this,
			0,
			&id)) == NULL) {
			throw "Cannot create thread";
		}
#endif
	}

	void join() {
#ifdef __linux__
		pthread_join(id,NULL);
#endif
#ifdef _WIN32
		WaitForSingleObject(hThread, INFINITE);
#endif
	}

	// is implemented by its ancestors
	// this is exectuted once "start()" has been called
	virtual void run() = 0;
	
};


#endif
