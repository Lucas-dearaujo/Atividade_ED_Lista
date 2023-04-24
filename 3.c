#include<stdio.h>
#include<stdlib.h>
typedef struct pilha_A
{
    int caixa;
    struct pilha_A * prox;
}A;

int Tamanho_A=0;
A * topo_a= NULL;

void recursao(A * topo, A * caixa_nova){
    if(caixa_nova->caixa <= topo->caixa || topo->prox == NULL ){
      topo->prox=caixa_nova;
      topo_a=topo;
    }
    else{
        recursao(topo->prox, caixa_nova);
        topo->prox=topo_a;
        topo_a=topo;
    }
}

void Add_in_Pilha_main(int caixa){
    A * novo = malloc(sizeof(A));
    novo->prox=NULL;
    novo->caixa=caixa;
    
    if(Tamanho_A == 0){
        topo_a=novo;
    }
    else if (Tamanho_A > 0 && novo->caixa > topo_a->caixa){
        recursao(topo_a, novo);
    }
    else{
        novo->prox=topo_a;
        topo_a=novo;
    }
    Tamanho_A++;
}

void imprimir(){
    A * aux=topo_a;
    while (aux != NULL){
       printf("Caixa:%d\n",aux->caixa);
       aux=aux->prox;
    }
    
}

int main(){
  Add_in_Pilha_main(5);
  Add_in_Pilha_main(7);
  Add_in_Pilha_main(5);
  Add_in_Pilha_main(7);
  imprimir();
}
