/**
 * @file predef_colors.hpp
 * @authors MarioS271
 */

#pragma once

#include "rgb_color.hpp"

/**
 * @namespace COLOR
 * @brief Predefined colors as rgb_color_t constants
 */
namespace COLOR {
    constexpr rgb_color_t RED     = { 4095,    0,    0 };
    constexpr rgb_color_t ORANGE  = { 4095,  900,    0 };
    constexpr rgb_color_t YELLOW  = { 4095, 4095,    0 };
    constexpr rgb_color_t GREEN   = {    0, 4095,    0 };
    constexpr rgb_color_t CYAN    = {    0, 4095, 4095 };
    constexpr rgb_color_t BLUE    = {    0,    0, 4095 };
    constexpr rgb_color_t MAGENTA = { 4095,    0, 4095 };
    constexpr rgb_color_t WHITE   = { 4095, 4095, 4095 };
}