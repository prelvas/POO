#include <iostream>
#include <string>
using namespace std;

void imprime(string s){
    cout << s << endl;
}
void imprime(string s, int i){
    cout << s << i << endl;
}

void imprime(int b, string c){
    cout << b << c << endl;
}
//
//void imprime(double b, string c){
//	cout << "double" << b << c << endl;
//}


int main_e2(){
    //        double d=10.4;
    //
    imprime("programação orientada a objetos");
    imprime("horas por aula teórica ", 2);
    imprime(3, " horas em cada aula prática");
    // imprime('a', "outra");
    // imprime(d, "nova");


    return 0;
}
