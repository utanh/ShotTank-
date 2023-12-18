#include "ENEMY03.h"

using namespace std;
using namespace cimg_library;

unsigned char colorTankENEMY03_wheel[] = { 255, 185, 15 };
unsigned char colorTankENEMY03_body[] = { 238, 173, 14 };
unsigned char colorTankENEMY03_head[] = { 205, 149, 12 };

ENEMY03::ENEMY03()
{
    mau = 1;
    loai = -3.2;
    cd = 3000;
    set_hdCoBan();
}

void ENEMY03::set_hdCoBan()
{
    hdCoBan.assign(r, d, 1, 3, 0);
    hdCoBan.draw_rectangle(0, 0, 7, 23, colorTankENEMY03_wheel);
    hdCoBan.draw_rectangle(22, 0, 29, 23, colorTankENEMY03_wheel);
    hdCoBan.draw_ellipse(14, 12, 14, 10, 0, colorTankENEMY03_body);
    hdCoBan.draw_ellipse(15, 12, 14, 10, 0, colorTankENEMY03_body);
    hdCoBan.draw_ellipse(14, 18, 2, 12, 0, colorTankENEMY03_head);
    hdCoBan.draw_ellipse(15, 18, 2, 12, 0, colorTankENEMY03_head);
}

void ENEMY03::vaCham_Tuong(Object obj)
{
    if(MovingObj::vaCham(obj) && obj.get_loai() == 1)
    {
        MovingObj::vaCham_Tuong(obj);
        set_hgDi(rand_hgDi());
    }
}
void ENEMY03::vaCham_Tank(Tank& tank)
{
    if(get_tocDo() == 0)
    {
        if(tank.get_loai() != 3)
        {
            set_hgDi(rand_hgDi());
            set_tocDo(4);
        }
        else
        {
            if(tank.get_old_hgDi() != tank.get_hgDi())
                set_tocDo(4);
        }
    }

    if(MovingObj::vaCham((Object)tank) && abs(tank.get_loai()) >= 3)
    {
        MovingObj::vaCham_Tuong((Object)tank);
        set_tocDo(0);
    }
}

HuongDi ENEMY03::rand_hgDi()
{
    int hg;
    if(get_hgDi() == DOWN)
    {
        hg = 0;
    }
    else if(get_hgDi() == UP)
    {
        hg = 1;
    }
    else if(get_hgDi() == RIGHT)
    {
        hg = 2;
    }
    else if(get_hgDi() == LEFT)
    {
        hg = 3;
    }

    int new_hg;
    do
    {
        new_hg = rand()%4;
    }while(new_hg == hg);

    if(new_hg == 0)
    {
        return DOWN;
    }
    else if(new_hg == 1)
    {
        return UP;
    }
    else if(new_hg == 2)
    {
        return RIGHT;
    }
    else if(new_hg == 3)
    {
        return LEFT;
    }
}

void ENEMY03::thaBom()
{
    int ktra = 0;

    if(get_cd() <= 0)
    {
        if((x < player.x && x + get_r()/2 > player.x) ||
           (x < player.x + player.get_r()/2 && x + get_r() > player.x + player.get_r()))
        {
            if(y < player.y)
                set_hgDi(DOWN);
            else
                set_hgDi(UP);

            ktra = 1;
        }
        else if((y < player.y && y + get_d()/2 > player.y) ||
                (y < player.y + player.get_d()/2 && y + get_d() > player.y + player.get_d()))
        {
            if(x < player.x)
                set_hgDi(RIGHT);
            else
                set_hgDi(LEFT);

            ktra = 1;
        }

        for(int i = 0; i < 4 && ktra == 1; i++)
        {
            if(bangDan[i].get_vTri() == IN_TANK)
            {
                bangDan[i].set_hgDi(get_hgDi());
                bangDan[i].set_vTri(OUT_TANK);

                if(get_hgDi() == DOWN)
                {
                    bangDan[i].x = x + r/2;
                    bangDan[i].y = y + d;
                }
                else if(get_hgDi() == UP)
                {
                    bangDan[i].x = x + r/2;
                    bangDan[i].y = y - bangDan[i].get_d();
                }
                else if(get_hgDi() == RIGHT)
                {
                    bangDan[i].x = x + r;
                    bangDan[i].y = y + d/2;
                }
                else if(get_hgDi() == LEFT)
                {
                    bangDan[i].x = x - bangDan[i].get_r();
                    bangDan[i].y = y + r/2;
                }
                reset_cd(750);
                set_hgDi(rand_hgDi());
                break;
            }
        }
    }
}
