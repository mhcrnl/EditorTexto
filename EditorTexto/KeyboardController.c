#include "KeyboardController.h"

#define SCROLL 0xE0

Keyboard GetUserInput() {
	
	Keyboard c;
	int ch1, ch2;
	ch1 = getch();
	ch2 = 0;

	// Uma tecla do 'Scroll' foi pressionada
	if (ch1 == SCROLL)
	{
		ch2 = getch(); // Determina qual tecla do scroll foi pressionada
		switch (ch2)
		{
		case 72:
			c.Command = UP_ARROW;
			break;
		case 80:
			c.Command = DOWN_ARROW;
			break;
		case 75:
			c.Command = LEFT_ARROW;
			break;
		case 77:
			c.Command = RIGHT_ARROW;
			break;
		case 83:
			c.Command = DELETE;
			break;
		default:
			c.Command = 0;
			break;
		}
	}
	else 
	{
		if (ch1 == 8)
			c.Command = BACKSPACE;
		else if (ch1 == 13)
			c.Command = ENTER;
		else
			c.Key = ch1;
	}
	return c;
}