//--------------------------------------------------------------------------//

#include "stdafx.h"
#include "CBitmap.h"
#include <cstdlib>
#include <conio.h>
#include <iostream>
using namespace std;


//--------------------------------------------------------------------------//


int _tmain(int argc, _TCHAR* argv[])
{
 CBitmap bmp;
 bmp.load("lena.bmp");
 for (int i = 0; i < 512; i++)
 {
  BYTE pixel = bmp.get_pixel(i, i);
  bmp.set_pixel(i, i, ~pixel);
 }
 bmp.save("lena_out.bmp");
 return 0;  
}


//--------------------------------------------------------------------------//
