#include <iostream>
#include <cctype>
#include <limits>
#include <string>
using namespace std;

#define MAX 50
/*
 *
 *
 */
int main_2d(int argc, char** argv) {
    int age;
    string name, temp;
    name = "olá"; //agora dá
    name = "";
    cout << "Introduza o nome e logo a seguir a idade:";
    while(!(cin >> age)) { //enquanto não for um inteiro, ainda está a introduzir o nome
        cin.clear();
        cin >> temp;
        if (toupper(temp[0]) < 'A' || toupper(temp[0] > 'Z'))
            cerr << "Cada parte do nome deve começar por letra (maiuscula)\n";
        else {
            name += temp;
            name += " ";
        }
    }

    while(age < 0 || age > 120){
        cout << "Leitura inválida da idade\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new
        cout << "Por favor introduza uma idade numérica e positiva\n";
        cin >> age;
    }

    cout << "Read data... name:" << name << "\tAge:" << age;

    return 0;
}
