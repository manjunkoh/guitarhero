/*
 * graphics_HAL.c
 *
 *  Created on: Oct 18, 2018
 *      Author: Leyla
 */

#include <ti/grlib/grlib.h>
#include "LcdDriver/Crystalfontz128x128_ST7735.h"
#include "Timer32_HAL.h"
#include "ButtonLED_HAL.h"
#include "sound.h"
#include "song.h"

// 100ms in us unit is 100,000
#define T100MS_IN_US 100000


#define BALL_Y_STEP 10                   // The ball moves in y direction 10 pixesl per step
#define BALL_TIME_STEP T100MS_IN_US      // We update the location of the ball evey 100 ms
// The above two numbers result in 10/100ms = 10/0.1s = 100 pixel/sec movement for the ball

extern HWTimer_t timer0, timer1;

extern const tImage  songlist_16bit4BPP_UNCOMP;
extern const tImage  noteSplash_16bit4BPP_UNCOMP;
extern const tImage  resultimage_16bit4BPP_UNCOMP;

typedef enum {Main, QuickPlay, HowtoPlay, HighScores} Menu;

void make_5digit_NumString(unsigned int num, int8_t *string)
{
    string[0]= (        num  / 10000) +'0';
    string[1]= ((num%10000) / 1000) +'0';
    string[2]= ((num%1000) / 100) +'0';
    string[3]= ((num%100) / 10) +'0';
    string[4]= ((num%10) / 1) +'0';
    string[5]= 0;
}

void drawXY(Graphics_Context *g_sContext_p, unsigned int x, unsigned int y)
{
    int8_t string[6];

    Graphics_drawString(g_sContext_p, "x=", -1, 10, 5, true);
    make_5digit_NumString(x, string);
    Graphics_drawString(g_sContext_p, string, -1, 30, 5, true);

    Graphics_drawString(g_sContext_p, "y=", -1, 10, 15, true);
    make_5digit_NumString(y, string);
    Graphics_drawString(g_sContext_p, string, -1, 30, 15, true);
}


void draw_Base(Graphics_Context *g_sContext_p)
{
    Graphics_Rectangle R;
    R.xMin = 0;
    R.xMax = 127;
    R.yMin = 32;
    R.yMax = 96;

    Graphics_drawRectangle(g_sContext_p, &R);
    Graphics_fillCircle(g_sContext_p, 63, 63, 10);
    Graphics_drawString(g_sContext_p, "circle move #:", -1, 10, 100, false);
    Graphics_drawString(g_sContext_p, "000", -1, 10, 110, true);
}

void make_3digit_NumString(unsigned int num, int8_t *string)
{
    if(num < 100)
    {
        string[0]= (num/10)+'0';
        string[1]= (num%10) + '0';
        string[2]= 0;
    }
    else if(num >= 100)
    {
        string[0]= (num/100)+'0';
        string[1]= ((num%100) / 10) + '0';
        string[2]= (num%10)+'0';
        string[3] =0;
    }

}





void InitFonts() {
    Crystalfontz128x128_Init();
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);
}


void InitGraphics(Graphics_Context *g_sContext_p) {

    Graphics_initContext(g_sContext_p,
                         &g_sCrystalfontz128x128,
                         &g_sCrystalfontz128x128_funcs);
    //Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_YELLOW);
    Graphics_setBackgroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
    Graphics_setFont(g_sContext_p, &g_sFontCmtt16);

    InitFonts();

    Graphics_clearDisplay(g_sContext_p);
}

void SplashScreen(Graphics_Context *g_sContext_p, const tImage *img)
{
    Graphics_drawImage(g_sContext_p,img,0,0);
    OneShotSWTimer_t splashTimer;
    InitOneShotSWTimer(&splashTimer,&timer0,3000000);
    StartOneShotSWTimer(&splashTimer);

    while(1)
    {
        if(OneShotSWTimerExpired(&splashTimer))
            break;
    }
}

void MenuScreen(Graphics_Context *g_sContext_p, const tImage *background, const tImage *options)
{
    Graphics_drawImage(g_sContext_p,background,0,0);
    Graphics_drawImage(g_sContext_p,options,50,30);
    Graphics_setBackgroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
    Graphics_drawString(g_sContext_p, ">", -1, 41, 30, true);
    //Graphics_drawString(g_sContext_p, ">", -1, 53, 45, true);
    //Graphics_drawString(g_sContext_p, ">", -1, 53, 60, true);

   /* while(1)
    {
        if(BoosterpackBottomButton_pressed())
        {
            Graphics_drawImage(g_sContext_p,&songlist_16bit4BPP_UNCOMP,50,30);
            Graphics_drawString(g_sContext_p, ">", -1, 41, 30, true);

        }
    }*/

}

void CreateGameLayout(Graphics_Context *g_sContext_p)
{
    int i;
    for (i=0; i < 2; i++)
    {
        Graphics_Rectangle Rect;
        //Rect.xMin = 1 ;
        //Rect.yMin = 18 + 72*i;
        //Rect.xMax = 127;
        // Rect.yMax = 19 + 72*i;

        Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
        //Graphics_drawRectangle(g_sContext_p, &Rect);
        //Graphics_fillRectangle(g_sContext_p, &Rect);

        Rect.xMin = 1 + 124*i ;
        Rect.yMin = 30;
        Rect.xMax = 2 + 124*i;

        Rect.yMax = 127;

        Graphics_drawRectangle(g_sContext_p, &Rect);
        Graphics_fillRectangle(g_sContext_p, &Rect);

    }

    for (i=0; i < 4; i++)
    {
        Graphics_Rectangle Rect;
        Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);

        Rect.xMin = 25 + 25*i ;
        Rect.yMin = 30;
        Rect.xMax = 25 + 25*i;

        Rect.yMax = 127;

        Graphics_drawRectangle(g_sContext_p, &Rect);
        Graphics_fillRectangle(g_sContext_p, &Rect);

    }

   /* Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
    Graphics_drawLineH(g_sContext_p,1,127,40);
    Graphics_drawLineH(g_sContext_p,1,127,60);
    Graphics_drawLineH(g_sContext_p,1,127,80);
    Graphics_drawLineH(g_sContext_p,1,127,100);
    Graphics_drawLineH(g_sContext_p,1,127,120);*/

    // draw the circles

    Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_GREEN);
    Graphics_fillCircle(g_sContext_p, 25, 120, 7);
    Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_RED);
    Graphics_fillCircle(g_sContext_p, 50, 120, 7);
    Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_YELLOW);
    Graphics_fillCircle(g_sContext_p, 75, 120, 7);
    Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLUE);
    Graphics_fillCircle(g_sContext_p, 100, 120, 7);
    Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
    for (i=0; i<4; i++)
    {
        Graphics_fillCircle(g_sContext_p, 25+25*i, 120, 5);
    }
}

void StartEnterSandman(Graphics_Context *g_sContext_p)
{

    InitGraphics(g_sContext_p);
    InitSound();
    InitSongList();
    Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
    Graphics_drawString(g_sContext_p,"Score:0",-1, 1, 10, true);
    //Graphics_drawString(g_sContext_p,"10000",-1, 55, 10, true);
    Graphics_drawString(g_sContext_p,"x1",-1, 105, 10, true);

    OneShotSWTimer_t swTimer;
    InitOneShotSWTimer(&swTimer,&timer0,20000);
    StartOneShotSWTimer(&swTimer);

    OneShotSWTimer_t noteTimer;
    InitOneShotSWTimer(&noteTimer,&timer1,12000000);
    StartOneShotSWTimer(&noteTimer);
    int count = 0;
    int gCount = 0, rCount = 0, yCount = 0, bCount = 0; // count for notes;
    int score = 0;
    char string[] = "";
    Graphics_drawString(g_sContext_p,string,-1, 55, 10, true);

    int LEFT_THRESHOLD = 0x1000;
    int RIGHT_THRESHOLD = 0x3200;
    int UP_THRESHOLD =  0x3200;
    int DOWN_THRESHOLD = 0x1000;

    initADC();
    initJoyStick();
    startADC();

    unsigned vx, vy;

    OneShotSWTimer_t jsDebounceTimer;
    InitOneShotSWTimer(&jsDebounceTimer,&timer0,160000);
    StartOneShotSWTimer(&jsDebounceTimer);

    // directions where the joystick is pushed js stand for Joystick
    bool jsRight = false;
    bool jsLeft = false;
    bool jsUp = false;
    bool jsDown = false;

    int end = 0;

    while(1)
    {
        if(!end)
            end = PlaySong(enter_sandman);

        if(OneShotSWTimerExpired(&swTimer))
        {
            InitOneShotSWTimer(&swTimer,&timer0,20000);
            StartOneShotSWTimer(&swTimer);
            count++;
            gCount++;
            rCount++;
            yCount++;
            bCount++;
            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
            Graphics_fillCircle(g_sContext_p, 25, 39+gCount, 5);
            Graphics_drawLineH(g_sContext_p,1,127,39+count);
            Graphics_drawLineH(g_sContext_p,1,127,59+count);
            Graphics_drawLineH(g_sContext_p,1,127,79+count);
            Graphics_drawLineH(g_sContext_p,1,127,99+count);
            Graphics_drawLineH(g_sContext_p,1,127,119+count);
            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
            Graphics_drawLineH(g_sContext_p,1,127,40+count);
            Graphics_drawLineH(g_sContext_p,1,127,60+count);
            Graphics_drawLineH(g_sContext_p,1,127,80+count);
            Graphics_drawLineH(g_sContext_p,1,127,100+count);
            Graphics_drawLineH(g_sContext_p,1,127,120+count);
            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_GREEN);
            Graphics_fillCircle(g_sContext_p, 25, 40+gCount, 5);
            if(rCount >= 120 && rCount < 600)
            {
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
                Graphics_fillCircle(g_sContext_p, 50, 39+rCount-120, 5);
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_RED);
                Graphics_fillCircle(g_sContext_p, 50, 40+rCount-120, 5);
            }
            if(yCount >= 240 && yCount < 720)
            {
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
                Graphics_fillCircle(g_sContext_p, 75, 39+yCount-240, 5);
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_YELLOW);
                Graphics_fillCircle(g_sContext_p, 75, 40+yCount-240, 5);
            }
            if(bCount >= 360 && bCount < 840)
            {
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
                Graphics_fillCircle(g_sContext_p, 100, 39+bCount-360, 5);
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLUE);
                Graphics_fillCircle(g_sContext_p, 100, 40+bCount-360, 5);
            }
            CreateGameLayout(g_sContext_p);


            if(count == 20)
                count = 0;
            if(gCount == 480)
                gCount = 0;
            if(rCount == 600)
                rCount = 0;
            if(yCount == 720)
                yCount = 0;
            if(bCount == 840)
                bCount = 0;

            jsRight = false;
            jsLeft = false;
            jsUp = false;
            jsDown = false;

            getSampleJoyStick(&vx, &vy);

            if(vy < DOWN_THRESHOLD && OneShotSWTimerExpired(&jsDebounceTimer))
            {
                StartOneShotSWTimer(&jsDebounceTimer);
                jsDown = true;
            }

            if (vy > UP_THRESHOLD && OneShotSWTimerExpired(&jsDebounceTimer))
            {
                StartOneShotSWTimer(&jsDebounceTimer);
                jsUp = true;
            }

            else if (vx < LEFT_THRESHOLD && OneShotSWTimerExpired(&jsDebounceTimer))
            {
                StartOneShotSWTimer(&jsDebounceTimer);
                jsLeft = true;
            }

            else if(vx > RIGHT_THRESHOLD && OneShotSWTimerExpired(&jsDebounceTimer))
            {
                StartOneShotSWTimer(&jsDebounceTimer);
                jsRight = true;
            }


            if(jsLeft == true && BoosterpackTopButton_pressed())
            {
                score = score +10;
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
                make_3digit_NumString(score, string);
                Graphics_fillCircle(g_sContext_p, 25, 120, 9);
                Graphics_drawString(g_sContext_p,string,-1, 55, 10, true);
            }
            else if(jsDown == true && BoosterpackTopButton_pressed())
            {
                score = score +10;
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
                make_3digit_NumString(score, string);
                Graphics_fillCircle(g_sContext_p, 50, 120, 9);
                Graphics_drawString(g_sContext_p,string,-1, 55, 10, true);
            }
            else if(jsUp == true && BoosterpackTopButton_pressed())
            {
                score = score +10;
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
                make_3digit_NumString(score, string);
                Graphics_fillCircle(g_sContext_p, 75, 120, 9);
                Graphics_drawString(g_sContext_p,string,-1, 55, 10, true);
            }
            else if(jsRight == true && BoosterpackTopButton_pressed())
            {
                score = score +10;
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
                make_3digit_NumString(score, string);
                Graphics_fillCircle(g_sContext_p, 100, 120, 9);
                Graphics_drawString(g_sContext_p,string,-1, 55, 10, true);
            }

        }


        if(OneShotSWTimerExpired(&noteTimer))
        {
            ShowResult(string,g_sContext_p);
            break;
        }


    }

}

void StartHokieFight(Graphics_Context *g_sContext_p)
{
    InitGraphics(g_sContext_p);
    InitSound();
    InitSongList();
    Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
    Graphics_drawString(g_sContext_p,"Score:",-1, 1, 10, true);
    //Graphics_drawString(g_sContext_p,"10000",-1, 55, 10, true);
    Graphics_drawString(g_sContext_p,"x1",-1, 105, 10, true);

    OneShotSWTimer_t swTimer;
    InitOneShotSWTimer(&swTimer,&timer0,20000);
    StartOneShotSWTimer(&swTimer);

    OneShotSWTimer_t noteTimer;
    InitOneShotSWTimer(&noteTimer,&timer1,10000000);
    StartOneShotSWTimer(&noteTimer);
    int count = 0;
    int gCount = 0, rCount = 0, yCount = 0, bCount = 0; // count for notes;
    int score = 0;
    char string[] = "0";
    Graphics_drawString(g_sContext_p,string,-1, 55, 10, true);

    int LEFT_THRESHOLD = 0x1000;
    int RIGHT_THRESHOLD = 0x3200;
    int UP_THRESHOLD =  0x3200;
    int DOWN_THRESHOLD = 0x1000;

    initADC();
    initJoyStick();
    startADC();

    unsigned vx, vy;

    OneShotSWTimer_t jsDebounceTimer;
    InitOneShotSWTimer(&jsDebounceTimer,&timer0,160000);
    StartOneShotSWTimer(&jsDebounceTimer);

    // directions where the joystick is pushed js stand for Joystick

    bool jsRight = false;
    bool jsLeft = false;
    bool jsUp = false;
    bool jsDown = false;
    int end = 0;

    while(1)
    {
        if(!end)
            end = PlaySong(hokie_fight);

        if(OneShotSWTimerExpired(&swTimer))
        {
            InitOneShotSWTimer(&swTimer,&timer0,20000);
            StartOneShotSWTimer(&swTimer);
            count++;
            gCount++;
            rCount++;
            yCount++;
            bCount++;
            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
            Graphics_fillCircle(g_sContext_p, 75, 39+yCount, 5);
            Graphics_drawLineH(g_sContext_p,1,127,39+count);
            Graphics_drawLineH(g_sContext_p,1,127,59+count);
            Graphics_drawLineH(g_sContext_p,1,127,79+count);
            Graphics_drawLineH(g_sContext_p,1,127,99+count);
            Graphics_drawLineH(g_sContext_p,1,127,119+count);
            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
            Graphics_drawLineH(g_sContext_p,1,127,40+count);
            Graphics_drawLineH(g_sContext_p,1,127,60+count);
            Graphics_drawLineH(g_sContext_p,1,127,80+count);
            Graphics_drawLineH(g_sContext_p,1,127,100+count);
            Graphics_drawLineH(g_sContext_p,1,127,120+count);
            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_YELLOW);
            Graphics_fillCircle(g_sContext_p, 75, 40+yCount, 5);
            if(rCount >= 120 && rCount < 600)
            {
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
                Graphics_fillCircle(g_sContext_p, 50, 39+rCount-120, 5);
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_RED);
                Graphics_fillCircle(g_sContext_p, 50, 40+rCount-120, 5);
            }
            if(bCount >= 240 && bCount < 720)
            {
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
                Graphics_fillCircle(g_sContext_p, 100, 39+bCount-240, 5);
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLUE);
                Graphics_fillCircle(g_sContext_p, 100, 40+bCount-240, 5);
            }
            if(gCount >= 360 && gCount < 840)
            {
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
                Graphics_fillCircle(g_sContext_p, 25, 39+gCount-360, 5);
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_GREEN);
                Graphics_fillCircle(g_sContext_p, 25, 40+gCount-360, 5);
            }
            CreateGameLayout(g_sContext_p);


            if(count == 20)
                count = 0;
            if(yCount == 480)
                yCount = 0;
            if(rCount == 600)
                rCount = 0;
            if(bCount == 720)
                bCount = 0;
            if(gCount == 840)
                gCount = 0;



            jsRight = false;
            jsLeft = false;
            jsUp = false;
            jsDown = false;

            getSampleJoyStick(&vx, &vy);

            if(vy < DOWN_THRESHOLD && OneShotSWTimerExpired(&jsDebounceTimer))
            {
                StartOneShotSWTimer(&jsDebounceTimer);
                jsDown = true;
            }

            if (vy > UP_THRESHOLD && OneShotSWTimerExpired(&jsDebounceTimer))
            {
                StartOneShotSWTimer(&jsDebounceTimer);
                jsUp = true;
            }

            else if (vx < LEFT_THRESHOLD && OneShotSWTimerExpired(&jsDebounceTimer))
            {
                StartOneShotSWTimer(&jsDebounceTimer);
                jsLeft = true;
            }

            else if(vx > RIGHT_THRESHOLD && OneShotSWTimerExpired(&jsDebounceTimer))
            {
                StartOneShotSWTimer(&jsDebounceTimer);
                jsRight = true;
            }


            if(jsLeft == true && BoosterpackTopButton_pressed())
            {
                score = score +10;
                make_3digit_NumString(score, string);
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
                Graphics_fillCircle(g_sContext_p, 25, 120, 9);
                Graphics_drawString(g_sContext_p,string,-1, 55, 10, true);
            }
            else if(jsDown == true && BoosterpackTopButton_pressed())
            {
                score = score +10;
                make_3digit_NumString(score, string);
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
                Graphics_fillCircle(g_sContext_p, 50, 120, 9);
                Graphics_drawString(g_sContext_p,string,-1, 55, 10, true);
            }
            else if(jsUp == true && BoosterpackTopButton_pressed())
            {
                score = score +10;
                make_3digit_NumString(score, string);
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
                Graphics_fillCircle(g_sContext_p, 75, 120, 9);
                Graphics_drawString(g_sContext_p,string,-1, 55, 10, true);
            }
            else if(jsRight == true && BoosterpackTopButton_pressed())
            {
                score = score +10;
                make_3digit_NumString(score, string);
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
                Graphics_fillCircle(g_sContext_p, 100, 120, 9);
                Graphics_drawString(g_sContext_p,string,-1, 55, 10, true);
            }

        }


        if(OneShotSWTimerExpired(&noteTimer))
        {
            ShowResult(string,g_sContext_p);
            break;
        }
    }
}

void StartGoT(Graphics_Context *g_sContext_p)
{

    InitGraphics(g_sContext_p);
    InitSound();
    InitSongList();
    Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
    Graphics_drawString(g_sContext_p,"Score:0",-1, 1, 10, true);
    //Graphics_drawString(g_sContext_p,"10000",-1, 55, 10, true);
    Graphics_drawString(g_sContext_p,"x1",-1, 105, 10, true);

    OneShotSWTimer_t swTimer;
    InitOneShotSWTimer(&swTimer,&timer0,20000);
    StartOneShotSWTimer(&swTimer);

    OneShotSWTimer_t noteTimer;
    InitOneShotSWTimer(&noteTimer,&timer1,19000000);
    StartOneShotSWTimer(&noteTimer);
    int count = 0;
    int gCount = 0, rCount = 0, yCount = 0, bCount = 0; // count for notes;
    int score = 0;
    char string[] = "";
    Graphics_drawString(g_sContext_p,string,-1, 55, 10, true);

    int LEFT_THRESHOLD = 0x1000;
    int RIGHT_THRESHOLD = 0x3200;
    int UP_THRESHOLD =  0x3200;
    int DOWN_THRESHOLD = 0x1000;

    initADC();
    initJoyStick();
    startADC();

    unsigned vx, vy;

    OneShotSWTimer_t jsDebounceTimer;
    InitOneShotSWTimer(&jsDebounceTimer,&timer0,160000);
    StartOneShotSWTimer(&jsDebounceTimer);

    // directions where the joystick is pushed js stand for Joystick
    bool jsRight = false;
    bool jsLeft = false;
    bool jsUp = false;
    bool jsDown = false;

    int end = 0;

    while(1)
    {

        if(!end)
            end = PlaySong(GoT_song);

        if(OneShotSWTimerExpired(&swTimer))
        {
            InitOneShotSWTimer(&swTimer,&timer0,20000);
            StartOneShotSWTimer(&swTimer);
            count++;
            gCount++;
            rCount++;
            yCount++;
            bCount++;
            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
            Graphics_fillCircle(g_sContext_p, 25, 39+gCount, 5);
            Graphics_drawLineH(g_sContext_p,1,127,39+count);
            Graphics_drawLineH(g_sContext_p,1,127,59+count);
            Graphics_drawLineH(g_sContext_p,1,127,79+count);
            Graphics_drawLineH(g_sContext_p,1,127,99+count);
            Graphics_drawLineH(g_sContext_p,1,127,119+count);
            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
            Graphics_drawLineH(g_sContext_p,1,127,40+count);
            Graphics_drawLineH(g_sContext_p,1,127,60+count);
            Graphics_drawLineH(g_sContext_p,1,127,80+count);
            Graphics_drawLineH(g_sContext_p,1,127,100+count);
            Graphics_drawLineH(g_sContext_p,1,127,120+count);
            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_GREEN);
            Graphics_fillCircle(g_sContext_p, 25, 40+gCount, 5);
            if(rCount >= 120 && rCount < 600)
            {
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
                Graphics_fillCircle(g_sContext_p, 50, 39+rCount-120, 5);
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_RED);
                Graphics_fillCircle(g_sContext_p, 50, 40+rCount-120, 5);
            }
            if(yCount >= 240 && yCount < 720)
            {
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
                Graphics_fillCircle(g_sContext_p, 75, 39+yCount-240, 5);
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_YELLOW);
                Graphics_fillCircle(g_sContext_p, 75, 40+yCount-240, 5);
            }
            if(bCount >= 360 && bCount < 840)
            {
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
                Graphics_fillCircle(g_sContext_p, 100, 39+bCount-360, 5);
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLUE);
                Graphics_fillCircle(g_sContext_p, 100, 40+bCount-360, 5);
            }
            CreateGameLayout(g_sContext_p);


            if(count == 20)
                count = 0;
            if(gCount == 480)
                gCount = 0;
            if(rCount == 600)
                rCount = 0;
            if(yCount == 720)
                yCount = 0;
            if(bCount == 840)
                bCount = 0;

            jsRight = false;
            jsLeft = false;
            jsUp = false;
            jsDown = false;

            getSampleJoyStick(&vx, &vy);

            if(vy < DOWN_THRESHOLD && OneShotSWTimerExpired(&jsDebounceTimer))
            {
                StartOneShotSWTimer(&jsDebounceTimer);
                jsDown = true;
            }

            if (vy > UP_THRESHOLD && OneShotSWTimerExpired(&jsDebounceTimer))
            {
                StartOneShotSWTimer(&jsDebounceTimer);
                jsUp = true;
            }

            else if (vx < LEFT_THRESHOLD && OneShotSWTimerExpired(&jsDebounceTimer))
            {
                StartOneShotSWTimer(&jsDebounceTimer);
                jsLeft = true;
            }

            else if(vx > RIGHT_THRESHOLD && OneShotSWTimerExpired(&jsDebounceTimer))
            {
                StartOneShotSWTimer(&jsDebounceTimer);
                jsRight = true;
            }


            if(jsLeft == true && BoosterpackTopButton_pressed())
            {
                score = score +10;
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
                make_3digit_NumString(score, string);
                Graphics_fillCircle(g_sContext_p, 25, 120, 9);
                Graphics_drawString(g_sContext_p,string,-1, 55, 10, true);
            }
            else if(jsDown == true && BoosterpackTopButton_pressed())
            {
                score = score +10;
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
                make_3digit_NumString(score, string);
                Graphics_fillCircle(g_sContext_p, 50, 120, 9);
                Graphics_drawString(g_sContext_p,string,-1, 55, 10, true);
            }
            else if(jsUp == true && BoosterpackTopButton_pressed())
            {
                score = score +10;
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
                make_3digit_NumString(score, string);
                Graphics_fillCircle(g_sContext_p, 75, 120, 9);
                Graphics_drawString(g_sContext_p,string,-1, 55, 10, true);
            }
            else if(jsRight == true && BoosterpackTopButton_pressed())
            {
                score = score +10;
                Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
                make_3digit_NumString(score, string);
                Graphics_fillCircle(g_sContext_p, 100, 120, 9);
                Graphics_drawString(g_sContext_p,string,-1, 55, 10, true);
            }

        }


        if(OneShotSWTimerExpired(&noteTimer))
        {
            ShowResult(string,g_sContext_p);
            break;
        }


    }

}

void ShowResult(char *string[], Graphics_Context *g_sContext_p)
{
    OneShotSWTimer_t resultTimer;
    InitOneShotSWTimer(&resultTimer,&timer0,7000000);
    StartOneShotSWTimer(&resultTimer);
    Graphics_drawImage(g_sContext_p,&resultimage_16bit4BPP_UNCOMP,0,0);

    while(!OneShotSWTimerExpired(&resultTimer))
    {

        Graphics_setBackgroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
        Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
        Graphics_drawString(g_sContext_p,"Great Job!",-1, 5, 20, true);
        Graphics_drawString(g_sContext_p,"Score:",-1, 15, 35, true);
        Graphics_drawString(g_sContext_p,string,-1, 65,35, true);
        Graphics_drawString(g_sContext_p,"Streak:x4",-1, 15, 50, true);


    }

}
