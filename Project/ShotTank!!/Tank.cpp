#include "Tank.h"

using namespace std;
using namespace cimg_library;

Tank::Tank()
{
    loai = -2;
    tocDo = 4;
    r = 30;
    d = 30;
    bangDan.resize(5);
    cd = 0;
}

HuongDi Tank::get_old_hgDi()
{
    return old_hgDi;
}
void Tank::set_old_hgDi()
{
    old_hgDi = hgDi;
}

int Tank::get_cd()
{
    return cd;
}
void Tank::reset_cd(const int& ts_cdMAX)
{
    cd = ts_cdMAX;
}
void Tank::tru_cd(const int& nhip)
{
    cd -= nhip;
}

void Tank::hienThi(CImg<>& imgMain)
{
    if(get_hgDi() == DOWN)
        imgMain.draw_image(x, y, this->get_hdCoBan());
    else if(get_hgDi() == UP)
        imgMain.draw_image(x, y, this->get_hdCoBan().rotate(180));
    else if(get_hgDi() == LEFT)
        imgMain.draw_image(x, y, this->get_hdCoBan().rotate(90));
    else if(get_hgDi() == RIGHT)
        imgMain.draw_image(x, y, this->get_hdCoBan().rotate(-90));
}

void Tank::napDan()
{
    int n = bangDan.size();

    for(int i = 0; i < n; i++)
    {
        if(bangDan[i].get_mau() <= 0)
         {
            bangDan.erase(bangDan.begin() + i);
            bangDan.push_back(Dan());
            i--;
            n--;
         }
    }
}

void Tank::cuongEp_napDan()
{
    int n = bangDan.size();

    for(int i = 0; i < n; i++)
    {
        if(bangDan[i].get_vTri() == OUT_TANK)
         {
            bangDan.erase(bangDan.begin() + i);
            bangDan.push_back(Dan());
            i--;
            n--;
         }
    }
}

void Tank::Dan_diChuyen()
{
    for(int i = 0; i < bangDan.size(); i++)
        bangDan[i].diChuyen();
}

bool Tank::Dan_vaCham(Object& obj)
{
    bool trung = false;

    for(int i = 0; i < bangDan.size(); i++)
    {
        if(bangDan[i].vaCham(obj))
            trung = true;
    }

    return trung;
}

void Tank::Dan_hienThi(CImg<>& imgMain)
{
    for(int i = 0; i < bangDan.size(); i++)
        bangDan[i].hienThi(imgMain);
}
