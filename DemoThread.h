#ifndef DEMO_THREAD_H
#define DEMO_THREAD_H

#include "CppThread.h"

class DemoThread : public CppThread {

public:
	DemoThread(int _offset) {
		offset = _offset;
	}

private:
	void run();

private:
	int offset;
};

#endif
