#include <bits/stdc++.h>

using namespace std;

class Diem{
    private:
        float hd, td;
    public:
        Diem(){}
        Diem(float hd, float td){
            this->hd = hd;
            this->td = td;
        }
        void nhap(){
            cout << "Nhap hoanh do: "; cin >> hd;
            cout << "Nhap tung do: "; cin >> td;
        }
        void xuat(){
            cout << "( " << hd << " , " << td << " )" << " ; ";
        }
        float kc1(){
            return sqrt(pow(hd, 2) + pow(td, 2));
        }
        float kc2(const Diem &d){
            return sqrt(pow(hd - d.hd, 2) + pow(td - d.td, 2));
        }
        friend float kc3(Diem d1, Diem d2){
            return sqrt(pow(d1.hd - d2.hd, 2) + pow(d1.td - d2.td, 2));
        }
};

int main(){
    Diem x1, x2;
    x1.nhap(); x2.nhap();
    x1.xuat(); x2.xuat();
    float kc1 = x1.kc1();
    cout << "\nKhoang cach tu diem den goc toa do la: " << kc1 << endl;
    float kc2 = x1.kc2(x2);
    cout << "Khoang cach giua 2 diem la: " << kc2 << endl;
    float kc4 = kc3(x1, x2);
    cout << "Khoang cach dung friend function: " << kc4 << endl;
}