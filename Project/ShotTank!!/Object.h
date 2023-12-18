#ifndef __Object_H__
#define __Object_H__

#include <iostream>
#include "CImg.h"
using namespace cimg_library;

class Object{
protected:
    int d, r;   //d<->y; r<->x
    int mau;
    CImg<> hdCoBan;
    float loai;

public:
    int x, y;

    Object();

    virtual int get_d();
    virtual int get_r();
    virtual void set_d(const int& ts_d);
    virtual void set_r(const int& ts_r);

    virtual int get_mau();
    virtual void tru_mau(const int& ts_mauTru);
    virtual void set_mau(const int& ts_mau);

    virtual CImg<> get_hdCoBan();
    virtual void set_hdCoBan();

    virtual float get_loai();

    virtual void hienThi(CImg<>& imgMain);
};

#endif // __Object_H__

