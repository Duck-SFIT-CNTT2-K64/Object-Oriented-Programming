#include <bits/stdc++.h>

using namespace std;

class Xe{
    string bienso;
    float trongluong;
public:
    Xe() : bienso(" "), trongluong(0.0) {}
    Xe(string bienso, float trongluong){
        this->bienso = bienso;
        this->trongluong = trongluong;
    }

    void nhap_xe(){
        cout << "Nhap bien so cho xe: ";
        cin.ignore();
        getline(cin, bienso);
        cout << "Trong luong cua xe: ";
        cin >> trongluong;
    }

    void xuat_xe(){
        cout << "Bien so: " << bienso << endl;
        cout << "Trong luong: " << trongluong << endl;
    }

    string get_bienso(){
        return bienso;
    }

    float get_trongluong(){
        return trongluong;
    }
};

class Xe_Bus : public Xe{
    int cho;
public:
    Xe_Bus() : Xe(){
        cho = 0;
    }

    void nhap_bus(){
        nhap_xe();
        cout << "Nhap so cho cho xe: "; cin >> cho;
    }

    void xuat_bus(){
        xuat_xe();
        cout << "Cho ngoi cua xe: " << cho << endl;
    }

    int get_cho(){
        return cho;
    }
};

class Xe_Tai : public Xe{
    float taitrong;
public:
    Xe_Tai() : Xe(){
        taitrong = 0.0;
    }

    void nhap_tai(){
        nhap_xe();
        cout << "Nhap tai trong cho xe: ";
        cin >> taitrong;
    }

    void xuat_tai(){
        xuat_xe();
        cout << "Tai trong cua xe: " << taitrong << endl;
    }

    float get_taitrong(){
        return taitrong;
    }
};

int main(){
    int n; cout << "Nhap so xe bus: "; cin >> n;
    Xe_Bus *xb = new Xe_Bus[n + 1];
    for(int i = 0; i < n; i++){
        xb[i].nhap_bus();
    }
    int m; cout << "Nhap so xe tai: "; cin >> m;
    Xe_Tai* xt = new Xe_Tai[m + 1];
    for(int i = 0; i < m; i++){
        xt[i].nhap_tai();
    }
    int check = 0;
    for(int i = 0; i < n; i++){
        if(xb[i].get_trongluong() > 3000){
            if(xb[i].get_cho() > 24){
                xb[i].xuat_bus();
                check = 1;
            }
        }
    }
    if(check == 0) cout << "Khong co xe bus thoa man" << endl;
    check = 0;
    for(int i = 0; i < m; i++){
        if(xt[i].get_trongluong() > 3000){
            if(xt[i].get_taitrong() <= 15000){
                xt[i].xuat_tai();
                check = 1;
            }
        }
    }
    if(check == 0) cout << "Khong co xe tai thoa man" << endl;
    string nhap_bienso; cout << "Nhap bien so can tim: ";
    cin.ignore();
    getline(cin, nhap_bienso);
    check = 0;
    for (int i = 0; i < n; i++) {  // Duyệt mảng xe bus
        if (xb[i].get_bienso() == nhap_bienso) {
            xb[i].xuat_bus();
            check = true;
        }
    }

    for (int i = 0; i < m; i++) {  // Duyệt mảng xe tải
        if (xt[i].get_bienso() == nhap_bienso) {
            xt[i].xuat_tai();
            check = true;
        }
    }
    if(check == 0) cout << "Khong co xe theo bien so duoc nhap" << endl;
}