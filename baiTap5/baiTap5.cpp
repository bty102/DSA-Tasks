#include <iostream>

struct Nut {
    int Info;
    Nut *Left;
    Nut *Right;
};

struct Node {
    int Info;
    Node *Next;
};

void insertFirst(Node *&F, int Info) {
    Node *tmp = new Node;
    tmp->Info = Info;
    tmp->Next = F;
    F = tmp;
}

void insertLast(Node *&F, int X) {
    if(F==NULL) insertFirst(F, X);
    else insertLast(F->Next, X);
}

void show(Node *F) {
    while(F!=NULL) {
        std::cout << F->Info << " ";
        F = F->Next;
    }
}

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
Nut *diaChi(Nut *T, int X) {
    if(T==NULL) return NULL;
    else {
        if(T->Info == X) return T;
        else if(T->Info > X) return diaChi(T->Left, X);
        else return diaChi(T->Right, X);
    }
}

// b. T la cay nhi phan bat ki
// Nut *diaChi(Nut *T, int X) {
//     if(T==NULL) return NULL;
//     else {
//         if(T->Info == X) return T;
//         else {
//             Nut *L = diaChi(T->Left, X);
//             if(L!=NULL) return L;
//             else return diaChi(T->Right, X);
//         }
//     }
// }

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
    if(P==T) return 1; 
    else return muc(T, cha(T, P))+1;
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

// Ham tim min cua cay NP bat ky T(T!=NULL)
int Min(Nut *T) {
    if(T->Left==NULL and T->Right==NULL) return T->Info;
    else {
        int M = T->Info;
        if(T->Left != NULL) M = std::min(M, Min(T->Left));
        if(T->Right !=NULL) M = std::min(M, Min(T->Right));
        return M;
    }
}

// 10. Kiem tra mot cay T bat ki co phai la cay NPTK hay khong
bool laCayNPTK(Nut *T) {
    if(T==NULL or (T->Left==NULL and T->Right==NULL)) return true;
    else {
        if(T->Left==NULL) return (T->Info <= Min(T->Right)) and laCayNPTK(T->Right);
        else if(T->Right==NULL) return (T->Info > Max(T->Left)) and laCayNPTK(T->Left);
        else return (T->Info > Max(T->Left)) and (T->Info <= Min(T->Right)) and laCayNPTK(T->Left) and laCayNPTK(T->Right);
    }
}

// 11. Tim cap(bac) cua cay T
int cap(Nut *T) {
    if(T==NULL or (T->Left==NULL and T->Right==NULL)) return 0;
    else {
        if(T->Left == NULL) return std::max(1, cap(T->Right));
        else if(T->Right == NULL) return std::max(1, cap(T->Left));
        else return std::max(2, std::max(cap(T->Left), cap(T->Right)));
    }
}

// 12.
void duyet_thayThe(Nut *T) {
    if(T->Left !=NULL) {
        T->Left->Info = T->Info + 1;
        duyet_thayThe(T->Left);
    }
    if(T->Right != NULL) {
        T->Right->Info = T->Info + 1;
        duyet_thayThe(T->Right);
    }
}
// a. Thay the gia tri cac nut tren cay T bang muc cua nut do
void thayThe(Nut *T) {
    if(T!=NULL) {
        T->Info = 1;
        duyet_thayThe(T);
    }
}

void duyet_soNut(Nut *T, int X, int &SL) {
    if(T!=NULL) {
        if(T->Info == X) SL++;
        duyet_soNut(T->Left, X, SL);
        duyet_soNut(T->Right, X, SL);
    }
}

// b. Tim so nut tren cay T co muc la X
int soNut(Nut *T, int X) {
    thayThe(T);
    int SL = 0;
    duyet_soNut(T, X, SL);
    return SL;
}

// 13.
void duyet_taoDS(Node *&F, Nut *T) {
    if(T!=NULL) {
        insertLast(F, T->Info);
        duyet_taoDS(F, T->Left);
        duyet_taoDS(F, T->Right);
    }
}
// a. tao danh sach F bang cach copy gia tri ta ca cac nut tu cay T
void taoDS(Node *&F, Nut *T) {
    F = NULL;
    duyet_taoDS(F, T);
}

// b. Sap xep danh sach F tang dan
void sapXep(Node *F) {
    for(Node *i = F; i->Next != NULL; i = i->Next) {
        for(Node *j = i->Next; j!=NULL; j = j->Next) {
            if(i->Info > j->Info) {
                std::swap(i->Info, j->Info);
            }
        }
    }
}

// 14.
// a. Kiem tra cay T co phai la mot dong hay khong
bool laMotDong(Nut *T) {
    if(T==NULL or (T->Left==NULL and T->Right==NULL)) return true;
    else {
        if(T->Left == NULL) return (T->Info > T->Right->Info) and laMotDong(T->Right);
        else if(T->Right == NULL) return (T->Info > T->Left->Info) and laMotDong(T->Left);
        else return (T->Info > T->Left->Info) and (T->Info > T->Right->Info) and laMotDong(T->Left) and laMotDong(T->Right);
    }
}

Nut *T;
Node *F;
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
    if(laMotDong(T)) std::cout << "T la mot dong";
    else std::cout << "T khong la mot dong";
    return 0;
}
