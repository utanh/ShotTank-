#ifndef __Selection_H__
#define __Selection_H__

#include "Map.h"

using namespace cimg_library;

class Selection : public Map{
public:
    void setUp();

    void set_giaoDien(CImg<>& imgMain);
    int get_mauMap01();
    int get_mauMap02();
    int get_mauMap03();
    int get_mauMap04();
    int get_mauMap05();
    int get_mauMap06();
};

#endif // __Selection_H__



