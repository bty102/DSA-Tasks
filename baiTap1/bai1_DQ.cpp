#include <iostream>

/*
1. Tim gia tri lon nhat cua day A.
int A[]: mang can tim GTLN.
int n: kich thuoc cua mang.(n >= 1)
PTTC: n == 1 (if(n == 1))
Goi g(n) la so lan thuc hien cua PTTC trong MAX(A, n)
=> g(n-1) la so lan thuc hien cua PTTC trong MAX(A, n-1)
g(n) = 1 neu n = 1
g(n) = 1 + g(n-1) neu n > 1
------------------------------
g(n) = g(n-1) + 1
g(n-1) = g(n-2) + 1
...
g(2) = g(1) + 1
g(1) = 1
=> g(n) = n
=> T(n) = O(n)
*/
int MAX(int A[], int n) {
    if(n == 1) return A[1];
    else {
        return std::max(A[n], MAX(A, n-1));
    }
}

/*
2. Dao nguoc day A.
int A[]: day muon dao nguoc.
int start_pos: chi so phan tu dau.
int end_pos: chi so phan tu cuoi.
PTTC: start_pos < end_pos
Goi g(n) la so lan thuc hien cua PTTC trong loi goi ham DaoNguoc(A, 1, n)
=> g(n-1) la so lan thuc hien cua PTTC trong loi goi ham DaoNguoc(A, 1, n-1)
g(n) = 1 neu n <= 1, n nguyen
g(n) = 1 + g(n-1) neu n > 1, n nguyen
--------------------------------------
g(n) = 1 + g(n-1)
g(n-1) = 1 + g(n-2)
...
g(1) = 1
g(-1) = 1
...
*/
void DaoNguoc(int A[], int start_pos, int end_pos) {
    if(start_pos < end_pos) {
        std::swap(A[start_pos], A[end_pos]);
        DaoNguoc(A, start_pos+1, end_pos-1);    
    }
}

/*
3. Kiem tra day A co doi xung hay khong.
int A[]: day muon kiem tra doi xung.
int start_pos: chi so phan tu dau.
int end_pos: chi so phan tu cuoi.
*/
bool DoiXung(int A[], int start_pos, int end_pos) {
    if(start_pos >= end_pos) return true;
    else {
        return (A[start_pos]==A[end_pos]) and DoiXung(A, start_pos+1, end_pos-1);
    }
}

/*
4. Dem so cap nghich dao trong A.
int A[]: day can dem so cap nghich dao.
int n: kich thuoc cua day.
PTTC: n <= 1 (if(n <= 1))
Goi g(n) la so lan thuc hien cua PTTC trong SoCapND(A, n)
=> g(n-1) la so lan thuc hien cua PTTC trong SoCapND(A, n-1)
g(n) = 1 neu n = 1 hoac n = 0
g(n) = 1 + g(n-1) neu n > 1, nguyen
-----------------------------------
g(n) = 1 + g(n-1)
g(n-1) = 1 + g(n-2)
...
g(1) = 1
g(0) = 1
=> g(n) = n => T(n) = O(n)
*/
int SoCapND(int A[], int n) {
    if(n <= 1) return 0;
    else {
        int dc = 0;
        for(int i = n-1; i >= 1; i--) {
            if(A[n] < A[i]) dc++;
        }
        return dc + SoCapND(A, n-1);
    }
}

/*
5. Dem so cap trong A ma co tong bang x cho truoc.
int A[]: day can dem.
int n: kich thuoc day.
int x: so cho truoc.
*/
int SoCap(int A[], int n, int x) {
    if(n <= 1) return 0;
    else {
        int dc = 0;
        for(int i = n-1; i >= 1; i--) {
            if(A[n]+A[i] == x) dc++;
        }
        return dc + SoCap(A, n-1, x);
    }
}

/*
6.
*/
// void InDay(int A[], int start_pos, int end_pos) {
//     if(start_pos == end_pos) {std::cout << 0; return;}
//     int d = 0;
//     for(int i = start_pos+1; i <= end_pos; i++) {
//         if(A[i] <= A[start_pos]) d++;
//     }
//     std::cout << d << " ";
//     InDay(A, start_pos+1, end_pos);
// }
void InDay(int A[], int start_pos, int end_pos) {
    if(start_pos==end_pos) std::cout << 0;
    else {
        int dd = 0;
        for(int i = start_pos+1; i <= end_pos; i++) {
            if(A[i] <= A[start_pos]) dd++;
        }
        std::cout << dd << " ";
        InDay(A, start_pos+1, end_pos);
    }
}
int main() {
    int n;
    std::cout << "Nhap so phan tu: ";
    std::cin >> n;
    int A[n+1];
    std::cout << "Nhap cac phan tu: ";
    for(int i = 1; i <= n; i++) {
        std::cin >> A[i];
    }
    // std::cout << "Gia tri lon nhat: " << MAX(A, n);
    // DaoNguoc(A, 1, n);
    // std::cout << "Sau khi dao nguoc: ";
    // for(int i = 1; i <= n; i++) {
    //     std::cout << A[i] << " ";
    // }
    // std::cout << ((DoiXung(A, 1, n))? "Doi xung" : "Khong doi xung");
    // std::cout << "So cap nghich dao: " << SoCapND(A, n);
    // int x;
    // std::cout << "Nhap so cho truoc: ";
    // std::cin >> x;
    // std::cout << "So cap co tong bang " << x << " la: " << SoCap(A, n, x);
    InDay(A, 1, n);
    return 0;
}
