/**
 * @file fireplaceTask.hpp
 * @authors MarioS271
 */

#include <esp_random.h>
#include "delay.hpp"
#include "rgb_color.hpp"
#include "predef_colors.hpp"
#include "ledcontroller.hpp"

void fireplaceTask(void* params) {
    LedController *leds = static_cast<LedController*>(params);
    rgb_color_t targetColor;
    int fadeTime;

    leds->off();
    while (true) {
        float factor = 0.1f + (esp_random() % 3686) / 4095.0f;

        targetColor.red = static_cast<uint16_t>(COLOR::ORANGE.red * factor);
        targetColor.green = static_cast<uint16_t>(COLOR::ORANGE.green * factor);

        fadeTime = 50 + (esp_random() % 250);
        leds->fadeRGB(targetColor, fadeTime);

        delay(fadeTime + 1);
    }
}