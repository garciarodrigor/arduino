
/* 
 Stepper Motor Control - one revolution
 
 This program drives a unipolar or bipolar stepper motor. 
 The motor is attached to digital pins 8 - 11 of the Arduino.
 
 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.  
 
  
 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe
 
 */

#include <Arduino.h>
#include <Stepper.h>

/*
 * Stepper 1 Config
 */
#define SP1_1 2
#define SP1_2 3
#define SP1_3 4
#define SP1_4 5
#define SP1_STEPS 48
#define SP1_MAXSPD 60

/*
 * Stepper 2 Config
 */
#define SP2_1 6
#define SP2_2 7
#define SP2_3 8
#define SP2_4 9
#define SP2_STEPS 48
#define SP2_MAXSPD 60

void stepperInit(Stepper &sp, int speed)
{
    // set the speed
    sp.setSpeed(speed);
}

/**
 * Draw a pattern
 *
 * sp1: Stepper 1
 * sp2: Stepper 2
 * sz1: Initial Size
 * sz2: Final Size
 * step: Size increment
 * loop: Number of iteration
 */
void draw_pattern_1(Stepper &sp1, Stepper &sp2, int sz1, int sz2, int step, int loop)
{
    while (loop > 0) {

        int size  = sz1;
    
        while (size < sz2) {
            sp1.step(size);    
            size += step;
            delay(10);
                
            sp2.step(size);    
            size += step;
            delay(10);
            
            sp1.step(-size);
            size += step;
            delay(10);

            sp2.step(-size);
            size += step;
            delay(10);
            
            //step++;
        }
        
        loop--; 
    }
}

/**
 * Draw a pattern
 *
 * sp1: Stepper 1
 * sp2: Stepper 2
 * size: Pattern Size
 * step: Initial Step
 * loop: Number of iterations
 */
void draw_pattern_2(Stepper &sp1, Stepper &sp2, int size, int step, int loop)
{
    while (loop > 0 || step == 0) {

        sp1.step(size);    
        delay(10);
            
        sp2.step(step);    
        delay(10);
        
        sp1.step(-size);
        delay(10);

        sp2.step(step);
        delay(10);

        step--;
        loop--; 
    }
}

void setup()
{
    Stepper s1(SP1_STEPS, SP1_1, SP1_2, SP1_3, SP1_4);
    Stepper s2(SP2_STEPS, SP2_1, SP2_2, SP2_3, SP2_4);

    stepperInit(s1, SP1_MAXSPD);
    stepperInit(s2, SP2_MAXSPD);

    draw_pattern_2(s2, s1, -48, 0, 12);
    draw_pattern_1(s2, s1, 2, 12, 1, 4);
    draw_pattern_2(s1, s2, 48, 0, 12); 
}

void loop()
{
}

