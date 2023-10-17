#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define BUTTON1_PIN 13
#define BUTTON2_PIN 12
#define BUTTON3_PIN 14

void setup() {
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }

  display.display();
  delay(1000);
  display.clearDisplay();
  display.setTextSize(1);
}

void loop() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  if (!digitalRead(BUTTON1_PIN)) {
    display.setCursor(0,0);
    display.println("Bus_No: 12C");
    display.println("Route: T.Nagar");
    display.println("Platform: A");
    
  } else if (!digitalRead(BUTTON2_PIN)) {
    display.setCursor(0,0);
    display.println("Bus_No: 7M");
    display.println("Route: Central");
    display.println("Platform: B");
  } else if (!digitalRead(BUTTON3_PIN)) {
    display.setCursor(0,0);
    display.println("Bus_No: 72");
    display.println("Route: Vadapalani");
    display.println("Platform: C");
  }

  display.display();
  delay(2000);  
}
