#include <bits/stdc++.h>

using namespace std;

class DT{
private:
    float hd, td;
public:
    DT(){}
    DT(float hd1, float td1){
        this->hd = hd1;
        this->td = td1;
    }
    DT(const DT& T1){
        hd = T1.hd;
        td = T1.td;
    }
    float kc1(){
        return sqrt(pow(hd, 2) + pow(td, 2));
    }
    bool operator==(const DT& other){
        if(this->hd == other.hd && this->td == other.td) return 1;
        else return 0;
    }
    DT operator*(DT& other){
        DT tmp;
        tmp.hd = this->hd * other.hd;
        tmp.td = this->td * other.td;
        return tmp;
    }
    friend ostream& operator<<(ostream& os, DT& tmp){
        os << "(" << tmp.hd << ";" << tmp.td << ")";
        return os;
    }
    friend istream& operator>>(istream& is, DT& tmp){
        is >> tmp.hd >> tmp.td;
        return is;
    }
    ~DT(){}
};

int main(){
    DT x, y;
    cin >> x >> y;
    cout << x << endl << y;
    cout << "\nKhoang cach cua diem x la: " << x.kc1() << endl;
    if(x == y) cout << "2 diem x va y bang nhau" << endl;
    else cout << "2 diem x va y khong bang nhau" << endl;
    DT tmp = x * y;
    cout << "x * y = " << tmp;
    return 0;
}