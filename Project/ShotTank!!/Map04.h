#ifndef __Map04_H__
#define __Map04_H__

#include "Map.h"

using namespace cimg_library;

class Map04 : public Map{
public:
    void setUp();

    void set_giaoDien(CImg<>& imgMain);

    void ghiTime();
};

#endif // __Map04_H__
