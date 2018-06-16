// @Library : TTP229.c
// @Author  : hatodev (haiphamnguyenhoang@gmail.com)
// @Brief   : This library is built for PIC microcontroller to work with
//            TTP229 4x4 capacitive touchpad module
          
#IFNDEF TTP229_SCL
#DEFINE TTP229_SCL  PIN_A0
#ENDIF

#IFNDEF TTP229_SDA
#DEFINE TTP229_SDA  PIN_A1
#ENDIF

#DEFINE TTP229_SCL_SET(X)     OUTPUT_BIT(TTP229_SCL,X)
#DEFINE TTP229_SDA_SET(X)     OUTPUT_BIT(TTP229_SDA,X)

// KEYPAD FUNCTIONS
//#DEFINE KEYPAD_BACKSPACE 4
#DEFINE KEYPAD_BACKSPACE 13
//#DEFINE KEYPAD_CLEAR     8
#DEFINE KEYPAD_CLEAR     15
//#DEFINE KEYPAD_CANCEL    12
//#DEFINE KEYPAD_OK        16
// KEYPAD NUMBERS
#DEFINE KEYPAD_1         1
#DEFINE KEYPAD_2         2
#DEFINE KEYPAD_3         3
#DEFINE KEYPAD_4         5
#DEFINE KEYPAD_5         6    
#DEFINE KEYPAD_6         7
#DEFINE KEYPAD_7         9
#DEFINE KEYPAD_8         10   
#DEFINE KEYPAD_9         11
//#DEFINE KEYPAD_STAR      13
#DEFINE KEYPAD_0         14
//#DEFINE KEYPAD_SHARP     15

UINT8_T TTP229_GETKEY(VOID){
     UINT8_T I=0,NUM=0;
     FOR(I=0;I<16;I++){
          TTP229_SCL_SET(0);
          IF(!INPUT(TTP229_SDA)){
               NUM=I+1;
          }
          TTP229_SCL_SET(1);
     }
     RETURN NUM;
}

UINT8_T KEYPAD_CONVERT(UINT8_T NUM){
     SWITCH(NUM){
          CASE KEYPAD_1:
               RETURN 1;
          CASE KEYPAD_2:
               RETURN 2;
          CASE KEYPAD_3:
               RETURN 3;
          CASE KEYPAD_4:
               RETURN 4;
          CASE KEYPAD_5:
               RETURN 5;
          CASE KEYPAD_6:
               RETURN 6;
          CASE KEYPAD_7:
               RETURN 7;
          CASE KEYPAD_8:
               RETURN 8;
          CASE KEYPAD_9:
               RETURN 9;
          CASE KEYPAD_0:
               RETURN 0;
          DEFAULT:
               RETURN 0;
     }
}

UINT8_T KEYPAD_CONVERTTOCHAR(UINT8_T NUM){
     SWITCH(NUM){
          CASE KEYPAD_1:
               RETURN '1';
          CASE KEYPAD_2:
               RETURN '2';
          CASE KEYPAD_3:
               RETURN '3';
          CASE KEYPAD_4:
               RETURN '4';
          CASE KEYPAD_5:
               RETURN '5';
          CASE KEYPAD_6:
               RETURN '6';
          CASE KEYPAD_7:
               RETURN '7';
          CASE KEYPAD_8:
               RETURN '8';
          CASE KEYPAD_9:
               RETURN '9';
          CASE KEYPAD_0:
               RETURN '0';
          DEFAULT:
               RETURN 0;
     }
}
