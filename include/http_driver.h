#ifndef _HTTP_DRIVER_H_
#define _HTTP_DRIVER_H_

#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_tls.h"

#include "esp_http_client.h"

#include "structs.h"

void http_driver(void * pvParameters);

#endif 