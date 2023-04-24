#include<stdio.h>
#include<stdlib.h>
typedef struct fila{
    int valor;
    struct fila * prox;
}FILA;

int tam = 0 ;
FILA * maior = NULL;
FILA * inicio = NULL ;
FILA * fim = NULL;

//a) Adicionar um elemento na fila;
void Add_Nao_ordenada(int valor){
    FILA * novo = malloc(sizeof(FILA));
    novo->prox = NULL;
    novo->valor=valor;
    if(inicio == NULL){
        inicio = novo;
        fim = novo;
    }
    else{
        fim->prox = novo;
        fim = novo;
    }
    tam++;

}
//b) Remover um elemento da fila;
void recursao(FILA * aux ){
        if(aux->prox == NULL){
            maior = aux;
        }
        else{
             recursao(aux->prox);
                if(aux->valor > maior->valor){
                    maior = aux;
                }

        }
}
int remover_Nao_ordenada(){
        FILA * lixo;
        if(tam == 1){
            lixo=inicio;
            inicio = NULL;
            fim = NULL;
        }
        else if(maior == NULL){
             recursao(inicio);
                if(maior->valor == inicio->valor){
                    inicio=inicio->prox;
                }
                //Podia ter usado fila dupla encadeada pra não ter que dar esse loop? podia, o problema de fazer o codigo do zero é so perceber isso quando ele ja ta mais da metade feito, e a questão 5 me destruiu entao estou sem energia pra isso.
                else if(maior->valor == fim->valor){
                    FILA * aux = inicio;
                    while(aux->prox != fim){
                        aux=aux->prox;
                    }
                    fim = aux;
                }
                
                else{
                    FILA * aux = inicio;
                    while(aux->prox->valor != maior->valor){
                    aux=aux->prox;
                    }
                    aux->prox = maior->prox;
                }
                lixo=maior;
                maior=NULL;
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
    Add_Nao_ordenada(3);
    Add_Nao_ordenada(10);
    Add_Nao_ordenada(8);
    Add_Nao_ordenada(20);
    Add_Nao_ordenada(15);
    imprimir();
    printf("tam = %d\n", tam);
    printf("\n");
    
    
    remover_Nao_ordenada();
    imprimir();
    
    
    
}