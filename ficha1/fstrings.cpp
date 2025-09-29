/*
 * STRINGS

    s.at(i) ==> devolve o caracter na posição i
            - faz a verificação dos limites e lança uma exceção se i for inválido

    s[i] ==> devolve o caracter da pos i, sem verificar os limites => pode rebentar
    s.size() / s.length() ==> número de caracteres da string - pode dizer-se que produzem o mesmo efeito
    s.empty() ==> true se a string estiver vazia ("")
    s.compare(string t) ==> faz comparação lexigráfica (código ASCII)
    s.insere(int pos, string t) ==> insere o segundo argumento na string s a partir da posição pos

 **/

#include <iostream>
#include <string>

using namespace std;

int main_strings(){
    std::cout << "Exemplos com Strings" << std::endl;

    cout << "Exemplos com Strings (com namespace)" << endl;

    // = (atribuição)
    std::string a = "olá";
    std::string b;
    b = a;  // b = "olá"

    cout << b << endl;

    // == (comparação)
    if (a == "olá") cout << "são iguais" << endl;

    // compare() - comparação lexicográfica (tipo o dicionário)
    //    ==>  retorna 0 se forem iguais, <0 se s1 < s2, >0 se s1 > s2
    if (a.compare("olá") == 0 ) cout << "iguais (compare)" << endl;
    if(a.compare("palavra") <0 ) cout << "são diferentes (<0) " << endl;
    if(a.compare("aaPla") >0 ) cout << "são diferentes (>0)" << endl;


    // + concatenar
    string c = a + " mundo";  // "olá mundo"
    cout << "Concatenar: " << c << endl;

    // insert (pode ser visto como um concatenar "especial")
    string s = "strings";
    s.insert(0, "Aula 1 ");  // "Aula 1 strings"
    cout << "Insert: " << s << endl;


    // for-each
    std::string nome = "Rita";
    for (char c : nome) {
        cout << c << endl;   // imprime R i T A (cada letra em linha diferente)
    }



    return 0;
}