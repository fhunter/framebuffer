#include "framebuffer.h"
#include <stdio.h>
#include <unistd.h>

int
main (void)
{
  struct fb_struct *framebuffer;
  int i, j;
  framebuffer = fb_init ();
  if (framebuffer == NULL)
    {
      fprintf (stderr, "Error opening framebuffer\n");
      exit (1);
    };
  for (i = 0; i < fb_getwidth (framebuffer); i++)
    {
      for (j = 0; j < fb_getheight (framebuffer); j++)
	{
	  if (((i % 20)==0) || ((j % 20)==0))
	    {
	      fb_putpixel (framebuffer, i, j, RGB (255, 255, 255));
	    }
	  else
	    {
	      fb_putpixel (framebuffer, i, j, RGB (i + j, i - j, i));
	    }
	}
    };
  fb_close (framebuffer);
  return 0;
};
