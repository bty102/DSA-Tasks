#include <iostream>

//Tim phan tu lon nhat cua day => T(n) = O(n)
int max(int *arr, int n) {
    int Mx = arr[0];
    for(int i = 1; i <= n-1; i++) {
        if(Mx < arr[i])
            Mx = arr[i];
    }
    return Mx;
}

//Dao nguoc day => T(n) = O(n)
void daoNguoc(int *arr, int n) {
    for(int i = 0; i <= (n/2)-1; i++) {
        int tmp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = tmp;
    }
}

//Kiem tra day doi xung => T(n) = O(n)
bool laDoiXung(int *arr, int n) {
    for(int i = 0; i <= (n/2)-1; i++) {
        if(arr[i] != arr[n-1-i])
            return false;
    }
    return true;
}

//Tim so cap nghich dao cua day => T(n) = O(n^2)
int soCapND(int *arr, int n) {
    int SCND = 0;
    for(int i = 0; i <= n-2; i++) {
        for(int j = i+1; j <= n-1; j++) {
            if(arr[i] > arr[j])
                SCND++;
        }
    }
    return SCND;
}

//Dem so cap trong day s/c tong cua mot cap bang mot so cho truoc => T(n) = O(n^2)
int soCapTong(int *arr, int n, int x) {
    int SL = 0;
    for(int i = 0; i <= n-2; i++) {
        for(int j = i+1; j <= n-1; j++) {
            if((arr[i]+arr[j]) == x)
                SL++;
        }
    }
    return SL;
}

//T(n) = O(n^2)
void inDay(int *arr, int n) {
    int D[n];
    for(int i = 0; i <= n-1; i++) {
        int SL = 0;
        for(int j = i+1; j <= n-1; j++) {
            if(arr[j] <= arr[i])
                SL++;
        }
        D[i] = SL;
    }

    for(int &item : D) {
        std::cout << item << " ";
    }
}
int main() {
    int n;
    std::cout << "Nhap so luong phan tu: ";
    std::cin >> n;
    int A[n];
    std::cout << "Nhap cac phan tu cua day: ";
    for(int &item : A) {
        std::cin >> item;
    }
    // std::cout << "Phan tu lon nhat cua day: " << max(A, n) << "\n";
    // daoNguoc(A, n);
    // std::cout << "Day sau khi dao nguoc: ";
    // for(int &item : A) {
    //     std::cout << item << " ";
    // }
    // std::cout << (laDoiXung(A, n)?"\nDay doi xung\n":"\nDay khong doi xung\n");
    // std::cout << "So cap nghich dao cua day: " << soCapND(A, n) << "\n";
    // int x;
    // std::cout << "x = ";
    // std::cin >> x;
    // std::cout << "So cap co tong bang " << x << " : " << soCapTong(A, n, x) << "\n";

    inDay(A, n);
    return 0;
}
