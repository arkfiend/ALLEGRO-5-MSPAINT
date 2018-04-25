#include "dll.c"
#define xTela 800
#define yTela 600
#define cores 8

int main(){

  al_init();                    // Inicializa os addons     
  al_init_primitives_addon();   // Habilita a criação de retângulos, triângulos...              
  al_install_mouse();           // Habilita a interação com o mouse    
  al_install_keyboard();        // Habilita o teclado
  al_init_image_addon();        // Habilita adição de imagens
  
  ALLEGRO_BITMAP *eraser=al_load_bitmap("db//eraser.png");    // Foto da borracha
  ALLEGRO_DISPLAY *display = al_create_display(xTela, yTela); // Tela que será usada
  
  int cor[cores][3];
  cor[0][0]=0;    cor[0][1]=0;    cor[0][2]=255;  // Azul
  cor[1][0]=255;  cor[1][1]=255;  cor[1][2]=255;  // Branco
  cor[2][0]=0;    cor[2][1]=0;    cor[2][2]=0;    // Preto
  cor[3][0]=92;   cor[3][1]=51;   cor[3][2]=23;   // Marrom
  cor[4][0]=255;  cor[4][1]=0;    cor[4][2]=255;  // Rosa
  cor[5][0]=255;  cor[5][1]=255;  cor[5][2]=0;    // Amarelo
  cor[6][0]=255;  cor[6][1]=165;  cor[6][2]=0;    // Laranja
  cor[7][0]=0;    cor[7][1]=255;  cor[7][2]=0;    // Verde
  cor[8][0]=255;  cor[8][1]=0;    cor[8][2]=0;    // vermelho
  
  
  int corSelecionada=2;  // Cor que está sendo usada pelo usuário
  int pos_x; int pos_y;  // Posição x e y do mouse nesse isntante
  int clique=0;          // Saber se segurou o botão esquerdo do mouse ou não
  int x=1;               // Apenas variável do loop
  int size=10;            // Largura do ponteiro
  
  ALLEGRO_EVENT_QUEUE *fila= al_create_event_queue();             // Cria fila de eventos que serão pegos
  al_register_event_source(fila, al_get_keyboard_event_source()); // Recebe eventos referente do teclado
  al_register_event_source(fila, al_get_mouse_event_source());    // Recebe eventos referente do mouse
  
  
  al_clear_to_color(al_map_rgb(255,255,255));                            // Desenhar o fundo branco
  al_draw_filled_rectangle(720, 3, 797, 597, al_map_rgb(168, 168, 168)); // Quadro cinza "3D"
  
  //Quadro de cores
  al_draw_filled_rectangle(725, 8, 792, 38, al_map_rgb(0, 0, 255));      // Azul     - cor 0
  al_draw_filled_rectangle(725, 43, 792, 73, al_map_rgb(255, 255, 255)); // Branco   - cor 1
  al_draw_filled_rectangle(725, 78, 792, 108, al_map_rgb(0, 0, 0));      // Preto    - cor 2 
  al_draw_filled_rectangle(725, 113, 792, 143, al_map_rgb(92, 51, 23));  // Marrom   - cor 3 
  al_draw_filled_rectangle(725, 148, 792, 178, al_map_rgb(255, 0, 255)); // Rosa     - cor 4 
  al_draw_filled_rectangle(725, 183, 792, 213, al_map_rgb(255, 255, 0)); // Amarelo  - cor 5
  al_draw_filled_rectangle(725, 218, 792, 248, al_map_rgb(255, 165, 0)); // Laranja  - cor 6
  al_draw_filled_rectangle(725, 253, 792, 283, al_map_rgb(0, 255, 0));   // Verde    - cor 7  
  al_draw_filled_rectangle(725, 288, 792, 318, al_map_rgb(255, 0, 0));   // Vermelho - cor 8 
  
  
  //////////////////////////////////////////////////////////////////// //////////////// LOOP /////////////////////////////////////////////
  al_draw_bitmap(eraser, 738, 323, 0); //DESENHA - borracha                                                                             //
  while (x==1){                                                                                                                         //
    ALLEGRO_EVENT eventoAtual;                                                                                                          //
    al_wait_for_event(fila, &eventoAtual);                                                                                              //
                                                                                                                                        //
    // Esc para sair                                                                                                                    //
    if (eventoAtual.type==ALLEGRO_EVENT_KEY_DOWN){                                                                                      //
      if (eventoAtual.keyboard.keycode==ALLEGRO_KEY_ESCAPE){                                                                            //
        return 1;                                                                                                                       //
      }                                                                                                                                 //
    }                                                                                                                                   //
                                                                                                                                        //
    // Apenas para detectar onde o mouse esta na tela                                                                                   //
    if (eventoAtual.type==ALLEGRO_EVENT_MOUSE_AXES){                                                                                    //
      pos_x=eventoAtual.mouse.x;                                                                                                        //
      pos_y=eventoAtual.mouse.y;                                                                                                        //
    }                                                                                                                                   //
                                                                                                                                        //
    // Ver se apertou o mouse                                                                                                           //
    if (eventoAtual.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){                                                                             //
      clique=1;                                                                                                                         //
                                                                                                                                        //
      // Ver se está clicando em uma cor                                                                                                //
      if (eventoAtual.mouse.x>=725 && eventoAtual.mouse.y>=8){                                                                          //
        if (eventoAtual.mouse.y<=38){                                                                                                   //
          corSelecionada=0;                                                                                                             //
        }else if(eventoAtual.mouse.y<=73){                                                                                              //
          corSelecionada=1;                                                                                                             //
        }else if(eventoAtual.mouse.y<=108){                                                                                             //
          corSelecionada=2;                                                                                                             //
        }else if(eventoAtual.mouse.y<=143){                                                                                             //
          corSelecionada=3;                                                                                                             //
        }else if(eventoAtual.mouse.y<=178){                                                                                             //
          corSelecionada=4;                                                                                                             //
        }else if(eventoAtual.mouse.y<=213){                                                                                             //
          corSelecionada=5;                                                                                                             //
        }else if(eventoAtual.mouse.y<=248){                                                                                             //
          corSelecionada=6;                                                                                                             //
        }else if(eventoAtual.mouse.y<=283){                                                                                             //
          corSelecionada=7;                                                                                                             //
        }else if(eventoAtual.mouse.y<=318){                                                                                             //
          corSelecionada=8;                                                                                                             //
        }                                                                                                                               //
        size=3;                                                                                                                         //
      }                                                                                                                                 //
                                                                                                                                        //
      // Ver se está usando a borracha - 47x34                                                                                          //
      if (eventoAtual.mouse.x>=738 && eventoAtual.mouse.x<=785 && eventoAtual.mouse.y>=323 && eventoAtual.mouse.y<=357){                //
        size=10; corSelecionada=1;                                                                                                      //
      }                                                                                                                                 //
    }                                                                                                                                   //
                                                                                                                                        //
    // Ver se soltou o mouse                                                                                                            //
    if (eventoAtual.type==ALLEGRO_EVENT_MOUSE_BUTTON_UP){                                                                               //
      clique=0;                                                                                                                         //
    }                                                                                                                                   //
                                                                                                                                        //
    // Apenas se clicar, desenhe o pixel.                                                                                               //
    if (clique==1 && pos_x < 720-size){                                                                                                 //
      //al_draw_pixel(pos_x, pos_y, al_map_rgb(255, 255, 255));                                                                         //
      al_draw_filled_circle(pos_x, pos_y, size, al_map_rgb(cor[corSelecionada][0], cor[corSelecionada][1], cor[corSelecionada][2]));    //
    }                                                                                                                                   //
                                                                                                                                        //
    al_flip_display();                                                                                                                  //
  }                                                                                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  al_destroy_display(display);
  return 0;
}
