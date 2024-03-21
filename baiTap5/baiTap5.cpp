#include <iostream>

struct Nut {
    int Info;
    Nut *Left;
    Nut *Right;
};

// 1.
int chieuCao(Nut *T) {
    if(T==NULL) return 0;
    else return 1+std::max(chieuCao(T->Left), chieuCao(T->Right));
}

// 2.
void boSung(Nut *&T, int X) {
    if(T==NULL) {
        T = new Nut;
        T->Info = X;
        T->Left = NULL;
        T->Right = NULL;
    }
    else {
        if(X < T->Info) boSung(T->Left, X);
        else boSung(T->Right, X);
    }
}

// 3.
void xoa(Nut *&T) {
    if(T!=NULL) {
        xoa(T->Left);
        xoa(T->Right);
        delete T;
        T = NULL;
    }
}

// 4.
// a.
/*
int Max(Nut *T) {
    if(T->Right==NULL) return T->Info;
    else return Max(T->Right);
}
*/

// b.
int Max(Nut *T) {
    if(T->Left==NULL && T->Right==NULL) return T->Info;
    else {
        if(T->Left==NULL) return std::max(T->Info, Max(T->Right));
        else if(T->Right==NULL) return std::max(T->Info, Max(T->Left));
        else return std::max(T->Info, std::max(Max(T->Left), Max(T->Right)));
    }
}

Nut *T;
int main() {
    T = NULL;
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        int X;
        std::cin >> X;
        boSung(T, X);
    }
    std::cout << Max(T);
    return 0;
}
