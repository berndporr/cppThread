#ifndef __CPP_THREAD_H_
#define __CPP_THREAD_H_

/**
 * GNU GENERAL PUBLIC LICENSE
 * Version 3, 29 June 2007
 *
 * (C) 2020-2021, Bernd Porr <mail@bernporr.me.uk>
 **/

#include <thread>

// abstract thread which contains the inner workings of the thread model
class CppThread {

public:
	void start() {
		uthread.reset(new std::thread(CppThread::exec, this));
	}

	void join() {
		if (nullptr != uthread) {
			uthread->join();
		}
		uthread = nullptr;
	}

protected:
	// is implemented by its ancestors
	virtual void run() = 0;	

private:
	std::unique_ptr<std::thread> uthread = nullptr;

	// static function which points back to the class
	static void exec(CppThread* cppThread) {
		cppThread->run();
	}
};


#endif
