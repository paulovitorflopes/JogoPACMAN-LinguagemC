#ifndef TECLADO1_H_INCLUDED
#define TECLADO1_H_INCLUDED

void keyboard_input(){
    int i;
    for(i=0;i<KEY_MAX;i++) // PERCORRER TODAS AS TECLAS DO TECLADO
    teclas_anteriores[i]=key[i];

    poll_keyboard(); // ATUALIZAR O ESTADO DO TECLADO
}
int apertou(int TECLA){

    return(key[TECLA] == TRUE && teclas_anteriores == FALSE);

}
int segurou(int TECLA){

    return(key[TECLA] == TRUE && teclas_anteriores == TRUE);

}
int soltou(int TECLA){

    return(key[TECLA] == FALSE && teclas_anteriores == TRUE);

}

#endif // TECLADO1_H_INCLUDED
