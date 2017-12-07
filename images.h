//
//  images.h
//  
//
//  Created by Yves BAZIN on 25/11/17.
//

#ifndef images_h
#define images_h

const CRGB  ghost[14][14] = {
    {0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 3, 3, 1, 1},
    {1, 1, 1, 3, 3, 2, 2, 1, 1, 3, 3, 2, 2, 1},
    {0, 1, 1, 3, 3, 2, 2, 1, 1, 3, 3, 2, 2, 1},
    {0, 1, 1, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 1},
    {0, 1, 1, 1, 3, 3, 1, 1, 1, 1, 3, 3, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0}
};



const CRGB fraise[11][10] = {
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 2, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 2, 1, 0, 0},
    {0, 1, 2, 1, 2, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 2, 1, 0},
    {1, 1, 2, 1, 2, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 2, 1, 2, 1},
    {1, 2, 1, 2, 1, 3, 1, 1, 1, 1},
    {0, 1, 1, 1, 3, 3, 3, 1, 2, 0},
    {0, 0, 3, 3, 3, 2, 3, 3, 3, 0},
    {0, 0, 0, 0, 0, 2, 0, 0, 0, 0}
};

 CRGB fraiseCalc[110];
const CRGB transparent = CRGB(1, 1, 1);


int cerise[196] = {
    100, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100,
    100, 100, 0, 1, 1, 1, 1, 0, 100, 100, 100, 100, 100, 100,
    100, 0, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0, 100, 100,
    100, 0, 1, 1, 1, 1, 2, 1, 0, 1, 1, 1, 0, 100,
    100, 0, 1, 1, 1, 1, 1, 1, 0, 2, 2, 1, 1, 0,
    100, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 0,
    100, 100, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0,
    100, 100, 100, 0, 0, 3, 0, 1, 1, 1, 1, 1, 1, 0,
    100, 100, 100, 0, 3, 0, 100, 0, 1, 1, 1, 1, 0, 100,
    100, 100, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 100, 100,
    100, 0, 0, 3, 0, 3, 3, 0, 100, 100, 100, 100, 100, 100,
    0, 3, 3, 3, 3, 0, 0, 100, 100, 100, 100, 100, 100, 100,
    0, 3, 3, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 100,
    100, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100
};
 int mario[238]={
    100,3,3,100,100,100,100,100,100,100,100,100,100,100,100,100,100,
    100,3,3,3,2,2,2,2,2,2,100,100,100,100,100,100,100,
    100,100,3,3,2,2,2,2,2,2,2,2,2,2,3,3,100,
    100,100,100,100,2,2,2,2,4,2,2,2,2,2,3,3,100,
    100,5,5,1,1,1,1,2,2,2,2,4,2,2,3,3,100,
    5,5,1,1,1,1,1,2,1,1,1,2,100,100,3,3,100,
    5,5,1,1,1,1,2,1,1,1,2,1,1,100,100,3,100,
    100,100,100,100,100,5,5,5,5,5,5,5,1,1,100,100,100,
    100,100,100,3,3,5,5,5,5,6,6,6,6,1,100,100,100,
    100,100,100,3,5,3,3,5,5,5,6,5,5,5,1,100,100,
    100,100,100,3,5,3,5,5,5,6,5,5,5,1,1,100,100,
    100,100,100,100,3,3,3,5,5,6,5,100,1,1,1,100,100,
    100,100,100,100,1,1,1,1,1,1,1,1,1,5,5,100,100,
    100,100,100,100,100,1,1,1,1,1,100,100,5,5,5,100,100
};

 CRGB palm[7]={CRGB:: Red,CRGB::Red, CRGB::Blue,CRGB(98,65,7),CRGB::Yellow,CRGB(238,151,64),CRGB::Black};
 CRGB pall[7]={CRGB:: Red,CRGB::Green, CRGB::Blue,CRGB(98,65,7),CRGB::Yellow,CRGB(238,151,64),CRGB::Black};
 CRGB palec[4] = {CRGB::Black, CRGB::Red, CRGB::White, CRGB::Green};
//les images

CRGB cerisecalc[196];
CRGB mariocalc[238];
CRGB luigicalc[238];
CRGB ghostred[296];
CRGB ghostyellow[296];
CRGB ghostgreen[296];
CRGB ghostPurple[296];
CRGB ghostCyan[296];


//version autre je ne voulais pas me faire c...
void calculghosts(CRGB color)
{
    for (int m = 0; m < 14; m++)
    {
        for (int y = 0; y < 14; y++)
        {
            if (ghost[m][y] == (CRGB)1)
            {
                ghostred[m * 14 + y] = CRGB :: Red;
                ghostyellow[m * 14 + y] = CRGB :: Yellow;
                ghostgreen[m * 14 + y] = CRGB :: Green;
                ghostPurple[m * 14 + y] = CRGB :: Purple;
                ghostCyan[m * 14 + y] = CRGB(64, 222, 255);
            }
            if (ghost[m][y] == (CRGB)2)
            {
                ghostred[m * 14 + y] = CRGB :: Blue;
                ghostyellow[m * 14 + y] = CRGB :: Blue;
                ghostgreen[m * 14 + y] = CRGB :: Blue;
                ghostPurple[m * 14 + y] = CRGB :: Blue;
                ghostCyan[m * 14 + y] = CRGB :: Blue;
            }
            
            if (ghost[m][y] == (CRGB)3)
            {
                ghostred[m * 14 + y] = CRGB :: White;
                ghostyellow[m * 14 + y] = CRGB :: White;
                ghostgreen[m * 14 + y] = CRGB :: White;
                ghostPurple[m * 14 + y] = CRGB :: White;
                ghostCyan[m * 14 + y] = CRGB :: White;
            }
            if (ghost[m][y] == (CRGB)0)
            {
                ghostred[m * 14 + y] = color;
                ghostyellow[m * 14 + y] = color;
                ghostgreen[m * 14 + y] = color;
                ghostPurple[m * 14 + y] = color;
                ghostCyan[m * 14 + y] = color;
            }
            
        }
    }
}

void calculfraise(CRGB color)
{
    for (int m = 0; m < 11; m++)
    {
        for (int y = 0; y < 10; y++)
        {
            if (fraise[m][y] == (CRGB)1)
            {
                fraiseCalc[m * 10 + y] = CRGB :: Red;
                
            }
            if (fraise[m][y] == (CRGB)2)
            {
                fraiseCalc[m * 10 + y] = CRGB :: White;
                
            }
            
            if (fraise[m][y] == (CRGB)3)
            {
                fraiseCalc[m * 10 + y] = CRGB :: Green;
                
            }
            if (fraise[m][y] == (CRGB)0)
            {
                fraiseCalc[m * 10 + y] = color;
                
            }
            
        }
    }
}


//function to apply a palette to an image
void calculpic(int *pic, CRGB *palette, CRGB color, int h, int w,CRGB *result)
{
    Serial.println("on est là");
    int to = h * w;
    // static CRGB result[296];
    for (int m = 0; m < h; m++)
    {
        for (int y = 0; y < w; y++)
        {
            
            result[m * w + y] = palette[pic[m * w + y]];
            //Serial.print(palette[pic[m * w + y]]);
            //Serial.printf(":%d\n", pic[m * w + y]);
            
            
            if (pic[m * w + y] == 100)
            {
                result[m * w + y] = color;
                
            }
            if (pic[m * w + y] == 9)
            {
                result[m * w + y] = color;
                
            }
            
        }
    }
    // return result;
}





#endif /* images_h */

