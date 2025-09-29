#include <cstdio> //só é possível desta forma garantir que as funções do C irão ser acrescentadas
//ao espaço de nomes std

//using namespace std;

int main_e2a(int argc, char** argv) {
    int age;
    char name[20]="", ageTxt[20];
    int result;

    // leitura via linha de comandos - usando o terminal
    std::printf("argv-0: %s\n", argv[0]);
    std::printf("argv-1: %s\n", argv[1]);
    std::printf("argv-2: %s\n", argv[2]);

    std::printf("Give me your name:");
    std::scanf("%[^\n]s",name);

    //consuming <enter>
    getchar();
    do{
        std::printf("Age:");
        std::fgets(ageTxt,sizeof(ageTxt), stdin);
        result=std::sscanf(ageTxt, "%d",&age);
    }
    while(result != 1 || age < 0 || age > 120);

    std::printf("Your name is:%s\t and your age:%d\n",name,age);

    return 0;
}

