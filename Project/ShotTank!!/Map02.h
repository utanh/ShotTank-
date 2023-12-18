#ifndef __Map02_H__
#define __Map02_H__

#include "Map.h"

using namespace cimg_library;

class Map02 : public Map{
public:
    void setUp();

    void set_giaoDien(CImg<>& imgMain);

    void ghiTime();
};

#endif // __Map02_H__


