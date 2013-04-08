#include "stdafx.h"
#include "MPKeyboard.h"

USING_NS_CC;
using namespace std;

// We need to keep track of whether the key is up because of key repeat.

bool MPKeyboard::isWUp = true;

void MPKeyboard::wUp() 
{
	isWUp = true;
	CCLOG("W key up");
}

void MPKeyboard::wDown() 
{
	if (isWUp)
	{
		isWUp = false;
		CCLOG("W key down");
	}
}
