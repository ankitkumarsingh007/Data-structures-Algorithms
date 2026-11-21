class DiningPhilosophers {
    mutex mtx[5];
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		scoped_lock lck(mtx[philosopher], mtx[(philosopher + 1) % 5]);
        pickLeftFork(); pickRightFork(); eat(); putLeftFork(); putRightFork();
    }
};