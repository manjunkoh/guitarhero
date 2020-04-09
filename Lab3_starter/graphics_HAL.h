/*
 * graphics_HAL.h
 *
 *  Created on: Oct 18, 2018
 *      Author: Leyla
 */

#ifndef GRAPHICS_HAL_H_
#define GRAPHICS_HAL_H_

#include <ti/grlib/grlib.h>
#include "ButtonLED_HAL.h"
#include "ADC_HAL.h"

//include images
extern const tImage guitarhero_16bit4BPP_UNCOMP;
extern const tImage  menuImage_16bit4BPP_UNCOMP;
extern const tImage  MenuOptions_16bit4BPP_UNCOMP;
extern const tImage  songlist_16bit4BPP_UNCOMP;

void draw_Base(Graphics_Context *g_sContext_p);
void MoveCircle(Graphics_Context *g_sContext_p, bool moveToLeft, bool moveToRight);
void InitGraphics(Graphics_Context *g_sContext_p);
void drawXY(Graphics_Context *g_sContext_p, unsigned int x, unsigned int y);
void SplashScreen(Graphics_Context *g_sContext_p, const tImage *img);
void MenuScreen(Graphics_Context *g_sContext_p, const tImage *background, const tImage *options);
void CreateGameLayout(Graphics_Context *g_sContext_p);
void StartEnterSandman(Graphics_Context *g_sContext_p);
void StartHokieFight(Graphics_Context *g_sContext_p);
void StartGoT(Graphics_Context *g_sContext_p);
void ShowResult(int8_t *string, Graphics_Context *g_sContext_p);

#endif /* GRAPHICS_HAL_H_ */
