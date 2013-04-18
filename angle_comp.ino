byte angle_comp(){
    byte i;
    unsigned int val_max = 0;
    byte angle = 0;    
    Serial.print("\n ampl array");
    for(i=0; i<SERVO_180_NUM;i++){
        Serial.print("  ");
        Serial.print(i);
        Serial.print("-");
        Serial.print(ampl[i]);
        if (ampl[i] > val_max){
            val_max = ampl[i];
            angle = i;
        }
    }  
    Serial.print("\nangle=");
    Serial.print(angle);    
    return angle;
}
