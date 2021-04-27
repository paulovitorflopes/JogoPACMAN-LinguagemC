#include <allegro.h>'
#include "teclado.h"

 volatile int exit_program;
 void fecha_programa(){exit_program = TRUE;}
 END_OF_FUNCTION(fecha_programa)

int main()
{
	// Inicializa a biblioteca Allegro
	allegro_init();
	install_keyboard();
	install_timer();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
	set_window_title("Projeto AED - PACMAN");

	exit_program = FALSE;
	LOCK_VARIABLE(exit_program);
	LOCK_FUNCTION(fecha_programa);
    set_close_button_callback(fecha_programa);


    // BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* lab = load_bitmap("pacman_multi_agent.bmp", NULL);
    BITMAP* pacman = load_bitmap("pac-man.bmp", NULL);
    BITMAP* bola = load_bitmap("bola.bmp", NULL);

    // VARIÁVEIS
    int i,j;
    int set_i=0,set_j=0;
    int passos=0;
    int matriz[18][33];

    // GAME LOOP
	while(!exit_program)
	{
     // INPUT ENTRADA DE TECLADO, MOUSE
     keyboard_input();

     if(key[KEY_ESC]){
     fecha_programa();
     }

     if(apertou(KEY_UP)){
     passos++;
     set_i--;}
     else if(apertou(KEY_DOWN)){
     set_i++;
     passos++;}
     else if(apertou(KEY_LEFT)){
     set_j--;
     passos++;}
     else if(apertou(KEY_RIGHT)){
     set_j++;
     passos++;}

     // update controle das variáveis do jogo

     if(set_i>16)
     set_i=16;
     else if(set_j>31)
     set_j=31;
     else if (set_i<1)
     set_i=1;
     else if (set_j<1)
     set_j=1;
     //else if ((set_j>7&&set_j<10) && (set_i<5))
     //set_j=10;
     else if ((set_j>7&&set_j<10) && (set_i<5))
     set_j=7;
     //else if(set_i<5 && (set_j==8||set_j==9))
     //set_i=5;
    //else if(set_j>2 && set_j<6 && set_i>3 && set_i<8)
//set_j=2;

else if( (set_i+1) &&set_j ==3 && set_i>3&&set_i<7)
set_j = 2;
else if((set_j+1) &&set_j==4 && set_i>3 && set_i<7)
set_j=4;

else if(set_i>3 && set_i<5 && (set_j==4||set_j==5))
set_j=4;

//else if (set_j>2 && set_i>10 && set_i<15)
//set_j=2;

     // Draw desenhar na tela
     draw_sprite(buffer,lab,10,20);
        for (i=0 ; i<18 ; i++)
     {
        for(j=0 ; j<33 ; j++)

            rect(buffer ,20+j*20 , 20+i*20 , 20+j*20+20 ,20+i*20+20, makecol(255,0,255));


     }
    textprintf_ex(buffer, font,100, 400,makecol(255,255,0),-1, "NUMERO DE PASSOS:%d",passos );
    draw_sprite(buffer,bola,640,345);
    draw_sprite(buffer,pacman,20 + set_j* 20,20 + set_i* 20);

    //rectfill(buffer ,20 + set_j* 20 , 20 + set_i* 20 , 20 + set_j * 20 + 20 ,20 + set_i * 20 + 20, makecol(255,0,0));

     // texto printf

	draw_sprite(screen, buffer,0,0);
    clear(buffer);
	}

 // finalização
    destroy_bitmap(pacman);
    destroy_bitmap(lab);
    destroy_bitmap(buffer);
    destroy_bitmap(bola);
    return 0;
    }
END_OF_MAIN();


