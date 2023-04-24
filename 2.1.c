#include<stdio.h>
#include<stdlib.h>
typedef struct fila{
    int valor;
    struct fila * prox;
}FILA;
FILA * inicio = NULL;
FILA * fim = NULL;
int Tamanho_fila;
//a) Adicionar um elemento na fila
void Add_no_fila(int parametro){
    FILA * novo = malloc(sizeof(FILA));
    novo->valor=parametro;
    novo->prox=NULL;

    if(inicio==NULL){
        inicio=novo;
        fim=novo;
    }
    else{
        fim->prox=novo;
        fim=novo;
    }
    Tamanho_fila++;
}
//b) Remover elementos da lista
int Remover_no_fila(){
    FILA * lixo = inicio;
    int valor_removido= -1;
    if(Tamanho_fila == 1){
        valor_removido=inicio->valor;
        inicio=NULL;
        fim=NULL;
    }
    else if(Tamanho_fila > 0){
        valor_removido=inicio->valor;
        inicio=inicio->prox;
    }
    Tamanho_fila--;
    free(lixo);
    return valor_removido;
}
//c) Imprimir os elementos da fila
void Imprimir_fila(){
    FILA * aux = inicio;
    while (aux != NULL){
        printf("Valor:%d\n",aux->valor);
        aux=aux->prox;
    }
    
}
//d Retornar o tamanho
int Tam(){
    return Tamanho_fila;
}
int main(){
Add_no_fila(1);
Add_no_fila(2);
Add_no_fila(3);
printf("Tamanho da fila:%d\n",Tamanho_fila);
Remover_no_fila();
Imprimir_fila();
printf("Tamanho da fila:%d\n",Tamanho_fila);
}