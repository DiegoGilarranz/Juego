#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>

ALLEGRO_DISPLAY *display; 

int main(int argc, char *argv[]) {
    {
    al_init();

    display = al_create_display(1640, 1480);
    al_clear_to_color(al_map_rgb(150, 150, 150));   

    al_flip_display();
    al_rest(4.0);

    al_destroy_display(display);

    

   

    return 0;
    }    

	return EXIT_SUCCESS;
}
