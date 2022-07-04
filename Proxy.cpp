#include<iostream>

using namespace std;

class CreditCard {
public:
    virtual void Pay(int amount) const{
        cout<<"Pay "<<amount<<" money"<<endl;
    }
};

class Proxy: CreditCard {
public:
    Proxy(CreditCard*c): c(c){};

    void Pay(int amount) const {
        if (Check()) {
            LogIn();
            c->Pay(amount);
            LogOut();
        }
    }


private:
    CreditCard* c;
    bool Check() const{
        cout<<"Checking access"<<endl;
        return true;
    }

    void LogIn() const {
        cout<<"Logging in"<<endl;
    }

    void LogOut() const {
        cout<<"Logging out"<<endl;
    }

};

int main() {
    CreditCard* c = new CreditCard();
    Proxy* p = new Proxy(c);
    p->Pay(500);
    return 0;
}