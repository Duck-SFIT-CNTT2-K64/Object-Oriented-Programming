#include <bits/stdc++.h>

using namespace std;

class QLH {
    int ma, loai, sl;
    string ten, xx;
public:
    QLH(){}
    QLH(int ma, int loai, int sl, string ten, string xx){
        this->ma = ma;
        this->loai = loai;
        this->ten = ten;
        this->xx = xx;
        this->sl = sl;
    }
    void nhap(){
        cout << "ma hang: ";
        cin >> ma;
        cout << "Ten hang: ";
        cin.ignore();
        getline(cin, ten);
        cout << "Xuat xu cua mat hang: ";
        getline(cin, xx);
        cout << "Loai hang: ";
        cin >> loai;
        cout << "So luong hang hoa: ";
        cin >> sl;
    }
    void xuat(){
        cout << "\n";
        cout << "ma: " << ma << endl;
        cout << "ten: " << ten << endl;
        cout << "xuat xu cua mat: " << xx << endl;
        cout << "loai: " << loai << endl;
        cout << "so luong: " << sl << endl;
    }
    int getHangHoa() const{
        return loai;
    }
};

class DIENTU : public QLH{
    int tgbh;
public:
    DIENTU(){}
    DIENTU(int ma, int loai, int sl, string ten, string xx, int tgbh) : QLH(ma, loai, sl, ten, xx){
        this->tgbh = tgbh;
    }
    int getThoiGian() const{
        return tgbh;
    }
    void nhap(){
        QLH::nhap();
        cout << "thoi gian bao hanh: ";
        cin >> tgbh;
    }
    void xuat(){
        QLH::xuat();
        cout << "thoi gian bao hanh la: " << tgbh << endl;
    }

};

int main(){
    int n; cout << "So luong hang can nhap la: "; cin >> n;
    DIENTU* arr = new DIENTU[n];
    for(int i = 0; i < n; i++){
        arr[i].nhap();
    }
    for(int i = 0; i < n; i++){
        arr[i].xuat();
    }
    DIENTU max = DIENTU("","", "", 0, 0, 0); 
    for(int i = 0; i < n; i++){
        if(dientu[i].getLoaiHang() == 1 && dientu[i].getTGBH()>max.getTGBH()){
            max = dientu[i];
        }
    }
    if(max.getTGBH() == 0){
        cout << "Khong co hang dien tu loai 1" << endl;
    }
    else{
        cout << "Hang dien tu loai 1 co thoi gian bao hanh lon nhat: " << endl;
        cout << endl;
        max.xuat();
    }
    delete[] arr;
}