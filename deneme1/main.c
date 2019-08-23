#include <stdio.h>
#include <stdlib.h>
#include<allegro.h>
int main()
{
   if (allegro_init() != 0)
      return 1;
   install_keyboard();
   if (set_gfx_mode(GFX_AUTODETECT, 320, 200, 0, 0) != 0) {
      if (set_gfx_mode(GFX_SAFE, 320, 200, 0, 0) != 0) {
    set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
    allegro_message("Unable to set any graphic mode\n%s\n", allegro_error);
    return 1;
      }
   }
   set_palette(desktop_palette);
   clear_to_color(screen, makecol(255, 255, 255));
   acquire_screen();
   textout_centre_ex(screen, font, "Hello, world!", SCREEN_W/2, SCREEN_H/2, makecol(0,0,0), -1);
   release_screen();
   readkey();
    return 0;
}

END_OF_MAIN()
