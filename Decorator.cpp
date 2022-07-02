#include<iostream>
using namespace std;


class Component {
public:
    virtual ~Component(){} ;

    virtual string ingredients() = 0; 
};

class Milk: public Component{
public:
    string ingredients() override{
        return "Milk";
    }
};

class Tea: public Component{
public:
    string ingredients() override{
        return "Tea";
    }
};

class Decorator: public Component {
protected:
    Component* component_;

public: 
    Decorator(Component* c): component_(c) {};

    string ingredients() override{
        return "";
    }
};

class Pearl: public Decorator {
public:
    Pearl(Component* c): Decorator(c) {};

    string ingredients() override{
        return "Pearls + " + component_->ingredients();
    }
};

class Pudding: public Decorator {
public:

    Pudding(Component* c): Decorator(c) {};
    string ingredients() override{
        return "Pudding + " + component_->ingredients();
    }
};

void ClientCode(Component* c) {
    cout<<c->ingredients()<<endl;
}

int main() {
    Component* A = new Tea();
    Component* B = new Pearl(A);
    Component* C = new Pudding(B);
    ClientCode(C);
    delete C;

    Component* D = new Milk();
    Component* E = new Pudding(D);
    ClientCode(E);
    delete E;
    return 0;
}