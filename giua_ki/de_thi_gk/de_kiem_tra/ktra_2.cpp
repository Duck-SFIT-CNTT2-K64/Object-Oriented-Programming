#include <bits/stdc++.h>

using namespace std;

class Mathang{
    string ma_hang;
    float don_gia;
public:
    Mathang() : ma_hang(""), don_gia(0) {}
    Mathang(string ma_hang, float don_gia) : ma_hang(ma_hang), don_gia(don_gia) {}
    friend istream& operator>>(istream& is, Mathang &other){
        cout << "Nhap ma hang: "; is >> other.ma_hang;
        cout << "Nhap don gia: "; is >> other.don_gia;
        return is;
    }
    friend ostream& operator<<(ostream& os, Mathang &other){
        os << "Ma hang: " << other.ma_hang << endl;
        os << "Don gia: " << other.don_gia << endl;
        return os;
    }
    float get_don_gia(){
        return don_gia;
    }
    string get_ma_hang(){
        return ma_hang;
    }
};

class HoaDon{
    string ma_hang;
    int so_luong;
    string ngay_ban;
public:
    HoaDon() : ma_hang(""), so_luong(0), ngay_ban("") {}
    HoaDon(string ma_hang, int so_luong, string ngay_ban) : ma_hang(ma_hang), so_luong(so_luong), ngay_ban(ngay_ban) {}
    friend istream& operator>>(istream& is, HoaDon &other){
        cout << "Nhap ma hang: "; is >> other.ma_hang;
        cout << "Nhap so luong: "; is >> other.so_luong;
        cout << "Nhap ngay ban: "; is >> other.ngay_ban;
        return is;
    }
    friend ostream& operator<<(ostream& os, HoaDon &other){
        os << "Ma hang: " << other.ma_hang << endl;
        os << "So luong: " << other.so_luong << endl;
        os << "Ngay ban: " << other.ngay_ban << endl;
        return os;
    }
    int get_so_luong(){
        return so_luong;
    }
    string get_ma_hang(){
        return ma_hang;
    }
    string get_ngay_ban(){
        return ngay_ban;
    }
};

int main(){
    int n, m;
    cout << "Nhap so mat hang: "; cin >> n;
    cout << "Nhap so hoa don: "; cin >> m;
    Mathang *a = new Mathang[n + 1];
    HoaDon *b = new HoaDon[m + 1];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin mat hang thu " << i + 1 << endl;
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cout << "Nhap thong tin hoa don thu " << i + 1 << endl;
        cin >> b[i];
    }
    // dem so hoa don co so luong lon hon 10
    int dem = 0;
    for(int i = 0; i < m; i++){
        if(b[i].get_so_luong() > 10){
            dem++;
        }
    }
    if(dem == 0) cout << "Khong co hoa don nao co so luong lon hon 10" << endl;
    else cout << "So hoa don co so luong lon hon 10: " << dem << endl;
    // tinh so tien ban duoc trong mot ngay cho truoc
    string ngay;
    cout << "Nhap ngay can tinh: "; cin >> ngay;
    float tong = 0;
    for(int i = 0; i < m; i++){
        if(b[i].get_ngay_ban() == ngay){
            for(int j = 0; j < n; j++){
                if(b[i].get_ma_hang() == a[j].get_ma_hang()){
                    tong += a[j].get_don_gia() * b[i].get_so_luong();
                }
            }
        }
    }
    cout << "Tong so tien ban duoc trong ngay " << ngay << " la: " << tong << endl;
    return 0;
}