#include "ledTable.h"
#include "images.h"
#include "yves_image.h"

int k=0;

void setup() {
 system_update_cpu_freq(SYS_CPU_160MHZ);
  Serial.begin(115200);
  delay(100);
  Serial.setDebugOutput(true);

 
  calculghosts(bgColor) ;
  calculfraise(bgColor);
  calculpic(cerise, palec, bgColor, 14, 14,cerisecalc);
  calculpic(mario, palm, bgColor, 14, 17,mariocalc);
  calculpic(mario, pall, bgColor, 14, 17,luigicalc);
 
if(initTable(30,20)) //size of your led grid (wide*height)
      {
            FastLED.setBrightness(32);
            fill(bgColor);
    

          FastLED.show();


         tableOrientation=DOWN_RIGHT_INV; //used if i want ta change table orientation )
  
           
      }
}


void loop() {
int offset=-20;;
int YO=0;
if(isTable)
      {

     

      
          k = (k+1) % 300;
          
          
         fill(bgColor);
          
          displaypic(cerisecalc,k +offset, YO, 14, 14);
          
          displaypic(fraiseCalc, k + offset - 14 , YO + 2, 11, 10);
          displaypic(ghostred, k + offset - 30, YO, 14, 14);
          displaypic(ghostyellow, k + offset - 46, YO, 14, 14);
          displaypic(ghostgreen, k + offset - 62, YO, 14, 14);
          displaypic(ghostPurple, k + offset - 78, YO, 14, 14);
          displaypic(ghostCyan, k + offset - 94, YO, 14, 14);
          displaypic(mariocalc, k + offset-110 , YO, 14, 17);
          displaypic(luigicalc, k + offset-127 , YO, 14, 17);
           displayBitmap(mickey, k + offset-127-15,YO,30,32);
           displayBitmap(champi, k + offset-127-15-17,YO+3,16,16);
          FastLED.show();
          FastLED.delay((int)(1000 / 100));
           

 
      }
}

