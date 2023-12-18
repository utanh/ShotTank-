#include "Object.h"

using namespace std;
using namespace cimg_library;

Object::Object()
{
}

int Object::get_d()
{
    return d;
}
int Object::get_r()
{
    return r;
}
void Object::set_d(const int& ts_d)
{
    d = ts_d;
}
void Object::set_r(const int& ts_r)
{
    r = ts_r;
}

int Object::get_mau()
{
    return mau;
}
void Object::tru_mau(const int& ts_mauTru)
{
    mau = mau - ts_mauTru;
}
void Object::set_mau(const int& ts_mau)
{
    mau = ts_mau;
}

CImg<> Object::get_hdCoBan()
{
    return hdCoBan;
}

float Object::get_loai()
{
    return loai;
}

void Object::hienThi(CImg<>& imgMain)
{
    imgMain.draw_image(x, y, hdCoBan);
}

void Object::set_hdCoBan()
{
}
