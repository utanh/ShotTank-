#include "MovingObj.h"

using namespace std;
using namespace cimg_library;

MovingObj::MovingObj()
{
    loai = -1;
}

int MovingObj::get_tocDo()
{
    return tocDo;
}
void MovingObj::set_tocDo(const int& ts_tocDo)
{
    tocDo = ts_tocDo;
}

HuongDi MovingObj::get_hgDi()
{
    return hgDi;
}
void MovingObj::set_hgDi(const HuongDi& ts_hgDi)
{
    hgDi = ts_hgDi;
}

void MovingObj::diChuyen()
{
    if(get_hgDi() == UP)
        y -= tocDo;
    else if(get_hgDi() == DOWN)
        y += tocDo;
    else if(get_hgDi() == LEFT)
        x -= tocDo;
    else if(get_hgDi() == RIGHT)
        x += tocDo;
}

bool MovingObj::vaCham(Object obj)
{
    //Obj co d va r >=
    if(obj.x <= x && x <= obj.x + obj.get_r() && obj.y <= y && y <= obj.y + obj.get_d()){
        return true;
    }
    else if(obj.x <= x + get_r() && x + get_r() <= obj.x + obj.get_r() && obj.y <= y && y <= obj.y + obj.get_d()){
        return true;
    }
    else if(obj.x <= x + get_r() && x + get_r() <= obj.x + obj.get_r() && obj.y <= y + get_d() && y + get_d() <= obj.y + obj.get_d()){
        return true;
    }
    else if(obj.x <= x && x <= obj.x + obj.get_r() && obj.y <= y + get_d() && y + get_d() <= obj.y + obj.get_d()){
        return true;
    }
    //Obj co d va r <
    else if(x <= obj.x && obj.x + obj.get_r() <= x + get_r() && obj.y <= y && y <= obj.y + obj.get_d()){
        return true;
    }
    else if(x <= obj.x && obj.x + obj.get_r() <= x + get_r() && obj.y <= y + get_d() && y + get_d() <= obj.y + obj.get_d()){
        return true;
    }
    else if(y <= obj.y && obj.y + obj.get_d() <= y + get_d() && obj.x <= x && x <= obj.x + obj.get_r()){
        return true;
    }
    else if(y <= obj.y && obj.y + obj.get_d() <= y + get_d() && obj.x <= x + get_r() && x + get_r() <= obj.x + obj.get_r()){
        return true;
    }

    return false;
}
void MovingObj::vaCham_Tuong(Object obj)
{
    if(get_hgDi() == UP){
        y = obj.y + obj.get_d() + 1;
    }
    else if(get_hgDi() == DOWN){
        y = obj.y - get_d() - 1;
    }
    else if(get_hgDi() == LEFT){
        x = obj.x + obj.get_r() + 1;
    }
    else if(get_hgDi() == RIGHT){
        x = obj.x - get_r() - 1;
    }
}
