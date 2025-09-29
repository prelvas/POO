#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>
#define N 10

using namespace std;

void minusculas(string & s){
    for(int i=0; i <s.length(); i++)
        s[i]=tolower(s[i]);
}

int main() {
    string nomes[N] = { "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez" };
    string pal;
    int num;
    char c='\n';

    // do while para ficar à espera que seja digitada a palavra fim
    do{
        if(c!='\n')
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Introduza texto ou número:";
        getline(cin, pal);
        istringstream is(pal);
        is >> num;
        if(is.fail()){
            /* cin >> num;
            if(cin.fail()){
                cin.clear();
                cin >> pal; //Afinal é uma palavra*/
            minusculas(pal);
            if (pal == "fim")
                break;
            for (int i = 0; i < N; i++)
                if (nomes[i] == pal)
                    cout << i + 1 << endl;
        }
        else
        if (num >= 1 && num <= 10)
            cout << nomes[num-1] << endl;

        cout << "Prima <enter> para avançar...";
        // cin.ignore(numeric_limits<streamsize>::max(),'\n');
        c=cin.get();
    } while (true);


}