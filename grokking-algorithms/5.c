#include <stdio.h>

void sauda(char nome[]);
void sauda2(char nome[]);
void tchau();

void sauda(char nome[]){
    printf("ola, %s!\n", nome);
    sauda2(nome);
    printf("preparando pra dizer tchau...\n");
    tchau();
}

void sauda2(char nome[]){
    printf("como vai, %s?\n", nome);
}

void tchau(){
    printf("ok, tchau!\n");
}


int main(){
    char nome[] = "felipe";
    sauda(nome);

    return 0;
}