#include<iostream>
using namespace std;

class Device {
public:
    virtual bool isEnabled() = 0;
    virtual void enable() = 0;
    virtual void disable() = 0; 
    virtual int getVolume() = 0;
    virtual void setVolume(int v) = 0;
    virtual int getChannel() = 0;
    virtual void setChannel(int c) = 0;
};

class TV: public Device {
public:
    TV() {
        accessible = false;
        volume = 0;
        channel = 0;
    }

    bool isEnabled() override {
        return accessible;
    };

    void enable() override {
        accessible = true;
    };

    void disable() override {
        accessible = false;
    }; 

    int getVolume() override {
        return volume;
    };

    void setVolume(int v) override {
        volume = v;
    };
    int getChannel() override{
        return channel;
    };
    void setChannel(int c) override {
        channel = c;
    };
private:
    bool accessible;
    int volume, channel;

};

class Remote {
public:

    void connectDevice(Device* d) {
        device = d;
        return;
    };

    void Power() {
        if (device == nullptr) {
            cout<<"please connect to a device"<<endl;
            return;
        }
        if (device->isEnabled()) {
            device->disable();
        }
        else {
            device->enable();
        }
    }

    void volumeUp() {
        if (!device->isEnabled()) {
            cout<<"Power down!"<<endl;
            return;
        };
        device->setVolume(device->getVolume() + 1);
    }

    void volumeDown() {
        if (!device->isEnabled()) {
            cout<<"Power down!"<<endl;
            return;
        };
        device->setVolume(device->getVolume() - 1);
    }

    void channelUp() {
        if (!device->isEnabled()) {
            cout<<"Power down!"<<endl;
            return;
        };
        device->setChannel(device->getChannel() + 1);
    }

    void channelDown() {
        if (!device->isEnabled()) {
            cout<<"Power down!"<<endl;
            return;
        };
        device->setChannel(device->getChannel() - 1);
    }

private:
    Device* device;
};


int main() {
    Device* tv = new TV();
    Remote* remote = new Remote();
    
    remote->connectDevice(tv);
    remote->Power();
    remote->volumeUp();
    cout<<tv->getVolume()<<endl;
    remote->volumeDown();
    cout<<tv->getVolume()<<endl;
    remote->channelUp();
    cout<<tv->getChannel()<<endl;
    remote->channelDown();
    cout<<tv->getChannel()<<endl;

}