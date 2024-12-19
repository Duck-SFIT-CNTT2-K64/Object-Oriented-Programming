#include <bits/stdc++.h>

using namespace std;

class Monhoc{
    int ma, sotin;
    string ten;
public:
    Monhoc() : ma(0), sotin(0), ten(" ") {}
    Monhoc(int ma, int sotin, string ten){
        this->ma = ma;
        this->sotin = sotin;
        this->ten = ten;
    }

    void nhap(){
        cout << "Nhap ma mon hoc: ";
        cin >> ma;
        cout << "Nhap ten cua mon hoc: ";
        getline(cin, ten);
        cout << "Nhap so tin chi: ";
        cin >> sotin;
    }

    void xuat(){
        cout << "Ma mon hoc: " << ma << endl;
        cout << "Ten mon hoc: " << ten << endl;
        cout << "So tin chi: " << sotin << endl;
    }
    int get_ma(){
        return ma;
    }    
    int get_sotin(){
        return sotin;
    }
    string get_ten(){
        return ten;
    }
};

class DKHP{
    int masv;
    string tensv;
    Monhoc *arr;
public:
    DKHP() : masv(0), tensv(" "), arr(nullptr) {}
    DKHP(int masv, string tensv, Monhoc *arr){
        this->masv = masv;
        this->tensv = tensv;
        this->arr = arr;
    }

    void nhap(){
        cout << "Nhap ma sinh vien: ";
        cin >> masv;
        cout << "Nhap ten sinh vien: ";
        getline(cin, tensv);
        cout << "Nhap thong tin mon hoc: " << endl;
        for(int i = 0; i < 3; i++){
            arr[i].nhap();
        }
    }

    void xuat(){
        cout << "Ma sinh vien: " << masv << endl;
        cout << "Ten sinh vien: " << tensv << endl;
        cout << "Thong tin mon hoc: " << endl;
        for(int i = 0; i < 3; i++){
            arr[i].xuat();
        }
    }
};

int main(){
    int n; cout << "Nhap ban DKHP: "; cin >> n;
    int m; cout << "Nhap so mon hoc: "; cin >> m;
    DKHP *a = new DKHP[n];
    for(int i = 0; i < n; i++){
        a[i].nhap();
    }
    for(int i = 0; i < n; i++){
        a[i].xuat();
    }
}