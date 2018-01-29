#ifndef __CPP_THREAD_H_
#define __CPP_THREAD_H_

/**
 * GNU GENERAL PUBLIC LICENSE
 * Version 3, 29 June 2007
 *
 * (C) 2017, Bernd Porr <mail@bernporr.me.uk>
 **/

#ifdef __linux__
#include <pthread.h>
#include <string.h>
#endif

#ifdef _WIN32
#include <windows.h>
#endif


#define NUM_THREADS 12


// abstract thread which contains the inner workings of the thread model
class CppThread {

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
		if ((ret = pthread_create(&id, NULL, &CppThread::exec, this)) != 0) {
			fprintf(stderr,"%s\n",strerror(ret)); 
			throw "Error"; 
		}
#endif
#ifdef _WIN32
		hThread = CreateThread(
			NULL,                   // default security attributes
			0,                      // use default stack size  
			&LayerThread::exec,     // thread function name
			this,                   // argument to thread function 
			0,                      // use default creation flags 
			&id);   // returns the thread identifier 
		if (hThread == NULL) {
			ExitProcess(3);
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

	// is implemented by its children to do the specfic task the thread
	virtual void run() = 0;
	
};


#endif
