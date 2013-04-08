#ifndef  _MP_KEYBOARD_H_
#define  _MP_KEYBOARD_H_

#include "cocos2d.h"

/**
@brief    Keyboard events.

Platform specific code sends keyboard events here.
*/
class  MPKeyboard 
{
public:
	static void wUp();
	static void wDown();

private:
	static bool isWUp;
};

#endif