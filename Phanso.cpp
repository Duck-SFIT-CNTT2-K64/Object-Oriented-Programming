#include <bits/stdc++.h>
using namespace std;

class Phanso {
private:
    int ts, ms;

public:
    Phanso(){}
    Phanso(int ts, int ms){
        this->ts = ts;
        this->ms = ms;
    }
    //
    Phanso operator+(const Phanso& other) const {
        Phanso result;
        result.ts = this->ts * other.ms + other.ts * this->ms;
        result.ms = this->ms * other.ms;
        return result;
    }

    Phanso operator*(const Phanso& other) const {
        Phanso result;
        result.ts = this->ts * other.ts;
        result.ms = this->ms * other.ms;
        return result;
    }

    friend istream& operator>>(istream& is, Phanso &a){
        is >> a.ts >> a.ms;
        return is;
    }
    friend ostream& operator<<(ostream& os, Phanso &a){
        os << a.ts << "/" << a.ms << endl;
        return os;
    }
};
int main(){
    Phanso x1, x2;
    cin >> x1 >> x2;
    cout << x1 << x2;

    Phanso sum = x1 + x2;
    Phanso product = x1 * x2;

    cout << "Sum: " << sum;
    cout << "Product: " << product;
}