#include<iostream>

using namespace std;

class SubSystem1 {
public:
    void start() {
        cout<<"Starting subsystem1"<<endl;
    }

    void freeze() {
        cout<<"Freezing susbsystem1"<<endl;
    }

    void end() {
        cout<<"Ending subsystem1"<<endl;
    }
};

class SubSystem2 {
public:
    void start() {
        cout<<"Starting subsystem2"<<endl;
    }

    void freeze() {
        cout<<"Freezing susbsystem2"<<endl;
    }

    void end() {
        cout<<"Ending subsystem2"<<endl;
    }
};

class Facade {
public:
    Facade(SubSystem1* s1, SubSystem2* s2): subsystem1(s1), subsystem2(s2) {};
    ~ Facade() {
        delete subsystem1;
        delete subsystem2;
    }

    void Operation() {
        subsystem1->start();
        subsystem2->start();
        subsystem1->freeze();
        subsystem2->freeze();
        subsystem1->end();
        subsystem2->end();

    }

private:
    SubSystem1* subsystem1;
    SubSystem2* subsystem2;
};

int main() {
    SubSystem1* s1 = new SubSystem1();
    SubSystem2* s2 = new SubSystem2();
    Facade* f = new Facade(s1, s2);
    f->Operation();
    delete f;
    return 0;
}

