#include <bits/stdc++.h>

using namespace std;

class Hang{
    string mahang, tenhang;
    int soluong;
    float dongia;
public:
    Hang() : mahang(" "), tenhang(" "), soluong(0), dongia(0.0) {}
    
    void nhap(){
        cout << "Nhap ma hang: ";
        cin.ignore();
        getline(cin, mahang);
        cout << "Nhap ten hang: ";
        getline(cin, tenhang);
        cout << "Nhap so luong: "; cin >> soluong;
        cout << "Nhap don gia: "; cin >> dongia;
        cout << endl;
    }

    void xuat(){
        cout << endl;
        cout << "Ma hang: " << mahang << endl;
        cout << "Ten hang: " << tenhang << endl;
        cout << "So luong: " << soluong << endl;
        cout << "Don gia: " << dongia << endl;
    }
};

int main(){
    int n; cout << "Nhap so luong may giat: "; cin >> n;
    Hang *h = new Hang[n];
    for(int i = 0; i < n; i++){
        h[i].nhap();
    }
    for(int i = 0; i < n; i++){
        h[i].xuat();
    }
}