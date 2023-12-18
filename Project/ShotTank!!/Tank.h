#ifndef __Tank_H__
#define __Tank_H__

#include "MovingObj.h"
#include "Dan.h"
#include <vector>
using namespace cimg_library;
using namespace std;

class Tank : public MovingObj{
protected:
    HuongDi old_hgDi;
    int cd;
    vector<Dan> bangDan;

public:
    Tank();

    HuongDi get_old_hgDi();
    void set_old_hgDi();

    virtual int get_cd();
    virtual void reset_cd(const int& ts_cdMAX);
    virtual void tru_cd(const int& nhip);

    virtual void set_hdCoBan() = 0;
    virtual void hienThi(CImg<>& imgMain);

    virtual void napDan();
    virtual void cuongEp_napDan();
    virtual void Dan_diChuyen();
    virtual bool Dan_vaCham(Object& obj);
    virtual void Dan_hienThi(CImg<>& imgMain);
};

#endif // __Tank_H__
