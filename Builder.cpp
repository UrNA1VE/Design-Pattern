#include<iostream>
using namespace std;

class Captain {
public:
    virtual ~Captain(){};
    virtual void SendSoldiers() const = 0;
    virtual void SendTanks() const = 0;
    virtual void SendAirplanes() const = 0;
    virtual void SendShips() const = 0;
};

class CaptainA: public Captain {
public:
    void SendSoldiers() const override{
        cout<<"Send 100 soldiers!"<<endl;
    };

    void SendTanks() const override{
        cout<<"Send 100 tanks!"<<endl;
    };

    void SendAirplanes() const override{
        cout<<"Send 100 airplanes!"<<endl;
    };

    void SendShips() const override{
        cout<<"Send 100 ships"<<endl;
    };
};

class CaptainB: public Captain {
public:
    void SendSoldiers() const override{
        cout<<"Send 50 soldiers!"<<endl;
    };

    void SendTanks() const override{
        cout<<"Send 50 tanks!"<<endl;
    };

    void SendAirplanes() const override{
        cout<<"Send 50 airplanes!"<<endl;
    };

    void SendShips() const override{
        cout<<"Send 50 ships"<<endl;
    };
};

class Commander {
public:
    void ChooseCaptain(Captain* c) {
        captain = c;
    };

    void LandBattle() {
        captain->SendSoldiers();
        captain->SendTanks();
        captain->SendAirplanes();
    };

    void NavalBattle() {
        captain->SendShips();
        captain->SendAirplanes();
    };

    void AirBattle() {
        captain->SendAirplanes();
    }

private:
    Captain* captain;
};

int main() {
    Commander* commander = new Commander();
    Captain* A = new CaptainA();
    Captain* B = new CaptainB();
    commander->ChooseCaptain(A);
    commander->AirBattle();
    commander->LandBattle();
    commander->NavalBattle();
    delete A;


    commander->ChooseCaptain(B);
    commander->AirBattle();
    commander->LandBattle();
    commander->NavalBattle();
    delete B;
    delete commander;
    return 0;
}