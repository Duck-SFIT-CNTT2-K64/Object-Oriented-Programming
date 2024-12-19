#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CTY {
protected:
    string ten;
    int ntl;
public:
    CTY() : ten(""), ntl(0) {}
    CTY(string ten, int ntl) : ten(ten), ntl(ntl) {}
    virtual void nhap() {
        cout << "Ten cong ty: ";
        cin.ignore();
        getline(cin, ten);
        cout << "Nam thanh lap: ";
        cin >> ntl;
    }
    virtual void xuat() const {
        cout << "Ten cong ty: " << ten << endl;
        cout << "Nam thanh lap: " << ntl << endl;
    }
    string getTen() const { return ten; }
    int getNtl() const { return ntl; }
};

class CTYPM : public CTY {
    int sltv;
public:
    CTYPM() : sltv(0) {}
    CTYPM(string ten, int ntl, int sltv) : CTY(ten, ntl), sltv(sltv) {}
    void nhap() override {
        CTY::nhap();
        cout << "So lap trinh vien: ";
        cin >> sltv;
    }
    void xuat() const override {
        CTY::xuat();
        cout << "So lap trinh vien: " << sltv << endl;
    }
    int getSltv() const { return sltv; }
};

class CTYVT : public CTY {
    int soto;
public:
    CTYVT() : soto(0) {}
    CTYVT(string ten, int ntl, int soto) : CTY(ten, ntl), soto(soto) {}
    void nhap() override {
        CTY::nhap();
        cout << "So o to: ";
        cin >> soto;
    }
    void xuat() const override {
        CTY::xuat();
        cout << "So o to: " << soto << endl;
    }
    int getSoto() const { return soto; }
};

int main() {
    int n, m;
    cout << "Nhap so cong ty phan mem: ";
    cin >> n;
    cout << "Nhap so cong ty van tai: ";
    cin >> m;

    vector<CTYPM> dsPM(n);
    vector<CTYVT> dsVT(m);

    cout << "\nNhap thong tin cong ty phan mem:\n";
    for (int i = 0; i < n; i++) {
        cout << "Cong ty " << i+1 << ":\n";
        dsPM[i].nhap();
    }

    cout << "\nNhap thong tin cong ty van tai:\n";
    for (int i = 0; i < m; i++) {
        cout << "Cong ty " << i+1 << ":\n";
        dsVT[i].nhap();
    }

    cout << "\nCac cong ty phan mem thanh lap sau nam 2000 va co tren 20 lap trinh vien:\n";
    for (const auto& cty : dsPM) {
        if (cty.getNtl() > 2000 && cty.getSltv() > 20) {
            cty.xuat();
        }
    }

    cout << "\nCac cong ty van tai thanh lap truoc nam 2000 va co khong qua 10 o to:\n";
    for (const auto& cty : dsVT) {
        if (cty.getNtl() < 2000 && cty.getSoto() <= 10) {
            cty.xuat();
        }
    }

    return 0;
}