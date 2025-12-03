/**
 * @file ledcontroller.hpp
 * @authors MarioS271
 */

#pragma once

#include <driver/gpio.h>
#include <driver/ledc.h>
#include "rgb_color.hpp"

class LedController {
private:
    static constexpr gpio_num_t PIN_RED = GPIO_NUM_2;
    static constexpr gpio_num_t PIN_GREEN = GPIO_NUM_3;
    static constexpr gpio_num_t PIN_BLUE = GPIO_NUM_4;

    static constexpr ledc_timer_t LEDC_TIMER = LEDC_TIMER_0;
    static constexpr uint16_t LEDC_FREQ_HZ = 1000;
    static constexpr ledc_timer_bit_t LEDC_RESOLUTION = LEDC_TIMER_12_BIT;

public:
    static constexpr ledc_mode_t LEDC_MODE = LEDC_LOW_SPEED_MODE;

    static constexpr ledc_channel_t RED_CHANNEL = LEDC_CHANNEL_0;
    static constexpr ledc_channel_t GREEN_CHANNEL = LEDC_CHANNEL_1;
    static constexpr ledc_channel_t BLUE_CHANNEL = LEDC_CHANNEL_2;

    LedController();

    /**
     * @brief Turns off the LEDs
     *
     * @return void
     */
    void off();

    /**
     * @brief Sets all LEDs to a specific color
     *
     * @return void
     *
     * @param color The color to set
     */
    void setRGB(rgb_color_t color);

    /**
     * @brief Fades all LEDs to a specific color
     *
     * @return void
     *
     * @param color The color to fade to
     * @param duration How long the fade should last
     */
    void fadeRGB(rgb_color_t color, uint16_t duration);
};
