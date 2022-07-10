#include<iostream>

using namespace std;

class Handler {
public:
    virtual Handler* setNext(Handler* ) = 0;
    virtual void handle(const string& ) = 0;
};

class abstractHandler: public Handler {
public:
    abstractHandler() {
        handler = nullptr;
    }

    Handler* setNext(Handler* h) override {
        handler = h;
        return h;
    }

    void handle(const string& num) override {
        if (handler != nullptr) this->handler->handle(num);
    }
private:
    Handler* handler;
};

class firstHandler: public abstractHandler {
public:
    void handle(const string& num) override{
        cout<<"If the first character is not 1, 2, 3, it will fail!"<<endl;
        if (num[0] == '1' || num[0] == '2' || num[0] == '3') {
            cout<<"Pass the first test!"<<endl;;
            abstractHandler::handle(num);
        }
        else {
            cout<<"Fail the first test!"<<endl;
        }
    }
};

class secondHandler: public abstractHandler {
public:
    void handle(const string& num) override{
        cout<<"If the second character is not 4, 5, 6 it will fail!"<<endl;
        if (num[1] == '4' || num[1] == '5' || num[1] == '6') {
            cout<<"Pass the second test!"<<endl;;
            abstractHandler::handle(num);
        }
        else {
            cout<<"Fail the second test!"<<endl;
        }
    }
};


class thirdHandler: public abstractHandler {
public:
    void handle(const string& num) override{
        cout<<"If the third character is not 7, 8, 9 it will fail!"<<endl;
        if (num[2] == '7' || num[2] == '8' || num[2] == '9') {
            cout<<"Pass the third test!"<<endl;;
            abstractHandler::handle(num);
        }
        else {
            cout<<"Fail the third test!"<<endl;
        }
    }
};

int main() {
    firstHandler* f = new firstHandler();
    secondHandler* s = new secondHandler();
    thirdHandler* t = new thirdHandler();
    f->setNext(s)->setNext(t);
    f->handle("147");
    f->handle("447");
    f->handle("269");
    return 0;
}

