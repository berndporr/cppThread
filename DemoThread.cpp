#include "DemoThread.h"

#include <stdio.h>
#include <chrono>
#include <thread>

void DemoThread::run() {
	for(int i=0;i<10;i++) {
		printf("%d\n",i+offset);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}
