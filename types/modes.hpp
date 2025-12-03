/**
 * @file modes.hpp
 * @authors MarioS271
 */

#pragma once

#include <cstdint>

/**
 * @enum mode_t
 * @brief Enum of possible LED modes
 */
enum mode_t : uint8_t {
    MODE_FADE = 0,
    MODE_STROBE = 1,
    MODE_FIREPLACE = 2,
    MODE_POLICE = 3,
    MODE_STRANGERTHINGS = 4
};

constexpr uint8_t MAX_MODE = MODE_STRANGERTHINGS;