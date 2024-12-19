#include <bits/stdc++.h>

using namespace std;

class Hinhtron{
    float bk;
public:
    Hinhtron() : bk(0.0) {}

    void nhap(){
        cin >> bk;
    }

    void xuat(){
        cout << bk << endl;
    }

    float tinh(float bk){
        return 3.14 * pow(bk, 2);
    }

    float get_bk() const{
        return bk;
    }
};

int main(){
    int n; cout << "Nhap so luong hinh tron: "; cin >> n;
    Hinhtron *ht = new Hinhtron[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap ban kinh cho hinh tron thu " << i + 1 << ": ";
        ht[i].nhap();
    }
    float T = 0, dem = 0, S = ht[0].get_bk();
    for(int i = 0; i < n; i++){
        T += ht[i].get_bk();
        dem++;
    }
    if(dem == 0) cout << "Khong co dien tich trung binh cua cac hinh tron tren" << endl;
    else cout << "Dien tich trung binh cua cac hinh tron tren la: " << fixed << setprecision(3) << T/dem << endl;
    for(int i = 0; i < n; i++){
        if(ht[i].get_bk() > S){
            S = ht[i].get_bk();
        }
    }
    cout << "Nhung hinh tron co dien tich lon nhat: " << endl;
    for(int i = 0; i < n; i++){
        if(S == ht[i].get_bk()){
            cout << "Ban kinh hinh tron thu " << i + 1 << ": ";
            ht[i].xuat();
        }
    }
    return 0;
}