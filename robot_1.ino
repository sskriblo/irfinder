/*
Main program.
*/
#include <Servo.h> 
///////////////////////////////////////////////////////////////////////////////////////
/*************************************************************************************
ToDo:
1) Search at reverse path;
2) Search at low angle span next time;
3) Catch instead Search. Means that when angle found then catch at small angle span
4) Move and Catch simultaneously;
5) If target not found than turn around and search again;

HISTORY:
2013-04-13 R.0.1 - initial release, works well, but need more polishing

**************************************************************************************/
///////////////////////////////////////////////////////////////////////////////////////
// State machine enum:
#define SM_START     0
#define SM_SEARCH    1
#define SM_ROTATE    2
#define SM_MOVE      3
#define SM_IR_TEST   4
#define SM_FINISH    99

int MOTOR_L_PWM = 11;    // LEFT Motor connected to digital pin 11
int MOTOR_R_PWM = 6;    // RIGHT Motor connected to digital pin 6
int MOTOR_R_1 = 2;
int MOTOR_R_2 = 3;
int MOTOR_L_1 = 4;
int MOTOR_L_2 = 5;
#define SERVO_PIN     10

#define SERVO_STEP    5 /* шаг поворота SERVO 5 град */
#define SERVO_180_NUM 36 /*число шагов SERVO при повороте на 180*/
#define SERVO_ZERO 20  /* позиция, соответствующая положению "прямо"*/
#define SERVO_TRSH    2 /*порог, если больше, то доворачиваем, если нет, то едем прямо*/

#define K_ANGLE2TIME 20

Servo myservo; 

unsigned int ampl[SERVO_180_NUM]; // массив амплитуд для измерения в секторе 180 с шагом 5
byte sm_state = SM_START; // State machine sm_state
byte angle = SERVO_ZERO;
signed int delta = 0;
///////////////////////////////////////////////////////////////////////////////////////
void setup() 
{ 
// Define various ADC prescaler
const unsigned char PS_16 = (1 << ADPS2);
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
  pinMode(0, INPUT);  
  // set up the ADC
  ADCSRA &= ~PS_128;  // remove bits set by Arduino library
  // you can choose a prescaler from above.
  // PS_16, PS_32, PS_64 or PS_128
  ADCSRA |= PS_32;    
//  myservo.attach(SERVO_PIN,544,2400); //default
  myservo.attach(SERVO_PIN,544,2400);  
  Serial.begin(9600);  
  // initialize the digital pin as an output.
  pinMode(MOTOR_L_PWM, OUTPUT); 
  pinMode(MOTOR_R_PWM, OUTPUT); 
  pinMode(MOTOR_R_1, OUTPUT); 
  pinMode(MOTOR_R_2, OUTPUT); 
  pinMode(MOTOR_L_1, OUTPUT); 
  pinMode(MOTOR_L_2, OUTPUT);  
  motor_stop();  
} 
///////////////////////////////////////////////////////////////////////////////////////
void loop() {
    byte i;
    switch(sm_state){
       case SM_IR_TEST:
           for(;;){
             ampl[0] = ampl_measure();
             delay(200);
           }
           break;  
       case SM_START:
 //         motor_test();
            sm_state = SM_SEARCH;
            break;
        
        case SM_SEARCH:
            Serial.print("\nSM_SEARCH\n");    
             /* поворачиваем SERVO на 180 с шагом 5, на каждом шаге 
              измеряем амплитуду и сохраняем  в массиве ampl[]
             */
            for(i=0; i<SERVO_180_NUM;i++){
  //              Serial.print("=");    
  //              Serial.print(SERVO_STEP * i);
                myservo.write(SERVO_STEP * i);
                delay(25);
                ampl[i] = ampl_measure();
             }
             angle = angle_comp();
             delta = angle - SERVO_ZERO;
             if (abs(delta) > SERVO_TRSH){
               sm_state = SM_ROTATE;             
             }else{
               sm_state = SM_MOVE;             
             }
             break;
         case SM_ROTATE:
             Serial.print("\nSM_ROTATE\n");    
             rotate();
             sm_state = SM_SEARCH;
             break;
         case SM_MOVE:
             Serial.print("\nSM_MOVE\n");    
             go_forward(200,255);
             sm_state = SM_SEARCH;
             break;
         case SM_FINISH:
//         sm_state = SM_SEARCH;
             break;
 }                
    delay(100);
}
