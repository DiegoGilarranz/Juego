#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


ALLEGRO_DISPLAY *display; /* muestra la ventana */
ALLEGRO_EVENT_QUEUE *event_queue; /* creamos variable para guaradar eventos */
ALLEGRO_TIMER *timer;
ALLEGRO_BITMAP *mi_sprite;
ALLEGRO_BITMAP *mi_sprite2;
ALLEGRO_BITMAP *mi_sprite3;


int main(int argc, char *argv[]) {
    {
	int redraw = 1;

	al_init(); /* inicia el allegro */
	al_init_image_addon();

	display = al_create_display(1640, 1480); /*crea la ventana */

	event_queue = al_create_event_queue(); /*reservamos memoria para la variable */
	timer = al_create_timer(1.0 / 60);

	mi_sprite = al_load_bitmap("ratoncito.png");
	 al_convert_mask_to_alpha(mi_sprite, al_map_rgb(255, 255, 255));

	mi_sprite2 = al_load_bitmap("rantocito2.png");
	 al_convert_mask_to_alpha(mi_sprite2, al_map_rgb(255, 255, 255));
	 
	 mi_sprite3 = al_load_bitmap("queso.png");
	 al_convert_mask_to_alpha(mi_sprite3, al_map_rgb(255, 255, 255));



	al_register_event_source(event_queue, al_get_display_event_source(display)); /* aqui decimos donde queremos registrar los eventos */
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_start_timer(timer);

	al_clear_to_color(al_map_rgb(0, 0, 0));  /* ponemos la ventana del color que queramos */

	al_flip_display(); /* actualiza la pantalla continuamente */

	while (1)
	{
	    ALLEGRO_EVENT event; /* aqui recibiremos los eventos */
	    al_wait_for_event(event_queue, &event); /* aqui se espera hasta recibir los eventos */

	    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		break; /* cuando pulsemos la cruzecita roja el juego se cerrara */
	    if (event.type == ALLEGRO_EVENT_TIMER)
	    {
		redraw = 1;
	    }

	    if (redraw)
	    {
		al_clear_to_color(al_map_rgb(0, 0, 0));

		al_draw_bitmap(mi_sprite, 50, 50, 0);
		al_draw_bitmap(mi_sprite2, 500, 500, 0);
		al_draw_bitmap(mi_sprite3, 450, 200, 0);

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

	return 0;
    }    

    return EXIT_SUCCESS;
}
