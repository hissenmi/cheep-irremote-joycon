#include "Joystick.h"
#include "IRremote.h"

////////////////////////////////////
// Joystick
////////////////////////////////////
// Create Joystick
Joystick_ Joystick;

// 入力検知後、次回入力検知を行うまで間隔(ms)
const unsigned long gcButtonDelta = 150;
// 999は入力なしを示すための値。それ以外の場合は実際のボタンの値
unsigned long gBeforeValue = 999;
// 次回のチェック時間（ms） millis()を入れる
unsigned long gNextTime = 0;

////////////////////////////////////
// IR Receiver
////////////////////////////////////
int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11
/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

// IRの定数
#define IR_REPEAT       0xFFFFFFFF
#define IR_POWER        0xFFA25D
#define IR_VOL_PLUS     0xFF629D
#define IR_FUNC         0xFFE21D
#define IR_FAST_BACK    0xFF22DD
#define IR_PAUSE        0xFF02FD
#define IR_FAST_FORWARD 0xFFC23D
#define IR_DOWN         0xFFE01F
#define IR_VOL_MINUS    0xFFA857
#define IR_UP           0xFF906F
#define IR_EQ           0xFF9867
#define IR_ST_REPT      0xFFB04F
#define IR_0            0xFF6897
#define IR_1            0xFF30CF
#define IR_2            0xFF18E7
#define IR_3            0xFF7A85
#define IR_4            0xFF10EF
#define IR_5            0xFF38C7
#define IR_6            0xFF5AA5
#define IR_7            0xFF42BD
#define IR_8            0xFF4AB5
#define IR_9            0xFF52AD

// 有効にするdecoderの定義
#define DECODE_RC5           0
#define DECODE_RC6           0
#define DECODE_NEC           1
#define DECODE_SONY          0
#define DECODE_PANASONIC     0
#define DECODE_JVC           0
#define DECODE_SAMSUNG       0
#define DECODE_WHYNTER       0
#define DECODE_AIWA_RC_T501  0
#define DECODE_LG            0
#define DECODE_SANYO         0
#define DECODE_MITSUBISHI    0
#define DECODE_DISH          0 // NOT WRITTEN
#define DECODE_SHARP         0 // NOT WRITTEN
#define DECODE_DENON         0
#define DECODE_LEGO_PF       0 // NOT WRITTEN


////////////////////////////////////
// function
////////////////////////////////////
void translateIRtoJoystick()
{
//  Serial.println(results.value);
  switch(results.value)
  {
    case IR_POWER:
//      Serial.println("power");
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(0);
      gBeforeValue = 0;
      break;

    case IR_VOL_PLUS:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(1);
      gBeforeValue = 1;
      break;

    case IR_FUNC:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(2);
      gBeforeValue = 2;
      break;

    case IR_FAST_BACK:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(3);
      gBeforeValue = 3;
      break;

    case IR_PAUSE:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(4);
      gBeforeValue = 4;
      break;

    case IR_FAST_FORWARD:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(5);
      gBeforeValue = 5;
      break;

    case IR_DOWN:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(6);
      gBeforeValue = 6;
      break;

    case IR_VOL_MINUS:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(7);
      gBeforeValue = 7;
      break;

    case IR_UP:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(8);
      gBeforeValue = 8;
      break;

    case IR_EQ:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(9);
      gBeforeValue = 9;
      break;

    case IR_ST_REPT:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(10);
      gBeforeValue = 10;
      break;

    case IR_0:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(11);
      gBeforeValue = 11;
      break;

    case IR_1:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(12);
      gBeforeValue = 12;
      break;

    case IR_2:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(13);
      gBeforeValue = 13;
      break;

    case IR_3:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(14);
      gBeforeValue = 14;
      break;

    case IR_4:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(15);
      gBeforeValue = 15;
      break;

    case IR_5:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(16);
      gBeforeValue = 16;
      break;

    case IR_6:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(17);
      gBeforeValue = 17;
      break;

    case IR_7:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(18);
      gBeforeValue = 18;
      break;

    case IR_8:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(19);
      gBeforeValue = 19;
      break;

    case IR_9:
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);      
      }
      Joystick.pressButton(20);
      gBeforeValue = 20;
      break;


    case IR_REPEAT:
//      Serial.println("repeat!");
      if (gBeforeValue != 999) {
        Joystick.pressButton(gBeforeValue);
      }
      break;

    default:
//      Serial.println("*other*");
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);
        gBeforeValue = 999;        
      }
      break;
  }
}

/**
 * 初期化処理
 */
void setup()
{
  /////////////////////////
  // IR receiver
  /////////////////////////
  // Start the IR receiver
  Serial.begin(9600);
  irrecv.enableIRIn(); 

  /////////////////////////
  // Joystick
  /////////////////////////
  // Set Range Values
  Joystick.setXAxisRange(-127, 127);
  Joystick.setYAxisRange(-127, 127);
  Joystick.setZAxisRange(-127, 127);
  Joystick.setRxAxisRange(0, 360);
  Joystick.setRyAxisRange(360, 0);
  Joystick.setRzAxisRange(0, 720);
  Joystick.setThrottleRange(0, 255);
  Joystick.setRudderRange(255, 0);
  
  Joystick.begin(false);
}

/**
 * メイン処理
 */
void loop()
{
  if (irrecv.decode(&results)) {
    gNextTime = millis() + gcButtonDelta;
    translateIRtoJoystick();
    Joystick.sendState();
    delay(20);
    irrecv.resume(); // receive the next value
  } else {
    // 赤外線からの入力がないまま所定の間隔を過ぎた場合、ボタンのkeyUpを行う
    if (millis() >= gNextTime) {
      if (gBeforeValue != 999) {
        Joystick.releaseButton(gBeforeValue);
        Joystick.sendState();        
      }
    }
  }

  
  
}
