/**
 * @file policeTask.hpp
 * @authors MarioS271
 */

#include "delay.h"
#include "rgb_color.hpp"
#include "predef_colors.hpp"
#include "ledcontroller.hpp"

void policeTask(void* params) {
    LedController *leds = static_cast<LedController*>(params);

    leds->off();
    while (true) {
        for (int i = 0; i < 5; i++) { leds->setRGB(COLOR::RED); delay(50); leds->off(); delay(50); }
        delay(200);
        for (int i = 0; i < 5; i++) { leds->setRGB(COLOR::BLUE); delay(50); leds->off(); delay(50); }
        delay(200);
    }
}