/*
** mouse_actions.c for scroller in /home/ibanez_j/parallax
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Wed Apr 12 15:03:59 2017 Jean-Alexandre IBANEZ
** Last update Mon Jun 12 10:53:20 2017 Jean-Alexandre IBANEZ
*/

#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <unistd.h>
#include "parallax.h"

sfVector2f	g_pos_mouse;
sfVector2f	temp_move;

void	pause_exe(sfVector2i pos_mouse, sfVector2u size_pause,
		  sfRenderWindow *window)
{
  usleep(150000);
  while (1)
    {
      pos_mouse = sfMouse_getPositionRenderWindow(window);
      if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
	  pos_mouse.x >= 100 && pos_mouse.x <= 100 + (int)size_pause.x &&
	  pos_mouse.y >= SCREEN_HEIGHT - 100 &&
	  pos_mouse.y <= SCREEN_HEIGHT - 100 + (int)size_pause.y)
	break;
    }
  usleep(150000);
}

void	mouse_actions(sfTexture **textures,
		      sfRenderWindow *window)
{
  sfVector2u	size_pause;
  sfVector2i	pos_mouse;

  pos_mouse = sfMouse_getPositionRenderWindow(window);
  size_pause = sfTexture_getSize(textures[PAUSE]);
  if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
      pos_mouse.x >= 100 && pos_mouse.x <= 100 + (int)size_pause.x &&
      pos_mouse.y >= SCREEN_HEIGHT - 100 &&
      pos_mouse.y <= SCREEN_HEIGHT - 100 + (int)size_pause.y)
    pause_exe(pos_mouse, size_pause, window);
}
