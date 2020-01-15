# CppThread
Generic C++ Thread

The C++ `std::thread` has the problem that it can only call static
functions / methods. This class solves this
problem with an abstract `run()` method which acts as the thread.

Just inherit this class, implement your `run()` method and
then use `start()` to start the thread.

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
