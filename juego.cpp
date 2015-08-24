#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


enum GAME_KEYS
{
    KEY_LEFT,
    KEY_RIGHT,
    KEY_UP,
    KEY_DOWN,
    KEY_W,
    KEY_A,
    KEY_S,
    KEY_D
};

ALLEGRO_DISPLAY *display; /* muestra la ventana */
ALLEGRO_EVENT_QUEUE *event_queue; /* creamos variable para guaradar eventos */
ALLEGRO_TIMER *timer;
ALLEGRO_BITMAP *mi_sprite;
ALLEGRO_BITMAP *mi_sprite2;
ALLEGRO_BITMAP *mi_sprite3;
ALLEGRO_BITMAP *mi_sprite4;

int key[] = {false, false, false, false };
int key2[] = {0, 0, 0, 0};
int playerX = 0;
int playerY = 0;

int player2X = 150;
int player2Y = 150;

int main(int argc, char *argv[]) {
    {
	int redraw = 1;

	al_init(); /* inicia el allegro */
	al_init_image_addon();

	al_install_keyboard ();

	display = al_create_display(1640, 1480);; /*crea la ventana */

	event_queue = al_create_event_queue(); /*reservamos memoria para la variable */
	timer = al_create_timer(1.0 / 60);

	mi_sprite4 = al_load_bitmap("forest.png");


	mi_sprite = al_load_bitmap("ratoncito.png");
	al_convert_mask_to_alpha(mi_sprite, al_map_rgb(255, 255, 255));

	mi_sprite2 = al_load_bitmap("rantocito2.png");
	al_convert_mask_to_alpha(mi_sprite2, al_map_rgb(255, 255, 255));

	mi_sprite3 = al_load_bitmap("queso.png");
	al_convert_mask_to_alpha(mi_sprite3, al_map_rgb(255, 255, 255));



	al_register_event_source(event_queue, al_get_display_event_source(display)); /* aqui decimos donde queremos registrar los eventos */

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);

	al_clear_to_color(al_map_rgb(0, 0, 0));  /* ponemos la ventana del color que queramos */

	al_flip_display(); /* actualiza la pantalla continuamente */

	while (1)
	{
	    ALLEGRO_EVENT event; /* aqui recibiremos los eventos */
	    al_wait_for_event(event_queue, &event); /* aqui se espera hasta recibir los eventos */

	    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		break; /* cuando pulsemos la cruzecita roja el juego se cerrara */

	    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
	    {
		if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
		    key[KEY_LEFT] = true;

		if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
		    key[KEY_RIGHT] = true;

		if (event.keyboard.keycode == ALLEGRO_KEY_UP)
		    key[KEY_UP] = true;

		if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
		    key[KEY_DOWN] = true; 
	    }

	    if (event.type == ALLEGRO_EVENT_KEY_UP)
	    {
		if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
		    key[KEY_LEFT] = false;

		if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
		    key[KEY_RIGHT] = false;

		if (event.keyboard.keycode == ALLEGRO_KEY_UP)
		    key[KEY_UP] = false;

		if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
		    key[KEY_DOWN] = false;
	    }

	    if (event.type == ALLEGRO_EVENT_KEY_UP)
	    {

		if (event.keyboard.keycode == ALLEGRO_KEY_A)
		    key[KEY_A] = 0;

		if (event.keyboard.keycode == ALLEGRO_KEY_D)
		    key[KEY_D] = 0;

		if (event.keyboard.keycode == ALLEGRO_KEY_W)
		    key[KEY_W] = 0;

		if (event.keyboard.keycode == ALLEGRO_KEY_S)
		    key[KEY_S] = 0;
	    } 		    

	    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
	    {
		if (event.keyboard.keycode == ALLEGRO_KEY_A)
		    key[KEY_A] = 1;

		if (event.keyboard.keycode == ALLEGRO_KEY_D)
		    key[KEY_D] = 1;

		if (event.keyboard.keycode == ALLEGRO_KEY_W)
		    key[KEY_W] = 1;

		if (event.keyboard.keycode == ALLEGRO_KEY_S)
		    key[KEY_S] = 1;
	    } 
	    if (event.type == ALLEGRO_EVENT_TIMER)
	    {
		if (key[KEY_LEFT])
		    playerX -= 4;
		if (key[KEY_RIGHT])
		    playerX += 4;
		if (key[KEY_UP])
		    playerY -= 4;
		if (key[KEY_DOWN])
		    playerY += 4;

		if (key[KEY_A])
		    player2X -= 4;
		if (key[KEY_D])
		    player2X += 4;
		if (key[KEY_W])
		    player2Y -= 4;
		if (key[KEY_S])
		    player2Y += 4;

		redraw = 1;
	    }

	    if (redraw)
	    {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(mi_sprite4, 0, 0, 0);
		al_draw_bitmap(mi_sprite3, rand() % 200, rand() % 200, 0);
		 al_draw_bitmap(mi_sprite2, player2X, player2Y, 0);
		al_draw_bitmap(mi_sprite, playerX, playerY, 0);

		al_flip_display();

		redraw = 0;
	    }   

	}
	al_destroy_display(display); /* libera la memoria guardada */ 
	al_destroy_event_queue(event_queue); /* liberamos la memoria de los eventos */
	al_destroy_timer(timer);
	al_destroy_bitmap(mi_sprite);
	al_destroy_bitmap(mi_sprite2);
	al_destroy_bitmap(mi_sprite3);
	al_destroy_bitmap(mi_sprite4);

	return 0;

    }
    return EXIT_SUCCESS;
}
