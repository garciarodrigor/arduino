/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

#include <Arduino.h>
#include <AccelStepper.h>

/*
 * Stepper 1 Config
 */
#define SP1_1 2
#define SP1_2 3
#define SP1_3 4
#define SP1_4 5
#define SP1_STEPS 48
#define SP1_MAXSPD 180

/*
 * Stepper 2 Config
 */
#define SP2_1 6
#define SP2_2 7
#define SP2_3 8
#define SP2_4 9
#define SP2_STEPS 48
#define SP2_MAXSPD 180


AccelStepper sp1;
AccelStepper sp2;


int sp1_paths[]     = {SP1_STEPS * 2, 0, SP1_STEPS, 0, SP1_STEPS / 2, 0};
int sp1_paths_count = 6;
int sp1_idx         = 0;

int sp2_paths[]     = {SP2_STEPS * 8, 0};
int sp2_paths_count = 2;
int sp2_idx         = 0;


AccelStepper stepperInit(int p1, int p2, int p3, int p4, int maxSpd) {
    AccelStepper sp = AccelStepper(AccelStepper::FULL4WIRE, p1, p2, p3, p4);
    sp.setMaxSpeed(maxSpd);
    sp.setAcceleration(maxSpd);

    return sp;
}


int stepperNextPath(AccelStepper sp, int sp_paths[], int sp_idx, int sp_max)
{
    sp.moveTo(sp_paths[sp_idx%sp_max]);
    sp_idx++;
    
    return sp_idx;
}
 

void setup() {
    
    sp1 = stepperInit(SP1_1, SP1_2, SP1_3, SP1_4, SP1_MAXSPD);       
    sp1_idx = stepperNextPath(sp1, sp1_paths, sp1_idx, sp1_paths_count);
        
    sp2 = stepperInit(SP2_1, SP2_2, SP2_3, SP2_4, SP2_MAXSPD);    
    sp2_idx = stepperNextPath(sp2, sp2_paths, sp2_idx, sp2_paths_count);

    Serial.begin(9600);
}

void loop() {

    if (sp1.distanceToGo() == 0) {
        sp1.moveTo(sp1_paths[sp1_idx%sp1_paths_count]);
        sp1_idx++;
    }

    if (sp2.distanceToGo() == 0) {
        sp2.moveTo(sp2_paths[sp2_idx%sp2_paths_count]);
        sp2_idx++;
    }
    
    //Serial.print(sp1.distanceToGo());
    Serial.print(sp1.currentPosition());
    //Serial.print(sp1_idx%sp1_paths_count);
    
    Serial.print(" - "); 
    Serial.println(sp2.currentPosition());

    sp1.run();
    sp2.run();
}
