// #define TFT_MOSI 23  // SDA Pin on ESP32
// #define TFT_SCLK 18  // SCL Pin on ESP32
// #define TFT_CS   -1  // Chip select control pin
// #define TFT_DC   15  // Data Command control pin
// #define TFT_RST  17  // Reset pin (could connect to RST pin)
// #define MAX_IMAGE_WIDTH 240;

// Include the PNG decoder library
#include <PNGdec.h>
#include "resources/pikachuBitmap.h"

#define MAX_IMAGE_WIDTH 240 // Adjust for your images

int16_t xpos = 0;
int16_t ypos = 0;

// Include the TFT library https://github.com/Bodmer/TFT_eSPI
#include "SPI.h"
#include <TFT_eSPI.h>              // Hardware-specific library
TFT_eSPI tft = TFT_eSPI();         // Invoke custom library

//====================================================================================
//                                    Setup
//====================================================================================
void setup()
{
  Serial.begin(115200);
  Serial.println("Initializing... Loading Image...");
  delay(1000);

  // Initialise the TFT
  tft.begin();
  tft.fillScreen(TFT_BLACK);
  delay(1000);

  Serial.println("Initialisation done.");
  delay(1000);
}

//====================================================================================
//                                    Loop
//====================================================================================
void loop()
{
  Serial.println("Displaying Image...");
  tft.pushImage(0, 0, 240, 240, shocked_pikachu_bitmap);
  //tft.drawCircle(120,120, 20, TFT_BLUE);
  // delay(1000);
}
