#include "d2_interface.h"

d2DrawRectangle_t*	d2DrawRectangle		= NULL;
d2DrawLine_t*		d2DrawLine			= NULL;

d2DrawText_t*		d2DrawText			= NULL;
d2GetTextSize_t*	d2GetTextSize		= NULL;
d2SetTextSize_t*	d2SetTextSize		= NULL;

void initializeInterface( DWORD baseAddress )
{
	d2DrawRectangle	= (d2DrawRectangle_t*)(baseAddress + d2DrawRectangleOffset);
	d2DrawLine		= (d2DrawLine_t*)(baseAddress + d2DrawLineOffset);

	d2DrawText		= (d2DrawText_t*)(baseAddress + d2DrawTextOffset);
	d2GetTextSize	= (d2GetTextSize_t*)(baseAddress + d2GetTextSizeOffset);
	d2SetTextSize	= (d2SetTextSize_t*)(baseAddress + d2SetTextSizeOffset);
}