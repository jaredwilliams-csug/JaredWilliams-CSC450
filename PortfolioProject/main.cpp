#include <iostream>
#include <thread>
using namespace std;

void increment(int &val, int limit);
void decrement(int &val, int min);
void printVal(int &val);
// Mutex for handling concurrency issues with a shared resource
mutex mtx;

int main() {
    // Variable to pass reference of to count up and down
    int val = 0;
    // Variables to increase readability (no magic numbers)
    int max = 20;
    int min = 0;
    // define the two threads
    thread a(increment, ref(val), max);
    thread b(decrement, ref(val), min);
    // execute the two threads
    a.join();
    b.join();

    return 0;
}

// Accepts a reference to the shared variable and the max value
// Increases value to max, outputs value to console.
void increment(int &val, int max) {
    mtx.lock();
    while (val < max) {
        cout << val << endl;
        val++;
    }
    cout << val << endl;
    printVal(val);
    mtx.unlock();
}

// Accepts a reference to the shared variable and the min value
// Decreases value to min, outputs value to console.
void decrement(int &val, int min) {
    mtx.lock();
    while (val > min) {
        cout << val << endl;
        val--;
    }
    cout << val << endl;
    printVal(val);
    mtx.unlock();
}
// Prints the calling thread id and the value of the variable
void printVal(int &val) {
    cout << "Thread " << this_thread::get_id() << " final value: " << val << endl;
}