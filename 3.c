#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int peso;
    struct no * prox;
}NO;
typedef struct pilha{
    struct no * topo;
    int tam;
}PILHA;

PILHA * inicia(){
    PILHA * p = malloc(sizeof(PILHA));
    p->tam = 0;
    p->topo = NULL;
    return p;
}
void add(PILHA * pA, int peso){
    NO * novo = malloc(sizeof(NO));
    novo->prox = NULL;
    novo->peso = peso;
        if(pA->topo == NULL){
            pA->topo = novo;
        }
        else if(pA->topo->peso < peso){
            PILHA * pC = inicia();
            PILHA * pB = inicia();
            while(pA->topo != NULL){
                if(pA->topo->peso == novo->peso){
                    novo->prox = pA->topo;
                    pA->topo= novo;
                    break;
                }
                if(pA->topo->peso==3){
                   if(pC->topo == NULL){
                        pC->topo = pA->topo;
                        pA->topo = pA->topo->prox;
                        pC->topo->prox = NULL;
                   }
                   else if(pC->tam > 0){
                       NO * aux = pA->topo->prox;
                       pA->topo->prox = pC->topo;
                       pC->topo = pA->topo;
                       pA->topo = aux;
                   }
                pA->tam--;
                pC->tam++;
                }
                else if(pA->topo->peso==5){
                   if(pB->topo == NULL){
                        pB->topo = pA->topo;
                        pA->topo = pA->topo->prox;
                        pB->topo->prox = NULL;
                   }
                    else if(pB->tam > 0){
                        NO * aux = pA->topo->prox;
                        pA->topo->prox = pB->topo;
                        pB->topo = pA->topo;
                        pA->topo = aux;
                    }
                pA->tam--;
                pB->tam++;
                }
            }
            if(pA->topo == NULL){
                pA->topo = novo;
            }
            while(pB->tam > 0 && pC->tam > 0){
                if(pA->topo->peso >= 5){
                    NO * aux = pB->topo->prox;
                    pB->topo->prox = pA->topo;
                    pA->topo = pB->topo;
                    pB->topo = aux;
                    pB->tam--;
                    pA->tam++;
                }
                if(pA->topo->peso >=3 && pB->tam == 0){
                    NO * aux = pC->topo->prox;
                    pC->topo->prox = pA->topo;
                    pA->topo = pC->topo;
                    pC->topo = aux;
                    pC->tam--;
                    pA->tam++;   
                }
            }
        }
        else{
            novo->prox = pA->topo;
            pA->topo = novo;
        }
        pA->tam++;
}
void imprimir(PILHA * p){
    NO * aux = p->topo;
    while(aux != NULL){
        printf("%d\n" , aux->peso);
        aux = aux->prox;
    }
}
int main() {
    PILHA * pA = inicia();
    add(pA, 7);
    add(pA, 5);
    add(pA, 5);
    add(pA, 3);
    add(pA, 7);
    printf("\n\n");
    imprimir(pA);
    printf("Tamanho de pA :%d" , pA->tam);
}
