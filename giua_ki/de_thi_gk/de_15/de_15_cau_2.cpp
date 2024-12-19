#include <bits/stdc++.h>
using namespace std;

class Mat_hang {
    string mahang;
    float dongia;

public:
    Mat_hang() : mahang(""), dongia(0.0) {}

    void nhap_hang() {
        cin.ignore();
        cout << "Nhap ma hang: ";
        getline(cin, mahang);
        cout << "Nhap don gia: ";
        cin >> dongia;
    }

    string get_mahang() const {
        return mahang;
    }

    float get_dongia() const {
        return dongia;
    }
};

class Hoa_don {
    string mahang, ngayban;
    int soluong;

public:
    Hoa_don() : mahang(""), ngayban(""), soluong(0) {}

    void nhap_hoa_don() {
        cin.ignore();
        cout << "Nhap ma hang cua hoa don: ";
        getline(cin, mahang);
        cout << "Nhap ngay ban cua hoa don: ";
        getline(cin, ngayban);
        cout << "Nhap so luong cho hoa don: ";
        cin >> soluong;
    }

    string get_mahang() const {
        return mahang;
    }

    string get_ngayban() const {
        return ngayban;
    }

    int get_soluong() const {
        return soluong;
    }
};

float tim_dongia(const vector<Mat_hang> &mh, string mahang) {
    for (const auto &item : mh) {
        if (item.get_mahang() == mahang) {
            return item.get_dongia();
        }
    }
    return 0;
}

int main() {
    int m;
    cout << "Nhap so mat hang: ";
    cin >> m;
    vector<Mat_hang> mh(m);
    for (int i = 0; i < m; i++) {
        mh[i].nhap_hang();
    }

    int n;
    cout << "Nhap so hoa don: ";
    cin >> n;
    vector<Hoa_don> hd(n);
    for (int i = 0; i < n; i++) {
        hd[i].nhap_hoa_don();
    }

    string nhap_ngay;
    cout << "Nhap ngay can tinh: ";
    cin.ignore();
    getline(cin, nhap_ngay);

    float res = 0;
    bool check = false;

    for (int i = 0; i < n; i++) {
        if (hd[i].get_ngayban() == nhap_ngay) {
            float dongia = tim_dongia(mh, hd[i].get_mahang());
            if (dongia > 0) {
                res += hd[i].get_soluong() * dongia;
                check = true;
            } else {
                cout << "Khong tim thay ma hang: " << hd[i].get_mahang() << endl;
            }
        }
    }

    if (!check)
        cout << "Khong co don hang can tinh" << endl;
    else
        cout << "So tien ban duoc: " << res << endl;

    return 0;
}
