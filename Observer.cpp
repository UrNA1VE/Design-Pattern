#include<iostream>
#include<list>

using namespace std;

class ISubscripter;

class IChannel {
public:
    virtual ~IChannel() {};
    virtual void notify(string m) = 0;
    virtual void add(ISubscripter* ) = 0;
    virtual void detach(ISubscripter* ) = 0;
    virtual string info() = 0;
};

class ISubscripter {
public:
    virtual ~ISubscripter() {};
    virtual void update(string& ) = 0;
    virtual void sub(IChannel* ) = 0;
    virtual void unsub(IChannel* ) = 0;
    virtual string info() = 0;
};



class Subscripter: public ISubscripter {
public:

    Subscripter(string m): message(m){};

    void update(string& m) override{
        cout<<this->info()<<" has got the new message: "<<m<<endl;
    }

    void sub(IChannel* c) override{
        c->add(this);
        cout<<"You have subscripted channel "<<c->info()<<endl;
    }

    void unsub(IChannel* c) override{
        c->detach(this);
        cout<<"You have unsubscripted channel "<<c->info()<<endl;
    }

    string info() override {
        return message;
    }



private:
    string message;
};

class Channel: public IChannel {
public:

    Channel(string m): message(m) {};

    void add(ISubscripter* s) override{
        subscripters.push_back(s);
        cout<<"Channel "<<this->info()<<" have added "<<s->info()<<"."<<endl;
    }

    void detach(ISubscripter* s) override{
        for (auto it = subscripters.cbegin(); it != subscripters.cend(); it++) {
            if (*it == s) {
                subscripters.erase(it);
                break;
            }
        }
        
        cout<<"Channel "<<this->info()<<" have detached "<<s->info()<<"."<<endl;
    }

    void notify(string m) override{
        cout<<"Channel "<<this->info()<<" has following subsripters: "<<endl;
        for (auto it = subscripters.begin(); it != subscripters.end(); it++) {
            (*it)->update(m);
        }
    }

    string info() override {
        return message;
    }

private:
    list<ISubscripter*> subscripters;
    string message;
};

int main() {
    Channel* c1 = new Channel("Music");
    Channel* c2 = new Channel("Sport");
    Subscripter* s1 = new Subscripter("Alice");
    Subscripter* s2 = new Subscripter("Bob");
    Subscripter* s3 = new Subscripter("Ted");

    s1->sub(c1);
    s1->sub(c2);
    s2->sub(c1);
    s3->sub(c2);
    c1->notify("AAA");
    c2->notify("BBB");
    s1->unsub(c1);

    c1->notify("AAA");
    c2->notify("BBB");

    return 0;

}

