#ifndef __ENEMY03_H__
#define __ENEMY03_H__

#include "Tank.h"
#include <time.h>
#include <stdlib.h>
using namespace cimg_library;

class ENEMY03 : public Tank{
public:
    ENEMY03();

    void set_hdCoBan();

    void vaCham_Tuong(Object obj);
    void vaCham_Tank(Tank& tank);
    HuongDi rand_hgDi();

    void thaBom();
};

#endif // __ENEMY03_H__
