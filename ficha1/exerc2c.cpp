#include <iostream>
#include <cctype>
#include <cstring>
#include <limits>
using namespace std;

#define MAX 50
/*
 *
 */
int main_2c(int argc, char** argv) {
    int age; char op1, op2;
    char name[MAX]="", temp[MAX];
    // name = "olá"; //não dá
    //printf("Name:");
    //Tentar ler a idade e se não for é porque é mais do que um nome

    cout << "Introduza o nome e logo a seguir a idade:";
    //scanf("%[^\n]s",name);

    while(!(cin >> age)) { //enquanto não for um inteiro, ainda está a introduzir o nome
        cin.clear();
        cin >> temp;
        strcat(name, temp);
        strcat(name, " ");
    }

    //printf("Age:");
    while(age < 0 || age > 120){
        cout << "Leitura inválida da idade\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new
        cout << "Por favor introduza uma idade numérica e positiva\n";
    }

    // exemplo para verificação se é digito, neste caso no nome
    for (int i = 0; name[i] != '\0'; i++) {
        if (isdigit(name[i])) {
            cout << "Encontrado um dígito no nome! -> " << name[i] << endl;
        }
    }

    for (int i = 0; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);  // coiloca tudo em letras minúsculas
    }
    // Capitalizar a primeira letra
    name[0] = toupper(name[0]);

    cout << "Read data... name:" << name << "\tAge:" << age;




    return 0;
}