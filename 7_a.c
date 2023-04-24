#include<stdio.h>
#include<stdlib.h>
//Fila de pilhas
//Caso der erro inverter a ordem V
typedef struct fila {
    struct fila * prox_fila;
    struct pilha * topo;
}FILA;

typedef struct pilha{
    int value;
    struct pilha * prox_pilha;
    
}PILHA;

FILA * inicio = NULL;
FILA * fim= NULL;
int tam_fila = 0;

void Add_Valor_in_Pilha(int n){
    PILHA * novo_p = malloc(sizeof(PILHA));
    novo_p->value=n;
    novo_p->prox_pilha= NULL;

    if(inicio == NULL){
        FILA * novo_f = malloc(sizeof(FILA));
        novo_f->prox_fila= NULL;
        novo_f->topo=novo_p;
        inicio= novo_f;
        fim=novo_f;
        tam_fila++;
    }
    else if(fim->topo == NULL){
        fim->topo= novo_p;
    }
    else{
        novo_p->prox_pilha = fim->topo;
        fim->topo= novo_p;
    }
}

void imprimir(){
    FILA * aux_main = inicio;
    PILHA * aux = inicio->topo;
    for(int i = 0; i<tam_fila ; i++){
        while(aux!= NULL){
            printf("Valor dentro da pilha: %d\n" , aux->value);
            aux=aux->prox_pilha;
        }
        aux_main=aux_main->prox_fila;
        aux=aux_main->topo;
        printf("\n");
    }

}

void Add_Pilha_in_fila(){
        FILA * novo_f = malloc(sizeof(FILA));
        novo_f->topo = NULL;
        fim->prox_fila=novo_f;
        fim = novo_f;
        tam_fila++;
    }
int main(){
    Add_Valor_in_Pilha(1);
    Add_Valor_in_Pilha(2);
    Add_Valor_in_Pilha(3);
    Add_Valor_in_Pilha(4);
    Add_Pilha_in_fila();
    
    Add_Valor_in_Pilha(5);
    Add_Valor_in_Pilha(6);
    Add_Valor_in_Pilha(7);
    Add_Valor_in_Pilha(8);
    imprimir();

}