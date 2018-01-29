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
			usleep(1000);
		}
	}
private:
	int offset;
};


main( int argc, const char* argv[] ) {
	DemoThread demoThread1(0);
	DemoThread demoThread2(10);
	DemoThread demoThread3(20);
	demoThread1.start();
	demoThread2.start();
	demoThread3.start();
	demoThread1.join();
	demoThread2.join();
	demoThread3.join();
}
