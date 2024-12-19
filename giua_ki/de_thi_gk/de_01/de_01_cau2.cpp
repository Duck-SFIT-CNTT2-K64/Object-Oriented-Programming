#include <bits/stdc++.h>

using namespace std;

class ThiSinh{
    string hoten;
    float toan, ly, hoa;
public:
    ThiSinh() : hoten(" "), toan(0.0), ly(0.0), hoa(0.0){}

    ThiSinh(string hoten, float toan, float ly, float hoa){
        this->hoten = hoten;
        this->toan = toan;
        this->ly = ly;
        this->hoa = hoa;
    }

    void nhapTS(){
        cout << "Nhap ho va ten cua thi sinh: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhap diem toan: ";
        cin >> toan;
        cout << "Nhap diem ly: ";
        cin >> ly;
        cout << "Nhap diem hoa: ";
        cin >> hoa;
    }

    void xuatTS(){
        cout << endl;
        cout << "+--------------------+------------------------+" << endl;
        cout << "|      Thuoc tinh    |        Gia Tri         |" << endl;
        cout << "+--------------------+------------------------+" << endl;
        cout << "| Ho ten      | " << setw(20) << hoten <<"          |" << endl;
        cout << "| Toan        | " << setw(20) << toan << "          |" << endl;
        cout << "| Ly          | " << setw(20) << ly << "          |" << endl;
        cout << "| Hoa         | " << setw(20) << hoa << "          |" << endl;
    }

    string get_hoten() const{
        return this->hoten;
    }
    float get_toan(){
        return this->toan;
    }
    float get_ly(){
        return this->ly;
    }
    float get_hoa(){
        return this->hoa;
    }
};

class Uutien : public ThiSinh{
    int loai;
public:
    Uutien() : ThiSinh() {
        this->loai = loai;
    }
    void nhap(){
        ThiSinh::nhapTS();
        cout << "Nhap loai uu tien: ";
        cin >> loai;
    }

    void xuat(){
        ThiSinh::xuatTS();
        cout << "| Loai        | " << setw(20) << loai << "          |" << endl;
        cout << "+--------------------+------------------------+" << endl;
    }

    int get_loai(){
        return this->loai;
    }
};

int main(){
    int n; cout << "Nhap so luong sinh vien: "; cin >> n;
    Uutien *ts = new Uutien[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin sinh vien thu: " << i + 1 << endl;
        ts[i].nhap();
    }
    float sum[n] = {0}, s_toan[n], s_ly[n], s_hoa[n], s_loai[n];
    for(int i = 0; i < n; i++){
        s_toan[i] = ts[i].get_toan();
        s_ly[i] = ts[i].get_ly();
        s_hoa[i] = ts[i].get_hoa();
        s_loai[i] = ts[i].get_loai() == 1 ? 1.5 : ts[i].get_loai() == 2 ? 1 : 0.5;
        sum[i] = s_toan[i] + s_ly[i] + s_hoa[i] + s_loai[i];
    }
    float diemchuan; cout << "Nhap diem chuan: "; cin >> diemchuan;
    int check = 0, dsach[n] = {0};
    for(int i = 0; i < n; i++){
        if(sum[i] >= diemchuan && s_toan[i] != 0 && s_ly[i] != 0 && s_hoa[i] != 0){
            dsach[i] = 1;
            check = 1;
        }
    }
    if(check){
        cout << "Danh sach trung tuyen la: ";
        for(int i = 0; i < n; i++){
            if(dsach[i] == 1){
                ts[i].xuat();
            }
        } 
    }
    else{
        cout << "Khong co sinh vien nao trung tuyen";
    }
    int dem[3] = {0};
    for(int i = 0; i < n; i++){
        if(ts[i].get_loai() == 1) dem[0]++;
        if(ts[i].get_loai() == 2) dem[1]++;
        if(ts[i].get_loai() == 3) dem[2]++;
    }
    if(dem[0] != 0) cout << "So luong thi sinh cua loai 1 la: " << dem[0] << endl;
    else cout << "Khong co sinh vien nao loai 1" << endl;
    if(dem[1] != 0) cout << "So luong thi sinh cua loai 2 la: " << dem[1] << endl;
    else cout << "Khong co sinh vien nao loai 2" << endl;
    if(dem[2] != 0) cout << "So luong thi sinh cua loai 3 la: " << dem[2] << endl;
    else cout << "Khong co sinh vien nao loai 3" << endl;
}