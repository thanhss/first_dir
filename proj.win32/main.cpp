#include "stdafx.h"
#include "CCEGLView.h"
#include "main.h"
#include "MPApplication.h"
#include "MPKeyboard.h"

USING_NS_CC;

void onKeyUpDown(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_KEYUP)
	{
		if (wParam == 'W') MPKeyboard::wUp();
	}
	else if (message == WM_KEYDOWN)
	{
		if (wParam == 'W') MPKeyboard::wDown();
	}
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    MPApplication app;
    CCEGLView * eglView = CCEGLView::sharedOpenGLView();
    eglView->setViewName("Multiproj");
    eglView->setFrameSize(1024, 768); // 4/3
    eglView->setFrameZoomFactor(1.0f);

	eglView->setAccelerometerKeyHook(onKeyUpDown);

    return CCApplication::sharedApplication()->run();
}
