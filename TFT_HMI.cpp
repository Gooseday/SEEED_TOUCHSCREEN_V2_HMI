#include <Arduino.h>
#include "TFT_button.h"



TFT_button::TFT_button(unsigned int x, unsigned int y, const char *text, unsigned int text_size, unsigned int text_color, unsigned int background)
{
	_x = x;
	_y = y;
	
	//Set-up text characteristics 
	_text_color = text_color;
	_text_width = (text_size * 6 * (sizeof(*text)/sizeof(char)) + 8);
	_text_height = text_size * 8;
	
	//Set-up background box
	_background = background;
	_box_width = _text_width+2;
	_box_height = _text_height+2;
	
	//Copy text pounsigned inter to array
	unsigned int i = 0;
	while(*text){
		_text[i] = *text;
		*text++;
		i++;
	}
	
	//Set-up initial button settings/state
	_sensitivity = 100;
	_last_state = 0;
	_state = 0;
	
	_x_end = _x+_box_width;
	_y_end = _y+_box_height;
	
	_type = 0;
	
	redraw();
}

TFT_button::TFT_button(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int color)
{
	_x = x;
	_y = y;
	
	_box_width = width;
	_box_height = height;
	
	_background = color;
	
	Tft.fillRectangle(_x, _y, _box_width, _box_height, _background);
	
	//Set-up initial button settings/state
	_sensitivity = 100;
	_last_state = 0;
	_state = 0;
	
	_x_end = _x+_box_width;
	_y_end = _y+_box_height;
	
	_type = 1;
	
	redraw();
}

int TFT_button::state(unsigned int x, unsigned int y, unsigned int z)
{
	_last_state = _state;
	
	if(z >= _sensitivity && x >= _x && x <= _x_end && y >= _y && y < _y_end)
	{
		_state = true;
	}
	else
	{
		_state = false;
	}
	
	if(_state == true)
	{
		if(_last_state == false)
		{
			return TOUCH;
		}
		else
		{
			return HELD;
		}
	}
	
	if(_state == false)
	{
		if(_last_state == false)
		{
			return OPEN;
		}
		else
		{
			return RELEASE;
		}
	}
}

void TFT_button::set_sensitivity(unsigned int sensitivity)
{
	_sensitivity = sensitivity;
	redraw();
}

void TFT_button::set_background(unsigned int color)
{
	_background = color;
	redraw();
}

void TFT_button::redraw()
{
	if(_type == 0)
	{
		Tft.fillRectangle(_x, _y, _box_width, _box_height, _background);
		Tft.drawString(_text, _x+2, _y+2, _text_size, _text_color);
	}
	else
	{
		Tft.fillRectangle(_x, _y, _box_width, _box_height, _background);
	}
}
