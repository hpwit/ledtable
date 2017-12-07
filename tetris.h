//
//  tetris.h
//  
//
//  Created by Yves BAZIN on 30/11/17.
//

#ifndef tetris_h
#define tetris_h





#define DISP_RIGHT   0
#define DISP_UP  1

int displayNextPiecePos=DISP_UP;

int hauteur=25;
int largeur=18;
int score=0;


CRGB *backgroundBlocks;     //8 x 16 display + 4 x 8 blocks above for blocks to spawn in
CRGB *displayScreen;
CRGB nextBlockImage[12]; //je prends les deux premieres lignes du block
//CRGB TdisplayScreen [160];

int TETRIS_HEIGHT=25;
int TETRIS_WIDTH=12;
int TETRIS_X=1;
int TETRIS_Y=1;
int blockType ;                   //7 different block types
int nextBlockType; //to Display the next piece
int state;                        //4 possible rotation states
bool isInitiated=false;
bool isDisplayNextPiece=false;
bool isDisplayScore=false;
int tetrisWebSocketPort=81;

const int activeBlocks [28][4][4] = {
    {{0,0,1,0},    //     blockType + 7(state)
        {0,1,1,0},    // 0 =    0      + 7(0)
        {0,1,0,0},
        {0,0,0,0}}  ,
    
    {{0,2,0,0},    // 1 =    1      + 7(0)
        {0,2,2,0},
        {0,2,0,0},
        {0,0,0,0}} ,
    
    {{0,3,0,0},    // 2 =    2      + 7(0)
        {0,3,3,0},
        {0,0,3,0},
        {0,0,0,0}} ,
    
    {{0,0,0,0},    // 3 =    3      + 7(0)
        {0,4,4,0},
        {0,4,4,0},
        {0,0,0,0}} ,
    
    {{0,5,0,0},    // 4 =    4      + 7(0)
        {0,5,0,0},
        {0,5,5,0},
        {0,0,0,0}} ,
    
    {{0,6,6,0},    // 5 =    5      + 7(0)
        {0,6,0,0},
        {0,6,0,0},
        {0,0,0,0}} ,
    
    {{0,0,7,0},    // 6 =    6      + 7(0)
        {0,0,7,0},
        {0,0,7,0},
        {0,0,7,0}} ,
    
    {{0,0,0,0},  // 7 =    0      + 7(1)
        {1,1,0,0},
        {0,1,1,0},
        {0,0,0,0}}  ,
    
    {{0,0,0,0},    // 8 =    1      + 7(1)
        {2,2,2,0},
        {0,2,0,0},
        {0,0,0,0}} ,
    
    {{0,0,0,0},    // 9 =    2      + 7(1)
        {0,3,3,0},
        {3,3,0,0},
        {0,0,0,0}} ,
    
    {{0,0,0,0},    // 10 =    3      + 7(1)
        {0,4,4,0},
        {0,4,4,0},
        {0,0,0,0}} ,
    
    {{0,0,0,0},    // 11 =    4      + 7(1)
        {5,5,5,0},
        {5,0,0,0},
        {0,0,0,0}} ,
    
    {{0,0,0,0},    // 12 =    5      + 7(1)
        {6,6,6,0},
        {0,0,6,0},
        {0,0,0,0}} ,
    
    {{0,0,0,0},    // 13 =    6      + 7(1)
        {0,0,0,0},
        {7,7,7,7},
        {0,0,0,0}} ,
    
    {{0,1,0,0},    // 14 =    0      + 7(2)
        {1,1,0,0},
        {1,0,0,0},
        {0,0,0,0}}  ,
    
    {{0,2,0,0},    // 15 =    1      + 7(2)
        {2,2,0,0},
        {0,2,0,0},
        {0,0,0,0}} ,
    
    {{3,0,0,0},    // 16 =    2      + 7(2)
        {3,3,0,0},
        {0,3,0,0},
        {0,0,0,0}} ,
    
    {{0,0,0,0},    // 17 =    3      + 7(2)
        {0,4,4,0},
        {0,4,4,0},
        {0,0,0,0}} ,
    
    {{5,5,0,0},    // 18 =    4      + 7(2)
        {0,5,0,0},
        {0,5,0,0},
        {0,0,0,0}} ,
    
    {{0,6,0,0},    // 19 =    5      + 7(2)
        {0,6,0,0},
        {6,6,0,0},
        {0,0,0,0}} ,
    
    {{0,7,0,0},    // 20 =    6      + 7(2)
        {0,7,0,0},
        {0,7,0,0},
        {0,7,0,0}} ,
    
    {{1,1,0,0},    // 21 =    0      + 7(3)
        {0,1,1,0},
        {0,0,0,0},
        {0,0,0,0}}  ,
    
    {{0,2,0,0},    // 22 =    1      + 7(3)
        {2,2,2,0},
        {0,0,0,0},
        {0,0,0,0}} ,
    
    {{0,3,3,0},    // 23 =    2      + 7(3)
        {3,3,0,0},
        {0,0,0,0},
        {0,0,0,0}} ,
    
    {{0,0,0,0},    // 24 =    3      + 7(3)
        {0,4,4,0},
        {0,4,4,0},
        {0,0,0,0}} ,
    
    {{0,0,5,0},    // 25 =    4      + 7(3)
        {5,5,5,0},
        {0,0,0,0},
        {0,0,0,0}} ,
    
    {{6,0,0,0},    // 26 =    5      + 7(3)
        {6,6,6,0},
        {0,0,0,0},
        {0,0,0,0}} ,
    
    {{0,0,0,0},    // 27 =    6      + 7(3)
        {7,7,7,7},
        {0,0,0,0},
        {0,0,0,0}}
};

CRGB paletblock[10]={CRGB::Black,CRGB::Red,CRGB::Green,CRGB::Blue,CRGB::Yellow,CRGB::Purple,CRGB::Cyan,CRGB::White} ;
int blockColumn;             //the x value of the left most row in the 4x4 active block placeholder
int blockRow;                //the y value of the bottom column in the 4x4 active block placeholder

int rowToBeDeleted;
bool inGame = false;
bool justLost = false;
int brightness = 8;
long fallRate;
long dixs=4000000;

WebSocketsServer tetrisWebSocket = WebSocketsServer(tetrisWebSocketPort); //creating the entry for socket

bool initTetris(int w,int h)
{
    if(isTable)
    {
        TETRIS_WIDTH=w;
        TETRIS_HEIGHT=h;
        backgroundBlocks =(CRGB*)os_malloc(w*h*sizeof(CRGB)) ;
        displayScreen =(CRGB*)os_malloc(w*h*sizeof(CRGB)) ;
        if(!backgroundBlocks && !displayScreen)
        {
            Serial.println("Unable to create the screens");
            isInitiated=false;
            return false;
        }
        Serial.println("Tetris créée");
        isInitiated=true;
        return true;
    }
    else{
        Serial.println("No table existing create the table first");
        isInitiated=false;
        return false;
    }
}

void  combineArrays()  //updates the displayScreen array by combining the current positions of the backgroundBlocks and the activeBlocks
{
    //first make an exact copy of the backgroundBlocks
    // Serial.println("on combine");
    for(byte y = 0; y < TETRIS_HEIGHT; y++)
        for(byte x = 0; x < TETRIS_WIDTH; x++)
            displayScreen[x+TETRIS_WIDTH*y] = backgroundBlocks[x+TETRIS_WIDTH*y];
    
    //then add the non zero elements of the activeBlocks
    for(int y = 0; y < 4; y++)
        for(int x = 0; x < 4; x++)
            if(activeBlocks[blockType + (7 * state)][y][x] > 0)
            {
                //   Serial.print("e:");
                //Serial.println(activeBlocks[blockType + (7 * state)][x][y]);
                displayScreen[x + blockColumn+TETRIS_WIDTH*(y + blockRow)] = paletblock[ activeBlocks[blockType + (7 * state)][y][x] ];
            }
}


void displayArray()  // cycles through each pixel in displayScreen and outputs corresponding colour
{
    
    displaypic(displayScreen,TETRIS_X,TETRIS_Y,TETRIS_HEIGHT,TETRIS_WIDTH);
    if(isDisplayNextPiece)
    {
        int x=0;
        int y=0;
        switch (displayNextPiecePos) {
            case DISP_UP:
                 x=2;
                y=(TETRIS_HEIGHT+1+TETRIS_Y);
                break;
            case DISP_RIGHT:
                x=TETRIS_X+TETRIS_WIDTH+2;
                y=2;
                break;
            default:
                break;
        }
        displaypic(nextBlockImage,x,y,3,4); //on ecrit la next piece
    }
    if(isDisplayScore)
    {
        char chi[1];
        sprintf(chi, "%d", score);
        afficheLettre((int)(chi[0])-32,14, 10);
    }
}

void updateDisplay() // this function is called by a timer interupt every 10 milliseconds
{
    //Serial.println("on affiche");
    combineArrays();
    
    
    
    
    // adds the latest position of the active block to the displayScreen Array
    //Serial.println("on display");
    displayArray();
    
    FastLED.show();// outputs the displayScreen Array
}


void resetArrays()  // resets arrays to all zeros
{
    for(byte y = 0; y < TETRIS_HEIGHT; y++)
        for(byte x = 0; x < TETRIS_WIDTH; x++)
        {
            displayScreen[x+TETRIS_WIDTH*y] = CRGB(0,0,0);
            backgroundBlocks[x+TETRIS_WIDTH*y] = CRGB(0,0,0);
        }   }


void fillNextBlock(int blockType)
{
    for(int y = 0; y < 3; y++)
        for(int x = 0; x < 4; x++)
                nextBlockImage[x +4*y] = paletblock[ activeBlocks[blockType + (7 * 3)][y][x] ];
}

void newBlock() //
{
    blockColumn = 2;
    blockRow = TETRIS_HEIGHT-3;
    blockType=nextBlockType;
    nextBlockType = random(7);// blocktype is a random between 0 and 6 inclusive
    //Serial.println(blockType);
    fillNextBlock(nextBlockType);
    state = 3;     // reset state back to spawn block state
}


bool canBeMoved(int newCol, int newRow)  // return true if the there is empty pixels for the block to move in to
{
    for(int y = 0; y < 4; y++)
    {
        for(int x = 0; x < 4; x++)
        {
            if(activeBlocks[blockType + (7 * state)][y][x] > 0)   // finds the positions of the non-blank blocks in the 4x4 matrix
            {
                int boardX = x + newCol;                            // calculates the corresponding x position on the display board
                int boardY = y + newRow;                            // calculates the corresponding y position on the display board
                //Serial.println(boardY);
                if(boardX < 0 ||  boardX > TETRIS_WIDTH-1 || boardY < 0)         // if the pixel is outside the boundaries of the board
                    return false;
                if(backgroundBlocks[boardX+TETRIS_WIDTH*boardY] > CRGB(0,0,0))            // if the pixel is already full
                    return false;
            }
        }
    }
    return true;
}

bool canMoveDown()   // row - 1
{
   if(blockRow-1<0)
       Serial.println(blockRow);
    
    if(canBeMoved(blockColumn, blockRow -1))
        return true;
    else
        return false;
}

bool canMoveLeft()
{
    if(canBeMoved(blockColumn - 1, blockRow)) // column -1
        return true;
    else
        return false;
}

bool canMoveRight()
{
    if(canBeMoved(blockColumn + 1, blockRow)) // column + 1
        return true;
    else
        return false;
}

bool canBeRotated(int newState)
{
    for(int y = 0; y < 4; y++)
    {
        for(int x = 0; x < 4; x++)
        {
            if(activeBlocks[blockType + (7 * newState)][y][x] > 0) // finds the positions of the non-blank blocks in the 4x4 matrix
            {
                int boardX = x + blockColumn;                        // calculates the corresponding x position on the display board
                int boardY = y + blockRow;                           // calculates the corresponding y position on the display board
                if(boardX < 0 ||  boardX > TETRIS_WIDTH || boardY < 0)          // if the pixel is outside the boundaries of the board
                    return false;
                
                if(backgroundBlocks[boardX+TETRIS_WIDTH*boardY] > CRGB(0,0,0))             // if the pixel is already full
                    return false;
            }
        }
    }
    return true;
}

bool canRotateLeft()
{
    int nextState;
    if(state == 0)      // state to the left of 0 is 3
        nextState = 3;
    else
        nextState = state - 1;
    
    if(canBeRotated(nextState))
        return true;
    else
        return false;
}

bool canRotateRight()
{
    int nextState;
    if(state == 3)      // state to the right of 3 is 0
        nextState = 0;
    else
        nextState = state + 1;
    
    if(canBeRotated(nextState))
        return true;
    else
        return false;
}

void moveActiveBlocksToBackground()
{
    combineArrays(); //updated the display array
    
    for(byte y = 0; y < TETRIS_HEIGHT; y++)
        for(byte x = 0; x < TETRIS_WIDTH; x++)
            backgroundBlocks[x+TETRIS_WIDTH*y] = displayScreen[x+TETRIS_WIDTH*y];    // copy the displayScreen to the backgroundBlocks
}

bool rowIsFull()                // goes through all 16 rows and checks if they are full
{
    for(byte y = 0; y < TETRIS_HEIGHT; y++)
    {
        bool isfull=true;
        for(byte x=0;x<TETRIS_WIDTH;x++)
        {
            if( backgroundBlocks[TETRIS_WIDTH*y+x] ==CRGB(0,0,0)  )
                isfull= false;
        }
        if(isfull)
        {
            Serial.println("on efface la ligne");
            rowToBeDeleted = y;      // the row is returned as a global variable
            return true;
        }
    }
    return false;
}

void deleteRow()
{
    score++;
    
    if(rowToBeDeleted==TETRIS_HEIGHT-1)
    {
        for(byte x = 0; x < TETRIS_WIDTH; x++)
            backgroundBlocks[x+TETRIS_WIDTH*(TETRIS_HEIGHT-1)] = CRGB(0,0,0);
    }
    else
    {
       // Serial.print("On efface ligne:");
       // Serial.println(rowToBeDeleted);
        for(byte y = rowToBeDeleted; y < TETRIS_HEIGHT-1; y++)
            for(byte x = 0; x < TETRIS_WIDTH; x++)
                backgroundBlocks[x+TETRIS_WIDTH*y] = backgroundBlocks[x+TETRIS_WIDTH*(y + 1)];  // replaces row with row above

    }
    
}


void speedUpFalling()
{
    if(fallRate > 1)   // to stop fallRate decreasing to zero
        fallRate -= 1;   // blocks falling speeds up by 50000 nanoseconds every full row made
    
    
}

void deleteFullRows()
{
    for(int i = 0; i < 4; i++) // checking 4 times if there are full rows to be deleted
    {
        if(rowIsFull())
        {
            deleteRow();
            speedUpFalling();
        }
    }
}

bool spaceForNewBlock()  // returns true if there is space for the new block to be spawned at the top of the matrix
{
    if(canBeMoved(2, TETRIS_HEIGHT-3))
        return true;
    else
        return false;
}


void fillScreenT()       // fills pixels one at a time with green at the end of the game one at a time starting from the top
{
    for(int y = 0; y <TETRIS_HEIGHT; y++)
    {
        for(int x = 0; x < TETRIS_WIDTH; x++)
        {
            displayScreen[x+TETRIS_WIDTH*y] = CRGB(0,100,0);    // turns the pixel green

        }
        displayArray();
        FastLED.show();// outputs the pixel change to the screen
        FastLED.delay(30);
    }
}


void fall()               // this function is called by a timer interupt every fallRate nanoseconds
{
    // Serial.println("on fal");
    noInterrupts();
    if(canMoveDown())
        blockRow--;
    else   //block cant move
    {
        moveActiveBlocksToBackground();      // adds the activeBlocks to the background display
        deleteFullRows();                    // deletes any full rows caused by now stationary block
        newBlock();
        if(spaceForNewBlock())
        {// checks can a new block spawn
 
        }
        else  // new block cant spawn so game over
        {
            timer0_detachInterrupt();            // timer1_detachInterrupt();// stops timer1 interupt

            //interrupts();
            //fillScreenT();
            inGame = false;
            justLost = true;
            //os_free(displayScreen);
            
            //delay(3000);
            //newGame();
            return;
        }
    }
    updateDisplay();
    long    next=ESP.getCycleCount() +  fallRate*dixs;
    timer0_write(next);
    interrupts();
    //yield();
}








void newGame()
{
    inGame = true;
    justLost = false;
    score=0;
    fallRate=10;
    Serial.println("voici tetris");// clears the red display matrix
    if(!isInitiated)
    {
        Serial.println("on cree la base fait");
        initTetris(TETRIS_WIDTH,TETRIS_HEIGHT);
        
    }
    if(isInitiated)
    {
        inGame = true;
        justLost = false;
        resetArrays();
        randomSeed(ESP.getCycleCount());
        nextBlockType = random(7); //on initie le next block type
        newBlock();
        updateDisplay();
        fallRate = 10;
        noInterrupts();

        timer0_isr_init();
        timer0_attachInterrupt(fall);
        long  next=ESP.getCycleCount() + fallRate*dixs;
        timer0_write(next);
        interrupts();
    }
    else
    {
        Serial.println("Tetris creation impossible");
    }
}



void tetrisWebSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length)
{
    noInterrupts();
   // Serial.printf("webSocketEvent(%d, %d, ...)\r\n", num, type);
    switch(type) {
        case WStype_DISCONNECTED:
            Serial.printf("[%u] Disconnected!\r\n", num);
            break;
        case WStype_CONNECTED:
        {
            IPAddress ip = tetrisWebSocket.remoteIP(num);
     //       Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\r\n", num, ip[0], ip[1], ip[2], ip[3], payload);
            // Send the current LED status
        }
            break;
        case WStype_TEXT:
           Serial.printf("[%u] get Text: %s\r\n", num, payload);
        /*    if (strcmp("up", (const char *)payload) == 0)  {
                //writeLED(true);
                Serial.println("on go up");
                YO = (YO + 1) % LED_HEIGHT;
                fill_solid(leds, NUM_LEDS, bgColor);
            }
            else  if (strcmp("down", (const char *)payload) == 0)  {
                Serial.println("on go down");
                YO = (YO -1) % LED_HEIGHT;
                fill_solid(leds, NUM_LEDS, bgColor);
            }
            */
            if (strcmp("right", (const char *)payload) == 0)  {
                
               // Serial.println("on va a droite");
                if(canMoveRight())
                {
                    noInterrupts();
                    blockColumn++;
                    updateDisplay();
                    int next=ESP.getCycleCount()+fallRate*dixs;
                    timer0_write(next);
                    interrupts();
                }
            }
            
            if (strcmp("left", (const char *)payload) == 0)  {
                
                //Serial.println("on va a droite");
                if(canMoveLeft())
                {
                    noInterrupts();
                    blockColumn--;
                    updateDisplay();
                    int next=ESP.getCycleCount()+fallRate*dixs;
                    timer0_write(next);
                    interrupts();
                }
            }
            if (strcmp("new", (const char *)payload) == 0)  {
                 fill(bgColor);
                newGame();
            }
            
            if (strcmp("turnr", (const char *)payload) == 0)  {
                
                if(canRotateRight())
                {
                    noInterrupts();
                    if(state == 3)
                        state = 0;  // state to the right of 3 is 0
                    else
                        state++;
                    
                    updateDisplay();
                    int next=ESP.getCycleCount()+fallRate*dixs;
                    timer0_write(next);
                    interrupts();
                }
                
            }
            
            
            
            
            if (strcmp("turnl", (const char *)payload) == 0)  {
                
                if(canRotateLeft())
                {
                    noInterrupts();
                    if(state == 0)
                        state = 3;  // state to the right of 3 is 0
                    else
                        state--;
                    
                    updateDisplay();
                    int next=ESP.getCycleCount()+fallRate*dixs;
                    timer0_write(next);
                    interrupts();
                }
                
            }
            
            
            else {
               // Serial.println("Unknown command");
            }
            // send data to all connected clients
            //webSocket.broadcastTXT(payload, length);
            break;
        case WStype_BIN:
            Serial.printf("[%u] get binary length: %u\r\n", num, length);
            hexdump(payload, length);
            
            // echo data back to browser
            // webSocket.sendBIN(num, payload, length);
            break;
        default:
            Serial.printf("Invalid WStype [%d]\r\n", type);
            break;
    }
    
    interrupts();
}


void initTetrisScoketControl()
{
    tetrisWebSocket.begin();
    tetrisWebSocket.onEvent(tetrisWebSocketEvent);
}

void executeTetrisSocketControl()
{
    tetrisWebSocket.loop();

}





#endif /* tetris_h */
