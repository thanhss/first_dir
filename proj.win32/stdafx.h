// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
//#include <stdlib.h>
//#include <malloc.h>
//#include <memory.h>
#include <tchar.h>

#include <vector>
#include <string>

// Additional headers

#undef CC_ENABLE_CHIPMUNK_INTEGRATION
#define CC_ENABLE_BOX2D_INTEGRATION 1

#include "CCStdC.h"
#include "cocos2d.h"