class MedianFinder {
public:
    int cnt;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() { cnt = 0; }

    void addNum(int num) {
        if ((cnt % 2) == 0) {
            left.push(num);
        } else {
            right.push(num);
        }

        if (!right.empty()) {
            if (left.top() > right.top()) {
                right.push(left.top());
                left.pop();
                left.push(right.top());
                right.pop();
            }
        }

        cnt++;
    }

    double findMedian() {
        return (cnt % 2) == 0 ? (left.top() + right.top()) / 2.0 : left.top();
     }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */