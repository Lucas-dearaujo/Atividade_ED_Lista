#include<stdio.h>
#include<stdlib.h>
typedef struct fila{
    int valor;
    struct fila * prox_fila;
}FILA;
typedef struct pilha{
    struct fila * inicio_fila;
    struct fila * fim_fila;
    struct pilha * prox_pilha;
}PILHA;

PILHA * topo= NULL;
int tam_pilha=0;

void Add_Valor_in_fila(int parametro){
    FILA * novo_f = malloc(sizeof(FILA));
    novo_f->valor=parametro;
    novo_f->prox_fila=NULL;
        if(topo==NULL){
            PILHA * novo_p= malloc(sizeof(PILHA));
            novo_p->inicio_fila=novo_f;
            novo_p->fim_fila = novo_f;
            novo_p->prox_pilha=NULL;
            topo=novo_p;
            tam_pilha++;
        }
        else if(topo->inicio_fila==NULL && topo->fim_fila==NULL){
            topo->inicio_fila=novo_f;
            topo->fim_fila=novo_f;
        }
        else{
            topo->fim_fila->prox_fila=novo_f;
            topo->fim_fila=novo_f;
            
        }
    
}
void Add_Lista_in_pilha(){
    PILHA * novo_p=malloc(sizeof(PILHA));
    novo_p->inicio_fila=NULL;
    novo_p->fim_fila=NULL;
    novo_p->prox_pilha=topo;
    topo=novo_p;
    tam_pilha++;

}

void imprimir(){
    FILA * aux = topo->inicio_fila;
    PILHA * aux2=topo;
    for (int i = 0; i<tam_pilha; i++)
    {
       while(aux!=NULL){
        printf("Valor dentro da FILA: %d \n",aux->valor);
        aux=aux->prox_fila;
    }
    aux2=aux2->prox_pilha;
    aux=aux2->inicio_fila;
    
    printf("\n");
    
    }
    
}

int main (){
    Add_Valor_in_fila(1);
    Add_Valor_in_fila(2);
    Add_Valor_in_fila(3);
    Add_Lista_in_pilha();
    Add_Valor_in_fila(4);
    Add_Valor_in_fila(5);
    Add_Valor_in_fila(6);
    imprimir();
    

}