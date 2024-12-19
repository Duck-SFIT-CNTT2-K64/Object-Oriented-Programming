#include <bits/stdc++.h>

using namespace std;

class Diem{
    double x, y;
public:
    Diem() : x(0), y(0) {}

    friend istream& operator>>(istream& is, Diem& other) {
        cout << "Nhap hoanh do: ";
        is >> other.x;
        cout << "Nhap tung do: ";
        is >> other.y;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Diem& other) {
        os << "(" << other.x << ", " << other.y << ")";
        return os;
    }

    friend double khoangCach(const Diem& d1, const Diem& d2) {
        return sqrt(pow(d2.x - d1.x, 2) + pow(d2.y - d1.y, 2));
    }

    bool operator==(const Diem& other) const {
        return x == other.x && y == other.y;
    }
};

int main() {
    int n; cout << "Nhap so luong diem: "; cin >> n;
    vector<Diem> diemArr(n);
    for (int i = 0; i < n; ++i) {
        cout << "Nhap diem thu " << i + 1 << ":\n";
        cin >> diemArr[i];
    }
    double maxDistance = 0;
    Diem diem1, diem2;
    bool found = false;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (diemArr[i] == diemArr[j]) continue;
            double distance = khoangCach(diemArr[i], diemArr[j]);
            if (distance > maxDistance) {
                maxDistance = distance;
                diem1 = diemArr[i];
                diem2 = diemArr[j];
                found = true;
            }
        }
    }
    if (found) {
        cout << "Hai diem cach xa nhau nhat la: " << diem1 << " va " << diem2 << endl;
        cout << "Khoang cach giua hai diem la: " << maxDistance << endl;
    } 
    else {
        cout << "Khong co hai diem nao khac nhau." << endl;
    }
    return 0;
}