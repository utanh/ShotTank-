#include "PLAYER.h"

using namespace std;
using namespace cimg_library;

unsigned char colorTankPlayer_wheel[] = { 255, 255, 255 };
unsigned char colorTankPlayer_body[] = { 240, 240, 240 };
unsigned char colorTankPlayer_head[] = { 220, 220, 220 };

unsigned char colorPAUSE_nen_ria[] = { 150, 205, 150 };
unsigned char colorPAUSE_nen[] = { 0, 0, 0 };

unsigned char colorText[] = { 255, 255, 255 };
unsigned char colorTextHeader[] = { 236, 135, 14 };


PLAYER::PLAYER()
{
    mau = 1;
    loai = 3;
    set_hdCoBan();
}

void PLAYER::set_hdCoBan()
{
    hdCoBan.assign(r, d, 1, 3, 0);
    hdCoBan.draw_rectangle(0, 0, 7, 23, colorTankPlayer_wheel);
    hdCoBan.draw_rectangle(22, 0, 29, 23, colorTankPlayer_wheel);
    hdCoBan.draw_ellipse(14, 12, 14, 10, 0, colorTankPlayer_body);
    hdCoBan.draw_ellipse(15, 12, 14, 10, 0, colorTankPlayer_body);
    hdCoBan.draw_ellipse(14, 18, 2, 12, 0, colorTankPlayer_head);
    hdCoBan.draw_ellipse(15, 18, 2, 12, 0, colorTankPlayer_head);
}

void PLAYER::dieuKhien(CImgDisplay& window, CImg<>& imgMain, int& ts_map, int& ts_ktra, int& ts_restart, int& ts_WinLose)
{
    if(window.is_keySPACE())
    {
        ban();
    }
    if(window.is_keyA())
    {
        set_hgDi(LEFT);
        diChuyen();
    }
    else if(window.is_keyD())
    {
        set_hgDi(RIGHT);
        diChuyen();
    }
    else if(window.is_keyW())
    {
        set_hgDi(UP);
        diChuyen();
    }
    else if(window.is_keyS())
    {
        set_hgDi(DOWN);
        diChuyen();
    }

    if(window.is_keyP() && ts_map != 0)
    {
        while(!window.is_keyO())
        {
            imgMain.draw_rectangle(240, 329, 560, 371, colorPAUSE_nen_ria);
            imgMain.draw_rectangle(246, 335, 554, 365, colorPAUSE_nen);
            imgMain.draw_rectangle(361, 335, 367, 365, colorPAUSE_nen_ria);
            imgMain.draw_rectangle(444, 335, 450, 365, colorPAUSE_nen_ria);

            imgMain.draw_text(248, 340, "CONTINUE(O)", colorText, 0, 1, 20);
            imgMain.draw_text(376, 340, "MENU(I)", colorText, 0, 1, 20);
            imgMain.draw_text(452, 340, "RESTART(U)", colorText, 0, 1, 20);
            window.display(imgMain).wait();

            if(window.is_keyI())
            {
                ts_map = 0;
                ts_ktra = 0;
                break;
            }
            if(window.is_keyU())
            {
                ts_restart = 1;
                break;
            }
        }
    }

    while(ts_WinLose == 2)
    {
        if(window.is_keyI())
        {
            ts_WinLose = 0;
            ts_map = 0;
            ts_ktra = 0;
        }

        if(window.is_keyU())
        {
            ts_WinLose = 0;
            ts_map++;
        }

        imgMain.draw_rectangle(295, 245, 505, 340, colorPAUSE_nen_ria);
        imgMain.draw_rectangle(301, 251, 499, 334, colorPAUSE_nen);
        imgMain.draw_rectangle(295, 297, 505, 303, colorPAUSE_nen_ria);
        imgMain.draw_rectangle(377, 303, 383, 340, colorPAUSE_nen_ria);
        imgMain.draw_text(320, 261, "YOU LOSE :(((", colorTextHeader, 0, 1, 30);
        imgMain.draw_text(308, 309, "MENU(I)", colorText, 0, 1, 20);
        imgMain.draw_text(391, 309, "RESTART(U)", colorText, 0, 1, 20);
        window.display(imgMain).wait();
    }
    while(ts_WinLose == 1)
    {
        if(window.is_keyI())
        {
            ts_WinLose = 0;
            ts_map = 0;
            ts_ktra = 0;
        }

        if(window.is_keyO())
        {
            ts_WinLose = 0;
            ts_map++;
        }

        imgMain.draw_rectangle(295, 245, 505, 340, colorPAUSE_nen_ria);
        imgMain.draw_rectangle(301, 251, 499, 334, colorPAUSE_nen);
        imgMain.draw_rectangle(295, 297, 505, 303, colorPAUSE_nen_ria);
        imgMain.draw_rectangle(377, 303, 383, 340, colorPAUSE_nen_ria);
        imgMain.draw_text(328, 261, "YOU WIN !!!!", colorTextHeader, 0, 1, 30);
        imgMain.draw_text(308, 309, "MENU(I)", colorText, 0, 1, 20);
        imgMain.draw_text(387, 309, "CONTINUE(O)", colorText, 0, 1, 20);
        window.display(imgMain).wait();
    }
}

void PLAYER::vaCham_Tuong(Object obj)
{
    if(MovingObj::vaCham(obj) && obj.get_loai() == 1)
    {
        MovingObj::vaCham_Tuong(obj);
    }
}
void PLAYER::vaCham_Tank(Tank& tank)
{
    if(old_hgDi != hgDi)
        set_tocDo(4);

    if(MovingObj::vaCham((Object)tank) && abs(tank.get_loai()) >= 3)
    {
        MovingObj::vaCham_Tuong((Object)tank);
        set_tocDo(0);
    }
}

void PLAYER::ban()
{
    if(get_cd() <= 0)
    {
        for(int i = 0; i < 4; i++)
        {
            if(bangDan[i].get_vTri() == IN_TANK)
            {
                bangDan[i].set_hgDi(get_hgDi());
                bangDan[i].set_vTri(OUT_TANK);

                if(get_hgDi() == DOWN)
                {
                    bangDan[i].x = x + r/2;
                    bangDan[i].y = y + d/2;
                }
                else if(get_hgDi() == UP)
                {
                    bangDan[i].x = x + r/2;
                    bangDan[i].y = y - bangDan[i].get_d()/2;
                }
                else if(get_hgDi() == RIGHT)
                {
                    bangDan[i].x = x + r/2;
                    bangDan[i].y = y + d/2;
                }
                else if(get_hgDi() == LEFT)
                {
                    bangDan[i].x = x - bangDan[i].get_r()/2;
                    bangDan[i].y = y + r/2;
                }
                reset_cd(750);
                break;
            }
        }
    }
}
