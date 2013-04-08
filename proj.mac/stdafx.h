#ifndef HelloCpp_stdafx_h
#define HelloCpp_stdafx_h

#undef CC_ENABLE_CHIPMUNK_INTEGRATION
#define CC_ENABLE_BOX2D_INTEGRATION 1

#ifdef __cplusplus

   #include <vector>
   #include <string>

   #include "CCStdC.h"
   #include "cocos2d.h"

#endif

#endif
