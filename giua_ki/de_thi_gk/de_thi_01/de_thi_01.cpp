#include <bits/stdc++.h>

using namespace std;

class Diem{
    float td, hd;
public:
    Diem() : td(0.0), hd(0.0) {}

    friend istream& operator>>(istream& is, Diem& other){
        cout << "Nhap hoanh do: "; is >> other.hd;
        cout << "Nhap tung do: "; is >> other.td;
        return is;
    }

    friend ostream& operator<<(ostream& os, Diem& other){
        os << "Hoanh do: " << other.hd << endl;
        os << "Tung do: " << other.td << endl;
        return os;
    }
    friend double kc(Diem& other1, Diem& other2){
        return sqrt(pow(other2.hd - other1.hd, 2) + pow(other2.td - other1.td, 2));
    }
    
};

int main(){
    Diem a, b, c;
    cin >> a;
    kc(a, b);
}