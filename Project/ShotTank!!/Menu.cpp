#include "Menu.h"
#include <fstream>

using namespace std;
using namespace cimg_library;

unsigned char colorChuThich[] = { 255, 255, 255 };
unsigned char colorChu[] = { 255, 140, 0 };
unsigned char colorNen[] = { 0, 0, 0};
unsigned char colorTextLucChon[] = { 85, 26, 139 };
unsigned char colorLucChon[] = { 255, 204, 153 };
unsigned char colorNenLucChon[] = { 255, 69, 0 };

void Menu::setUp()
{
    ifstream inp("Menu.TXT");
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
        if(i == 0 || i == 1)
            tuong[i].set_mau(mau_t);
        else
            tuong[i].set_mau(9999);
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

void Menu::set_giaoDien(CImg<>& imgMain)
{
    CImg<> S(120, 160, 1, 3, 0);
    S.draw_rectangle(0, 0, 120, 160, colorChu);
    S.draw_triangle(0, 0, 20, 0, 0, 20, colorNen);
    S.draw_triangle(100, 0, 120, 0, 120, 20, colorNen);
    S.draw_triangle(20, 40, 40, 20, 40, 40, colorNen);
    S.draw_triangle(100, 40, 80, 20, 80, 40, colorNen);
    S.draw_rectangle(40, 20, 80, 40, colorNen);
    S.draw_triangle(20, 40, 120, 40, 120, 100, colorNen);
    S.draw_triangle(0, 60, 0, 120, 100, 120, colorNen);
    S.draw_triangle(120, 160, 100, 160, 120, 140, colorNen);
    S.draw_triangle(20, 160, 0, 160, 0, 140, colorNen);
    S.draw_triangle(100, 120, 80, 140, 80, 120, colorNen);
    S.draw_triangle(20, 120, 40, 140, 40, 120, colorNen);
    S.draw_rectangle(80, 140, 40, 120, colorNen);

    CImg<> H(120, 160, 1, 3, 0);
    H.draw_rectangle(0, 0, 120, 160, colorChu);
    H.draw_rectangle(30, 0, 90, 65, colorNen);
    H.draw_rectangle(30, 95, 90, 160, colorNen);

    CImg<> O(120, 160, 1, 3, 0);
    O.draw_rectangle(0, 0, 120, 160, colorNen);
    O.draw_ellipse(60, 80, 60, 80, 0, colorChu);
    O.draw_ellipse(60, 80, 30, 50, 0, colorNen);

    CImg<> T(120, 160, 1, 3, 0);
    T.draw_rectangle(0, 0, 120, 160, colorChu);
    T.draw_rectangle(0, 30, 45, 160, colorNen);
    T.draw_rectangle(120, 30, 75, 160, colorNen);

    CImg<> A(120, 160, 1, 3, 0);
    A.draw_rectangle(0, 0, 120, 160, colorChu);
    A.draw_triangle(0, 0, 0, 160, 40, 0, colorNen);
    A.draw_triangle(80, 0, 120, 0, 120, 160, colorNen);
    A.draw_triangle(60, 20, 50, 70, 70, 70, colorNen);
    A.draw_triangle(44, 100, 32, 160, 44, 160, colorNen);
    A.draw_triangle(120-44, 100, 120-32, 160, 120-44, 160, colorNen);
    A.draw_rectangle(44, 100, 120-44, 160, colorNen);

    CImg<> N(120, 160, 1, 3, 0);
    N.draw_rectangle(0, 0, 120, 160, colorChu);
    N.draw_triangle(30, 160, 90, 160, 30, 60, colorNen);
    N.draw_triangle(90, 0, 30, 0, 90, 100, colorNen);

    CImg<> K(120, 160, 1, 3, 0);
    K.draw_rectangle(0, 0, 120, 160, colorChu);
    K.draw_triangle(30, 0, 80, 0, 30, 50, colorNen);
    K.draw_triangle(30, 160, 80, 160, 30, 110, colorNen);
    K.draw_triangle(120, 0, 120, 160, 40, 80, colorNen);
    K.draw_rectangle(0, 110, 30, 130, colorNen);

    CImg<> chamThan(30, 160, 1, 3, 0);
    chamThan.draw_rectangle(0, 0, 30, 160, colorChu);
    chamThan.draw_rectangle(0, 110, 30, 130, colorNen);

    imgMain.draw_image(220, 70, S);
    imgMain.draw_image(220 + 120 + 10, 70, H);
    imgMain.draw_image(220 + (120 + 10) * 2, 70, O);
    imgMain.draw_image(220 + (120 + 10) * 3, 70, T);
    imgMain.draw_image(220 , 70 + 160 + 50, T);
    imgMain.draw_image(220 + 120 + 10, 70 + 160 + 50, A);
    imgMain.draw_image(220 + (120 + 10) * 2, 70 + 160 + 50, N);
    imgMain.draw_image(220 + (120 + 10) * 3, 70 + 160 + 50, K);
    imgMain.draw_image(220 + (120 + 10) * 4 + 10, 70 + 160 + 50, chamThan);

    imgMain.draw_rectangle(250, 480 + 34, 250 + 200, 578 - 34, colorNenLucChon);
    imgMain.draw_rectangle(750 - 200, 480 + 34, 750, 578 - 34, colorNenLucChon);
    imgMain.draw_rectangle(252, 482 + 34, 248 + 200, 576 - 34, colorLucChon);
    imgMain.draw_rectangle(752 - 200, 482 + 34, 748, 576 - 34, colorLucChon);

    imgMain.draw_text(250 + 61, 480 + 34 + 7, "SELECTION", colorTextLucChon, 0, 1, 15);
    imgMain.draw_text(750-200 + 61, 480 + 34 + 7, "NEW GAME", colorTextLucChon, 0, 1, 15);

    imgMain.draw_text(350, 630-32, "Use 'W'; 'A'; 'S'; 'D' to move", colorChuThich, 0 , 1, 15);
    imgMain.draw_text(350, 630-16, "Use 'Space' to fire", colorChuThich, 0 , 1, 15);
    imgMain.draw_text(350, 630, "DESTROY ALL ENEMY TO WIN", colorChuThich, 0 , 1, 15);
    imgMain.draw_text(350, 630+16, "Now MOVE TANK and FIRE your selection!!", colorChuThich, 0 , 1, 15);

    imgMain.draw_text(770, 530-16, "When you start in a new map,", colorChuThich, 0 , 1, 15);
    imgMain.draw_text(808, 530, "you have 3s to check it.", colorChuThich, 0 , 1, 15);
}

int Menu::get_mauNEWGAME()
{
    return tuong[0].get_mau();
}
int Menu::get_mauSELECTION()
{
    return tuong[1].get_mau();
}
