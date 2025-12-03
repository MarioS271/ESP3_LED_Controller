/**
 * @file fadeTask.hpp
 * @authors MarioS271
 */

#include "delay.hpp"
#include "rgb_color.hpp"
#include "predef_colors.hpp"
#include "ledcontroller.hpp"

void fadeTask(void* params) {
    LedController *leds = static_cast<LedController*>(params);

    leds->off();
    while (true) {
        leds->fadeRGB(COLOR::RED, 999);
        delay(1000);
        leds->fadeRGB(COLOR::ORANGE, 999);
        delay(1000);
        leds->fadeRGB(COLOR::YELLOW, 999);
        delay(1000);
        leds->fadeRGB(COLOR::GREEN, 999);
        delay(1000);
        leds->fadeRGB(COLOR::CYAN, 999);
        delay(1000);
        leds->fadeRGB(COLOR::BLUE, 999);
        delay(1000);
        leds->fadeRGB(COLOR::MAGENTA, 999);
        delay(1000);
    }
}