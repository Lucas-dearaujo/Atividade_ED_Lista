#include<stdio.h>
#include<stdlib.h>
 typedef struct fila{
    char ch;
    struct fila * prox;
    struct fila * ant;    
 }F_D;
 F_D  * inicio = NULL;
 F_D  * fim = NULL;
 
 int tam=0;
 
 void add_pilha(char n){
    F_D * novo = malloc(sizeof(F_D));
    novo->ch=n;
    novo ->prox =NULL;
    novo->ant=NULL;

    if(tam == 0){
        inicio= novo;
        fim = novo;
    }
    else{
        novo->ant=fim;
        fim->prox = novo;
        fim = novo;

       //bcd
       //dcb
       //NULL <- bcda 
    }
    tam++;

}
void imprimir(){
    F_D * aux = inicio;
    F_D * aux2;
    // 97 101 105 111 117
    while(aux != NULL){
            if(aux-> ch == 97 || aux-> ch == 101 || aux-> ch == 105 || aux-> ch == 111 || aux-> ch == 117){
              printf("%c" , aux->ch);
              aux=aux->prox;
            }
            else if(aux->prox->ch == 97 || aux->prox->ch == 101 || aux->prox->ch == 105 || aux->prox->ch == 111 || aux->prox->ch == 117){
              printf("%c" , aux->ch);
              aux=aux->prox;
            }
            else{
            
            for(aux2= aux; aux2->prox != NULL;){       
                  if(aux2->prox->ch != 97 && aux2->prox->ch != 101 && aux2->prox->ch != 105 && aux2->prox->ch != 111 && aux2->prox->ch != 117){
                  aux2=aux2->prox; 
                  }
              else{
                break;
              }   
            }
            aux=aux2;
            for(aux2= aux; aux->ant != NULL;){
                  if(aux2->ch != 97 && aux2->ch != 101 && aux2->ch != 105 && aux2->ch != 111 && aux2->ch != 117){
                  printf("%c" , aux2->ch);
                  aux2=aux2->ant;
                  }
                  else{
                    break;
                  }   
            }
          }
          }
  }
          
        //Testes: Input acbda = adbca       
 int main(){
    char c;
    printf("Algoritmo de Criptografia.\nVogais sao exibidas normais, Consoantes consecutivas sao retornadas na ordem inversa\nDigite uma string e aperte enter para finalizar.\n");
    do {
        c=getchar();
        if(c != '\n'){
        add_pilha(c);
    }
    }while(c != '\n');
    imprimir();
 }
