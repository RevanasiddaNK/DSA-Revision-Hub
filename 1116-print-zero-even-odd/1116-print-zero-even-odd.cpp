class ZeroEvenOdd {
private:
    int n;
    condition_variable cv;
    mutex m;
    int i;  // Tracks the current number
    int turn;  // Keeps track of whose turn it is (0 for zero, 1 for odd, 2 for even)

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->i = 1;  // Start from 1 for odd numbers
        this->turn = 0;  // Zero is the first to print
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (i <= n) {
            unique_lock<mutex> lock(m);
            while (turn != 0 && i<=n) {
                cv.wait(lock);  
            }
            if(i > n){
                break;
            }

            printNumber(0);   
            turn = (i % 2 == 0) ? 2 : 1;       
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (i <= n) {
            unique_lock<mutex> lock(m);
            while (turn != 2 && i<=n) {
                cv.wait(lock);  
            }
            if(i > n){
                break;
            }

            printNumber(i++);   
            turn = 0;         
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (i <= n) {
            unique_lock<mutex> lock(m);
            while (turn != 1 && i<=n) {
                cv.wait(lock); 
            }
            if(i > n){
                break;
            }

            printNumber(i++);   
            turn = 0;          
            cv.notify_all();
        }
    }
};