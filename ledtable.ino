#include "ledTable.h"
#include "tetris.h"

int k = 0;

void setup() {
  // system_update_cpu_freq(SYS_CPU_160MHZ);
  Serial.begin(115200);
  delay(100);
  Serial.setDebugOutput(true);

  Serial.println("Setup");

  if (initTable(30, 20)) //size of your led grid (wide*height)
  {
    FastLED.setBrightness(32);
    fill(bgColor);
    Serial.println("Fill");

    FastLED.show();

    tableOrientation = DOWN_RIGHT_INV; //used if i want ta change table orientation )

  }
  initTetris(10, 20);
  initTetrisScoketControl();
}

void loop() {
  tetrisWebSocket.loop();
}

