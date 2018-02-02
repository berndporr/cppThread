#include <stdio.h>
#include "DemoThread.h"


int main( int argc, const char* argv[] ) {
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
