#include<stdio.h>
#include<stdlib.h>
typedef struct pilha{
    int valor;
    struct pilha * prox;
}PILHA;
int Tamanho_pilha=0;
PILHA * topo= NULL;

//a) Adicionar um elemento na pilha.
void Add_no_pilha(int parametro){
    PILHA * novo = malloc(sizeof(PILHA));
    novo->valor=parametro;
    novo->prox=NULL;

    if(topo==NULL){
        topo=novo;
    }
    else{
        novo->prox=topo;
        topo=novo;
    }
    Tamanho_pilha++;
}
//b)Remover um elemento da lista
int Remover_no_pilha(){
    PILHA * lixo = topo;
    int valor_Liberado = -1;
    if(Tamanho_pilha==1){
        topo=NULL;
    }
    else if(Tamanho_pilha>0){
        topo=topo->prox;
    }
    else if (Tamanho_pilha==0){
        printf("A pilha nao possui nos.");
    }
    valor_Liberado=lixo->valor;
    free(lixo);
    Tamanho_pilha--;
    return valor_Liberado;
//Apesar de o codigo da tati:Pilha, fazer apenas para Com elementos dentro da pilha(tam>0) ou pilha vazia(tam==0) eu preferi abordar todos os casos, ja que se mostrou um bom exercicio de logica.
}
//C) Imprimir os elementos da pilha
void Imprimir_pilha(){
    PILHA * aux = topo;
    while(aux != NULL){
        printf("Valor:%d\n",aux->valor);
        aux=aux->prox;
    }
}
//d) retornar o tamanho da pilha
int tam(){
    return Tamanho_pilha;
}
int main(){
    Add_no_pilha(1);
    Add_no_pilha(2);
    Add_no_pilha(3);
    Imprimir_pilha();
    printf("Tamanho da pilha:%d\n",tam());
    printf("\n");
    
    Remover_no_pilha();
    Remover_no_pilha();
    Imprimir_pilha();
    printf("Tamanho da pilha:%d\n",tam());
    

}