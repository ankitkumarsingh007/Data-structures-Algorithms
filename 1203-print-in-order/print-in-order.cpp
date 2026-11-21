class Foo {
public:
    int count;
    mutex mtx;
    condition_variable cv;
    Foo() { count = 0; }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lck(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        count = 1;
        lck.unlock();

        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [this] { return count == 1; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        count = 2;

        lck.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [this] { return count == 2; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        lck.unlock();
    }
};