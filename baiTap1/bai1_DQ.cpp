#include <iostream>

// 1. Tim max cua day A
int MAX(int A[], int n) {
    if(n == 1) return A[0];
    return (A[n-1] > MAX(A, n-1))? A[n-1] : MAX(A, n-1);
}

// 2. Dao nguoc day A
void DaoNguoc(int A[], int n) {
    if(n == 1) return;
    int tmp = A[0];
    for(int i = 0; i <= n-2; i++) {
        A[i] = A[i+1];
    }
    A[n-1] = tmp;
    DaoNguoc(A, n-1);
}

// 3. Kiem tra day A co doi xung hay khong
bool DoiXung(int A[], int start_pos, int end_pos) {
    if(start_pos == end_pos or start_pos > end_pos) return true;
    if(A[start_pos] != A[end_pos]) return false;
    return DoiXung(A, start_pos+1, end_pos-1);
}

// 4. Dem so cap nghich dao cua A
int SoCapND(int A[], int n) {
    if(n == 1) return 0;
    int SND = 0;
    for(int i = n-2; i >= 0; i--) {
        if(A[n-1] < A[i]) SND++;
    }
    return SND + SoCapND(A, n-1);
}
int main() {
    int n;
    std::cin >> n;
    int A[n];
    for(int i = 0; i <= n-1; i++) {
        std::cin >> A[i];
    }
    // std::cout << "Max = " << MAX(A, n) << "\n";
    // DaoNguoc(A, n);
    // std::cout << "Sau khi dao nguoc: ";
    // for(int i = 0; i <= n-1; i++) {
    //     std::cout << A[i] << " ";
    // }
    // std::cout << (DoiXung(A, 0, n-1)? "La doi xung\n" : "La khong doi xung\n");
    std::cout << "So cap nghich dao: " << SoCapND(A, n);
    return 0;
}
