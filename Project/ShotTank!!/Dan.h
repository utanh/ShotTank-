#ifndef __Dan_H__
#define __Dan_H__

#include "MovingObj.h"
using namespace cimg_library;

enum VITRI { IN_TANK, OUT_TANK };

class Dan : public MovingObj{
private:
    VITRI vTri;
public:
    Dan();

    VITRI get_vTri();
    void set_vTri(const VITRI& ts_vTri);

    void set_hdCoBan();

    bool vaCham(Object& obj);
    void diChuyen();
    void hienThi(CImg<>& imgMain);
};

#endif // __Dan_H__
