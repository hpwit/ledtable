//
//  paint.h
//  
//
//  Created by Yves BAZIN on 14/12/17.
//

#ifndef paint_h
#define paint_h


void initPaintScoketControl();
void paintWebSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length);
void initPaint();
void newPaint();
void executePaintSocketControl();

int paintWebSocketPort=82;
bool paintInitiated=false;
bool inPaint=false;

WebSocketsServer paintWebSocket = WebSocketsServer(paintWebSocketPort);

void initPaintScoketControl()
{
    paintWebSocket.begin();
   paintWebSocket.onEvent(paintWebSocketEvent);
}

void executePaintSocketControl()
{
    paintWebSocket.loop();
    
}




bool initPaint()
{
    if(isTable) 
    {
        server.serveStatic("/paint.html", SPIFFS, "/paint.html"); //on ajoute le lien vers tetris
        initPaintScoketControl();
        paintInitiated=true;
                Serial.println("patint cree");
        return true;

    }
    else{
        Serial.println("No table existing create the table first");
        paintInitiated=false;
        return false;
    }
}




void newPaint()
{

    Serial.println("voici paint");// clears the red display matrix
    if(!paintInitiated)
    {
        Serial.println("on cree la base fait");
        initPaint();
        
    }
    inPaint=true;
    fill(CRGB(0,0,0));
    FastLED.show();

}


void paintWebSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length)
{
   // noInterrupts();
    // Serial.printf("webSocketEvent(%d, %d, ...)\r\n", num, type);
    switch(type) {
        case WStype_DISCONNECTED:
            Serial.printf("[%u] Disconnected!\r\n", num);
            break;
        case WStype_CONNECTED:
        {
            IPAddress ip = paintWebSocket.remoteIP(num);
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
            
            char str[20];
            int x,y,r,g,b;
            sscanf ((const char *)payload,"%s  %d  %d %d %d %d",str,&x,&y,&r,&b,&g);
            if (strcmp("paint", (const char *)str) == 0)  {
                PixelOn(x,y,CRGB(r,g,b));
                FastLED.show();
                // Serial.println("on va a droite");
  
            }
            
          
            if (strcmp("new", (const char *)payload) == 0)  {
                fill(CRGB(0,0,0));
                
                newPaint();
            }
            if (strcmp("stop", (const char *)payload) == 0)  {
                fill(bgColor);
                inPaint=false;
                
                
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
    
   // interrupts();
}

#endif /* paint_h */
