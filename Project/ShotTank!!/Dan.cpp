#include "Dan.h"

using namespace std;
using namespace cimg_library;

unsigned char colorDan[] = { 255, 255, 255 };

Dan::Dan()
{
    loai = 2;
    tocDo = 10;
    mau = 1;
    r = 5;
    d = 5;
    vTri = IN_TANK;
    set_hdCoBan();
}

VITRI Dan::get_vTri()
{
    return vTri;
}
void Dan::set_vTri(const VITRI& ts_vTri)
{
    vTri = ts_vTri;
}

void Dan::set_hdCoBan()
{
    hdCoBan.assign(r, d, 1, 3, 0);
    hdCoBan.draw_rectangle(0, 0, r, d, colorDan);
}

bool Dan::vaCham(Object& obj)
{
    if(vTri == OUT_TANK)
    {
        if(MovingObj::vaCham(obj))
        {
            tru_mau(1);
            obj.tru_mau(1);
            return true;
        }
    }

    return false;
}

void Dan::diChuyen()
{
    if(get_vTri() == OUT_TANK)
        MovingObj::diChuyen();
}

void Dan::hienThi(CImg<>& imgMain)
{
    if(get_vTri() == OUT_TANK)
        Object::hienThi(imgMain);
}
