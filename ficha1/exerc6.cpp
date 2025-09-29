#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>
#include <fstream>

#define N 10

using namespace std;

void minusculas_(string & s){
    for(int i=0; i < s.length(); i++)
        s[i]=tolower(s[i]);
}

int main_6() {
    string nomes[N] = { "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez" };
    string pal, ficheiro;
    int num;
    char c='\n';

    cout << "Introduza o nome do ficheiro a ler:";
    cin >> ficheiro;
    ifstream file(ficheiro);
    if (!file) { //Nao foi possível abrir este ficheiro (talvez não exista)
        cerr << "[Erro!] Ficheiro nao encontrado!\n";
        return -1;
    }
    while(getline(file, pal)){
        if(c!='\n')
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "A ler texto ou número:";

        istringstream is(pal);
        is >> num;
        if(is.fail()){
            /* cin >> num;
            if(cin.fail()){
                cin.clear();
                cin >> pal; //Afinal é uma palavra*/
            minusculas_(pal);
            if (pal == "fim")
                break;
            for (int i = 0; i < N; i++)
                if (nomes[i] == pal)
                    cout << i + 1 << endl;
        }
        else
        if (num >= 1 && num <= 10)
            cout << nomes[num-1] << endl;

        //cout << "Prima <enter> para avançar...";
        //cin.ignore(numeric_limits<streamsize>::max(),'\n');
        //c=cin.get();
    }
    return 0;

}