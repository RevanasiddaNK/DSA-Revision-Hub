class Semaphore{
    
    private:
        mutex m;
        condition_variable cv;
        int count;

    public:
        Semaphore(){}
        Semaphore(int count){
            this->count = count;
        }
    
    void setCount(int n){
        this->count = n;
    }

    inline void signal(){
        unique_lock<mutex>lock(m);
        count++;
        if(count <= 0){
            cv.notify_one();
        }
    }

    inline void wait(){
        unique_lock<mutex>lock(m);
        count--;
        if(count < 0){
            cv.wait(lock);
        }

    }

};

class DiningPhilosophers {
public:

    Semaphore fork[5];
    mutex m,l;
    
    DiningPhilosophers() {
        for(int i=0; i<5; i++){
            fork[i].setCount(1);
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        
        lock_guard<mutex>lock(m);
        fork[philosopher].wait();
        fork[(philosopher+1)%5].wait();
        

        pickLeftFork();
        pickRightFork();
        // Eaating
        eat();

        putLeftFork();
        fork[(philosopher+1)%5].signal();
        putRightFork();
        fork[philosopher].signal();

		
    }
};