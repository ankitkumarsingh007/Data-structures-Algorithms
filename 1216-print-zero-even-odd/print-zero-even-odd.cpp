class ZeroEvenOdd {
private:
    int n;
    bool zeroFlag = true;
    bool oddFlag = true;
    condition_variable cv;
    mutex mtx;

public:
    ZeroEvenOdd(int n) { this->n = n; }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [this] { return zeroFlag; });

            printNumber(0);
            zeroFlag = false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [this] { return !zeroFlag && !oddFlag; });
            printNumber(i);
            zeroFlag = true;
            oddFlag = true;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [this] { return !zeroFlag && oddFlag; });
            printNumber(i);
            zeroFlag = true;
            oddFlag = false;
            cv.notify_all();
        }
    }
};