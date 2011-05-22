#ifndef _FRAMEBUFFER_H_
#define _FRAMEBUFFER_H_
struct fb_struct {
	int width;
	int height;
	int descriptor;
	int colordepth;
};

#define RGB(r,g,b) (unsigned char[4]){(b)%255,(g)%255,(r)%255,0}

struct fb_struct* fb_init();
inline int fb_getheight(struct fb_struct*);
inline int fb_getwidth(struct fb_struct*);
void fb_putpixel(struct fb_struct*,int x,int y,unsigned char[4]);
void fb_close(struct fb_struct*);



#endif
