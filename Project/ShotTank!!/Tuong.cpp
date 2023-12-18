#include "Tuong.h"

using namespace std;
using namespace cimg_library;

unsigned char colorTuong[] = { 90, 145, 90 };

Tuong::Tuong()
{
    mau = 99999;
    loai = 1;
    set_hdCoBan();
}

void Tuong::set_hdCoBan()
{
    hdCoBan.assign(r, d, 1, 3, 0);
    hdCoBan.draw_rectangle(0, 0, r, d, colorTuong);
}

