#include <bits/stdc++.h>

using namespace std;

class PS{
private:
    float ts, ms;
public:
    PS(){}
    PS(float ts, float ms){
        this->ts = ts;
        this->ms = ms;
    }
    void nhap(){
        cout << "Nhap ts: "; cin >> ts;
        cout << "Nhap ms: "; cin >> ms;
    }
    void xuat(){
        cout << ts << "/" << ms << endl;
    }
    PS nhan(PS b){
        PS t;
        t.ts = ts * b.ts;
        t.ms = ms * b.ms;
        return t;   
    }
    ~PS(){}
};

int main(){
    PS a, b, c;
    a.nhap();
    b.nhap();
    a.xuat();
    b.xuat();
    c = a.nhan(b);
    c.xuat();
}