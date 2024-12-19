#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MonHoc {
private:
    string maMon;
    string tenMon;
    int soTinChi;

public:
    MonHoc() : maMon(""), tenMon(""), soTinChi(0) {}
    MonHoc(string maMon, string tenMon, int soTinChi) : maMon(maMon), tenMon(tenMon), soTinChi(soTinChi) {}
    void nhap() {
        cout << "Nhap ma mon: ";
        cin >> maMon;
        cout << "Nhap ten mon: ";
        cin.ignore();
        getline(cin, tenMon);
        cout << "Nhap so tin chi: ";
        cin >> soTinChi;
    }
    void xuat() const {
        cout << "Ma mon: " << maMon << ", Ten mon: " << tenMon << ", So tin chi: " << soTinChi << endl;
    }
    string getMaMon() const { return maMon; }
    string getTenMon() const { return tenMon; }
    int getSoTinChi() const { return soTinChi; }
};
class DKHP {
private:
    string maSV;
    string tenSV;
    vector<MonHoc> danhSachMonHoc;

public:
    DKHP() : maSV(""), tenSV("") {}
    DKHP(string maSV, string tenSV) : maSV(maSV), tenSV(tenSV) {}

    void nhap(vector<MonHoc>& danhSachMon) {
        cout << "Nhap ma sinh vien: ";
        cin >> maSV;
        cout << "Nhap ten sinh vien: ";
        cin.ignore();
        getline(cin, tenSV);

        int soMon;
        cout << "Nhap so mon hoc da dang ky: ";
        cin >> soMon;

        for (int i = 0; i < soMon; i++) {
            string maMon;
            cout << "Nhap ma mon hoc thu " << i + 1 << ": ";
            cin >> maMon;

            bool found = false;
            for (auto& mon : danhSachMon) {
                if (mon.getMaMon() == maMon) {
                    danhSachMonHoc.push_back(mon);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Ma mon hoc khong ton tai!" << endl;
            }
        }
    }
    void xuat() const {
        cout << "Ma sinh vien: " << maSV << ", Ten sinh vien: " << tenSV << endl;
        cout << "Danh sach mon hoc da dang ky:" << endl;
        for (const auto& mon : danhSachMonHoc) {
            mon.xuat();
        }
    }
    int tongSoTinChi() const {
        int total = 0;
        for (const auto& mon : danhSachMonHoc) {
            total += mon.getSoTinChi();
        }
        return total;
    }

    string getMaSV() const { return maSV; }

    bool daDangKyMonHoc(const string& maMon) const {
        for (const auto& mon : danhSachMonHoc) {
            if (mon.getMaMon() == maMon) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<MonHoc> danhSachMon;
    vector<DKHP> danhSachDKHP;

    int soMon;
    cout << "Nhap so luong mon hoc: ";
    cin >> soMon;

    for (int i = 0; i < soMon; i++) {
        MonHoc mon;
        mon.nhap();
        danhSachMon.push_back(mon);
    }

    int soSV;
    cout << "Nhap so luong sinh vien: ";
    cin >> soSV;

    for (int i = 0; i < soSV; i++) {
        DKHP dkhp;
        dkhp.nhap(danhSachMon);
        danhSachDKHP.push_back(dkhp);
    }

    for (const auto& dkhp : danhSachDKHP) {
        dkhp.xuat();
        cout << "Tong so tin chi: " << dkhp.tongSoTinChi() << endl;
    }

    string maMonCanTim;
    cout << "Nhap ma mon hoc can tim: ";
    cin >> maMonCanTim;

    int count = 0;
    for (const auto& dkhp : danhSachDKHP) {
        if (dkhp.daDangKyMonHoc(maMonCanTim)) {
            count++;
        }
    }

    cout << "So sinh vien da dang ky mon hoc " << maMonCanTim << ": " << count << endl;

    return 0;
}