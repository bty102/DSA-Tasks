#include <iostream>
int UCLN(int n, int m) {
    if(m <= n and n%m == 0) return m;
    else {
        if(n < m) return UCLN(m, n);
        else return UCLN(m, n%m);
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::cout << UCLN(n, m);
    return 0;
}
