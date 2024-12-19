#include <bits/stdc++.h>
using namespace std;

class DaThuc {
    int bac;
    float* arr;

public:
    // Constructor mặc định
    DaThuc() : bac(0), arr(nullptr) {}

    // Constructor với tham số
    DaThuc(int bac, float* arr) {
        this->bac = bac;
        this->arr = new float[bac + 1];
        for (int i = 0; i <= bac; i++) {
            this->arr[i] = arr[i];
        }
    }

    // Constructor sao chép
    DaThuc(const DaThuc& other) {
        this->bac = other.bac;
        this->arr = new float[bac + 1];
        for (int i = 0; i <= bac; i++) {
            this->arr[i] = other.arr[i];
        }
    }

    // Toán tử gán
    // DaThuc& operator=(const DaThuc& other) {
    //     if (this == &other) return *this; // Tránh tự gán
    //     delete[] arr; // Xóa mảng cũ
    //     this->bac = other.bac;
    //     this->arr = new float[bac + 1];
    //     for (int i = 0; i <= bac; i++) {
    //         this->arr[i] = other.arr[i];
    //     }
    //     return *this;
    // }

    // Destructor
    ~DaThuc() {
        delete[] arr;
    }

    // Nhập đa thức
    void nhap() {
        cout << "Nhap bac cua da thuc: ";
        cin >> bac;
        arr = new float[bac + 1];
        for (int i = 0; i <= bac; i++) {
            cout << "Nhap he so thu " << i << ": ";
            cin >> arr[i];
        }
    }

    // Toán tử xuất
    friend ostream& operator<<(ostream& os, const DaThuc& other) {
        os << "Da thuc vua nhap la: ";
        for (int i = 0; i <= other.bac; i++) {
            if (other.arr[i] != 0) {
                if (i > 0 && other.arr[i] > 0) os << "+";
                os << other.arr[i];
                if (i > 0) os << "x^" << i;
            }
        }
        return os;
    }

    // Tính đạo hàm tại x
    friend float tinh(const DaThuc& a, float x) {
        float sum = 0;
        for (int i = 1; i <= a.bac; i++) {
            float term = a.arr[i] * i * pow(x, i - 1);
            sum += term;
        }
        return sum;
    }
};

int main() {
    DaThuc a;
    a.nhap();
    cout << a;
    float d1, d2;
    cout << "\nNhap d1: ";
    cin >> d1;
    cout << "Nhap d2: ";
    cin >> d2;
    cout << "Ket qua: " << sqrt(tinh(a, d1) + tinh(a, d2));
    return 0;
}
