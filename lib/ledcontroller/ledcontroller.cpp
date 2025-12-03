/**
 * @file ledcontroller.cpp
 * @authors MarioS271
 */

#include "ledcontroller.hpp"

#include "delay.hpp"

LedController::LedController() {
    // Timer Setup
    ledc_timer_config_t timer_conf = {};
    timer_conf.speed_mode       = LEDC_MODE;
    timer_conf.timer_num        = LEDC_TIMER;
    timer_conf.duty_resolution  = LEDC_RESOLUTION;
    timer_conf.freq_hz          = LEDC_FREQ_HZ;
    timer_conf.clk_cfg          = LEDC_AUTO_CLK;
    ledc_timer_config(&timer_conf);

    // Red Channel
    ledc_channel_config_t red_channel_conf = {};
    red_channel_conf.channel      = RED_CHANNEL;
    red_channel_conf.duty         = 0;
    red_channel_conf.gpio_num     = PIN_RED;
    red_channel_conf.speed_mode   = LEDC_MODE;
    red_channel_conf.timer_sel    = LEDC_TIMER;
    ledc_channel_config(&red_channel_conf);

    // Green Channel
    ledc_channel_config_t green_channel_conf = {};
    green_channel_conf.channel    = GREEN_CHANNEL;
    green_channel_conf.duty       = 0;
    green_channel_conf.gpio_num   = PIN_GREEN;
    green_channel_conf.speed_mode = LEDC_MODE;
    green_channel_conf.timer_sel  = LEDC_TIMER;
    ledc_channel_config(&green_channel_conf);

    // Blue Channel
    ledc_channel_config_t blue_channel_conf = {};
    blue_channel_conf.channel     = BLUE_CHANNEL;
    blue_channel_conf.duty        = 0;
    blue_channel_conf.gpio_num    = PIN_BLUE;
    blue_channel_conf.speed_mode  = LEDC_MODE;
    blue_channel_conf.timer_sel   = LEDC_TIMER;
    ledc_channel_config(&blue_channel_conf);

    ledc_fade_func_install(0);
}

void LedController::off() {
    ledc_set_duty(LedController::LEDC_MODE, RED_CHANNEL, 0);
    ledc_set_duty(LedController::LEDC_MODE, GREEN_CHANNEL, 0);
    ledc_set_duty(LedController::LEDC_MODE, BLUE_CHANNEL, 0);

    ledc_update_duty(LEDC_MODE, RED_CHANNEL);
    ledc_update_duty(LEDC_MODE, GREEN_CHANNEL);
    ledc_update_duty(LEDC_MODE, BLUE_CHANNEL);
}

void LedController::setRGB(rgb_color_t color) {
    if (color.red > 4095) color.red = 4095;
    if (color.green > 4095) color.green = 4095;
    if (color.blue > 4095) color.blue = 4095;

    ledc_set_duty(LedController::LEDC_MODE, RED_CHANNEL, color.red);
    ledc_set_duty(LedController::LEDC_MODE, GREEN_CHANNEL, color.green);
    ledc_set_duty(LedController::LEDC_MODE, BLUE_CHANNEL, color.blue);

    ledc_update_duty(LEDC_MODE, RED_CHANNEL);
    ledc_update_duty(LEDC_MODE, GREEN_CHANNEL);
    ledc_update_duty(LEDC_MODE, BLUE_CHANNEL);
}

void LedController::fadeRGB(rgb_color_t color, uint16_t duration) {
    if (color.red > 4095) color.red = 4095;
    if (color.green > 4095) color.green = 4095;
    if (color.blue > 4095) color.blue = 4095;

    ledc_set_fade_with_time(LEDC_MODE, RED_CHANNEL, color.red, duration);
    ledc_fade_start(LEDC_MODE, RED_CHANNEL, LEDC_FADE_NO_WAIT);

    ledc_set_fade_with_time(LEDC_MODE, GREEN_CHANNEL, color.green, duration);
    ledc_fade_start(LEDC_MODE, GREEN_CHANNEL, LEDC_FADE_NO_WAIT);

    ledc_set_fade_with_time(LEDC_MODE, BLUE_CHANNEL, color.blue, duration);
    ledc_fade_start(LEDC_MODE, BLUE_CHANNEL, LEDC_FADE_NO_WAIT);
}