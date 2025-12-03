/**
 * @file strobeTask.hpp
 * @authors MarioS271
 */

#include <esp_random.h>
#include "delay.hpp"
#include "rgb_color.hpp"
#include "predef_colors.hpp"
#include "ledcontroller.hpp"

void strobeTask(void* params) {
    LedController *leds = static_cast<LedController*>(params);
    
    constexpr int NUM_COLORS = 8;
    rgb_color_t colors[NUM_COLORS] = { COLOR::RED, COLOR::ORANGE, COLOR::YELLOW,
                              COLOR::GREEN, COLOR::CYAN, COLOR::BLUE,
                              COLOR::MAGENTA, COLOR::WHITE };

    leds->off();
    while (true) {
        leds->setRGB(colors[esp_random() % NUM_COLORS]);
        delay(150);
        leds->off();
        delay(150);
    }
}