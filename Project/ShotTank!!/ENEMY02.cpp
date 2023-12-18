#include "ENEMY02.h"

using namespace std;
using namespace cimg_library;

unsigned char colorTankENEMY02_nen[] = { 0, 0, 0 };

unsigned char colorTankENEMY02_wheel[] = { 213, 155, 0 };
unsigned char colorTankENEMY02_body[] = { 243, 194, 70 };
unsigned char colorTankENEMY02_head[] = { 241, 175, 0 };
unsigned char colorTankENEMY02_head02[] = { 252, 224, 166 };

unsigned char colorTankENEMY02_wheel_2[] = { 197, 0, 35 };
unsigned char colorTankENEMY02_body_2[] = { 229, 70, 70 };
unsigned char colorTankENEMY02_head_2[] = { 223	, 0, 41 };
unsigned char colorTankENEMY02_head02_2[] = { 245, 168, 154 };

unsigned char colorTankENEMY02_boom[] = {72, 61, 139};

ENEMY02::ENEMY02()
{
    set_d(40);
    set_r(40);
    bangDan.resize(0);
    mau = 1;
    loai = -3.1;
    set_hdCoBan();
}

void ENEMY02::set_hdCoBan()
{
    hdCoBan.assign(r, d, 1, 3, 0);

    hdCoBan.draw_rectangle(0, 20, 40, 40, colorTankENEMY02_nen);
    hdCoBan.draw_triangle(39, 39, 39, 20, 20, 20, colorTankENEMY02_head);
    hdCoBan.draw_triangle(0, 39, 0, 20, 19, 20, colorTankENEMY02_head);
    hdCoBan.draw_rectangle(0, 25, 12, 0, colorTankENEMY02_wheel);
    hdCoBan.draw_rectangle(27, 25, 39, 0, colorTankENEMY02_wheel);
    hdCoBan.draw_ellipse(19, 12, 19, 10, 0, colorTankENEMY02_body);
    hdCoBan.draw_ellipse(20, 12, 19, 10, 0, colorTankENEMY02_body);
    hdCoBan.draw_ellipse(19, 12, 4, 7, 0, colorTankENEMY02_head02);
    hdCoBan.draw_ellipse(20, 12, 4, 7, 0, colorTankENEMY02_head02);
}

void ENEMY02::vaCham_Tuong(Object obj)
{
    if(MovingObj::vaCham(obj) && obj.get_loai() == 1)
    {
        MovingObj::vaCham_Tuong(obj);
        set_hgDi(rand_hgDi());
    }
}
void ENEMY02::vaCham_Tank(Tank& tank)
{
    if(get_tocDo() == 0 && tank.get_loai() <= -3)
    {
            set_hgDi(rand_hgDi());
            set_tocDo(2);
    }

    if(MovingObj::vaCham(tank) && tank.get_loai() <= -3)
    {
        MovingObj::vaCham_Tuong(tank);
        set_tocDo(0);
    }
}

HuongDi ENEMY02::rand_hgDi()
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

void ENEMY02::huc(PLAYER& player)
{
    if(get_cd() <= 0)
    {
        if((x < player.x && x + get_r() > player.x) ||
           (x < player.x + player.get_r() && x + get_r() > player.x + player.get_r()))
        {
            if(y < player.y)
                set_hgDi(DOWN);
            else
                set_hgDi(UP);

            reset_cd(3000);
            set_tocDo(8);
        }
        else if((y < player.y && y + get_d() > player.y) ||
                (y < player.y + player.get_d() && y + get_d() > player.y + player.get_d()))
        {
            if(x < player.x)
                set_hgDi(RIGHT);
            else
                set_hgDi(LEFT);

            reset_cd(3000);
            set_tocDo(8);
        }
    }

    if(!((x < player.x && x + get_r() > player.x) || (x < player.x + player.get_r() && x + get_r() > player.x + player.get_r())) &&
       !((y < player.y && y + get_d() > player.y) || (y < player.y + player.get_d() && y + get_d() > player.y + player.get_d())))
    {
        set_tocDo(2);
    }

    if(vaCham(player) == true)
    {
        player.tru_mau(1);
        vaCham_Tuong(player);
        set_tocDo(1);
    }
}

void ENEMY02::hienThi(CImg<>& imgMain)
{
    if(get_tocDo() == 8)
    {
        hdCoBan.draw_rectangle(0, 20, 40, 40, colorTankENEMY02_nen);
        hdCoBan.draw_triangle(39, 39, 39, 20, 20, 20, colorTankENEMY02_head_2);
        hdCoBan.draw_triangle(0, 39, 0, 20, 19, 20, colorTankENEMY02_head_2);
        hdCoBan.draw_rectangle(0, 25, 12, 0, colorTankENEMY02_wheel_2);
        hdCoBan.draw_rectangle(27, 25, 39, 0, colorTankENEMY02_wheel_2);
        hdCoBan.draw_ellipse(19, 12, 19, 10, 0, colorTankENEMY02_body_2);
        hdCoBan.draw_ellipse(20, 12, 19, 10, 0, colorTankENEMY02_body_2);
        hdCoBan.draw_ellipse(19, 12, 4, 7, 0, colorTankENEMY02_head02_2);
        hdCoBan.draw_ellipse(20, 12, 4, 7, 0, colorTankENEMY02_head02_2);

        hdCoBan.draw_ellipse(19, 35, 5, 5, 0, colorTankENEMY02_boom);
        hdCoBan.draw_ellipse(20, 35, 5, 5, 0, colorTankENEMY02_boom);
    }
    else
        set_hdCoBan();

    if(get_hgDi() == DOWN)
        imgMain.draw_image(x, y, this->get_hdCoBan());
    else if(get_hgDi() == UP)
        imgMain.draw_image(x, y, this->get_hdCoBan().rotate(180));
    else if(get_hgDi() == LEFT)
        imgMain.draw_image(x, y, this->get_hdCoBan().rotate(90));
    else if(get_hgDi() == RIGHT)
        imgMain.draw_image(x, y, this->get_hdCoBan().rotate(-90));
}
