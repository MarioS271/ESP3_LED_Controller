/**
 * @file strangerThingsTask.hpp
 * @authors MarioS271
 */

#include <esp_random.h>
#include "delay.hpp"
#include "rgb_color.hpp"
#include "predef_colors.hpp"
#include "ledcontroller.hpp"

void strangerThingsTask(void* params) {
    LedController *leds = static_cast<LedController*>(params);
    rgb_color_t targetColor;
    int fadeTime;

    leds->off();
    while (true) {
        float factor = 0.05f + (esp_random() % 3960) / 4095.0f;

        targetColor.red = static_cast<uint16_t>(COLOR::RED.red * factor);
        targetColor.green = static_cast<uint16_t>(COLOR::RED.green * factor);

        fadeTime = 300 + (esp_random() % 1200);
        leds->fadeRGB(targetColor, fadeTime);

        delay(fadeTime + 1);
    }
}