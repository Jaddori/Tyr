#include "d2_interface.h"

// functions
d2DrawRectangle_t*	d2DrawRectangle		= NULL;
d2DrawLine_t*		d2DrawLine			= NULL;

d2DrawText_t*		d2DrawText			= NULL;
d2GetTextSize_t*	d2GetTextSize		= NULL;
d2SetTextSize_t*	d2SetTextSize		= NULL;

// variables
DWORD*				d2ScreenSizeX		= NULL;
DWORD*				d2ScreenSizeY		= NULL;
DWORD*				d2MouseX			= NULL;
DWORD*				d2MouseY			= NULL;
DWORD*				d2MouseOffsetY		= NULL;
DWORD*				d2MouseOffsetX		= NULL;
DWORD*				d2MouseOffsetZ		= NULL;

void initializeInterface( DWORD baseAddress )
{
	// functions
	d2DrawRectangle	= (d2DrawRectangle_t*)(baseAddress + d2DrawRectangleOffset);
	d2DrawLine		= (d2DrawLine_t*)(baseAddress + d2DrawLineOffset);

	d2DrawText		= (d2DrawText_t*)(baseAddress + d2DrawTextOffset);
	d2GetTextSize	= (d2GetTextSize_t*)(baseAddress + d2GetTextSizeOffset);
	d2SetTextSize	= (d2SetTextSize_t*)(baseAddress + d2SetTextSizeOffset);

	// variables
	d2ScreenSizeX	= (DWORD*)(baseAddress + d2ScreenSizeXOffset);
	d2ScreenSizeY	= (DWORD*)(baseAddress + d2ScreenSizeYOffset);
	d2MouseX		= (DWORD*)(baseAddress + d2MouseXOffset);
	d2MouseY		= (DWORD*)(baseAddress + d2MouseYOffset);
	d2MouseOffsetY	= (DWORD*)(baseAddress + d2MouseOffsetYOffset);
	d2MouseOffsetX	= (DWORD*)(baseAddress + d2MouseOffsetXOffset);
	d2MouseOffsetZ	= (DWORD*)(baseAddress + d2MouseOffsetZOffset);
}