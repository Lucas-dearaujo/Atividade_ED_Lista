
#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    char n;
    struct no * prox;
}NO;
typedef struct pilha{
    struct no * topo;
    int tam;
}PILHA;

void desempilha(PILHA * p){
        NO * aux = p->topo;
        NO * lixo = p->topo;
            for(int i = p->tam; i > 0; i--){
                printf("%c", aux->n);
                aux = aux->prox;
                free(lixo);
                lixo = aux;
                p->tam--;
            }
            p->topo = NULL;
}
void empilha(PILHA * p , char n){
    NO * novo = malloc(sizeof(NO));
    novo->prox= NULL;
    novo->n= n;  
    if(p->topo == NULL){
        p->topo = novo;
    }
    else{
        novo->prox = p->topo;
        p->topo = novo;
        
    }
    p->tam++;
}

int main(){
    char temp;
    
    //1. Inicia a pilha na main
    PILHA * p = malloc(sizeof(PILHA));
    p->topo = NULL;
    p->tam = 0;
    printf("Digita ai\n"); 
  
  //2. recebe caracteres ate dar enter.
  do
  {
    temp = getchar();
  
    if(temp != 'a' && temp != '\n' && temp != 'e' && temp != '\n' && temp != 'i' && temp != '\n' && temp != 'o' && temp != '\n' && temp != 'u' && temp != '\n'){
        empilha(p, temp);
    }
    else if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o'  || temp == 'u'){
           desempilha(p);
            printf("%c", temp);
    }
    else{
    desempilha(p);
    }
  }while(temp != '\n');
 
}   
        //Testes: acbda = adbca
        //bacagdf = bacafdg   
