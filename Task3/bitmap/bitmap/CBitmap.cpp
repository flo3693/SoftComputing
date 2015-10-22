//--------------------------------------------------------------------------//


#include "stdafx.h"
#include "CBitmap.h"


//--------------------------------------------------------------------------//


CBitmap::CBitmap()
{
 bits = 0;
}


//--------------------------------------------------------------------------//


CBitmap::~CBitmap()
{
 if (bits) delete bits;
}


//--------------------------------------------------------------------------//


void CBitmap::load(char *file_name)
{
 FILE *bitmap_file = fopen(file_name, "rb");
 fread(&bmfh.bfType,          2, 1, bitmap_file);
 fread(&bmfh.bfSize,          4, 1, bitmap_file);
 fread(&bmfh.bfReserved1,     2, 1, bitmap_file);
 fread(&bmfh.bfReserved2,     2, 1, bitmap_file);
 fread(&bmfh.bfOffBits,       4, 1, bitmap_file);
 fread(&bmih.biSize,          4, 1, bitmap_file);
 fread(&bmih.biWidth,         4, 1, bitmap_file);
 fread(&bmih.biHeight,        4, 1, bitmap_file);
 fread(&bmih.biPlanes,        2, 1, bitmap_file);
 fread(&bmih.biBitCount,      2, 1, bitmap_file);
 fread(&bmih.biCompression,   4, 1, bitmap_file);
 fread(&bmih.biSizeImage,     4, 1, bitmap_file);
 fread(&bmih.biXPelsPerMeter, 4, 1, bitmap_file);
 fread(&bmih.biYPelsPerMeter, 4, 1, bitmap_file);
 fread(&bmih.biClrUsed,       4, 1, bitmap_file);
 fread(&bmih.biClrImportant,  4, 1, bitmap_file);
 fread(&palette[0], (size_t)bmih.biClrUsed * 4, 1, bitmap_file);
 bits = new BYTE [(int)(bmih.biWidth * bmih.biHeight)];
 for (int i = (int)bmih.biHeight - 1; i >= 0; i--)
  fread (bits + (int)bmih.biWidth * i, (int)bmih.biWidth, 1, bitmap_file);
 fclose(bitmap_file);
 width  = (int)bmih.biWidth;
 height = (int)bmih.biHeight;
}


//--------------------------------------------------------------------------//


void CBitmap::save(char *file_name)
{
 FILE *bitmap_file = fopen(file_name, "wb");
 fwrite(&bmfh.bfType,          2, 1, bitmap_file);
 fwrite(&bmfh.bfSize,          4, 1, bitmap_file);
 fwrite(&bmfh.bfReserved1,     2, 1, bitmap_file);
 fwrite(&bmfh.bfReserved2,     2, 1, bitmap_file);
 fwrite(&bmfh.bfOffBits,       4, 1, bitmap_file);
 fwrite(&bmih.biSize,          4, 1, bitmap_file);
 fwrite(&bmih.biWidth,         4, 1, bitmap_file);
 fwrite(&bmih.biHeight,        4, 1, bitmap_file);
 fwrite(&bmih.biPlanes,        2, 1, bitmap_file);
 fwrite(&bmih.biBitCount,      2, 1, bitmap_file);
 fwrite(&bmih.biCompression,   4, 1, bitmap_file);
 fwrite(&bmih.biSizeImage,     4, 1, bitmap_file);
 fwrite(&bmih.biXPelsPerMeter, 4, 1, bitmap_file);
 fwrite(&bmih.biYPelsPerMeter, 4, 1, bitmap_file);
 fwrite(&bmih.biClrUsed,       4, 1, bitmap_file);
 fwrite(&bmih.biClrImportant,  4, 1, bitmap_file);
 fwrite(&palette[0], (size_t)bmih.biClrUsed * 4, 1, bitmap_file);
 for (int i = (int)bmih.biHeight - 1; i >= 0; i--)
  fwrite(bits + (int)bmih.biWidth * i, (int)bmih.biWidth, 1, bitmap_file);
}


//--------------------------------------------------------------------------//


BYTE CBitmap::get_pixel(int x, int y)
{
 return bits[y * bmih.biWidth + x];
}



//--------------------------------------------------------------------------//


void CBitmap::set_pixel(int x, int y, BYTE color)
{
 bits[y * bmih.biWidth + x] = color;
}


//--------------------------------------------------------------------------//
