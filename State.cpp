#include<iostream>

using namespace std;

class Context;

class State {
public:
    virtual void handle1() = 0;
    virtual void handle2() = 0;
    virtual void setContext(Context* ) = 0;

protected:
    Context* context;
};

class Context {
public:
    void setState(State* s) {
        state = s;
        s->setContext(this);
    }

    void request1() {
        this->state->handle1();
    }


    void request2() {
        this->state->handle2();
    }

private:
    State* state = nullptr;
};


class StateB;

class StateA: public State {
public:
    void handle1() override {
        cout<<"StateA handle request 1!";
    }

    void handle2() override;

    void setContext(Context* c) override {
        context = c;
    }

};

class StateB: public State {
public:
    void handle1() override {
        cout<<"StateB handle request 1!";
        cout<<"Change state to A!";
        this->context->setState(new StateA());
    }

    void handle2() override {
        cout<<"StateB handle request 2!";
    }

    void setContext(Context* c) override {
        context = c;
    }

};
void StateA::handle2() {
        cout<<"StateA handle request 2!";
        cout<<"Change state to B!";
        context->setState(new StateB());

}




int main() {
    State* a = new StateA();
    Context* c = new Context();
    c->setState(a);
    c->request1();
    c->request2();
    c->request1();
    c->request2();
}