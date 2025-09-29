#include <iostream>
#include <cctype>
#include <limits>
using namespace std;

#define MAX 50

/*
 * exercício 2b ficha 1 - substituir printf e scanf por cin e cout
 */
int main_2b(int argc, char** argv) {
    int age;
    char name[MAX], temp[MAX];
    //string name;

    //Ler nome
    cout << "Introduza o nome:";
    cin >> name;

    while(cout << "\nIntroduza a idade:" && (! (cin >> age) || cin.fail())){
        cout << "Leitura inválida da idade\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new
        cout << "Por favor introduza uma idade numérica\n";
    }

    cout << "Read data... name:" << name << "\tAge:" << age;

    return 0;
}