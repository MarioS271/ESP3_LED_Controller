/**
 * @file task_delete.hpp
 * @authors MarioS271
 */

#pragma once

#include <freertos/task.h>

/**
 * @brief Deletes a FreeRTOS task safely
 *
 * @return void
 *
 * @param taskHandle The task handle of the task to delete
 */
inline void task_delete(TaskHandle_t* taskHandle) {
    if (taskHandle != nullptr && *taskHandle != nullptr) {
        vTaskDelete(*taskHandle);
        *taskHandle = nullptr;
    }
}