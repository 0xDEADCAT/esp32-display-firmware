#ifndef _DISPLAY_DRIVER_H_
#define _DISPLAY_DRIVER_H_

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include <EPD.h>
#include <GUI_Paint.h>
#include "ImageData.h"
#include <stdlib.h>

#include "structs.h"

void display_driver(void * pvParameters);

#endif