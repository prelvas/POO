#include <iostream>
#include <string>
using namespace std;

// troca por referência: maior legibilidade e menos propício a erros (por exemplo nullptr não é possível)
void troca(int &ra, int &rb){
    int temp;
    temp = ra;
    cout << "ra=" << &ra << endl;
    cout << "rb=" << &rb << endl;
    ra = rb;
    rb = temp;
}

// troca por ponteiros - maior cuidado (no uso do & na chamada e no valor apontado por para a troca)
void troca(int *pa, int *pb){
    int temp;
    temp = *pa;
    cout << "pa=" << pa << endl;
    cout << "pb=" << pb << endl;
    *pa = *pb;
    *pb = temp;
}

int main_e4(){

    int a = 5, b = 10;
    cout << "&a=" << &a << endl;
    cout << "&b=" << &b << endl;
    //cout << "Resultado:" << static_cast<char>(cin.get()) << "\n";
    troca(a, b);
    cout << "\na = " << a << "\nb = " << b << endl;

    // aparece a = 10 e b = 5

    a = 5, b = 10;
    troca(&a, &b);
    cout << "\na = " << a << "\nb = " << b <<endl;
    // aparece a = 10 e b = 5

    return 0;

}
