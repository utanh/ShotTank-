#ifndef __ENEMY02_H__
#define __ENEMY02_H__

#include "Tank.h"
#include "PLAYER.h"
#include <time.h>
#include <stdlib.h>
using namespace cimg_library;

class ENEMY02 : public Tank{
public:
    ENEMY02();

    void set_hdCoBan();

    void vaCham_Tuong(Object obj);
    void vaCham_Tank(Tank& tank);
    HuongDi rand_hgDi();

    void huc(PLAYER& player);

    void hienThi(CImg<>& imgMain);
};

#endif // __ENEMY02_H__

