#include <iostream>
using namespace std;

// Devolve referência do menor ou maior dos dois ==> a) e b); devolve escolhe se é o primeiro parâmetro ou o segundo que é devolvido
// a)
/*
int& seleciona(int& x, int& y, char op) {
    if (op == 'm')            // menor
        return (x < y ? x : y);
    else if (op == 'M')       // maior
        return (x > y ? x : y);
    return x; // fallback simples
}
*/


int& seleciona(int& x, int& y, char op) {
    if (op == 'm')            // menor
        return (x < y ? x : y);
    else if (op == 'M')       // maior
        return (x > y ? x : y);
    else if (op == 'p')
        return x;
    else if (op == 'u')
        return y;
    else
        throw invalid_argument("Código de seleção desconhecido!");
    //return x; // fallback simples
}

int main_e5() {
    /*
    // --a)--
     {
         int a = 5, b = 10;
         seleciona(a, b, 'm') = 0;
         cout << "a = " << a << " b = " << b;
         // aparece 0 10
    }
     */

    /*
    // --b)--
     {
         int a = 5, b = 10;
         seleciona(a, b, 'M') -= 3;
         cout << "a = " << a << " b = " << b;
         // aparece 5 7
    }
     */
    // --c)--
    {
        int a = 5, b = 10;
        try{
            seleciona(a, b, 'x') -= 3;  // seleciona o maior (b) e subtrai 3
            // aparece 5 e 7

            cout << "a = " << a << " b = " << b << endl;
            // na saída aparece: a = 5 b = 7
        }catch (const invalid_argument& e) {
            cerr << "Erro: " << e.what() << endl;
        }catch (const exception& e) {
            cerr << "Erro::Outra exceção -> " << e.what() << endl;
        }
    }

}
