#include <bits/stdc++.h>

using namespace std;

class DaThuc{
    float x;
    int n;
    float *arr;
public:
    DaThuc() : n(0), arr(nullptr) {}

    DaThuc(const DaThuc& other){
        this->n = other.n;
        this->arr = new float[n + 1];
        for(int i = 0; i <= n; i++){
            arr[i] = other.arr[i];
        }
    }

    DaThuc(int degree) : n(degree) {
        arr = new float[n + 1];
        for(int i = 0; i <= n; i++) {
            arr[i] = 0;
        }
    }

    ~DaThuc(){delete[] arr;}

    void nhap(){
        cout << "Nhap da thuc bac: "; cin >> n;
        delete[] arr;
        arr = new float[n + 1];
        for(int i = 0; i <= n; i++){
            cout << "Nhap he so x^" << i << ": ";
            cin >> arr[i];
        }
        cout << "Nhap 1 so thuc x: "; cin >> x;
    }

    void xuat(){
        cout << "P(x): ";
        for(int i = 0; i <= n; i++){
            if(i == 0){
                if(arr[i] >= 0){
                    cout << arr[i];
                }
                else{
                    cout << arr[i];
                }
            }
            else{
                if(arr[i] >= 0){
                    cout << " + " << arr[i] << "x^" << i;
                }
                else{
                    cout << " " << arr[i] << "x^" << i;
                }
            }
        }
    }

    void tinh(){
        float sum[2];
        for(int i = 0; i <= n; i++){
            sum[0] += arr[i] * pow(x, i);
        }
        for(int i = 1; i <= n; i++){
            sum[1] += arr[i] * i * pow(x, i - 1);
        }
        cout << "\nGia tri cua da thuc: " << sum[0] << endl;
        cout << "Gia tri dao ham cua da thuc: " << sum[1] << endl;
    }
};

int main(){
    DaThuc a;
    a.nhap();
    a.xuat();
    a.tinh();
}