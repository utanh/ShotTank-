#ifndef __Menu_H__
#define __Menu_H__

#include "Map.h"

using namespace cimg_library;

class Menu : public Map{
public:
    void setUp();

    void set_giaoDien(CImg<>& imgMain);
    int get_mauNEWGAME();
    int get_mauSELECTION();
};

#endif // __Menu_H__


