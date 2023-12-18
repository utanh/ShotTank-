#include "Map.h"

using namespace std;
using namespace cimg_library;

unsigned char colorTime[] = { 255, 255, 255 };
unsigned char colorKhung[] = { 100, 145, 100 };

void Map::setUp()
{
    enemy.resize(0);
    enemy02.resize(0);
    tuong.resize(0);
    tuong_shadow.resize(0);
}

int Map::get_n_e()
{
    return enemy.size()+enemy02.size();
}

void Map::dem_time(const int& nhip)
{
    time += nhip;
}
void Map::ghiTime()
{
}
void Map::reset_time()
{
    time = 0;
}

void Map::xuLy_napDan()
{
   player.napDan();

   for(int i = 0; i < enemy.size(); i++)
        enemy[i].napDan();
}
void Map::xuLy_cuongEp_napDan()
{
    player.cuongEp_napDan();
    player.reset_cd(0);

    for(int i = 0; i < enemy.size(); i++){
        enemy[i].cuongEp_napDan();
        enemy[i].reset_cd(0);
    }

    for(int i = 0; i < enemy02.size(); i++)
        enemy02[i].reset_cd(0);
}
void Map::xuLy_diChuyen_ban_vaCham(CImgDisplay& window, CImg<>& imgMain, int& ts_map, int& ts_ktra, int& ts_restart, int& ts_WinLose)
{
    //PLAYER========================================================================================
    player.set_old_hgDi();
    player.dieuKhien(window, imgMain, ts_map, ts_ktra, ts_restart, ts_WinLose);
    player.Dan_diChuyen();

    for(int i = 0; i < enemy.size(); i++)
    {
        player.Dan_vaCham(enemy[i]);
        player.vaCham_Tank(enemy[i]);
    }

    for(int i = 0; i < enemy02.size(); i++)
    {
        player.Dan_vaCham(enemy02[i]);
    }

    for(int i = 0; i < tuong.size(); i++)
    {
        player.Dan_vaCham(tuong[i]);
        player.vaCham_Tuong(tuong[i]);
    }

    //ENEMY===========================================================================================
    for(int i = 0; i < enemy.size(); i++)
    {
        enemy[i].ban(player);
        enemy[i].diChuyen();
        enemy[i].Dan_diChuyen();


        enemy[i].Dan_vaCham(player);
        enemy[i].vaCham_Tank(player);

        for(int h = 0; h < enemy.size() - 1; h++){
            if(h != i)
                enemy[i].vaCham_Tank(enemy[h]);
        }

        for(int l = 0; l < enemy02.size(); l++){
            enemy[i].vaCham_Tank(enemy02[l]);
        }

        for(int j = 0; j < tuong.size(); j++){
            enemy[i].Dan_vaCham(tuong[j]);
            enemy[i].vaCham_Tuong(tuong[j]);
        }

        for(int k = 0; k < tuong_shadow.size(); k++){
            enemy[i].vaCham_Tuong(tuong_shadow[k]);
        }
    }

    //ENEMY02=========================================================================================

    for(int i = 0; i < enemy02.size(); i++)
    {
        enemy02[i].huc(player);
        enemy02[i].diChuyen();


        for(int h = 0; h < enemy02.size() - 1; h++){
            if(h != i)
                enemy02[i].vaCham_Tank(enemy02[h]);
        }

        for(int l = 0; l < enemy.size(); l++){
            enemy02[i].vaCham_Tank(enemy[l]);
        }

        for(int j = 0; j < tuong.size(); j++){
            enemy02[i].vaCham_Tuong(tuong[j]);
        }

        for(int k = 0; k < tuong_shadow.size(); k++){
            enemy02[i].vaCham_Tuong(tuong_shadow[k]);
        }
    }
}
void Map::xuLy_truCD(const int& nhip)
{
    player.tru_cd(nhip);

    for(int i = 0; i < enemy.size(); i++)
        enemy[i].tru_cd(nhip);

    for(int i = 0; i < enemy02.size(); i++)
        enemy02[i].tru_cd(nhip);
}
void Map::xuLy_enemyChet()
{
    int n = enemy.size();
    for(int i = 0; i < n; i++)
    {
        if(enemy[i].get_mau() <= 0)
         {
            enemy.erase(enemy.begin() + i);
            i--;
            n--;
         }
    }

    int m = enemy02.size();
    for(int i = 0; i < m; i++)
    {
        if(enemy02[i].get_mau() <= 0)
         {
            enemy02.erase(enemy02.begin() + i);
            i--;
            m--;
         }
    }
}

void Map::hienThiMap(CImg<>& imgMain)
{
    player.hienThi(imgMain);
    player.Dan_hienThi(imgMain);

    for(int i = 0; i < enemy.size(); i++){
        enemy[i].hienThi(imgMain);
        enemy[i].Dan_hienThi(imgMain);
    }

    for(int i = 0; i < enemy02.size(); i++){
        enemy02[i].hienThi(imgMain);
    }

    for(int i = 0; i < tuong.size(); i++){
        tuong[i].set_hdCoBan();
        tuong[i].hienThi(imgMain);
    }
}

bool Map::player_hetMau()
{
    if(player.get_mau() <= 0)
        return true;

    return false;
}

void Map::set_giaoDien(CImg<>& imgMain)
{
    //TIME===========================================================
    string s_time;
    ostringstream convert;
    convert << time;
    s_time = convert.str();
    char *c_time = new char[s_time.size() + 1];
    for(int i = 0; i < s_time.size(); i++)
	{
		c_time[i] = s_time[i];
	}
	c_time[s_time.size()] = 'm';
	c_time[s_time.size()+1] = 's';
	c_time[s_time.size()+2] = '\0';
    imgMain.draw_text(400 - (s_time.size()+2)*10 / 2, 8, c_time, colorTime, 0, 1, 14);
}
