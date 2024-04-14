#include <iostream>
#include <condition_variable>

using namespace std;


/*
Mutex + Conditional Variable.
The idea is that H is released when currently released Hs becomes less than 2,
and O is released when currently released Hs becomes equal to 2.
*/
class H2O {
public:
    int hydro_count = 0;
    mutex mtx;
    condition_variable cv;

    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]{return hydro_count < 2;});

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        ++hydro_count;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]{return hydro_count >= 2;});

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

        hydro_count = 0;
        cv.notify_all();
    }
};