/*
	TFT_button.h - An object for the SEEEDStudio as an HMI type screen object
	Created by Christopher R. Stradling, April 14, 2015.
	Released unsigned into the public domain.
*/


#ifndef TFT_HMI_h
#define TFT_HMI_h

#include <Arduino.h>
#include <stdint.h>
#include <SeeedTouchScreen.h>
#include <TFTv2.h>
#include <SPI.h>

#define OPEN 0
#define HELD 1
#define TOUCH 2
#define RELEASE 3

class TFT_button
{
	
	public:
		TFT_button(unsigned int x, unsigned int y, const char *text, unsigned int text_size, unsigned int text_color, unsigned int background);
		TFT_button(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int background);
		int state(unsigned int x, unsigned int y, unsigned int z);
		void set_sensitivity(unsigned int sensitivity);
		void set_background(unsigned int background);
		void redraw();
		
	private:
		unsigned int _type;
		
		unsigned int _x;
		unsigned int _y;
		unsigned int _x_end;
		unsigned int _y_end;
		
		char _text[];
		unsigned int _text_size;
		unsigned int _text_color;
		unsigned int _text_width;
		unsigned int _text_height;
		
		unsigned int _box_width;
		unsigned int _box_height;
		unsigned int _background;
		
		unsigned int _sensitivity;
		boolean _last_state;
		boolean _state;
};

#endif
