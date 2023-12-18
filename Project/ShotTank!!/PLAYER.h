#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Tank.h"
using namespace cimg_library;

class PLAYER : public Tank{
public:
    PLAYER();

    void set_hdCoBan();

    void dieuKhien(CImgDisplay& window, CImg<>& imgMain, int& ts_map, int& ts_ktra, int& ts_restart, int& ts_WinLose);
    void vaCham_Tuong(Object obj);
    void vaCham_Tank(Tank& tank);

    void ban();
};

#endif // __PLAYER_H__
