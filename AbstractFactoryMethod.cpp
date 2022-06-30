#include<iostream>
using namespace std;

class Armor {
public:
    virtual ~Armor() {};
    virtual void Defend() const = 0; 
    virtual void Clean() const = 0;

};

class Knife {
public:
    virtual ~Knife() {};
    virtual void Stab() const = 0;
    virtual void Polish() const = 0;
};

class ironArmor: public Armor {
public:
    void Defend() const override{
        cout<<"Iron armor defending!"<<endl;
    };

    void Clean() const override{
        cout<<"Cleaning iron armor!"<<endl;
    };
};

class woodArmor: public Armor {
public:
    void Defend() const override{
        cout<<"Wood armor defending!"<<endl;
    };

    void Clean() const override{
        cout<<"Cleaning wood armor!"<<endl;
    };
};

class ironKnife: public Knife {
public:
    void Stab() const override{
        cout<<"Iron knife stabing!"<<endl;
    };

    void Polish() const override{
        cout<<"Polishing iron knife!"<<endl;
    };
};

class woodKnife: public Knife {
public:
    void Stab() const override{
        cout<<"wood knife stabing!"<<endl;
    };

    void Polish() const override{
        cout<<"Polishing wood knife!"<<endl;
    };
};

class Creator {
public:
    virtual ~Creator() {};
    virtual Knife* createKnife() = 0;
    virtual Armor* createArmor() = 0;
    virtual string name() const = 0;

};

class woodCreator: public Creator {
public:
    Knife* createKnife() override {
        Knife* knife = new woodKnife();
        return knife;
    }
    
    Armor* createArmor() override {
        Armor* armor = new woodArmor();
        return armor;
    }

    string name() const override {
        return "Wood Factory";
    }

};

class ironCreator: public Creator {
public:
    Knife* createKnife() override {
        Knife* knife = new ironKnife();
        return knife;
    }
    
    Armor* createArmor() override {
        Armor* armor = new ironArmor();
        return armor;
    }

    string name() const override {
        return "Iron Factory";
    }

};

void look(Creator* creator) {
    cout<<"look! it's a "<<creator->name()<<endl;
}

int main() {
    Creator* A = new woodCreator();
    Knife* knife1 = A->createKnife();
    Armor* armor1 = A->createArmor();
    knife1->Stab();
    knife1->Polish();
    armor1->Clean();
    armor1->Defend();
    look(A);
    Creator* B = new ironCreator();
    Knife* knife2 = B->createKnife();
    Armor* armor2 = B->createArmor();
    knife2->Stab();
    knife2->Polish();
    armor2->Clean();
    armor2->Defend();
    look(B);

    delete A;
    delete B;

    return 0;
}