/* Definitions for creating compiling tiles. */
/* This is a mix of the vanilla NetHack and Slash'EM code. */
/* Modified 29 Oct 2010 by Alex Smith */

typedef unsigned char pixval;

typedef struct {
    pixval r, g, b;
} pixel;

#define MAXCOLORMAPSIZE 	256

#define CM_RED		0
#define CM_GREEN	1
#define CM_BLUE 	2

#define DEFAULT_BACKGROUND  { 71, 108, 108 } /* For transparency */

/* shared between reader and writer */
extern pixval ColorMap[3][MAXCOLORMAPSIZE];
extern int colorsinmap;
/* writer's accumulated colormap */
extern pixval MainColorMap[3][MAXCOLORMAPSIZE];
extern int colorsinmainmap;

#include "dlb.h"	/* for MODEs */

/* maximum possible size of tiles */
#define MAX_TILE_X 128
#define MAX_TILE_Y 128

extern int tile_x, tile_y;

#define Fprintf (void) fprintf

#define pixel_equal(x,y) ((x.r == y.r) && (x.g == y.g) && (x.b == y.b))

extern boolean FDECL(fopen_text_file, (const char *, const char *));
extern boolean FDECL(read_text_tile, (pixel (*)[MAX_TILE_X]));
extern boolean FDECL(write_text_tile, (pixel (*)[MAX_TILE_X]));
extern boolean NDECL(fclose_text_file);

extern void NDECL(init_colormap);
extern void NDECL(merge_colormap);

#if defined(MICRO) || defined(WIN32)
#undef exit
# if !defined(MSDOS) && !defined(WIN32)
extern void FDECL(exit, (int));
# endif
#endif
