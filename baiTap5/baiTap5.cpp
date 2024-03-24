#include <iostream>

struct Nut {
    int Info;
    Nut *Left;
    Nut *Right;
};

void inGiua(Nut *T) {
    if(T!=NULL) {
        inGiua(T->Left);
        std::cout << T->Info << " ";
        inGiua(T->Right);
    }
}

// 1. Tim chieu cao cua cay T
int chieuCao(Nut *T) {
    if(T==NULL) return 0;
    else return 1 + std::max(chieuCao(T->Left), chieuCao(T->Right));
}

// 2. Bo sung mot nut la co gia tri X vao cay NPTK T
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

// 3. Xoa tat ca cac nut cua cay T
void xoa(Nut *&T) {
    if(T!=NULL) {
        xoa(T->Left);
        xoa(T->Right);
        delete T;
        T = NULL;
    }
}

// 4. Tim max cua cay T(T!=NULL)
// a. T la cay NPTK
// int Max(Nut *T) {
//     if(T->Right==NULL) return T->Info;
//     else return Max(T->Right);
// }

// b. T la cay nhi phan bat ki
int Max(Nut *T) {
    if(T->Left==NULL and T->Right==NULL) return T->Info;
    else {
        int M = T->Info;
        if(T->Left != NULL) M = std::max(M, Max(T->Left));
        if(T->Right != NULL) M = std::max(M, Max(T->Right));
        return M;
    }
}

// 5. Tim so nut nhanh trong cay T
int slNutNhanh(Nut *T) {
    if(T==NULL or (T->Left==NULL and T->Right==NULL)) return 0;
    else return 1 + slNutNhanh(T->Left) + slNutNhanh(T->Right);
}

// 6. Tim dia chi cua mot nut co gia tri bang X trong cay T
// a. T la cay NPTK
// Nut *diaChi(Nut *T, int X) {
//     if(T==NULL) return NULL;
//     else {
//         if(T->Info == X) return T;
//         else if(T->Info > X) return diaChi(T->Left, X);
//         else return diaChi(T->Right, X);
//     }
// }

// b. T la cay nhi phan bat ki
Nut *diaChi(Nut *T, int X) {
    if(T==NULL) return NULL;
    else {
        if(T->Info == X) return T;
        else {
            Nut *L = diaChi(T->Left, X);
            if(L!=NULL) return L;
            else return diaChi(T->Right, X);
        }
    }
}

// 7.
// a. Tim dia chi nut cha cua nut tro boi P trong cay T
Nut *cha(Nut *T, Nut *P) {
    if(T==NULL or T==P) return NULL;
    else if(T->Left==P or T->Right==P) return T;
    else {
        Nut *L = cha(T->Left, P);
        if(L!=NULL) return L;
        else return cha(T->Right, P);
    }
}

// b. Tim muc cua nut duoc tro boi P trong cay T
int muc(Nut *T, Nut *P) {
    if(T==NULL) return 0;
    else {
        if(P==T) return 1;
        else if(P==T->Left or P==T->Right) return 2;
        else {
            if(cha(T->Left, P)!=NULL) return 1+muc(T->Left, P);
            else return 1+muc(T->Right, P);
        }
    }
}

// 8. In cay NPTK T theo thu tu giam dan
void inGiam(Nut *T) {
    if(T!=NULL) {
        inGiam(T->Right);
        std::cout << T->Info << " ";
        inGiam(T->Left);
    }
}

// 9. Tao ra cay L duoc sao chep tu cay T
void saoChep(Nut *T, Nut *&L) {
    if(T==NULL) L = NULL;
    else {
        L = new Nut;
        L->Info = T->Info;
        saoChep(T->Left, L->Left);
        saoChep(T->Right, L->Right);
    }
}

Nut *T;
int main() {
    T = NULL;
    int n;
    std::cout << "Nhap so nut cua cay T: ";
    std::cin >> n;
    std::cout << "Nhap cac nut cua cay T: ";
    for(int i = 1; i <= n; i++) {
        int X;
        std::cin >> X;
        boSung(T, X);
    }
    std::cout << "In giua cay T: ";
    inGiua(T);
    Nut *L;
    saoChep(T, L);
    std::cout << "In giua cay L: ";
    inGiua(L);
    return 0;
}
