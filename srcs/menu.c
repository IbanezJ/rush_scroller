/*
** menu.c for parallax in /home/ibanez_j/parallax
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Tue Apr 11 12:59:44 2017 Jean-Alexandre IBANEZ
** Last update Fri Apr 21 18:06:04 2017 Jean-Alexandre IBANEZ
*/

#include "parallax.h"

sfColor	set_color()
{
  sfColor	color;

  color.r = 107;
  color.g = 174;
  color.b = 146;
  color.a = 255;
  return (color);
}

void	before_win(sfSprite *button, sfTexture *play_button,
		   sfVector2f pos_button)
{
  sfSprite_setTexture(button, play_button, sfTrue);
  sfSprite_setPosition(button, pos_button);
}

void	end_win(sfRenderWindow *window, sfColor color_menu, sfSprite *button)
{
  sfRenderWindow_clear(window, color_menu);
  sfRenderWindow_drawSprite(window, button, NULL);
  sfRenderWindow_display(window);
}

void	menu_loop(sfRenderWindow *window)
{
  sfColor	color_menu;
  sfVector2u	size_button;
  sfVector2f	pos_button;
  sfSprite	*button;
  sfTexture	*play_button;
  sfVector2i	pos_mouse;

  color_menu = set_color();
  pos_button.x = SCREEN_WIDTH / 2 - 350;
  pos_button.y = SCREEN_HEIGHT - 400;
  play_button = sfTexture_createFromFile("images/PlayNowButton.png", NULL);
  button = sfSprite_create();
  before_win(button, play_button, pos_button);
  size_button = sfTexture_getSize(play_button);
  while (1)
    {
      pos_mouse = sfMouse_getPositionRenderWindow(window);
      if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
	  pos_mouse.x >= SCREEN_WIDTH / 2 - 350 &&
	  pos_mouse.x <= SCREEN_WIDTH / 2 - 350 + (int)size_button.x &&
	  pos_mouse.y >= SCREEN_HEIGHT - 400 &&
	  pos_mouse.y <= SCREEN_HEIGHT - 400 + (int)size_button.y)
	break;
      end_win(window, color_menu, button);
    }
}
