#include <time.h>
#include "Menu.h"
#include "Selection.h"
#include "Map01.h"
#include "Map02.h"
#include "Map03.h"
#include "Map04.h"
#include "Map05.h"
#include "Map06.h"

using namespace cimg_library;
using namespace std;


int main()
{
    srand(time(0));
    CImgDisplay window(1000, 700, "Shot Tank !!");
    CImg<> imgMain(1000, 700, 1, 3, 0);
    int nhip = 10;

    vector<Map*> n_map;
    n_map.resize(8);
    n_map[0] = new Menu;
    n_map[1] = new Selection;
    n_map[2] = new Map01;
    n_map[3] = new Map02;
    n_map[4] = new Map03;
    n_map[5] = new Map04;
    n_map[6] = new Map05;
    n_map[7] = new Map06;

    int ktraTao = 0;
    int ktraRestart = 0;
    int i = 0;
    int ktraChuyenMap = 0;
    int WinLose = 0;

    while (!window.is_closed())
    {
        while(i == 0)
        {
            if(ktraTao == 0)
            {
                for(int j = 0; j < n_map.size(); j++)
                {
                    n_map[j]->setUp();
                    n_map[j]->reset_time();
                    n_map[j]->xuLy_cuongEp_napDan();
                }

                ktraTao = 1;
            }

            n_map[0]->hienThiMap(imgMain);
            n_map[0]->set_giaoDien(imgMain);
            window.display(imgMain).wait(nhip);

            n_map[0]->dem_time(10);
            n_map[0]->xuLy_napDan();
            n_map[0]->xuLy_diChuyen_ban_vaCham(window, imgMain, i, ktraTao, ktraRestart, WinLose);
            n_map[0]->xuLy_truCD(30);
            n_map[0]->xuLy_enemyChet();

            imgMain.fill(0);

            if(((Menu*)n_map[0])->get_mauNEWGAME() <= 0){
                i = 2;
                ktraChuyenMap = 1;
            }
            else if(((Menu*)n_map[0])->get_mauSELECTION() <= 0){
                while(1)
                {
                    n_map[1]->hienThiMap(imgMain);
                    n_map[1]->set_giaoDien(imgMain);
                    window.display(imgMain).wait(nhip);

                    n_map[1]->dem_time(10);
                    n_map[1]->xuLy_napDan();
                    n_map[1]->xuLy_diChuyen_ban_vaCham(window, imgMain, i, ktraTao, ktraRestart, WinLose);
                    n_map[1]->xuLy_truCD(30);
                    n_map[1]->xuLy_enemyChet();

                    imgMain.fill(0);

                    if(((Selection*)n_map[1])->get_mauMap01() <= 0){
                        i = 2;
                        ktraChuyenMap = 1;
                        break;
                    }
                    else if(((Selection*)n_map[1])->get_mauMap02() <= 0){
                        i = 3;
                        ktraChuyenMap = 1;
                        break;
                    }
                    else if(((Selection*)n_map[1])->get_mauMap03() <= 0){
                        i = 4;
                        ktraChuyenMap = 1;
                        break;
                    }
                    else if(((Selection*)n_map[1])->get_mauMap04() <= 0){
                        i = 5;
                        ktraChuyenMap = 1;
                        break;
                    }
                    else if(((Selection*)n_map[1])->get_mauMap05() <= 0){
                        i = 6;
                        ktraChuyenMap = 1;
                        break;
                    }
                    else if(((Selection*)n_map[1])->get_mauMap06() <= 0){
                        i = 7;
                        ktraChuyenMap = 1;
                        break;
                    }
                }
            }
        }

        n_map[i]->hienThiMap(imgMain);
        n_map[i]->set_giaoDien(imgMain);
        if(ktraChuyenMap == 1){
            window.display(imgMain).wait(3000);
            ktraChuyenMap = 0;
        }
        window.display(imgMain).wait(nhip);

        n_map[i]->dem_time(10);
        n_map[i]->xuLy_napDan();
        n_map[i]->xuLy_diChuyen_ban_vaCham(window, imgMain, i, ktraTao, ktraRestart, WinLose);
        n_map[i]->xuLy_truCD(30);
        n_map[i]->xuLy_enemyChet();

        imgMain.fill(0);

        if(ktraRestart == 1)
        {
            n_map[i]->setUp();
            n_map[i]->reset_time();
            n_map[i]->xuLy_cuongEp_napDan();
            ktraRestart = 0;
            ktraChuyenMap = 1;
        }

        //Chuyen map
        if(i < n_map.size() && i != 0 && i != 1){
            if(n_map[i]->get_n_e() == 0)
            {
                WinLose = 1;
                n_map[i]->ghiTime();
                ktraChuyenMap = 1;
            }
        }

        if(i == n_map.size() || n_map[i]->player_hetMau()){
            WinLose = 2;
        }
    }

    return 0;
}
