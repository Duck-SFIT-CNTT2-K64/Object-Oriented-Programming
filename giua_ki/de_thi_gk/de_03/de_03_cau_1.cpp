#include <bits/stdc++.h>

using namespace std;

class DS_nguyen{
    int n;
    int *arr;
public:
    DS_nguyen() : n(0), arr(nullptr) {}
    DS_nguyen(int n) : n(n){
        arr = new int[n];
    }
    ~DS_nguyen(){
        delete[] arr;
    }
    friend istream& operator>>(istream& is, DS_nguyen &other){
        cout << "Nhap so phan tu: "; is >> other.n;
        other.arr = new int[other.n + 1];
        for(int i = 0; i < other.n; i++){
            cout << "Nhap phan tu thu " << i + 1 << ": ";
            is >> other.arr[i];
        }
        return is;
    }
    int get_n(){
        return n;
    }
    int get_arr(int i){
        return arr[i];
    }
};

int main(){
    DS_nguyen a;
    cin >> a;
    float tong = 0, dem = 0;
    for(int i = 0; i < a.get_n(); i++){
        if(a.get_arr(i) > 0){
            tong += a.get_arr(i);
            dem++;
        }
    }
    if(dem == 0){
        cout << "Khong co so duong nao trong day so" << endl;
    }
    else{
        cout << "Trung binh cong cac so duong: " << tong / dem << endl;
    }
    // so chinh phuong
    cout << "So chinh phuong trong day so: ";
    for(int i = 0; i < a.get_n(); i++){
        if(sqrt(a.get_arr(i)) == (int)sqrt(a.get_arr(i))){
            cout << a.get_arr(i) << " ";
        }
    }
    cout << endl;
    return 0;
}