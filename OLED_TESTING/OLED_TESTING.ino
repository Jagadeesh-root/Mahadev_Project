#include <SPI.h> 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  Serial.begin(9600);
   if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
   }

   display.clearDisplay();
   printText();
}

void loop()
{

  
}


void printText() {
  display.clearDisplay();
  display.setTextSize(2);             // The fontsize
 display.setTextColor(BLACK, WHITE);       // Draw white text
  display.setCursor(5, 5);           // Start at top-left corner
  display.print("Basavaraju");  
    display.setCursor(5, 30);           // Start at top-left corner
  display.print("Project");
  display.display();
  display.startscrollright(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x07);
}
