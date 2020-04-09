#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/grlib/grlib.h>
#include "LcdDriver/Crystalfontz128x128_ST7735.h"
#include "ButtonLED_HAL.h"
#include "graphics_HAL.h"
#include "ADC_HAL.h"
#include "sound.h"
#include "song.h"

extern HWTimer_t timer0, timer1;
//include images
extern const tImage guitarhero_16bit4BPP_UNCOMP;
extern const tImage  menuImage_16bit4BPP_UNCOMP;
extern const tImage  MenuOptions_16bit4BPP_UNCOMP;
extern const tImage  songlist_16bit4BPP_UNCOMP;
extern const tImage  Howtoplay_16bit4BPP_UNCOMP;
extern const tImage  ScoreBoard_16bit4BPP_UNCOMP;

typedef enum {QuickPlay, HowtoPlay, HighScores,SongList,HowtoPlayText,ScoreList,EnterSandman,HokieFight,GoT,playES,playHF,playGoT} screens;

// This function initializes all the peripherals except graphics
void initialize();
void ModifyLEDColor(bool leftButtonWasPushed, bool rightButtonWasPushed);
void drawStartBackground(Graphics_Context *g_sContext_p);
void MainScreenFSM(bool JoystickDown, bool JoystickUp, Graphics_Context *g_sContext_p, bool S1Pushed,bool S2Pushed,screens *state);

#define LEFT_THRESHOLD  0x1000
#define RIGHT_THRESHOLD 0x3200
#define UP_THRESHOLD  0x3200
#define DOWN_THRESHOLD 0x1000

#define DURATION 100

extern song_t enter_sandman;
extern song_t hokie_fight;
//extern song_t GoT_song;

int main(void)
{
    Graphics_Context g_sContext;
    screens state = QuickPlay;
    initialize();
    InitGraphics(&g_sContext);
    SplashScreen(&g_sContext,&guitarhero_16bit4BPP_UNCOMP);
    //InitGraphics(&g_sContext);
    MenuScreen(&g_sContext, &menuImage_16bit4BPP_UNCOMP,&MenuOptions_16bit4BPP_UNCOMP);

    button_t S1Button;
    initButton(&S1Button, GPIO_PORT_P5, GPIO_PIN1, &timer0);

    button_t S2Button;
    initButton(&S2Button, GPIO_PORT_P3, GPIO_PIN5, &timer0);

    //draw_Base(&g_sContext);
    unsigned vx, vy;


    //TODO: comment out this part once you complete part 3

  /* InitSound();
    InitSongList();
    PlaySong(enter_sandman);
    PlaySong(hokie_fight);*/

//    InitSound();
//    InitSongList();
//    PlaySong(enter_sandman);
//    PlaySong(GoT_song);

    OneShotSWTimer_t jsDebounceTimer;
    InitOneShotSWTimer(&jsDebounceTimer,&timer0,325000);
    StartOneShotSWTimer(&jsDebounceTimer);

    // directions where the joystick is pushed js stand for Joystick

    bool jsRight = false;
    bool jsLeft = false;
    bool jsUp = false;
    bool jsDown = false;



    while (1)
    {

        jsRight = false;
        jsLeft = false;
        jsUp = false;
        jsDown = false;

        bool S1Pushed = ButtonPushed(&S1Button);
        bool S2Pushed = ButtonPushed(&S2Button);
        getSampleJoyStick(&vx, &vy);

        if(vy < DOWN_THRESHOLD && OneShotSWTimerExpired(&jsDebounceTimer))
        {
           StartOneShotSWTimer(&jsDebounceTimer);
           jsDown = true;
        }

        else if (vy > UP_THRESHOLD && OneShotSWTimerExpired(&jsDebounceTimer))
        {
            StartOneShotSWTimer(&jsDebounceTimer);
            jsUp = true;
        }

        else if (vx < LEFT_THRESHOLD)
        {
            jsLeft = true;
        }

        else if(vx > RIGHT_THRESHOLD)
        {
            jsRight = true;
        }

        MainScreenFSM(jsDown, jsUp, &g_sContext, S1Pushed,S2Pushed,&state);//screens *state);

        if(state == playES)
        {
            CreateGameLayout(&g_sContext);
            StartEnterSandman(&g_sContext);
            MenuScreen(&g_sContext, &menuImage_16bit4BPP_UNCOMP,&MenuOptions_16bit4BPP_UNCOMP);
            state = QuickPlay;

        }
        else if(state == playHF)
        {
            CreateGameLayout(&g_sContext);
            StartHokieFight(&g_sContext);
            MenuScreen(&g_sContext, &menuImage_16bit4BPP_UNCOMP,&MenuOptions_16bit4BPP_UNCOMP);
            state = QuickPlay;

        }
        else if(state == playGoT)
        {
            CreateGameLayout(&g_sContext);
            StartGoT(&g_sContext);
            MenuScreen(&g_sContext, &menuImage_16bit4BPP_UNCOMP,&MenuOptions_16bit4BPP_UNCOMP);
            state = QuickPlay;

        }
        /*if(BoosterpackTopButton_pressed())
        {
            Graphics_clearDisplay(&g_sContext);
            CreateGameLayout(&g_sContext);
            StartGame(&g_sContext);
            //drawStartBackground(&g_sContext);
        }*/

        //drawStartBackground(&g_sContext);
        /*bool leftButtonPushed = ButtonPushed(&LauchpadLeftButton);
        bool rightButtonPushed = ButtonPushed(&LauchpadRightButton);

        if (LaunchpadLeftButton_pressed())
            turnOn_LaunchpadLED1();
        else
            turnOff_LaunchpadLED1();

        if (LaunchpadRightButton_pressed())
            turnOn_LaunchpadLED2_red();
        else
            turnOff_LaunchpadLED2_red();


       // ModifyLEDColor(leftButtonPushed,rightButtonPushed);
        //MoveCircle(&g_sContext, leftButtonPushed,rightButtonPushed);

        getSampleJoyStick(&vx, &vy);
        bool joyStickPushedtoRight = false;
        bool joyStickPushedtoLeft = false;
        bool joyStickPushedtoUp = false;
        bool joyStickPushedtoDown = false;
        //drawXY(&g_sContext, vx, vy);


        //ModifyLEDColor(joyStickPushedtoLeft,joyStickPushedtoRight);
        //MoveCircle(&g_sContext, joyStickPushedtoLeft,joyStickPushedtoRight);*/

    }
}


void initialize()
{
    // stop the watchdog timer
    WDT_A_hold(WDT_A_BASE);

    // initialize the boosterPack LEDs and turn them off except for red LED
    initialize_BoosterpackLED_red();
    initialize_BoosterpackLED_green();
    initialize_BoosterpackLED_blue();
    initialize_LaunchpadLED1();
    initialize_LaunchpadLED2_red();
    initialize_LaunchpadLED2_blue();
    initialize_LaunchpadLED2_green();

    //turnOn_BoosterpackLED_red();
    turnOff_BoosterpackLED_red();
    turnOff_BoosterpackLED_green();
    turnOff_BoosterpackLED_blue();
    turnOff_LaunchpadLED1();
    turnOff_LaunchpadLED2_red();
    turnOff_LaunchpadLED2_blue();
    turnOff_LaunchpadLED2_green();

    initHWTimer0();
    initHWTimer1();

    initADC();
    initJoyStick();
    startADC();
}

// This FSM has two inputs each of them the FSM if a button has been pushed or not
// The FSM has three states: Red, Green, Blue. The initial state is Red
// The FSM has three outputs, each output is a boolean that decides if an LED should be on or off
// When the left button is pressed, the FSM goes
void MainScreenFSM(bool JoystickDown, bool JoystickUp, Graphics_Context *g_sContext_p, bool S1Pushed, bool S2Pushed,screens *state )
{

    //static screens state = QuickPlay;
    //state = QuickPlay;

    Graphics_Rectangle Rect;

     Rect.xMin = 40;
     Rect.yMin = 20;
     Rect.xMax = 127;
     Rect.yMax = 95;

    switch(*state)
    {
    case QuickPlay:
        if (JoystickDown)
            *state = HowtoPlay;
        else if (JoystickUp)
            *state = HighScores;
        else if (S1Pushed)
            *state = EnterSandman;
        break;

    case HowtoPlay:
        if (JoystickDown)
            *state = HighScores;
        else if (JoystickUp)
            *state = QuickPlay;
        else if (S1Pushed)
            *state = HowtoPlayText;
        break;

    case HighScores:
        if (JoystickDown)
            *state = QuickPlay;
        else if (JoystickUp)
            *state = HowtoPlay;
        else if(S1Pushed)
            *state = ScoreList;
        break;

    case HowtoPlayText:
        if(S1Pushed)
        {
            //Graphics_clearDisplay(g_sContext_p);
            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
            Graphics_drawRectangle(g_sContext_p, &Rect);
            Graphics_fillRectangle(g_sContext_p, &Rect);
            *state = HowtoPlay;
        }
        break;

    case ScoreList:
        if(S1Pushed)
        {
            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
            Graphics_drawRectangle(g_sContext_p, &Rect);
            Graphics_fillRectangle(g_sContext_p, &Rect);
            *state = HighScores;
        }
        break;

    case EnterSandman:
        if(S1Pushed)
            *state = playES;
        else if(S2Pushed)
        {
            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
            Graphics_drawRectangle(g_sContext_p, &Rect);
            Graphics_fillRectangle(g_sContext_p, &Rect);
            *state = QuickPlay;
        }
        else  if(JoystickDown)
            *state = HokieFight;
        else if(JoystickUp)
            *state = GoT;
        break;

    case HokieFight:
        if(S1Pushed)
            *state = playHF;
    else if(JoystickDown)
            *state = GoT;
        else if(JoystickUp)
            *state = EnterSandman;
        else if(S2Pushed)
        {
            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
            Graphics_drawRectangle(g_sContext_p, &Rect);
            Graphics_fillRectangle(g_sContext_p, &Rect);
            *state = QuickPlay;
        }
        break;

    case GoT:
        if(JoystickDown)
            *state = EnterSandman;
        else if(JoystickUp)
            *state = HokieFight;
        else if(S1Pushed)
            *state = playGoT;
        else if(S2Pushed)
        {
            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
            Graphics_drawRectangle(g_sContext_p, &Rect);
            Graphics_fillRectangle(g_sContext_p, &Rect);
            *state = QuickPlay;
        }
        break;

    }

    if(*state == QuickPlay)
    {
        Graphics_drawImage(g_sContext_p,&MenuOptions_16bit4BPP_UNCOMP,50,30);
        Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
        Graphics_drawString(g_sContext_p, ">", -1, 41, 30, true);
        Graphics_drawString(g_sContext_p, " ", -1, 41, 45, true);
        Graphics_drawString(g_sContext_p, " ", -1, 41, 60, true);
    }
    else if(*state == HowtoPlay)
    {
        Graphics_drawImage(g_sContext_p,&MenuOptions_16bit4BPP_UNCOMP,50,30);
        Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
        Graphics_drawString(g_sContext_p, " ", -1, 41, 30, true);
        Graphics_drawString(g_sContext_p, ">", -1, 41, 45, true);
        Graphics_drawString(g_sContext_p, " ", -1, 41, 60, true);

    }
    else if(*state == HighScores)
    {
        Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
        Graphics_drawRectangle(g_sContext_p, &Rect);
        Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
        Graphics_drawImage(g_sContext_p,&MenuOptions_16bit4BPP_UNCOMP,50,30);
        Graphics_drawString(g_sContext_p, " ", -1, 41, 30, true);
        Graphics_drawString(g_sContext_p, " ", -1, 41, 45, true);
        Graphics_drawString(g_sContext_p, ">", -1, 41, 60, true);
    }
    else if(*state == HowtoPlayText)
    {
        Graphics_drawImage(g_sContext_p,&Howtoplay_16bit4BPP_UNCOMP,41,20);
    }
    else if(*state == EnterSandman)
    {
        Graphics_drawImage(g_sContext_p,&songlist_16bit4BPP_UNCOMP,50,30);
        Graphics_drawString(g_sContext_p, ">", -1, 41, 30, true);
        Graphics_drawString(g_sContext_p, " ", -1, 41, 45, true);
        Graphics_drawString(g_sContext_p, " ", -1, 41, 60, true);
    }
    else if(*state == HokieFight)
    {
        Graphics_drawString(g_sContext_p, " ", -1, 41, 30, true);
        Graphics_drawString(g_sContext_p, ">", -1, 41, 45, true);
        Graphics_drawString(g_sContext_p, " ", -1, 41, 60, true);
    }
    else if(*state == GoT)
    {
        Graphics_drawString(g_sContext_p, " ", -1, 41, 30, true);
        Graphics_drawString(g_sContext_p, " ", -1, 41, 45, true);
        Graphics_drawString(g_sContext_p, ">", -1, 41, 60, true);
    }
    else if(*state == ScoreList)
    {
        Graphics_drawImage(g_sContext_p,&ScoreBoard_16bit4BPP_UNCOMP,41,20);
    }
    else if(*state == playES || *state == playHF || *state == playGoT)
        Graphics_clearDisplay(g_sContext_p);


}

void drawStartBackground(Graphics_Context *g_sContext_p)
{
    Graphics_drawImage(g_sContext_p,&ScoreBoard_16bit4BPP_UNCOMP,0,0);
}



