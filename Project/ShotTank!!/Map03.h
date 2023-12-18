#ifndef __Map03_H__
#define __Map03_H__

#include "Map.h"

using namespace cimg_library;

class Map03 : public Map{
public:
    void setUp();

    void set_giaoDien(CImg<>& imgMain);

    void ghiTime();
};

#endif // __Map03_H__



