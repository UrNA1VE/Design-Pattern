#include<iostream>
using namespace std;

class Target {
public: 
    virtual int** Matrix1(int m, int n) {
        int** ret;
        ret = new int *[10];
        for (int i = 0; i < m; i++) {
            ret[i] = new int[n];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ret[i][j] = 1;
            }
        }
        return ret;
    }
};

class Adaptee {
public:
    int* Matrix1(int m, int n) {
        int all = m * n;
        int* ret = new int[all];
        for (int i = 0; i < all; i++) {
            ret[i] = 1;
        }
        return ret;
    }   
};

class Adapter: public Target {
public:
    Adapter(Adaptee* a): adaptee(a) {};
    int** Matrix1(int m, int n) override {
        int* result = adaptee->Matrix1(m, n);
        int** ret;
        ret = new int *[10];
        for (int i = 0; i < m; i++) {
            ret[i] = &result[i*3];
        }
        return ret;
    }

private:
    Adaptee* adaptee;
};

int main() {
    Target* A = new Target();
    Adaptee* B = new Adaptee();
    Adapter* C = new Adapter(B);
    int** ret = C->Matrix1(5, 3);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }

}