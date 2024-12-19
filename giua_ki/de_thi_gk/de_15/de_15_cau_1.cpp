#include <bits/stdc++.h>

using namespace std;

class Dathuc{
    int bac;
    float* heso;
public:
    Dathuc() : bac(0), heso(nullptr) {}

    Dathuc(int bac, float* heso){
        this->bac = bac;
        heso = new float[bac + 1];
        for(int i = 0; i <= bac; i++){
            this->heso[i] = heso[i];
        }
    }

    ~Dathuc(){
        delete[] heso;
    }

    void nhap(){
        cout << "Nhap bac cua da thuc: "; cin >> bac;
        heso = new float[bac + 1];
        for(int i = 0; i <= bac; i++){
            cout << "Nhap he so thu " << i + 1 << ": ";
            cin >> heso[i];
        }
    }

    friend ostream& operator<<(ostream& os, Dathuc& other){
        os << "Da thuc vua nhap la: ";
        for (int i = 0; i <= other.bac; i++) {
            if(i == 0){
                os << other.heso[i];
            }
            else if(i > 0 && other.heso[i] > 0){
                cout << "+" << other.heso[i] << "x^" << i;
            }
            else if(i > 0 && other.heso[i] < 0){
                cout << other.heso[i] << "x^" << i;
            }
        }
        return os;
    }

    friend float tinh(Dathuc& a, float x){
        float sum = 0;
        for(int i = 0; i <= a.bac; i++){
            sum += a.heso[i] * pow(x, i);
        }
        return sum;
    }
};

int main(){
    Dathuc dt;
    dt.nhap();
    cout << dt;
    float d1, d2; cout << "\nNhap d1: "; cin >> d1; cout << "Nhap d2: "; cin >> d2;
    cout << "Gia tri cua bieu thuc: " << tinh(dt, d1) + tinh(dt, d2) << endl;
    return 0;
}