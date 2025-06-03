//
// Created by ethanscharlie on 6/3/25.
//

#include "PiIO.hpp"

namespace View {

unsigned short PiIO::rgbToRgb565(unsigned char r, unsigned char g,
                                 unsigned char b) {
  unsigned short r565 = (r >> 3) & 0x1F;    // 5 bits for red
  unsigned short g565 = (g >> 2) & 0x3F;    // 6 bits for green
  unsigned short b565 = (b >> 3) & 0x1F;    // 5 bits for blue
  return (r565 << 11) | (g565 << 5) | b565; // Combine into RGB565
}

PiIO::PiIO() {
  if (DEV_ModuleInit() != 0) {
    DEV_ModuleExit();
    exit(0);
  }

  LCD_SCAN_DIR LCD_ScanDir = SCAN_DIR_DFT;
  printf("1.44inch LCD demo...\r\n");
  LCD_1in44_Init(LCD_ScanDir);
  LCD_1in44_Clear(WHITE);

  UDOUBLE Imagesize = LCD_HEIGHT * LCD_WIDTH * 2;
  printf("Imagesize = %d\r\n", Imagesize);
  if ((BlackImage = (UWORD *)malloc(Imagesize)) == NULL) {
    printf("Failed to apply for black memory...\r\n");
    exit(0);
  }

  Paint_NewImage(BlackImage, LCD_WIDTH, LCD_HEIGHT, 0, WHITE, 16);
  Paint_Clear(BLACK);
}

bool PiIO::isButtonDown() { return GET_KEY1 == 0; }

void PiIO::refreshDisplay() { LCD_1in44_Display(BlackImage); }

void PiIO::setDisplayColor(Color color) {
  // I have no fucking clue why it's this way but whatever
  Paint_Clear(rgbToRgb565(color.b, color.r, color.g));
}
} // namespace View
