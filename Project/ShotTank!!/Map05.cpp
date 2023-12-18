#include "Map05.h"
#include <fstream>

using namespace std;
using namespace cimg_library;

unsigned char colorTime05[] = { 255, 255, 255 };
unsigned char colorBlood05[] = { 255, 69, 0 };

void Map05::setUp()
{
    ifstream inp("Map05.TXT");
    if(inp.fail())
        cout << "\n*****Khong mo duoc file*****\n";

    int mau_p;
    inp >> mau_p;
    player.set_mau(mau_p);
    inp.ignore(1000, '\n');

    int hg_p;
    inp >> hg_p >> player.x >> player.y;
    if(hg_p == 0){
        player.set_hgDi(DOWN);
    }
    else if(hg_p == 1){
        player.set_hgDi(UP);
    }
    else if(hg_p == 2){
        player.set_hgDi(RIGHT);
    }
    else if(hg_p == 3){
        player.set_hgDi(LEFT);
    }
    inp.ignore(1000, '\n');


    int n_e, mau_e;
    inp >> n_e >> mau_e;
    enemy.resize(n_e);
    inp.ignore(1000, '\n');

    for(int i = 0; i < n_e; i++)
    {
        enemy[i].set_mau(mau_e);

        int hg_e;
        inp >> hg_e >> enemy[i].x >> enemy[i].y;

        if(hg_e == 0){
            enemy[i].set_hgDi(DOWN);
        }
        else if(hg_e == 1){
            enemy[i].set_hgDi(UP);
        }
        else if(hg_e == 2){
            enemy[i].set_hgDi(RIGHT);
        }
        else if(hg_e == 3){
            enemy[i].set_hgDi(LEFT);
        }

        inp.ignore(1000, '\n');
    }


    int n_e2, mau_e2;
    inp >> n_e2 >> mau_e2;
    enemy02.resize(n_e2);
    inp.ignore(1000, '\n');

    for(int i = 0; i < n_e2; i++)
    {
        enemy02[i].set_mau(mau_e2);

        int hg_e2;
        inp >> hg_e2 >> enemy02[i].x >> enemy02[i].y;

        if(hg_e2 == 0){
            enemy02[i].set_hgDi(DOWN);
        }
        else if(hg_e2 == 1){
            enemy02[i].set_hgDi(UP);
        }
        else if(hg_e2 == 2){
            enemy02[i].set_hgDi(RIGHT);
        }
        else if(hg_e2 == 3){
            enemy02[i].set_hgDi(LEFT);
        }

        inp.ignore(1000, '\n');
    }


    int n_t, mau_t;
    inp >> n_t >> mau_t;
    tuong.resize(n_t);
    inp.ignore(1000, '\n');

    for(int i = 0; i < n_t; i++)
    {
        tuong[i].set_mau(mau_t);

        int temp_d, temp_r;
        inp >> tuong[i].x >> tuong[i].y >> temp_r >> temp_d;
        tuong[i].set_r(temp_r);
        tuong[i].set_d(temp_d);

        inp.ignore(1000, '\n');
    }


    int n_ts, mau_ts;
    inp >> n_ts >> mau_ts;
    tuong_shadow.resize(n_ts);
    inp.ignore(1000, '\n');

    for(int i = 0; i < n_ts; i++)
    {
        tuong_shadow[i].set_mau(mau_ts);

        int temp_d, temp_r;
        inp >> tuong_shadow[i].x >> tuong_shadow[i].y >> temp_r >> temp_d;
        tuong_shadow[i].set_r(temp_r);
        tuong_shadow[i].set_d(temp_d);

        inp.ignore(1000, '\n');
    }

    inp.close();
}

void Map05::set_giaoDien(CImg<>& imgMain)
{
    Map::set_giaoDien(imgMain);

    imgMain.draw_text(850, 60, "MAP 05", colorTime05, 0, 1, 30);

    imgMain.draw_text(850, 150, "ENEMY : 6", colorTime05, 0, 1, 20);

    imgMain.draw_text(810, 250, "Speed tank : ", colorTime05, 0, 1, 18);
    imgMain.draw_text(830, 270, "Player : 4px/10ms", colorTime05, 0, 1, 14);
    imgMain.draw_text(830, 285, "TankEnemy : 4px/10ms", colorTime05, 0, 1, 14);
    imgMain.draw_text(830, 300, "CrashEnemy : 2px/10ms", colorTime05, 0, 1, 14);

    imgMain.draw_text(810, 340, "Speed bullet : ", colorTime05, 0, 1, 18);
    imgMain.draw_text(830, 355, "Player : 10px/10ms", colorTime05, 0, 1, 14);
    imgMain.draw_text(830, 370, "TankEnemy : 10px/10ms", colorTime05, 0, 1, 14);

    imgMain.draw_text(810, 410, "Max blood : ", colorTime05, 0, 1, 18);
    imgMain.draw_text(830, 425, "Player : 5", colorTime05, 0, 1, 14);
    imgMain.draw_text(830, 440, "TankEnemy : 2", colorTime05, 0, 1, 14);
    imgMain.draw_text(830, 455, "CrashEnemy : 8", colorTime05, 0, 1, 14);

    string s_mau_p;
    ostringstream convert;
    convert << player.get_mau();
    s_mau_p = convert.str();
    char *c_mau_p = new char[s_mau_p.size() + 1];
    for(int i = 0; i < s_mau_p.size(); i++)
	{
		c_mau_p[i] = s_mau_p[i];
	}
	c_mau_p[s_mau_p.size()] = '\0';
	imgMain.draw_text(895, 600, c_mau_p, colorBlood05, 0, 1, 20);
}

void Map05::ghiTime()
{
    int old_time;
    ifstream inp("Map05_Time.TXT");
    if(inp.fail())
        cout << "\n*****Khong mo duoc file01*****\n";
    inp >> old_time;
    inp.close();

    if(time < old_time || time != '#')
    {
        ofstream out("Map05_Time.TXT");

        if(out.fail())
            cout << "\n*****Khong mo duoc file*****\n";

        out << time;

        out.close();
    }
}
