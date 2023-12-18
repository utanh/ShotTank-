#ifndef __MovingObj_H__
#define __MovingObj_H__

#include "Object.h"
#include "Tuong.h"
using namespace cimg_library;

enum HuongDi {UP, DOWN, LEFT, RIGHT};

class MovingObj : public Object{
protected:
    int tocDo;
    HuongDi hgDi;

public:
    MovingObj();

    virtual int get_tocDo();
    virtual void set_tocDo(const int& ts_tocDo);

    virtual HuongDi get_hgDi();
    virtual void set_hgDi(const HuongDi& ts_hgDi);

    virtual bool vaCham(Object obj);
    virtual void vaCham_Tuong(Object obj);
    virtual void diChuyen();
};

#endif // __MovingObj_H__
