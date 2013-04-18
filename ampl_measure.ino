int ampl_measure(){

#define SIZE 50
    unsigned long start_times[SIZE];
    unsigned long stop_times[SIZE];
    unsigned long values[SIZE];
    unsigned int i,val;
    unsigned int val_min;
    unsigned int val_max;
    int val_diff;
  
    // capture the values to memory
    for(i=0;i<SIZE;i++) {
        start_times[i] = micros();
        delayMicroseconds(70);  // total 104 uS           
        values[i] = analogRead(0);
        stop_times[i] = micros();
    }
    val_min = 1024;
    val_max = 0;
    for(i=0;i<SIZE;i++){
        val = values[i];
        if(val < val_min){
            val_min = val;
        }
        if(val > val_max){
            val_max = val;    
        }
    }
    val_diff = val_max - val_min;
//    Serial.print("\ndiff=");    
//    Serial.print(val_max - val_min);
    return val_diff;
}

