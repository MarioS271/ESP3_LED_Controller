/**
 * @file rgb_color.h
 * @authors MarioS271
 */

#pragma once

#include <cstdint>

/**
 * @typedef rgb_color_t
 * @brief Type to represent an RGB color with 16-bit depth per channel
 */
typedef struct {
    uint16_t red;
    uint16_t green;
    uint16_t blue;
} rgb_color_t;