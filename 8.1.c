#include<stdio.h>
#include<stdlib.h>

typedef struct fila{
    int valor;
    struct fila * prox;
}FILA;

int tam = 0 ;
FILA * inicio;
FILA * fim;

//a) Adicionar um elemento na fila;
void Add_ordenada(int valor){
    FILA * novo = malloc(sizeof(FILA));
    novo->prox = NULL;
    novo->valor=valor;
    if(inicio == NULL){
        inicio = novo;
        fim = novo;
    }
    else if (valor > inicio->valor){
        
        novo->prox = inicio;
        inicio = novo;
    }
    else if(valor < fim->valor){
       
       fim->prox = novo;
       fim = novo;
    }
    else{
        
        FILA * aux = inicio;
        
        while(novo->valor < aux->prox->valor){
            aux=aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    tam++;

}
//b) Remover um elemento da fila;
    int remover_ordenada(){
        FILA * lixo;
        if(tam == 1){
            lixo=inicio;
            inicio = NULL;
            fim = NULL;
        }
        else{
            lixo = inicio;
            inicio=inicio->prox;
        }
        tam--;
        int recovery = lixo->valor;
        free(lixo);
        return recovery;
    }
//c) Imprimir os elementos da fila;
    void imprimir(){
        FILA * aux = inicio;
        
        while(aux != NULL){
            printf("Valor:%d\n", aux->valor);
            aux=aux->prox;
        }
    }
int main () {
    Add_ordenada(3);
    Add_ordenada(10);
    Add_ordenada(8);
    Add_ordenada(20);
    Add_ordenada(15);
    imprimir();
    printf("\n");
    
    printf("Valor removido:%d\n\n",remover_ordenada());
    imprimir();

}