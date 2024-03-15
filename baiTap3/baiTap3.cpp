#include <iostream>

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

void deleteFirst(Node *&F) {
    if(F!=NULL) {
        Node *tmp = F;
        F = F->Next;
        delete tmp;
    }
}

void show(Node *F) {
    while(F!=NULL) {
        std::cout << F->Info << " ";
        F = F->Next;
    }
}

void push(Node *&F, int X) {
    Node *tmp = new Node;
    tmp->Info = X;
    tmp->Next = F;
    F = tmp;
}

void pop(Node *&F, int &X) {
    if(F==NULL) std::cout << "Stack can\n";
    else {
        X = F->Info;
        Node *tmp = F;
        F = F->Next;
        delete tmp;
    }
}

// 1.
// int count_lt(Node *F, int X) {
//     if(F==NULL) return 0;
//     else {
//         if(F->Info < X) return 1 + count_lt(F->Next, X);
//         else return count_lt(F->Next, X);
//     }
// }


int count_lt(Node *F, int X) {
    int count = 0;
    while(F!=NULL) {
        if(F->Info < X) count++;
        F = F->Next;
    }
    return count;
}

// 2.
// void insert(Node *&F, int X) {
//     if(F==NULL or F->Info >= X) {
//         insertFirst(F, X);
//     }
//     else {
//         insert(F->Next, X);
//     }
// }


void insert(Node *&F, int X) {
    if(F==NULL or F->Info>=X) {
        insertFirst(F, X);
    }
    else {
        Node *tmp = F;
        while(tmp->Next!=NULL and tmp->Next->Info<X) tmp = tmp->Next;
        Node *P = new Node;
        P->Info = X;
        P->Next = tmp->Next;
        tmp->Next = P;
    }
}

// 3.
// void del(Node *&F, int X) {
//     if(F==NULL or F->Info > X) return;
//     else {
//         if(F->Info == X) deleteFirst(F);
//         else {
//             del(F->Next, X);
//         }
//     }
// }


void del(Node *&F, int X) {
    if(F==NULL or F->Info > X) return;
    else {
        if(F->Info == X) deleteFirst(F);
        else {
            Node *tmp = F;
            while(tmp->Next!=NULL) {
                if(tmp->Next->Info == X) {
                    Node *P = tmp->Next;
                    tmp->Next = tmp->Next->Next;
                    delete P;
                    break;
                }
                else tmp = tmp->Next;
            }           
        }
    }
}

// 4.
// int MAX(Node *F) {
//     if(F->Next == NULL) return F->Info;
//     else return std::max(F->Info, MAX(F->Next));
// }

int MAX(Node *F) {
    int M = F->Info;
    F = F->Next;
    while(F!=NULL) {
        if(F->Info > M) M = F->Info;
        F = F->Next;
    }
    return M;
}

// 5.
// void insertLast(Node *&F, int X) {
//     if(F==NULL) insertFirst(F, X);
//     else insertLast(F->Next, X);
// }

void insertLast(Node *&F, int X) {
    if(F==NULL) insertFirst(F, X);
    else {
        Node *tmp = F;
        while(tmp->Next != NULL) tmp = tmp->Next;
        Node *P = new Node;
        P->Info = X;
        P->Next = NULL;
        tmp->Next = P;
    }
}

// 6.
// void deleteLast(Node *&F) {
//     if(F!=NULL) {
//         if(F->Next == NULL) deleteFirst(F);
//         else deleteLast(F->Next);  
//     }
// }

void deleteLast(Node *&F) {
    if(F!=NULL) {
        if(F->Next == NULL) deleteFirst(F);
        else {
            Node *tmp = F;
            while(tmp->Next->Next != NULL) tmp = tmp->Next;
            delete tmp->Next;
            tmp->Next = NULL;
        }
    }
}

// 7.
// a.
// Node* address(Node *F, int X) {
//     if(F==NULL) return NULL;
//     else {
//         if(F->Info == X) return F;
//         else return address(F->Next, X);
//     }
// }

// Node* address(Node *F, int X) {
//     if(F==NULL) return NULL;
//     else {
//         if(F->Info == X) return F;
//         else {
//             Node *tmp = F->Next;
//             while(tmp!=NULL) {
//                 if(tmp->Info == X) return tmp;
//                 tmp = tmp->Next;
//             }
//             return NULL;
//         }
//     }
// }

// b.
// Node* address(Node *F, int X) {
//     if(F==NULL or F->Info > X) {return NULL;}
//     else {
//         if(F->Info == X) return F;
//         else return address(F->Next, X);
//     }
// }


Node* address(Node *F, int X) {
    if(F==NULL or F->Info > X) {return NULL;}
    else {
        if(F->Info == X) return F;
        else {
            Node *tmp = F->Next;
            while(tmp!=NULL) {
                if(tmp->Info == X) return tmp;
                tmp = tmp->Next;
            }
            return NULL;
        }
    }
}

// 8.
// void inNguoc(Node *F) {
//     if(F!=NULL) {
//         inNguoc(F->Next);
//         std::cout << F->Info << " ";
//     }
// }

// void inNguoc(Node *F) {
//     if(F!=NULL) {
//         Node *rF = NULL;
//         while(F!=NULL) {
//             insertFirst(rF, F->Info);
//             F = F->Next;
//         }
//         while(rF!=NULL) {
//             std::cout << rF->Info << " ";
//             deleteFirst(rF);
//         }
//     }
// }


void inNguoc(Node *F) {
    Node *T = NULL;
    while(F!=NULL) {
        push(T, F->Info);
        F = F->Next;
    }
    while(T!=NULL) {
        int X;
        pop(T, X);
        std::cout << X << " ";
    }
}

// 9.
// void saoChep(Node *F, Node *&L) {
//     if(F==NULL) L = NULL;
//     else {
//         Node *tmp = new Node;
//         tmp->Info = F->Info;
//         L = tmp;
//         saoChep(F->Next, L->Next);
//     }
// }

void saoChep(Node *F, Node *&L) {
    L = NULL;
    while(F!=NULL) {
        insertLast(L, F->Info);
        F = F->Next;
    }
}

// 10.
// a.
void hop(Node *F1, Node *F2, Node *&F3) {
    if(F1==NULL) saoChep(F2, F3); 
    else if(F2==NULL) saoChep(F1, F3);
    else {
        if(F1->Info == F2->Info) {
            Node *tmp = new Node;
            tmp->Info = F1->Info;
            F3 = tmp;
            hop(F1->Next, F2->Next, F3->Next);
        }
        else if(F1->Info < F2->Info) {
            Node *tmp = new Node;
            tmp->Info = F1->Info;
            F3 = tmp;
            hop(F1->Next, F2, F3->Next);
        }
        else {
            Node *tmp = new Node;
            tmp->Info = F2->Info;
            F3 = tmp;
            hop(F1, F2->Next, F3->Next);
        }
    }
}

// b.
void giao(Node *F1, Node *F2, Node *&F3) {
    if(F1==NULL or F2==NULL) F3 = NULL;
    else {
        if(F1->Info == F2->Info) {
            Node *tmp = new Node;
            tmp->Info = F1->Info;
            F3 = tmp;
            giao(F1->Next, F2->Next, F3->Next);
        }
        else if(F1->Info < F2->Info) {
            giao(F1->Next, F2, F3);
        }
        else {
            giao(F1, F2->Next, F3);
        }
    }
}

Node *F = NULL;
Node *L;
Node *F1 = NULL;
Node *F2 = NULL;
Node *F3;
int main() {
    int n1;
    std::cin >> n1;
    for(int i = 1; i <= n1; i++) {
        int X;
        std::cin >> X;
        insertLast(F1, X);
    }
    int n2;
    std::cin >> n2;
    for(int i = 1; i <= n2; i++) {
        int X;
        std::cin >> X;
        insertLast(F2, X);
    }
    giao(F1, F2, F3);
    show(F3);
    return 0;
}
