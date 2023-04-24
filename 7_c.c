#include<stdio.h>
#include<stdlib.h>
typedef struct fila_sec{
    int valor;
    struct fila_sec * prox_s;
}FILA_SEC;

typedef struct fila_main{
    struct fila_main * prox_m;
    
    struct fila_sec * inicio_s;
    struct fila_sec * fim_s;
} FILA_MAIN;

FILA_MAIN * inicio_main=NULL;
FILA_MAIN * fim_main=NULL;
int tamanho_main = 0 ;

void Add_Valor_in_fila(int value){
    FILA_SEC * novo_sec = malloc(sizeof(FILA_SEC));
    novo_sec->prox_s=NULL;
    novo_sec->valor=value;
    
    if(inicio_main == NULL){
        FILA_MAIN * novo_main = malloc(sizeof(FILA_MAIN));
        novo_main->prox_m = NULL;
        inicio_main= novo_main;
        fim_main= novo_main;
        
        novo_main->inicio_s = novo_sec;
        novo_main->fim_s = novo_sec;

        tamanho_main++;
    }
    else if(fim_main->inicio_s == NULL && fim_main->fim_s == NULL){
        fim_main->inicio_s = novo_sec;
        fim_main->fim_s = novo_sec;
    }
    else{
        fim_main->fim_s->prox_s= novo_sec;
        fim_main->fim_s= novo_sec;
    }

}

void Add_Fila_in_fila(){
    FILA_MAIN * novo_main = malloc(sizeof(FILA_MAIN));
    novo_main->inicio_s = NULL;
    novo_main->fim_s = NULL ;
    fim_main->prox_m = novo_main;
    fim_main = novo_main;
    tamanho_main++;
}
void imprimir(){
    FILA_MAIN * aux = inicio_main;
    FILA_SEC * aux2= inicio_main->inicio_s;
    for (int i = 0; i<tamanho_main; i++)
    {
       while(aux2!=NULL){
        printf("Valor dentro da FILA: %d \n",aux2->valor);
        aux2= aux2->prox_s;
    }
    aux=aux->prox_m;
    aux2= aux->inicio_s;
    printf("\n");
    }
    
}

int main(){
    Add_Valor_in_fila(10);
    Add_Valor_in_fila(20);
    Add_Valor_in_fila(30);
    Add_Valor_in_fila(40);
    Add_Fila_in_fila();

    Add_Valor_in_fila(50);
    Add_Valor_in_fila(60);
    Add_Valor_in_fila(70);
    Add_Valor_in_fila(80);
    imprimir();

}