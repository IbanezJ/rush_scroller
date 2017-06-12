/*
** framebuffer.h for bs in /home/ibanez_j/bsraytracer1
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Wed Feb  8 11:24:51 2017 Jean-Alexandre IBANEZ
** Last update Mon Jun 12 10:52:09 2017 Jean-Alexandre IBANEZ
*/

#ifndef FRAMEBUFFER_H_
# define FRAMEBUFFER_H_

# define GROUND (0)
# define BACK (1)
# define EARTH (2)
# define SHIP (3)
# define LFIRE (4)
# define LASER (5)
# define PAUSE (6)
# define TAKE (7)
# define BACK2 (8)
# define GROUND2 (9)
# define LASER2 (10)
# define LFIRE2 (11)
# define SCREEN_WIDTH (1920)
# define SCREEN_HEIGHT (1080)

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Window/Export.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>

typedef struct	s_dialog
{
  sfFont	*font;
  sfText	*text;
  sfClock	*clk;
}		t_dialog;

typedef struct  s_my_framebuffer
{
  sfUint8*      pixels;
  int           width;
  int           height;
}		t_my_framebuffer;

void			keyboard_hdl(sfSprite **sprites, sfTexture **textures,
				     sfRenderWindow *window);
void			my_framebuffer_destroy(t_my_framebuffer *framebuffer);
void			destroying_graph(sfSprite **sprites,
					 sfTexture **textures);
sfTexture		**init_textures(sfTexture **textures);
sfSprite		**init_sprites(sfSprite **sprites,
				       sfTexture **textures);
sfVector2f		*init_puts(sfVector2f *puts);
void			initial_pos(sfSprite **sprites, sfVector2f *puts,
				    sfVector2f *set);
void			action_loop(sfSprite **sprites, sfRenderWindow *window,
				    sfVector2f *set, sfVector2u size);
int			window_loop(sfRenderWindow *window,
				    sfTexture **texture, sfSprite **sprites);
void			my_put_pixel(t_my_framebuffer* framebuffer, int x,
				     int y, sfColor color);
t_my_framebuffer	*my_framebuffer_create (int width, int height);
void			my_framebuffer_destroy(t_my_framebuffer *framebuffer);
void			menu_loop(sfRenderWindow *window);
void			mouse_actions(sfTexture **textures,
				      sfRenderWindow *window);
void			play_music(char *music_name);
void			before_loop(sfSprite **sprites, sfVector2f *puts,
				    sfRenderWindow *window, sfVector2f *set);

void			dialog(char *, sfRenderWindow *, t_dialog);

#endif
