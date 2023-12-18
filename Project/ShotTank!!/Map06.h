#ifndef __Map06_H__
#define __Map06_H__

#include "Map.h"

using namespace cimg_library;

class Map06 : public Map{
public:
    void setUp();

    void set_giaoDien(CImg<>& imgMain);

    void ghiTime();
};

#endif // __Map06_H__

