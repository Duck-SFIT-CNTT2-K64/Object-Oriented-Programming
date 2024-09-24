#include<bits/stdc++.h>

using namespace std;

class Dathuc{
    int n;
    float *arr;
public:
    Dathuc () : n(0), arr(nullptr){}

    ~Dathuc(){ delete[] arr; }

    Dathuc(const Dathuc& other){
        n = other.n;
        arr = new float[n + 1];
        for(int i = 0; i <= n; i++){
            arr[i] = other.arr[i];
        }
    }
    Dathuc& operator=(const Dathuc& other){
        if(this != &other){
            delete[] arr;
            n = other.n;
            arr = new float[n + 1];
            for(int i = 0; i <= n; i++){
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    Dathuc operator+(const Dathuc& other){
        Dathuc tmp;
        tmp.n = max(this->n, other.n);
        tmp.arr = new float[tmp.n + 1];
        for(int i = 0; i <= tmp.n; i++){
            tmp.arr[i] = 0;
        }
        for(int i = 0; i <= this->n; i++){
            tmp.arr[i] += this->arr[i];
        }
        for(int i = 0; i <= other.n; i++){
            tmp.arr[i] += other.arr[i];
        }
        return tmp;
    }
    friend ostream& operator<<(ostream& os, Dathuc& other){
        os << other.arr[0];
        for(int i = 1; i <= other.n; i++){
            if(other.arr[i] >= 0){
                os << "+" << other.arr[i] << "x^" << i;
            }
            else{
                os << other.arr[i] << "x^" << i;
            }
        }
        return os;
    }
    friend istream& operator>>(istream& is, Dathuc& other){
        delete[] other.arr;
        is >> other.n;
        other.arr = new float[other.n + 1];
        for(int i = 0; i <= other.n; i++){
            is >> other.arr[i];
        }
        return is;
    }
};

int main(){
    Dathuc a, b;
    cout << "Nhap da thuc a: ";
    cin >> a;
    cout << "Nhap da thuc b: ";
    cin >> b;
    cout << "Da thuc a: " << a << endl;
    cout << "Da thuc b: " << b << endl;
    Dathuc c = a;
    cout << "Da thuc c sau khi sao chep la: " << c << endl;
    Dathuc d = a + b;
    cout << "a + b = " << d << endl;
}