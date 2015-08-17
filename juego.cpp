#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

ALLEGRO_DISPLAY *display; /* muestra la ventana */
ALLEGRO_EVENT_QUEUE *event_queue; /* creamos variable para guaradar eventos */

int main(int argc, char *argv[]) {
    {

    al_init(); /* inicia el allegro */
    display = al_create_display(1640, 1480); /*crea la ventana */

    event_queue = al_create_event_queue(); /*reservamos memoria para la variable */
    al_register_event_source(event_queue, al_get_display_event_source(display)); /* aqui decimos donde queremos registrar los eventos */

 al_clear_to_color(al_map_rgb(50, 50, 50)); /* ponemos la ventana del color que queramos */

    al_flip_display(); /* actualiza la pantalla continuamente */

    while (1)
    {
	ALLEGRO_EVENT event; /* aqui recibiremos los eventos */
	al_wait_for_event(event_queue, &event); /* aqui se espera hasta recibir los eventos */

	if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	    break; /* cuando pulsemos la cruzecita roja el juego se cerrara */
	
	al_clear_to_color(al_map_rgb(50, 50,50));
	al_flip_display();

    }
   

    al_destroy_display(display); /* libera la memoria guardada */ 
   al_destroy_event_queue(event_queue); /* liberamos la memoria de los eventos */

    return 0;
    }    

	return EXIT_SUCCESS;
}
