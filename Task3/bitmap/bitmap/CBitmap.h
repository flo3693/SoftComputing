//--------------------------------------------------------------------------//


#ifndef CBITMAP_H
#define CBITMAP_H


//--------------------------------------------------------------------------//


typedef unsigned char 		BYTE;
typedef unsigned int  		WORD;
typedef unsigned int  		UINT;
typedef unsigned __int64	DWORD;
typedef unsigned __int64	LONG;


//--------------------------------------------------------------------------//


struct BITMAPFILEHEADER
{
 UINT  bfType;
 DWORD bfSize;
 UINT  bfReserved1;
 UINT  bfReserved2;
 DWORD bfOffBits;
};


struct BITMAPINFOHEADER
{
 DWORD biSize;
 LONG  biWidth;
 LONG  biHeight;
 WORD  biPlanes;
 WORD  biBitCount;
 DWORD biCompression;
 DWORD biSizeImage;
 LONG  biXPelsPerMeter;
 LONG  biYPelsPerMeter;
 DWORD biClrUsed;
 DWORD biClrImportant;
};


struct RGBQUAD
{
 BYTE rgbBlue;
 BYTE rgbGreen;
 BYTE rgbRed;
 BYTE rgbReserved;
};


//--------------------------------------------------------------------------//


class CBitmap
{
 
 public:
 BITMAPFILEHEADER bmfh;
 BITMAPINFOHEADER bmih;
 RGBQUAD          palette[256];
 BYTE            *bits;
 
 int width;
 int height;
 
 CBitmap();
 ~CBitmap();
 
 void load(char *file_name);
 void save(char *file_name);
 BYTE get_pixel(int x, int y);
 void set_pixel(int x, int y, BYTE color);

};


//--------------------------------------------------------------------------//


#endif //CBITMAP_CPP
