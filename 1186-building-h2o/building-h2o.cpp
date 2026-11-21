class H2O {
    mutex mtx;
    condition_variable cv;
    int turn = 1;

public:
    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [this] { return turn % 3 != 0; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        turn++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [this] { return turn % 3 == 0; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        turn = 1;
        cv.notify_all();
    }
};