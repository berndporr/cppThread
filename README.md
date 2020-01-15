# CppThread
Generic C++ Thread

The `std::thread` has the problem that it can only call static
functions / methods which is useless in C++. This class is a
thin wrapper which creates a class with an abstract `run()`
function which is called as a new thread.

## Usage
Include CppThread.h in your program.

### Create the Thread class
```
class MyThread : public CppThread {

public:
	// override the constructor and add your init stuff
	MyThread(myArgs) {	    
	    // Your init code here!
	}

private:
	// implement run which is doing all the work
	void run() {
	     // Your magic worker here!
	}
	
private:
	// Your private data
};
```

### Run the Thread class
```
	MyThread myThread;
	myThread.start();
	myThread.join();
```

## Demo program

### Linux / Mac
To run `demo.cpp` just do `cmake .`, `make` and then `./demo`.

### Windows
To run `demo.cpp` just do `cmake .`, then start visual C++, open the solution, build it and then run `Debug\demo`.

That's it. Enjoy!
