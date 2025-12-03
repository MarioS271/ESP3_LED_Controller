/**
 * @file main.cpp
 * @authors MarioS271
 */

// Official Libraries
#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <esp_random.h>
#include <nvs_flash.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>

// Includes
#include "constants.hpp"

// Types
#include "rgb_color.hpp"
#include "modes.hpp"

// Helpers
#include "delay.hpp"
#include "task_delete.hpp"
#include "predef_colors.hpp"

// Custom Libraries
#include "logger.hpp"
#include "error.hpp"
#include "ledcontroller.hpp"

// Tasks
#include "fadeTask.hpp"
#include "strobeTask.hpp"
#include "fireplaceTask.hpp"
#include "policeTask.hpp"
#include "strangerThingsTask.hpp"


extern "C" void app_main() {
    delay(500);

    LOGI(TAG, "=== LED Controller starting ===");
    LOGI(TAG, "Hello, World!");

    esp_log_level_set("gpio", ESP_LOG_NONE);
    
    ERROR_CHECK(TAG, gpio_reset_pin(BUTTON_PIN));
    ERROR_CHECK(TAG, gpio_set_direction(BUTTON_PIN, GPIO_MODE_INPUT));


    LedController leds;

    mode_t mode = MODE_FADE;
    mode_t last_saved_mode = mode;
    bool init = false;
    int iterations = 0;
    int debounceCounter = 0;

    TaskHandle_t fadeTaskHandle = nullptr;
    TaskHandle_t strobeTaskHandle = nullptr;
    TaskHandle_t fireplaceTaskHandle = nullptr;
    TaskHandle_t policeTaskHandle = nullptr;
    TaskHandle_t strangerThingsTaskHandle = nullptr;

    ERROR_CHECK(TAG, nvs_flash_init());
    nvs_handle_t nvs;
    ERROR_CHECK(TAG, nvs_open("storage", NVS_READWRITE, &nvs));

    uint8_t savedMode = 0;
    ERROR_CHECK(TAG, nvs_get_u8(nvs, "mode", &savedMode));

    mode = static_cast<mode_t>(savedMode);
    last_saved_mode = mode;
    nvs_close(nvs);

    delay(500);
    leds.off();
    delay(2000);


    while (true) {
        iterations++;
        if (iterations >= 50) {
            iterations = 0;
            
            if (last_saved_mode != mode) {
                nvs_handle_t nvs;

                ERROR_CHECK(TAG, nvs_open("storage", NVS_READWRITE, &nvs));
                ERROR_CHECK(TAG, nvs_set_u8(nvs, "mode", static_cast<uint8_t>(mode)));
                ERROR_CHECK(TAG, nvs_commit(nvs));

                nvs_close(nvs);

                last_saved_mode = mode;
            }
        }

        if (gpio_get_level(BUTTON_PIN) == 0 && debounceCounter <= 0) {
            debounceCounter = 5;
            init = false;

            uint8_t mode_int = static_cast<uint8_t>(mode);
            mode_int++;
            if (mode_int > MAX_MODE) mode_int = 0;

            mode = static_cast<mode_t>(mode_int);
        }
        else if (debounceCounter > 0) {
            debounceCounter--;
        }

        if (!init) {
            task_delete(&fadeTaskHandle);
            task_delete(&strobeTaskHandle);
            task_delete(&fireplaceTaskHandle);
            task_delete(&policeTaskHandle);
            task_delete(&strangerThingsTaskHandle);
        }

        switch (mode) {
            case MODE_FADE:
                if (init) break;
                init = true;
                xTaskCreate(fadeTask, "FadeTask", 2048, &leds, 5, &fadeTaskHandle);
                break;

            case MODE_STROBE:
                if (init) break;
                init = true;
                xTaskCreate(strobeTask, "StrobeTask", 2048, &leds, 5, &strobeTaskHandle);
                break;

            case MODE_FIREPLACE:
                if (init) break;
                init = true;
                xTaskCreate(fireplaceTask, "FireplaceTask", 2048, &leds, 5, &fireplaceTaskHandle);
                break;

            case MODE_POLICE:
                if (init) break;
                init = true;
                xTaskCreate(policeTask, "PoliceTask", 2048, &leds, 5, &policeTaskHandle);
                break;

            case MODE_STRANGERTHINGS:
                if (init) break;
                init = true;
                xTaskCreate(strangerThingsTask, "StrangerThingsTask", 2048, &leds, 5, &strangerThingsTaskHandle);
                break;

            default: break;
        }

        delay(100);
    }
}
