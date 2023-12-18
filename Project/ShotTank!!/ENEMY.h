#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Tank.h"
#include <time.h>
#include <stdlib.h>
using namespace cimg_library;

class ENEMY : public Tank{
public:
    ENEMY();

    void set_hdCoBan();

    void vaCham_Tuong(Object obj);
    void vaCham_Tank(Tank& tank);
    HuongDi rand_hgDi();

    void ban(Object player);
};

#endif // __ENEMY_H__
