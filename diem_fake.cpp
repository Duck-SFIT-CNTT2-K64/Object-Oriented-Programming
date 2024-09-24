#include <bits/stdc++.h>

using namespace std;

class Diem{
    int x, y;
public:
    Diem() : x(0), y(0) {}
    Diem(int x, int y){
        this->x = x;
        this->y = y;
    }
    double kc(Diem other){
        return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
    }
    bool operator==(Diem other){
        return (this->x == other.x && this->y == other.y);
    }
    Diem operator*(Diem other){
        Diem tmp;
        tmp.x = this->x * other.x;
        tmp.y = this->y * other.y;
        return tmp;
    }
    friend ostream& operator<<(ostream& os, Diem& other){
        os << "(" << other.x << ", " << other.y << ")";
        return os;
    }
    friend istream& operator>>(istream& is, Diem& other){
        is >> other.x >> other.y;
        return is;
    }
};

int main(){
    Diem a, b, c;
    cin >> a;
    cin >> b;
    cout << a << endl << b << endl;
    c = a * b;
    cout << c << endl;
    if(a == b) cout << "Hai diem bang nhau" << endl;
    else cout << "Hai diem khong bang nhau" << endl;
}