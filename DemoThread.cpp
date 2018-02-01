#include "DemoThread.h"

#include <unistd.h>
#include <stdio.h>

void DemoThread::run() {
	for(int i=0;i<10;i++) {
		printf("%d\n",i+offset);
		usleep(1000);
	}
}
