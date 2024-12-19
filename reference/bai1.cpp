#include <bits/stdc++.h>
using namespace std;

class PS{
private:
    int ts, ms;
public:
    PS() : ts(0), ms(1){}
    ~PS(){}
    PS operator+(const PS& other) const {
        PS result;
        result.ts = this->ts * other.ms + other.ts * this->ms;
        result.ms = this->ms * other.ms;
        return result;
    }

    void nhap(){
        cout << "Nhap tu so: "; cin >> ts;
        cout << "Nhap mau so: "; cin >> ms;
    }

    void xuat(){
        cout << ts << "/" << ms << endl;
    }
};
int main(){
    PS x1, x2, x3;
    x1.nhap();
    x2.nhap();
    x3 = x1 + x2;
    x3.xuat();
}