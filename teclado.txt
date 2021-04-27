#include "teclado.h"

void keyboard_input(){

    int i;

    for(i=0;i< KEY_MAX ;i++) // PERCORRER TODAS AS TECLAS DO TECLADO
    teclas_anteriores[i]=key[i];

    poll_keyboard(); // ATUALIZAR O ESTADO DO TECLADO
}
int apertou(int TECLA){

    return(key[TECLA] == TRUE && teclas_anteriores[TECLA] == FALSE);

}
int segurou(int TECLA){

    return(key[TECLA] == TRUE && teclas_anteriores[TECLA] == TRUE);

}
int soltou(int TECLA){

    return(key[TECLA] == FALSE && teclas_anteriores[TECLA] == TRUE);

}
