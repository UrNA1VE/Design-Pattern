#include<iostream>
using namespace std;

class Weapon {
public:

    virtual ~Weapon() {};

    virtual void attack() = 0;

    virtual void defend() = 0;

    virtual void check() = 0;
    
};

class Gun: public Weapon {
public:

    Gun() {
        duration = 10;
    }

    void attack() override {
        check();
        duration--;
        cout<<"Gun Attack!"<<endl;
    }

    void defend() override {
        check();
        duration--;
        cout<<"Gun Defend!"<<endl;
    }

    void check() override {
        if (duration <= 0) delete this;
    }

private:
    int duration;
};

class RPG: public Weapon {
public:

    RPG() {
        duration = 5;
    }

    void attack() override {
        check();
        duration--;
        cout<<"RPG Attack!"<<endl;
    }

    void defend() override {
        check();
        duration--;
        cout<<"RPG Defend!"<<endl;
    }

    void check() override {
        if (duration <= 0) delete this;
    }

private:
    int duration;
};

class Creator {
public:

    virtual ~Creator() {};

    virtual Weapon* create() = 0;

    virtual void oneTime() const = 0;

    virtual string name() const = 0;

};

class GunCreator: public Creator {
public:
    Weapon* create() override {
        Weapon* gun = new Gun();
        return gun;
    }
    
    void oneTime() const override {
        Weapon* gun = new Gun();
        gun->attack();
        delete gun;
        return;
    }

    string name() const override {
        return "Gun Factory";
    }

};

class RPGCreator: public Creator {
public:
    Weapon* create() override {
        Weapon* rpg = new RPG();
        return rpg;
    }
    
    void oneTime() const override {
        Weapon* rpg = new RPG();
        rpg->attack();
        delete rpg;
        return;
    }

    string name() const override {
        return "RPG Factory";
    }

};

void look(Creator* creator) {
    cout<<"look! it's a "<<creator->name()<<endl;
}

int main() {
    Creator* A = new GunCreator();
    Weapon* gun = A->create();
    gun->attack();
    gun->defend();
    look(A);
    A->oneTime();
    Creator* B = new RPGCreator();
    Weapon* rpg = B->create();
    rpg->attack();
    rpg->defend();
    look(B);
    B->oneTime();

    Creator* C = new GunCreator();
    look(C);
    C->oneTime();

    delete A;
    delete B;
    delete C;

    return 0;
}