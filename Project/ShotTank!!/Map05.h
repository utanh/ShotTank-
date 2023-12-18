#ifndef __Map05_H__
#define __Map05_H__

#include "Map.h"

using namespace cimg_library;

class Map05 : public Map{
public:
    void setUp();

    void set_giaoDien(CImg<>& imgMain);

    void ghiTime();
};

#endif // __Map05_H__
