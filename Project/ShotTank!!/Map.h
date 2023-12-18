#ifndef __Map_H__
#define __Map_H__

#include "Tuong.h"
#include "PLAYER.h"
#include "ENEMY.h"
#include "ENEMY02.h"
#include "Dan.h"
#include <vector>
#include <sstream>
#include <string>

using namespace cimg_library;

class Map{
protected:
    PLAYER player;
    vector<ENEMY> enemy;
    vector<ENEMY02> enemy02;
    vector<Tuong> tuong;
    vector<Tuong> tuong_shadow;
    int time;

public:

    virtual void setUp();

    virtual int get_n_e();

    virtual void dem_time(const int& nhip);
    virtual void ghiTime();
    virtual void reset_time();

    virtual void xuLy_napDan();
    virtual void xuLy_cuongEp_napDan();
    virtual void xuLy_diChuyen_ban_vaCham(CImgDisplay& window, CImg<>& imgMain, int& ts_map, int& ts_ktra, int& ktraRestart, int& ts_WinLose);
    virtual void xuLy_truCD(const int& nhip);
    virtual void xuLy_enemyChet();

    virtual void hienThiMap(CImg<>& imgMain);

    virtual bool player_hetMau();

    virtual void set_giaoDien(CImg<>& imgMain);
};

#endif // __Map_H__
