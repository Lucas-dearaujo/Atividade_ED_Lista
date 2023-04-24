#include<stdio.h>
#include<stdlib.h>
 int calc(char teste[25]){
    int numero= 0;
    int numero_2=0;
    int resultado_1=0;
    int resultado_2=0;
    int fim;
    
    for(int j=0; teste[j] != '\0' ; j++){
        if(teste[j]>= 48 && teste[j] <= 57){
            if(numero == 0){
                numero = teste[j]- '0';
            }
            else if(numero > 0){
                numero_2 = teste[j]- '0';
            }
        }
        else if (teste[j] >= 42 && teste[j] <= 47){
        
        switch(teste[j]){
        case '+':
            if (resultado_1 == 0){
            resultado_1= numero+numero_2;
            numero=0;
            numero_2=0;
            }
            else if (resultado_1 != 0 && !(teste[j+1] == '\0')){
            resultado_2= numero+numero_2;
            numero=0;
            numero_2=0;
            }
          
            if (teste[j+1] == '\0'){
                fim = resultado_1+resultado_2;  
            }
            break;
        case '-':
            if (resultado_1 == 0){
            resultado_1= numero-numero_2;
            numero=0;
            numero_2=0;
            }
            else if (resultado_1 != 0 && !(teste[j+1] == '\0')){
            resultado_2= numero-numero_2;
            numero=0;
            numero_2=0;
            }
          
            if (teste[j+1] == '\0'){
                fim = resultado_1-resultado_2;  
            }
            break;
        case '*':
            if (resultado_1 == 0){
            resultado_1= numero*numero_2;
            numero=0;
            numero_2=0;
            }
            else if (resultado_1 != 0 && !(teste[j+1] == '\0')){
            resultado_2= numero*numero_2;
            numero=0;
            numero_2=0;
            }
          
            if (teste[j+1] == '\0'){
                fim = resultado_1*resultado_2;  
            }
            break;    
         case '/':
            if (resultado_1 == 0){
            resultado_1= numero/numero_2;
            numero=0;
            numero_2=0;
            }
            else if (resultado_1 != 0 && !(teste[j+1] == '\0')){
            resultado_2= numero/numero_2;
            numero=0;
            numero_2=0;
            }
          
            if (teste[j+1] == '\0'){
                fim=resultado_1/resultado_2;  
            }
            break;   
            
            default:
            break;
        }   
        }
    }
    return fim;
 }
 
 int main(){
    char teste [25];
    char c;
    int i= 0;
 printf("Calculadora pos-fixada.\nOBS:limitado a  no minimo e maximo 3 operacoes e 4 numeros, menos ou mais que isso nao funciona.\nEx:input 1 2 - 4 5 + *\nDigite uma operacao, e aperte enter para retornar o valor.\n.");
    do {
        c=getchar();
        teste[i]=c;
        i++;
    }while(c != '\n');
    teste[i-1]='\0';   
    printf("%s =",teste);
    printf(" %d", calc(teste));
    return 0;
    
}

