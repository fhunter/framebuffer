#include "framebuffer.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fb.h>

struct fb_struct* fb_init(){
	struct fb_struct *framebuffer;
	struct fb_var_screeninfo vinfo;
	framebuffer=calloc(sizeof(struct fb_struct),1);
	if(framebuffer==NULL) return NULL;
	framebuffer->descriptor=open("/dev/fb0",O_RDWR);
	if(framebuffer->descriptor<0){
		free(framebuffer);
		return NULL;
	};
	if (ioctl(framebuffer->descriptor, FBIOGET_VSCREENINFO, &vinfo)) {
		close(framebuffer->descriptor);
		free(framebuffer);
		return NULL;
	}
	framebuffer->width=vinfo.xres;
	framebuffer->height=vinfo.yres;
	return framebuffer;
};

inline int fb_getheight(struct fb_struct* framebuffer){
	return framebuffer->width;
};

inline int fb_getwidth(struct fb_struct* framebuffer){
	return framebuffer->height;
};

void fb_putpixel(struct fb_struct* framebuffer,int x,int y,unsigned char pixel[4]){
	unsigned long position=0;
	position=((unsigned long)x+((unsigned long)y)*(framebuffer->width))*4ul;
	lseek(framebuffer->descriptor,position,SEEK_SET);
	write(framebuffer->descriptor,pixel,4);
};

void fb_close(struct fb_struct* framebuffer){
	close(framebuffer->descriptor);
	free(framebuffer);
};
