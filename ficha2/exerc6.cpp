
#include <iostream>
using namespace std;

const int TAM = 20; //  caso se pretenda um valor único e nao por instância declarar como:: static const int TAM=20;

struct Tabela{
    int dados[TAM];
};

// 6.a) ==> função global para preencher a tabela com um valor
void preencher (Tabela &t, int v){
    cout<<":: 6.a) ...a preencher a tabela... ::" << endl;
    for(int i=0; i<TAM; i++){
        t.dados[i]=v;
    }
}

// 6.a) ==> função global para listar o conteúdo da tabela
void listar(const Tabela &t){
    cout<<":: 6.a) ...a listar o conteúdo da tabela... ::" << endl;
    for(int i=0; i<TAM; i++){
        cout << t.dados[i] << " ";
    }
    cout << endl;
}

// 6.b) ==> função global para obter o valor numa dada posição :: proteger indices inválidos
// ::.. faz mais sentido usar exceções - uma vez que se estiver fora dos limites,..::
int elementoEm(const Tabela &t, int pos){
    if(pos<0 || pos>=TAM)
        //return 0; // devolve 0 caso esteja fora dos limites
        throw out_of_range("índice fora dos limites da tabela!");
    return t.dados[pos];
}
/*
// ::.. faz mais sentido manter sem exceções - uma vez que ignora simplesmente se estiver fora dos limites..::
int & elementoEm( Tabela &t, int pos){
    if(pos<0 || pos>=TAM)
        //return 0; // devolve 0 caso esteja fora dos limites
        throw out_of_range("índice fora dos limites da tabela!");
        // faz sentido usar exceções, uma vez que a leitura fora dos limites não faz sentido receber 0 ou outro default value
    return t.dados[pos];

    // -- versão sem exceções --
    // static int default_value = 0;
    //    if (pos < 0 || pos >= TAM)
    //        return default_value;
    //    return t.dados[pos];

}
 */

// 6.b) ==> função global para alterar o valor numa dada posição :: proteger indices inválidos ::
// IMPORTANTE:: esta função não responde a: elementoEm(t, 4) = 15; em que a função que chama está do lado esquerdo
// USADA APENAS PARA DEMONSTRAÇÃO ==> pode/deve ser comentada
void atualizaElementoEm(Tabela &t, int pos, int v){
    if(v<0 || v>=TAM)
        return; // devolve 0 caso esteja fora dos limites
    t.dados[pos] = v;
}

// 6.c) ==> função global para devolver uma referência para o valor numa dada posição
// ::.. faz mais sentido usar exceções para lançar a mesma caso esteja fora dos limites: é inaceitável devolver um valor errado ou rebentar..::
int elementoEm_(const Tabela &t, int v){
    if (v < 0 || v >= TAM)
        throw out_of_range("índice fora dos limites da tabela!");
    return t.dados[v];
}

// -------------------------------------------------------------------
// 6.d) ==> Função unificada
    // (1) Sem exceções ==> devolve referência para um "default value"
    // ::.. faz mais sentido manter sem exceções - uma vez que ignora simplesmente se estiver fora dos limites ..::
    int & elementoEm(Tabela& t, int pos) {
        static int default_value = 0;
        if (pos < 0 || pos >= TAM)
            return default_value;
        return t.dados[pos];
    }

    // (2) Com exceções ==> devolve referência para o elemento válido - podia funcionar sem exceções
    int & elementoEmEx(Tabela& t, int pos) {
        if (pos < 0 || pos >= TAM)
            throw out_of_range("índice fora dos limites da tabela!");
        return t.dados[pos];
    }

int main()
{
    cout<<":: FICHA 2-Exercício 6a) ::" << endl;

    Tabela a;                   // a dimensão é de 20 elementos

    // 6.a)
    {
        cout << "6.a) Preencher e Listar" << endl;
        preencher(a, 5);
        listar(a);
    }
    // 6.b)
    {
        cout << "6.b) Obter e Atualizar" << endl;
        cout << elementoEm(a, 10); // aparece um determinado valor
        atualizaElementoEm(a, 6, 12); // nao fazia parte :: ver que é diferente de →→→ elementEm() = X
        listar(a);
        elementoEm(a, 10) = 15; // notar que a chamada à função fica do lado esquerdo da atribuição
        listar(a);
    }
    // 6.c)
    // obter valor fora de índice - deve ter exceções
    // alterar valor fora do índice - (deve) mas não seria um problema se não tivesse, simplesmente não alterava.

    // 6.d)
    cout << "Unificado e com exceções" << endl;
    try {
        elementoEmEx(a, 7) = 45;
        cout << "a[7] = " << elementoEmEx(a, 7) << endl;
        cout << "a[60] = " << elementoEmEx(a, 60) << endl; // erro
    }
    catch (const out_of_range& e) {
        cerr << "Erro: " << e.what() << endl;
    }
    return 0;
}
