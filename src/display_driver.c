#include "display_driver.h"

/* Entry point ----------------------------------------------------------------*/
static void display_setup()
{
  printf("EPD_4IN2_test Demo\r\n");
  DEV_Module_Init();

  printf("e-Paper Init and Clear...\r\n");
  EPD_4IN2_Init();
  EPD_4IN2_Clear();
  DEV_Delay_ms(500);
}

void display_driver(void* arg) {
  display_setup();

  //Create a new image cache
  UBYTE *BlackImage;
  /* you have to edit the startup_stm32fxxx.s file and set a big enough heap size */
  UWORD Imagesize = ((EPD_4IN2_WIDTH % 8 == 0) ? (EPD_4IN2_WIDTH / 8 ) : (EPD_4IN2_WIDTH / 8 + 1)) * EPD_4IN2_HEIGHT;
  if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
    printf("Failed to apply for black memory...\r\n");
    while (1);
  }
  printf("Paint_NewImage\r\n");
  Paint_NewImage(BlackImage, EPD_4IN2_WIDTH, EPD_4IN2_HEIGHT, 0, WHITE);

  //1.Select Image
  printf("SelectImage:BlackImage\r\n");
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);

  Paint_DrawString_EN(100, 40, "Welcome to", &Font24, WHITE, BLACK);
  Paint_DrawString_EN(40, 60, "Conference Display", &Font24, WHITE, BLACK);
  printf("EPD_Display\r\n");
  EPD_4IN2_Display(BlackImage);
  DEV_Delay_ms(2000);

  printf("Goto Sleep...\r\n");
  EPD_4IN2_Sleep();

  while (1) {
    vTaskDelay(portMAX_DELAY);
  }
}