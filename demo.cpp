#include <stdio.h>
#include "CppThread.h"
#include <unistd.h>


class DemoThread : public CppThread {

public:
	DemoThread(int _offset) {
		offset = _offset;
	}

private:
	void run() {
		for(int i=0;i<10;i++) {
			printf("%d\n",i+offset);
			sleep(1);
		}
	}
private:
	int offset;
};


main( int argc, const char* argv[] ) {
	DemoThread demoThread1(0);
	DemoThread demoThread2(10);
	demoThread1.start();
	demoThread2.start();
	demoThread1.join();
	demoThread2.join();
}
