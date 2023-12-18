#ifndef __Map01_H__
#define __Map01_H__

#include "Map.h"

using namespace cimg_library;

class Map01 : public Map{
public:
    void setUp();

    void set_giaoDien(CImg<>& imgMain);

    void ghiTime();
};

#endif // __Map01_H__

