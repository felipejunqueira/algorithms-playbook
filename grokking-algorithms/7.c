#include <stdio.h>

int soma(int list[], int n){
    if (n == 0) return 0;     
    return list[0] + soma(list + 1, n - 1);
}

int cont(int vet[], int n){
    if (n == 0) return 0;
    return 1 + cont(vet + 1, n - 1);
}

int max(int lista[], int n){
    if (n == 2) return (lista[0] > lista[1] ? lista[0] : lista[1]);
    int sub_max = max(lista + 1, n - 1);
    return (lista[0] > sub_max ? lista[0] : sub_max);
}

int main(){
    int lista[] = {1, 9, 3, 4};
    int total = soma(lista, 4);
    printf("%d\n", total);
    printf("there are %d items\n", cont(lista, 4));
    printf("the max is %d\n", max(lista, 4));
    return 0;
}
