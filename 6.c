#include<stdio.h>
#include<stdlib.h>
typedef struct pilha{
    int valor;
    int chave;
    struct pilha * prox;
}PILHA;

PILHA * topo = NULL;
int tam=0;

void recursao(PILHA * aux , int key){
    if(aux->chave == key){
        topo=aux->prox;
        free(aux);
    }
    else{
        recursao(aux->prox, key);
        aux->prox=topo;
        topo=aux;
    }
}

void Add_pilha(int value){
    PILHA * novo = malloc(sizeof(PILHA));
    novo->prox=NULL;
    novo->valor=value;
    
    if (tam == 0){
       topo=novo;
    }
    else if (tam > 0){
        novo->prox = topo;
        topo=novo;
    }
    tam++;
    //Uso como chave, o numero do tamanho quando o no foi adicionado. por que? nao pensei em algo melhor para manter o numero da chave, se fosse um numero aleatorio eu nao teria controle.
    novo->chave=tam;
}

void remover(int c){
    PILHA * lixo;
    if(topo->chave == c){
        lixo = topo;
        topo=lixo->prox;
    }
    else{
      recursao(topo , c);  
    }
}

void imprimir(){
    PILHA * aux=topo;
    while (aux!=NULL){
        printf("Valor:%d Chave:%d\n" , aux->valor, aux->chave);
        aux=aux->prox;
    }
}

int main(){
    Add_pilha(12);
    Add_pilha(40);
    Add_pilha(61);
    Add_pilha(30);
    remover(4);
    imprimir();
}