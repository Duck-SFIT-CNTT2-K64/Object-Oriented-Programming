#include<bits/stdc++.h>

using namespace std;
class Ds_nguyen{
private:
    int n;
    int *contro;
public:

    friend istream& operator>>(istream& is, Ds_nguyen &obj){
        cout << "Nhap n: ";
        cin >> obj.n;
        obj.contro = new int[obj.n];
        for(int i = 0; i < obj.n; i++){
            cin >> obj.contro[i];
        }    
        return is;
    } 
    friend ostream& operator<<(ostream& os, Ds_nguyen &obj){
        for(int i =  0; i < obj.n; i++){
            os << obj.contro[i] << " ";
        }
        return os;
    } 
    float demptucogiatriduong(){
        int sum = 0;
        int count=0;
        for(int i = 0; i < n;i++){
            if(this->contro[i] > 0){
                sum+=contro[i];
                count++;
            }  
        }
        return (float)sum/count;
    }
    int demsochinhphuong(){
        int sum = 0;
        for(int i = 0; i < n; i++){
            if((this->contro[i])== (sqrt(this->contro[i])*sqrt(this->contro[i]))){
                sum++;
            }
        }
        return sum;
    }
    
};

int main(){
    Ds_nguyen A;
    cin >> A;
    cout << "Day ban vua nhap la: ";
    cout << A;
    cout << "Tbc cac phan tu co gia tri duong la: ";
    cout << A.demptucogiatriduong() << endl;
    cout << "So so chinh phuong la: ";
    cout << A.demsochinhphuong() << endl;
    
}