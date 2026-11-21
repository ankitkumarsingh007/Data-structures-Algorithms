class FooBar {
private:
    int n;
    int count = 0;
    mutex mtx;
    condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
        count = 1;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [this] { return count == 1; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            count = 2;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [this] { return count == 2; });
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            count = 1;
            cv.notify_all();
        }
    }
};