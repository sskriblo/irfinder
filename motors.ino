///////////////////////////////////////////////////////////////////////////////////////
void motor_forward(void){
  //1,2=> H+H=idle; L+L=idle; H+L=Back; L+H=Forward
    digitalWrite(MOTOR_R_1, LOW);   // 
    digitalWrite(MOTOR_R_2, HIGH);   // 
    digitalWrite(MOTOR_L_1, LOW);   // 
    digitalWrite(MOTOR_L_2, HIGH);   // 
}
void motor_back(void){
  //1,2=> H+H=idle; L+L=idle; H+L=Back; L+H=Forward
    digitalWrite(MOTOR_R_1, HIGH);   // 
    digitalWrite(MOTOR_R_2, LOW);   // 
    digitalWrite(MOTOR_L_1, HIGH);   // 
    digitalWrite(MOTOR_L_2, LOW);   // 
}
void motor_left(void){
  //1,2=> H+H=idle; L+L=idle; H+L=Back; L+H=Forward
    digitalWrite(MOTOR_R_1, LOW);   // 
    digitalWrite(MOTOR_R_2, HIGH);   // 
    digitalWrite(MOTOR_L_1, LOW);   // 
    digitalWrite(MOTOR_L_2, LOW);   // 
}
void motor_right(void){
  //1,2=> H+H=idle; L+L=idle; H+L=Back; L+H=Forward
    digitalWrite(MOTOR_R_1, LOW);   // 
    digitalWrite(MOTOR_R_2, LOW);   // 
    digitalWrite(MOTOR_L_1, LOW);   // 
    digitalWrite(MOTOR_L_2, HIGH);   // 
}
void motor_turn_around_left(void){
  //1,2=> H+H=idle; L+L=idle; H+L=Back; L+H=Forward
    digitalWrite(MOTOR_R_1, LOW);   // 
    digitalWrite(MOTOR_R_2, HIGH);   // 
    digitalWrite(MOTOR_L_1, HIGH);   // 
    digitalWrite(MOTOR_L_2, LOW);   // 
}
void motor_turn_around_right(void){
  //1,2=> H+H=idle; L+L=idle; H+L=Back; L+H=Forward
    digitalWrite(MOTOR_R_1, HIGH);   // 
    digitalWrite(MOTOR_R_2, LOW);   // 
    digitalWrite(MOTOR_L_1, LOW);   // 
    digitalWrite(MOTOR_L_2, HIGH);   // 
}
void motor_stop(void){
  //1,2=> H+H=idle; L+L=idle; H+L=Back; L+H=Forward
    digitalWrite(MOTOR_R_1, LOW);   // 
    digitalWrite(MOTOR_R_2, LOW);   // 
    digitalWrite(MOTOR_L_1, LOW);   // 
    digitalWrite(MOTOR_L_2, LOW);   // 
}
///////////////////////////////////////////////////////////////////////////////////////
void pwm_set(byte pwm){
  analogWrite(MOTOR_R_PWM, pwm);
  analogWrite(MOTOR_L_PWM, pwm);
}
void  go_forward(unsigned int t, byte pwm){
  pwm_set(pwm);
  motor_forward();  
  delay(t);   
  motor_stop();  
}  
void go_back(unsigned int t, byte pwm){
  pwm_set(pwm);
  motor_back();
  delay(t);                          
  motor_stop();  
}  
void go_stop(unsigned int t, byte pwm){
  pwm_set(pwm);
  motor_stop(); 
  delay(t);                           
}
void go_left(unsigned int t, byte pwm){
  pwm_set(pwm);
  motor_left();
  delay(t);                          
  motor_stop();  
}  
void go_right(unsigned int t, byte pwm){
  pwm_set(pwm);
  motor_right();
  delay(t);                          
  motor_stop();  
}  
void go_turn_around_left(unsigned int t, byte pwm){
  pwm_set(pwm);
  motor_turn_around_left();
  delay(t);                          
  motor_stop();  
}  
void go_turn_around_right(unsigned int t, byte pwm){
  pwm_set(pwm);
  motor_turn_around_right();
  delay(t);                          
  motor_stop();  
}  
///////////////////////////////////////////////////////////////////////////////////////
void motor_test(void){
  go_forward(300,255);
  go_back(300,255);
  go_stop(300,255);
  go_left(300,255);
  go_right(300,255);
  go_turn_around_left(300,255);
  go_turn_around_right(300,255);
  delay(5000);  
}



