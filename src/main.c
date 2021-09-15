/* Esptouch example
   This example code is in the Public Domain (or CC0 licensed, at your option.)
   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include "nvs_flash.h"
#include "wifi_driver.h"
#include "display_driver.h"
#include "http_driver.h"

QueueHandle_t displayQueue;

void app_main(void)
{
    ESP_ERROR_CHECK( nvs_flash_init() );

    wifi_driver();
    displayQueue = xQueueCreate(5, sizeof( struct DisplayMessage));
    if (displayQueue != NULL) {
        xTaskCreate(display_driver,
                    "display_driver",
                    8192,
                    ( void * ) &displayQueue,
                    1,
                    NULL);
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        xTaskCreate(http_driver,
                    "http_driver",
                    8192,
                    ( void * ) &displayQueue,
                    1,
                    NULL);
    }
}
