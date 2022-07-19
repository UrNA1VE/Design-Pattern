#include<iostream>

using namespace std;

class Component;

class Mediator {
public:
    virtual void notify(Component* , string) = 0;
};

class Component {
public:
    Component(string s, Mediator* m = nullptr): name(s), mediator(m) {}

    void SetMediator(Mediator* m) {
        mediator = m;
        return;
    }

    string GetName() {
        return name;
    }

protected:
    Mediator* mediator;
    string name;
};

class Component1: public Component {
public:

    Component1(string s, Mediator* m = nullptr): Component(s, m) {};

    void doA() {
        cout<<"Do A"<<endl;
        this->mediator->notify(this, "A");
        return;
    }

    void doB() {
        cout<<"do B"<<endl;
        this->mediator->notify(this, "B");
    }

};


class Component2: public Component {
public:

    Component2(string s, Mediator* m = nullptr): Component(s, m) {};
    void doC() {
        cout<<"Do C"<<endl;
        this->mediator->notify(this, "C");
        return;
    }

    void doD() {
        cout<<"do D"<<endl;
        this->mediator->notify(this, "D");
    }
};

class Mediator1: public Mediator {
public:
    Mediator1(Component1* cc1, Component2* cc2): c1(cc1), c2(cc2) {};

    void notify(Component* component, string message) override {
        if (message == "A") {
            cout<<component->GetName()<<" is doing A. We need to do C"<<endl;
            this->c2->doC();
        }
        if (message == "D") {
            cout<<component->GetName()<<" is doing D. We need to do B"<<endl;
            this->c1->doB();
        }
    }
private:
    Component1* c1;
    Component2* c2;
};

int main() {
    string s1 = "1", s2 = "2";
    Component("asd");
    Component1* c1 = new Component1(s1);
    Component2* c2 = new Component2(s2);
    Mediator1* m1 = new Mediator1(c1, c2);
    c1->SetMediator(m1);
    c2->SetMediator(m1);
    c1->doA();
    c2->doD();
    return 0;
}