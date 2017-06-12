/*
** loop.c for scroller in /home/ibanez_j/parallax
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Sat Apr  1 05:11:44 2017 Jean-Alexandre IBANEZ
** Last update Mon Jun 12 10:53:04 2017 Jean-Alexandre IBANEZ
*/

#include <SFML/Audio.h>
#include <unistd.h>
#include "parallax.h"

extern sfVector2f	g_pos_mouse;
extern sfVector2f	temp_move;

void	draw_sprites(sfRenderWindow *window, sfSprite **sprites)
{
  sfRenderWindow_clear(window, sfBlack);
  sfRenderWindow_drawSprite(window, sprites[BACK], NULL);
  sfRenderWindow_drawSprite(window, sprites[BACK2], NULL);
  sfRenderWindow_drawSprite(window, sprites[EARTH], NULL);
  sfRenderWindow_drawSprite(window, sprites[LFIRE], NULL);
  sfRenderWindow_drawSprite(window, sprites[LFIRE2], NULL);
  sfRenderWindow_drawSprite(window, sprites[SHIP], NULL);
  sfRenderWindow_drawSprite(window, sprites[TAKE], NULL);
  sfRenderWindow_drawSprite(window, sprites[GROUND], NULL);
  sfRenderWindow_drawSprite(window, sprites[GROUND2], NULL);
  sfRenderWindow_drawSprite(window, sprites[LASER], NULL);
  sfRenderWindow_drawSprite(window, sprites[LASER2], NULL);
  sfRenderWindow_drawSprite(window, sprites[PAUSE], NULL);
  sfRenderWindow_display(window);
}

void	move_sprites(sfVector2f *dircs, sfSprite **sprites)
{
  sfVector2f	pos_ship;
  sfVector2f	scale;

  scale = sfSprite_getScale(sprites[EARTH]);
  pos_ship = sfSprite_getPosition(sprites[SHIP]);
  if (!(pos_ship.x >= g_pos_mouse.x - 5 && pos_ship.y <= g_pos_mouse.y + 5 &&
       pos_ship.y >= g_pos_mouse.y - 5 && pos_ship.y <= g_pos_mouse.y + 5))
    {
      sfSprite_move(sprites[SHIP], temp_move);
      sfSprite_move(sprites[LFIRE], temp_move);
      sfSprite_move(sprites[LFIRE2], temp_move);
    }
  sfSprite_move(sprites[LASER2], dircs[4]);
  sfSprite_move(sprites[LASER], dircs[4]);
  sfSprite_move(sprites[BACK], dircs[1]);
  sfSprite_move(sprites[BACK2], dircs[1]);
  sfSprite_move(sprites[GROUND], dircs[0]);
  sfSprite_move(sprites[GROUND2], dircs[0]);
  if (scale.x != (float)0.3)
    sfSprite_move(sprites[EARTH], dircs[2]);
}

void	set_position(sfVector2u size, sfSprite **sprites,
		     sfVector2f *set, sfVector2f *positions)
{
  if (positions[0].x == -(int)size.x)
    sfSprite_setPosition(sprites[BACK], set[0]);
  if (positions[1].x == -(int)size.x)
    sfSprite_setPosition(sprites[BACK2], set[0]);
  if (positions[3].x == -(int)size.x)
    sfSprite_setPosition(sprites[GROUND2], set[1]);
  if (positions[2].x == -(int)size.x)
    sfSprite_setPosition(sprites[GROUND], set[1]);
  positions[2] = sfSprite_getPosition(sprites[EARTH]);
  if (positions[2].x == -200)
    {
      positions[2].x = SCREEN_WIDTH + 200;
      positions[2].y = SCREEN_HEIGHT;
      sfSprite_setPosition(sprites[EARTH], positions[2]);
    }
}

void	action_loop(sfSprite **sprites, sfRenderWindow *window,
		    sfVector2f *set, sfVector2u size)
{
  sfVector2f	positions[4];
  sfVector2f	dircs[4];

  dircs[4].x = 10;
  dircs[4].y = 0;
  dircs[2].x = -0.5;
  dircs[2].y = -0.3;
  dircs[1].x = -0.5;
  dircs[1].y = 0;
  dircs[0].x = -10;
  dircs[0].y = 0;
  move_sprites(dircs, sprites);
  positions[2] = sfSprite_getPosition(sprites[GROUND]);
  positions[3] = sfSprite_getPosition(sprites[GROUND2]);
  positions[0] = sfSprite_getPosition(sprites[BACK]);
  positions[1] = sfSprite_getPosition(sprites[BACK2]);
  set_position(size, sprites, set, positions);
  usleep(5000);
  draw_sprites(window, sprites);
}

int		window_loop(sfRenderWindow *window, sfTexture **textures,
			    sfSprite **sprites)
{
  sfVector2f	*puts;
  sfVector2f	set[2];
  sfVector2u	size;
  sfEvent	event;

  size = sfTexture_getSize(textures[BACK]);
  puts = NULL;
  puts = init_puts(puts);
  set[1].x = (int)size.x;
  set[1].y = SCREEN_HEIGHT - 377;
  set[0].x = (int)size.x;
  set[0].y = 0;
  before_loop(sprites, puts, window, set);
  usleep(150000);
  while (sfRenderWindow_isOpen(window))
    {
      keyboard_hdl(sprites, textures, window);
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(window);
	}
      action_loop(sprites, window, set, size);
    }
  return (0);
}
