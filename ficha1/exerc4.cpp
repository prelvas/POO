#include <string>
#include <iostream>
#include <limits>

using namespace std;

string maiusculas(string s){
    for(int i=0; i <s.length(); i++)
        s[i]=toupper(s[i]);
    return s;
}

int main_e4(){
    string pal;
    int i, k;
    bool iguais;

    do{
        iguais = true;
        cout << "\nPalavra:";
        getline(cin, pal);

        for(k = pal.length() - 1, i = 0; k >= 0 && i < pal.length();i++, k--){
            if ( toupper(pal[i]) != toupper(pal[k])){
                iguais = false;
                break;
            }
        }
        pal=maiusculas(pal);
        if(pal == "FIM")
            break;
        if (iguais)
            cout << "Palíndromo ";
        cout << pal;
        cout << "\nPrima <enter> para continuar\n";
        //while (cin.get() != '\n');
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    } while (pal != "FIM");
    return 0;
}