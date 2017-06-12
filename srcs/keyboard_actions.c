/*
** keyboard_actions.c for scroller in /home/ibanez_j/parallax
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Sun Apr  2 05:18:34 2017 Jean-Alexandre IBANEZ
** Last update Mon Jun 12 10:51:50 2017 Jean-Alexandre IBANEZ
*/

#include <unistd.h>
#include "parallax.h"

void	key_up(sfVector2f position_sprite, sfVector2f pos_lfire,
	       sfSprite **sprites, sfVector2f pos_lfire2)
{
  sfVector2f	new_pos;

  new_pos.y = position_sprite.y - 2;
  new_pos.x = position_sprite.x;
  sfSprite_setPosition(sprites[SHIP], new_pos);
  new_pos.y = pos_lfire.y - 2;
  new_pos.x = pos_lfire.x;
  sfSprite_setPosition(sprites[LFIRE], new_pos);
  new_pos.y = pos_lfire2.y - 2;
  new_pos.x = pos_lfire2.x;
  sfSprite_setPosition(sprites[LFIRE2], new_pos);
}

void	key_down(sfVector2f position_sprite, sfVector2f pos_lfire,
		 sfSprite **sprites, sfVector2f pos_lfire2)
{
  sfVector2f	new_pos;

  new_pos.y = position_sprite.y + 2;
  new_pos.x = position_sprite.x;
  sfSprite_setPosition(sprites[SHIP], new_pos);
  new_pos.y = pos_lfire.y + 2;
  new_pos.x = pos_lfire.x;
  sfSprite_setPosition(sprites[LFIRE], new_pos);
  new_pos.y = pos_lfire2.y + 2;
  new_pos.x = pos_lfire2.x;
  sfSprite_setPosition(sprites[LFIRE2], new_pos);
}

void	key_right(sfVector2f position_sprite, sfVector2u size_ship,
		  sfSprite **sprites)
{
  sfVector2f	new_pos;

  new_pos.y = position_sprite.y + size_ship.y - 35;
  new_pos.x = position_sprite.x + size_ship.x - 190;
  sfSprite_setPosition(sprites[LASER], new_pos);
  new_pos.y = position_sprite.y + size_ship.y - 160;
  new_pos.x = position_sprite.x + size_ship.x - 190;
  sfSprite_setPosition(sprites[LASER2], new_pos);
}

void	keyboard_hdl(sfSprite **sprites, sfTexture **textures,
		     sfRenderWindow *window)
{
  sfVector2f	pos_lfire2;
  sfVector2f	pos_laser;
  sfVector2f	pos_lfire;
  sfVector2f	position_sprite;
  sfVector2u	size_ground;
  sfVector2u	size_ship;

  pos_lfire2 = sfSprite_getPosition(sprites[LFIRE2]);
  pos_laser = sfSprite_getPosition(sprites[LASER]);
  pos_lfire = sfSprite_getPosition(sprites[LFIRE]);
  size_ground = sfTexture_getSize(textures[GROUND]);
  position_sprite = sfSprite_getPosition(sprites[SHIP]);
  size_ship = sfTexture_getSize(textures[SHIP]);
  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue && position_sprite.y > 0)
    key_up(position_sprite, pos_lfire, sprites, pos_lfire2);
  if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue && position_sprite.y +
      (int)size_ship.y < SCREEN_HEIGHT - (int)size_ground.y)
    key_down(position_sprite, pos_lfire, sprites, pos_lfire2);
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue &&
      pos_laser.x >= SCREEN_WIDTH)
    key_right(position_sprite, size_ship, sprites);
  mouse_actions(textures, window);
}
