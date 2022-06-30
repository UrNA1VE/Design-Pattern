//Imagine that you created an object, but after a while decided to create a new one. 
// Instead of receiving a fresh object, you’ll get the one you already created.

#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mutex_;

protected:
    ~Singleton() {};
    Singleton(string s) {
        value_ = s;
    };
    string value_;
public:
    Singleton(const Singleton& sample) = delete;
    void operator=(const Singleton&) = delete;
    static Singleton* GetInstance(string name);
    string name() {
        return value_;
    }
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mutex_;
Singleton* Singleton::GetInstance(string name) {
    lock_guard<mutex> lock(mutex_);
    if (instance == nullptr) {
        instance = new Singleton(name);
    }
    return instance;
};

void Thread1() {
    this_thread::sleep_for(chrono::milliseconds(100));
    Singleton* sample = Singleton::GetInstance("BAR");
    cout<<sample->name()<<endl;
}

void Thread2() {
    this_thread::sleep_for(chrono::milliseconds(100));
    Singleton* sample = Singleton::GetInstance("FOO");
    cout<<sample->name()<<endl;
}

int main() {
    std::cout <<"If you see the same value, then singleton was reused \n" <<
                "If you see different values, then 2 singletons were created\n\n" <<
                "RESULT:\n";  
    thread t1(Thread1);
    thread t2(Thread2);
    t1.join();
    t2.join();
    return 0;
}

