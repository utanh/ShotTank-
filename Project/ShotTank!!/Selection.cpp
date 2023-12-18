#include "Selection.h"
#include <fstream>

using namespace std;
using namespace cimg_library;

unsigned char colorTextMap[] = { 255, 255, 255};
unsigned char colorNenMap_ria[] = { 150, 205, 150 };
unsigned char colorNenMap[] = { 20, 20, 20 };

void Selection::setUp()
{
    ifstream inp("Selection.TXT");
    if(inp.fail())
        cout << "\n*****Khong mo duoc file01*****\n";

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


    int n_t, mau_t;
    inp >> n_t >> mau_t;
    tuong.resize(n_t);
    inp.ignore(1000, '\n');

    for(int i = 0; i < n_t; i++)
    {
        if(i <= 5)
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

void Selection::set_giaoDien(CImg<>& imgMain)
{
    //01===============================================================01
    imgMain.draw_rectangle(70, 70, 130, 130, colorNenMap_ria);
    imgMain.draw_rectangle(75, 75, 125, 125, colorNenMap);
    imgMain.draw_text(92, 77, "1", colorTextMap, 0, 1, 50);

    ifstream inp01("Map01_Time.TXT");
    if(inp01.fail())
        cout << "\n*****Khong mo duoc file*****\n";
    string highScore01;
    inp01 >> highScore01;
    inp01.close();

    imgMain.draw_text(50, 135, "Time:", colorTextMap, 0, 1, 14);
    char* c_hScore01 = new char[highScore01.size()+1];
    for(int i = 0; i < highScore01.size(); i++)
        c_hScore01[i] = highScore01[i];
    c_hScore01[highScore01.size()+1] = '\0';
    imgMain.draw_text(93, 135, c_hScore01, colorTextMap, 0, 1, 14);

    //04===============================================================04
    imgMain.draw_rectangle(70, 270, 130, 330, colorNenMap_ria);
    imgMain.draw_rectangle(75, 275, 125, 325, colorNenMap);
    imgMain.draw_text(88, 277, "4", colorTextMap, 0, 1, 50);

    ifstream inp04("Map04_Time.TXT");
    if(inp04.fail())
        cout << "\n*****Khong mo duoc file*****\n";
    string highScore04;
    inp04 >> highScore04;
    inp04.close();

    imgMain.draw_text(50, 335, "Time:", colorTextMap, 0, 1, 14);
    char* c_hScore04 = new char[highScore04.size()+1];
    for(int i = 0; i < highScore04.size(); i++)
        c_hScore04[i] = highScore04[i];
    c_hScore04[highScore04.size()+1] = '\0';
    imgMain.draw_text(93, 335, c_hScore04, colorTextMap, 0, 1, 14);

    //02================================================================02
    imgMain.draw_rectangle(470, 70, 530, 130, colorNenMap_ria);
    imgMain.draw_rectangle(475, 75, 525, 125, colorNenMap);
    imgMain.draw_text(490, 77, "2", colorTextMap, 0, 1, 50);

    ifstream inp02("Map02_Time.TXT");
    if(inp02.fail())
        cout << "\n*****Khong mo duoc file*****\n";
    string highScore02;
    inp02 >> highScore02;
    inp02.close();

    imgMain.draw_text(450, 135, "Time:", colorTextMap, 0, 1, 14);
    char* c_hScore02 = new char[highScore02.size()+1];
    for(int i = 0; i < highScore02.size(); i++)
        c_hScore02[i] = highScore02[i];
    c_hScore02[highScore02.size()+1] = '\0';
    imgMain.draw_text(493, 135, c_hScore02, colorTextMap, 0, 1, 14);

    //05================================================================05
    imgMain.draw_rectangle(470, 270, 530, 330, colorNenMap_ria);
    imgMain.draw_rectangle(475, 275, 525, 325, colorNenMap);
    imgMain.draw_text(490, 277, "5", colorTextMap, 0, 1, 50);

    ifstream inp05("Map05_Time.TXT");
    if(inp05.fail())
        cout << "\n*****Khong mo duoc file*****\n";
    string highScore05;
    inp05 >> highScore05;
    inp05.close();

    imgMain.draw_text(450, 335, "Time:", colorTextMap, 0, 1, 14);
    char* c_hScore05 = new char[highScore05.size()+1];
    for(int i = 0; i < highScore05.size(); i++)
        c_hScore05[i] = highScore05[i];
    c_hScore05[highScore05.size()+1] = '\0';
    imgMain.draw_text(493, 335, c_hScore05, colorTextMap, 0, 1, 14);

    //03================================================================03
    imgMain.draw_rectangle(870, 70, 930, 130, colorNenMap_ria);
    imgMain.draw_rectangle(875, 75, 925, 125, colorNenMap);
    imgMain.draw_text(890, 77, "3", colorTextMap, 0, 1, 50);

    ifstream inp03("Map03_Time.TXT");
    if(inp03.fail())
        cout << "\n*****Khong mo duoc file*****\n";
    string highScore03;
    inp03 >> highScore03;
    inp03.close();

    imgMain.draw_text(850, 135, "Time:", colorTextMap, 0, 1, 14);
    char* c_hScore03 = new char[highScore03.size()+1];
    for(int i = 0; i < highScore03.size(); i++)
        c_hScore03[i] = highScore03[i];
    c_hScore03[highScore03.size()+1] = '\0';
    imgMain.draw_text(893, 135, c_hScore03, colorTextMap, 0, 1, 14);

    //06================================================================06
    imgMain.draw_rectangle(870, 270, 930, 330, colorNenMap_ria);
    imgMain.draw_rectangle(875, 275, 925, 325, colorNenMap);
    imgMain.draw_text(890, 277, "6", colorTextMap, 0, 1, 50);

    ifstream inp06("Map06_Time.TXT");
    if(inp06.fail())
        cout << "\n*****Khong mo duoc file*****\n";
    string highScore06;
    inp06 >> highScore06;
    inp06.close();

    imgMain.draw_text(850, 335, "Time:", colorTextMap, 0, 1, 14);
    char* c_hScore06 = new char[highScore06.size()+1];
    for(int i = 0; i < highScore06.size(); i++)
        c_hScore06[i] = highScore06[i];
    c_hScore06[highScore06.size()+1] = '\0';
    imgMain.draw_text(893, 335, c_hScore06, colorTextMap, 0, 1, 14);
}

int Selection::get_mauMap01()
{
    return tuong[0].get_mau();
}
int Selection::get_mauMap02()
{
    return tuong[1].get_mau();
}
int Selection::get_mauMap03()
{
    return tuong[2].get_mau();
}
int Selection::get_mauMap04()
{
    return tuong[3].get_mau();
}
int Selection::get_mauMap05()
{
    return tuong[4].get_mau();
}
int Selection::get_mauMap06()
{
    return tuong[5].get_mau();
}
