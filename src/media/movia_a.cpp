#include <string.h>
#include "common.h"
#include "media/movie.h"
#include "graphics/gfxapi.h"

/*************************************************************************
ANIM_Render () - Renders an ANIM FRAME
 *************************************************************************/
void 
ANIM_Render(
	ANIMLINE *inmem
)
{
	while (inmem->opt)
	{
		int l = inmem->length;
		int p = inmem->offset;
		
		inmem++;
		
		memcpy(&displaybuffer[p], inmem, l);
		
		inmem = (ANIMLINE*)((char*)inmem + l);
	}
}
