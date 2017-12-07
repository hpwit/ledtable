//
//  ledTable.h
//  
//
//  Created by Yves BAZIN on 25/11/17.
//

#ifndef ledTable_h
#define ledTable_h


#define FASTLED_ESP8266_RAW_PIN_ORDER
#define FASTLED_ESP8266_NODEMCU_PIN_ORDER
#define FASTLED_ESP8266_D1_PIN_ORDER
#define FASTLED_ALLOW_INTERRUPTS 0
#include "FastLED.h"
FASTLED_USING_NAMESPACE
//#include <ArduinoJson.h>

#include <mem.h>
extern "C" {
#include "user_interface.h"
}
// How many leds in your strip?




#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>
//#include <ESP8266WiFiMulti.h>
//#include <ESP8266mDNS.h>

#include <FS.h>
//#include <EEPROM.h>



// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN

#define DATA_PIN 3
#define CLOCK_PIN 13 //needed if we go for ws2801


#define DATA_PIN      D7     // for Huzzah: Pins w/o special function:  #4, #5, #12, #13, #14; // #16 does not work :(
#define LED_TYPE      WS2812
#define COLOR_ORDER   GRB

//Define table orientation this is where the pixel 0 is
#define DOWN_RIGHT   0 //natural mode no transpostion to be made
#define DOWN_LEFT    1 //We turn 90° clock wise
#define UP_LEFT      2
#define UP_RIGHT     3
#define DOWN_RIGHT_INV   4 //natural mode no transpostion to be made
#define DOWN_LEFT_INV    5 //We turn 90° clock wise
#define UP_LEFT_INV      6
#define UP_RIGHT_INV     7
#define DEFAULT_BRIGHTNESS 16


byte font1[][7]=
{
    
    //32->47
    {B00000,  B00000, B00000, B00000, B00000, B00000, B00000  },{B01000,  B01000, B01000, B01000, B01000, B00000, B01000  },  {B01010,  B01010, B01010, B00000, B00000, B00000, B00000  },  {B01010,  B01010, B11111, B01010, B11111, B01010, B01010  },  {B00100,  B01111, B10100, B01110, B00101, B11110, B00100  },  {B11000,  B11001, B00010, B00100, B01000, B10011, B00011  },  {B01000,  B10100, B10100, B01000, B10101, B10010, B01101  },  {B01100,  B00100, B01000, B00000, B00000, B00000, B00000  },  {B00010,  B00100, B01000, B01000, B01000, B00100, B00010  },  {B01000,  B00100, B00010, B00010, B00010, B00100, B01000  },  {B10101,  B01110, B00100, B01110, B10101, B00000, B00000  },  {B00100,  B00100, B00100, B11111, B00100, B00100, B00100  },  {B00000,  B00000, B00000, B00000, B11000, B01000, B10000  },  {B00000,  B00000, B00000, B11100, B00000, B00000, B00000  },  {B00000,  B00000, B00000, B00000, B00000, B01100, B01100  },  {B00000,  B00001, B00010, B00100, B01000, B10000, B00000  },
    
    //48->57
    {B01110,  B10001, B10011, B10101, B11001, B10001, B01110  },  {B00100,  B01100, B00100, B00100, B00100, B00100, B01110  },  {B01110,  B10001, B00001, B00010, B00100, B01000, B11111  },  {B11111,  B00010, B00100, B00010, B00001, B10001, B01110  },  {B00010,  B00110, B01010, B10010, B11111, B00010, B00010  },  {B11111,  B10000, B11110, B00001, B00001, B10001, B01110  },  {B00110,  B01000, B10000, B11110, B10001, B10001, B01110  },  {B11111,  B00001, B00010, B00100, B01000, B10000, B10000  },  {B01110,  B10001, B10001, B01110, B10001, B10001, B01110  },  {B01110,  B10001, B10001, B01111, B00001, B00010, B01100  },
    
    //58->64
    {B00000,  B01100, B01100, B00000, B01100, B01100, B00000  },  {B00000,  B01100, B01100, B00000, B01100, B00100, B01000  },  {B00010,  B00100, B01000, B10000, B01000, B00100, B00010  },  {B00000,  B00000, B11111, B00000, B11111, B00000, B00000  },  {B10000,  B01000, B00100, B00010, B00100, B01000, B10000  },  {B01110,  B10001, B00001, B00010, B00100, B00000, B00100  },  {B01110,  B10001, B10011, B10100, B10101, B10001, B01110  },
    
    //65->90
    {B01110,  B10001, B10001, B11111, B10001, B10001, B10001  },  {B11110,  B10001, B10001, B11110, B10001, B10001, B11110  },  {B01110,  B10001, B10000, B10000, B10000, B10001, B01110  },  {B11110,  B10001, B10001, B10001, B10001, B10001, B11110  },  {B11111,  B10000, B10000, B11110, B10000, B10000, B11111  },  {B11111,  B10000, B10000, B11110, B10000, B10000, B10000  },  {B01110,  B10001, B10000, B10111, B10001, B10001, B01110  },  {B10001,  B10001, B10001, B11111, B10001, B10001, B10001  },  {B01110,  B00100, B00100, B00100, B00100, B00100, B01110  },  {B00111,  B00010, B00010, B00010, B00010, B10010, B01100  },  {B10001,  B10010, B10100, B11000, B10100, B10010, B10001  },  {B10000,  B10000, B10000, B10000, B10000, B10000, B11111  },  {B10001,  B11011, B10101, B10101, B10001, B10001, B10001  },  {B10001,  B10001, B11001, B10101, B10011, B10001, B10001  },  {B01110,  B10001, B10001, B10001, B10001, B10001, B01110  },  {B11110,  B10001, B10001, B11110, B10000, B10000, B10000  },  {B01110,  B10001, B10001, B10001, B10101, B10010, B01101  },  {B11110,  B10001, B10001, B11110, B10100, B10010, B10001  },  {B01111,  B10000, B10000, B01110, B00001, B00001, B11110  },  {B11111,  B00100, B00100, B00100, B00100, B00100, B00100  },  {B10001,  B10001, B10001, B10001, B10001, B10001, B01110  },  {B10001,  B10001, B10001, B10001, B10001, B01010, B00100  },  {B10001,  B10001, B10001, B10001, B10101, B10101, B01010  },  {B10001,  B10001, B01010, B00100, B01010, B10001, B10001  },  {B10001,  B10001, B10001, B01010, B00100, B00100, B00100  },  {B11111,  B00001, B00010, B00100, B01000, B10000, B11111  },
    
    //91->96
    {B01110,  B01000, B01000, B01000, B01000, B01000, B01110  },  {B10001,  B01010, B11111, B00100, B11111, B00100, B00100  },  {B01110,  B00010, B00010, B00010, B00010, B00010, B01110  },  {B00100,  B01010, B10001, B00000, B00000, B00000, B00000  },  {B00000,  B00000, B00000, B00000, B00000, B00000, B11111  },  {B01000,  B00100, B00010, B00000, B00000, B00000, B00000  },
    
    //97->122
    {B00000,  B00000, B01110, B00001, B01111, B10001, B01111  },  {B10000,  B10000, B10110, B11001, B10001, B10001, B11110  },  {B00000,  B00000, B01110, B10000, B10000, B10001, B01110  },  {B00001,  B00001, B01101, B10011, B10001, B10001, B01111  },  {B00000,  B00000, B01110, B10001, B11111, B10000, B01110  },  {B00110,  B01001, B01000, B11100, B01000, B01000, B01000  },  {B00000,  B01111, B10001, B10001, B01111, B00001, B01110  },  {B10000,  B10000, B10110, B11001, B10001, B10001, B10001  },  {B00100,  B00000, B01100, B00100, B00100, B00100, B01110  },  {B00010,  B00000, B00110, B00010, B00010, B10010, B01100  },  {B10000,  B10000, B10010, B10100, B11000, B10100, B10010  },  {B01100,  B00100, B00100, B00100, B00100, B00100, B01110  },  {B00000,  B00000, B11010, B10101, B10101, B10001, B10001  },  {B00000,  B00000, B10110, B11001, B10001, B10001, B10001  },  {B00000,  B00000, B01110, B10001, B10001, B10001, B01110  },  {B00000,  B00000, B11110, B10001, B11110, B10000, B10000  },  {B00000,  B00000, B01110, B10001, B01111, B00001, B00001  },  {B00000,  B00000, B10110, B11001, B10000, B10000, B10000  },  {B00000,  B00000, B01110, B10000, B01110, B00001, B11110  },  {B01000,  B01000, B11100, B01000, B01000, B01001, B00110  },  {B00000,  B00000, B10001, B10001, B10001, B10011, B01101  },  {B00000,  B00000, B10001, B10001, B10001, B01010, B00100  },  {B00000,  B00000, B10001, B10001, B10001, B10101, B01010  },  {B00000,  B00000, B10001, B01010, B00100, B01010, B10001  },  {B00000,  B00000, B10001, B10001, B01111, B00001, B01110  },  {B00000,  B00000, B11111, B00010, B00100, B01000, B11111  },
    
    
};

const uint8_t  gamma8[] = {
          0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
          0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
          1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
          2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
         5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
         10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
         17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
         25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
       37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
       51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
       69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
       90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
      115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
      144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
      177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
      215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };

CRGB lettrefont1[35];

CRGB *leds;//leds[420];
CRGB *Tpic;

CRGB solidColor = CRGB(10, 10, 10);
CRGB bgColor = CRGB(10, 10, 10);
CRGB Color = CRGB :: Blue;
CRGB Color2 = CRGB :: Green;
bool isTable=false;
int tableOrientation=DOWN_RIGHT; //we put the first pixel down and right

int LED_WIDTH=30;
int LED_HEIGHT=14;
int NUM_LEDS;

ESP8266WebServer server(80);




//CREATTION DES LEDS (on prend la longueur des strips w et le nombre de strip h)
bool initTable(int w,int h)
{
    LED_WIDTH=w;
    LED_HEIGHT=h;
    NUM_LEDS=w*h;
    leds =(CRGB*)os_malloc(NUM_LEDS*sizeof(CRGB)) ;
    Tpic =(CRGB*)os_malloc(NUM_LEDS*sizeof(CRGB)) ;
    if(!leds or !Tpic)
    {
        Serial.println("Unable to create the screen");
        isTable=false;
        return false;
    }
    Serial.println("Table créée");
    isTable=true;
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(DEFAULT_BRIGHTNESS);
    return true;
}



void putOrientation(CRGB *pic,int h,int w,int x0,int y0)
{
    //CRGB * Tpic = (CRGB*)calloc(h*w,sizeof(CRGB));
    if(!Tpic)
    {
        Serial.println("pas possible");
        return ;//NULL;
    }
    switch(tableOrientation){
            
        case DOWN_RIGHT: //on ne fait rien
            for(int y=0;y<h;y++)
            {
                for (int x=0;x<w;x++)
                {
                    if( ((x+x0)+LED_WIDTH*(y+y0)) <NUM_LEDS && x+x0 >=0 && y+y0>=0 && x+x0<LED_WIDTH && y+y0 <LED_HEIGHT)
                        Tpic[x+x0+LED_WIDTH*(y+y0)]=pic[w*y+x];
                }
            }
            
            break;
            
        case DOWN_LEFT:
            for(int y=0;y<h;y++)
            {
                for (int x=0;x<w;x++)
                {
                    if( LED_WIDTH*(LED_HEIGHT-1-x-x0)+y+y0 <NUM_LEDS && LED_HEIGHT-1-x-x0 >=0 && y+y0>=0 && LED_HEIGHT-1-x-x0<LED_HEIGHT && y+y0 <LED_WIDTH)
                    Tpic[LED_WIDTH*(LED_HEIGHT-1-x-x0)+y+y0]=pic[w*y+x];
                }
            }
            break;
            
            
        case UP_RIGHT:
            for(int y=0;y<h;y++)
            {
                for (int x=0;x<w;x++)
                {
                    if( (LED_WIDTH*((x+x0))+LED_WIDTH-1-(y+y0)) <NUM_LEDS  && (x+x0) >=0 && LED_WIDTH-1-(y+y0)>=0 && (x+x0)<LED_HEIGHT && LED_WIDTH-1-(y+y0) <LED_WIDTH  )
                    Tpic[LED_WIDTH*((x+x0))+LED_WIDTH-1-(y+y0)]=pic[w*y+x];
                }
            }
            break;
            
        case UP_LEFT:
            for(int y=0;y<h;y++)
            {
                for (int x=0;x<w;x++)
                {
                    if( LED_WIDTH-1-(x+x0)+LED_WIDTH*(LED_HEIGHT-1-(y+y0)) <NUM_LEDS  && LED_WIDTH-1-(x+x0)>=0 && LED_WIDTH*(LED_HEIGHT-1-(y+y0))>=0 && (LED_HEIGHT-1-(y+y0))<LED_HEIGHT && LED_WIDTH-1-(x+x0) <LED_WIDTH )
                        Tpic[LED_WIDTH-1-(x+x0)+LED_WIDTH*(LED_HEIGHT-1-(y+y0))]=pic[w*y+x];
                }
            }
            break;
            
//on inverse la lecture des pixels au niveau des X on lit de gauche a droite
        case DOWN_RIGHT_INV: //on ne fait rien
            for(int y=0;y<h;y++)
            {
                for (int x=0;x<w;x++)
                {
                    if( LED_WIDTH-1-x-x0+LED_WIDTH*(y+y0) <NUM_LEDS && LED_WIDTH-1-x-x0 >=0 && y+y0>=0 && LED_WIDTH-1-x-x0<LED_WIDTH && y+y0 <LED_HEIGHT)
                        Tpic[LED_WIDTH-1-x-x0+LED_WIDTH*(y+y0)]=pic[w*y+x];
                }
            }
            
            break;
            
        case DOWN_LEFT_INV:
            for(int y=0;y<h;y++)
            {
                for (int x=0;x<w;x++)
                {
                    if( LED_WIDTH*(x+x0)+y+y0 <NUM_LEDS && x+x0 >=0 && y+y0>=0 && x+x0<LED_HEIGHT && y+y0 <LED_WIDTH)
                        Tpic[LED_WIDTH*(x+x0)+y+y0]=pic[w*y+x];
                }
            }
            break;
            
            
        case UP_RIGHT_INV:
            for(int y=0;y<h;y++)
            {
                for (int x=0;x<w;x++)
                {
                    if( (LED_WIDTH*((x+x0))+(y+y0)) <NUM_LEDS  && (x+x0) >=0 && (y+y0)>=0 && (x+x0)<LED_HEIGHT && (y+y0) <LED_WIDTH  )
                        Tpic[LED_WIDTH*((x+x0))+(y+y0)]=pic[w*y+x];
                }
            }
            break;
            
        case UP_LEFT_INV:
            for(int y=0;y<h;y++)
            {
                for (int x=0;x<w;x++)
                {
                    if( (x+x0)+LED_WIDTH*(LED_HEIGHT-1-(y+y0)) <NUM_LEDS  && (x+x0)>=0 && LED_WIDTH*(LED_HEIGHT-1-(y+y0))>=0 && (LED_HEIGHT-1-(y+y0))<LED_HEIGHT && (x+x0) <LED_WIDTH )
                        Tpic[(x+x0)+LED_WIDTH*(LED_HEIGHT-1-(y+y0))]=pic[w*y+x];
                }
            }
            break;
            
            
            
    }
     //return Tpic;
    
}



void displaypic( CRGB *pica, int x0, int y0, int h, int w)
{
    putOrientation(pica,h,w,x0,y0);
    if(Tpic)
    {
       int hmin=LED_HEIGHT;
       int  wmin=LED_WIDTH;
        x0=0;
        y0=0;
        for (int y = y0; y < hmin + y0; y++)
        {
            if (y >= 0) {
                if (y % 2 == 0)
                {
                    if (x0 < 0)
                    {
                        int nh = wmin + x0;
                        if (nh > 0)
                            memcpy(&leds[LED_WIDTH * y], &Tpic[(y - y0) *wmin - x0], nh * sizeof(CRGB));
                    }
                    else
                        memcpy(&leds[LED_WIDTH * y + x0], &Tpic[(y - y0)*wmin], wmin * sizeof(CRGB));
                }
                else
                {
                    for (int x = x0; x < wmin + x0; x++)
                    {
                        if (x >= 0)
                            leds[2 * LED_WIDTH * ((int)floor(y / 2) + 1) - 1 - x] = Tpic[wmin * (y - y0) + x - x0 ];
                    }
                }
            }
        }
       
    }
}



void displayBitmap(unsigned char *pic,int x0,int y0,int h,int w)
{
  //frame size
    int max_wide=0;
    int wide=w+x0;
    int offsety;
    int offsetx;
    int newx=0;
    int newy=0;
    if(wide<=0)
        return; // l'image ne peut etre affichée
    if(tableOrientation%2==0)
        max_wide=LED_WIDTH;
    else
        max_wide=LED_HEIGHT;
    
    if (x0>=max_wide) //on est en dehors du cadre
        return;
    if(x0>=0)
    {
        newx=x0;
        offsetx=0;
        if(w+x0<max_wide)
            wide=w;
        else
            wide=max_wide-x0;
    }
    else
    {
        newx=0;
        offsetx=-x0;
        if(w+x0<max_wide)
            wide=w+x0;
        else
            wide=max_wide;
    }
    
    
    
    
    int max_height=0;
    int height=h+y0;
    if(height<=0)
        return; // l'image ne peut etre affichée
    if(tableOrientation%2==0)
        max_height=LED_HEIGHT;
    else
        max_height=LED_WIDTH;
    
    if (y0>=max_height) //on est en dehors du cadre
        return;
    if(y0>=0)
    {
        newy=y0;
        offsety=0;
        if(h+y0<max_height)
            height=h;
        else
            height=max_height-y0;
    }
    else
    {
        newy=0;
        offsety=-y0;
        if(h+y0<max_height)
            height=h;
        else
            height=max_height;
    }
    
    
    
    int r;
    int g;
    int b;
    // Serial.println("r1");
    CRGB *bitmapRGB =(CRGB*)os_malloc(wide*height*sizeof(CRGB)) ;
    if(bitmapRGB==NULL)
    {
        Serial.println("immossibnle de créer l'image");
        Serial.println(wide);
        Serial.println(height);
        Serial.println(x0);
        Serial.println(y0);
        return;
    }
    //Serial.println("image cree");
    for(int y=0;y<height;y++){
        for(int x=0;x<wide;x++){
          
            r=(int)pic[3*((y+offsety)*w+x+offsetx)];
            g= (int)pic[3*((y+offsety)*w+x+offsetx)+1];
            b= (int)pic[3*((y+offsety)*w+x+offsetx)+2];
           bitmapRGB[x+y*wide]=CRGB(r,g,b); //I have a program that switches directly from
        }
    }
    displaypic(bitmapRGB,newx,newy,height,wide);
    os_free(bitmapRGB);
    
    
    
}


void displayBitmap_old(unsigned char *pic,int x0,int y0,int h,int w )
{
    //
    //Serial.println("r1");
    int r;
    int g;
    int b;
   // Serial.println("r1");
    CRGB *bitmapRGB =(CRGB*)os_malloc(h*w*sizeof(CRGB)) ;
  if(bitmapRGB==NULL)
    {
        Serial.println("immossibnle de créer l'image");

        return;
    }
    Serial.println("image cree");
    for(int y=0;y<h;y++){
        for(int x=0;x<w;x++){
             //int wmin = (w > maxx) ? maxx : w;
            r=gamma8[(int)pic[3*(y*w+x)]];//<0 )     ? (256+(int)pic[3*(y*w+x)]):(int)pic[3*(y*w+x)];
           // Serial.println("r");
            g= gamma8[(int)pic[3*(y*w+x)+1]];//<0 ) ? (256+(int)pic[3*(y*w+x)+1]):(int)pic[3*(y*w+x)+1];
            b= gamma8[(int)pic[3*(y*w+x)+2]];//<0 ) ? (256+(int)pic[3*(y*w+x)+2]):(int)pic[3*(y*w+x)+2];
                // Serial.print(r);Serial.print(";");Serial.print(g);Serial.print(";");Serial.print(b);Serial.println("");
           // bitmapRGB[x+y*w]=CRGB(pic[3*(y*w+x)+2],pic[3*(y*w+x)+1],pic[3*(y*w+x)]);
            //Serial.println("ecrire");
            bitmapRGB[x+y*w]=CRGB(r,g,b);
        }
    }
    displaypic(bitmapRGB,x0,y0,h,w);
    os_free(bitmapRGB);

}

void displayBitmapFromProgmem(unsigned char *pic,int x0,int y0,int h,int w )
{

    int max_wide=0;
    int wide=w+x0;
    int offsety;
    int offsetx;
    int newx=0;
    int newy=0;
    if(wide<0)
        return; // l'image ne peut etre affichée
    if(tableOrientation%2==0)
        max_wide=LED_WIDTH;
    else
        max_wide=LED_HEIGHT;
    
    if (x0==max_wide) //on est en dehors du cadre
        return;
    if(x0>=0)
    {
        newx=x0;
        offsetx=0;
        if(w+x0<max_wide)
            wide=w;
        else
            wide=max_wide-x0;
    }
    else
    {
        newx=0;
        offsetx=-x0;
        if(w+x0<max_wide)
            wide=w+x0;
        else
            wide=max_wide;
    }
    
    
    
    
    int max_height=0;
    int height=h+y0;
    if(height<0)
        return; // l'image ne peut etre affichée
    if(tableOrientation%2==0)
        max_height=LED_HEIGHT;
    else
        max_height=LED_WIDTH;
    
    if (y0==max_height) //on est en dehors du cadre
        return;
    if(y0>=0)
    {
        newy=y0;
        offsety=0;
        if(h+y0<max_height)
            height=h;
        else
            height=max_height-x0;
    }
    else
    {
        newy=0;
        offsety=-y0;
        if(h+y0<max_height)
            height=h;
        else
            height=max_height;
    }
    
    int r;
    int g;
    int b;

    CRGB *bitmapRGB =(CRGB*)os_malloc(wide*height*sizeof(CRGB)) ;
    if(bitmapRGB==NULL)
    {
        Serial.println("immossibnle de créer l'image");
        return;
    }

    for(int y=0;y<height;y++){
        for(int x=0;x<wide;x++){
            
             r= (int)pgm_read_byte(pic+ 3*(y*w+x));
            g= (int)pgm_read_byte(pic+3*(y*w+x)+1);
            b= (int)pgm_read_byte(pic+3*(y*w+x)+2);
            bitmapRGB[x+y*wide]=CRGB(r,g,b); //I have a program that switches directly from
        }
    }
    displaypic(bitmapRGB,newx,newy,height,wide);
    os_free(bitmapRGB);
    
}

void fill(CRGB color)
{
     fill_solid(leds, NUM_LEDS, color);
    fill_solid(Tpic, NUM_LEDS, color);
}


void afficheLettre(int let,int x0,int y0)
{
    
    int taille=5;
    int hauteur=7;
    
    for(int x=x0;x<taille+x0;x++)
    {
        for (int y=y0;y<hauteur+y0;y++)
        {
            if ( ( (1 << (x0-x+taille-1)) &   font1[let][hauteur-1 - y + y0] ) > 0 )
            {
                lettrefont1[(x-x0)+(y-y0)*5]=CRGB(Color);
            }
            else
            {
                lettrefont1[(x-x0)+(y-y0)*5]=CRGB(bgColor);
            }
        }
    }
    
    displaypic(lettrefont1,x0,y0,7,5);
    
}



#endif /* ledTable_h */

