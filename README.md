# CppThread

Super-thin wrapper class around `std::thread` as a demo how
to use it.

Just inherit this class, implement your `run()` method and
then use `start()` to start the thread. You can use `join()` for
the thread to complete.

## Usage

Include CppThread.h in your program. It's header-only.

### Create your Thread class by inheriting `CppThread`

Just overload `run()` which does the work in your thread:

```
class MyThread : public CppThread {

private:
	// implement run which is doing all the work
	void run() {
	     // Your magic worker here!
	}
};
```

### Run the Thread class

`start()` starts the thread and runs the method `run()`.
If you need to wait for its completion then call `join()`:
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
