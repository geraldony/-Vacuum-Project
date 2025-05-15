/* Author: Gerald Onyedika */
/* Project: Autonomous Vaccum Robot */

// Including the motorcode.h file  and arduino functions
#include "motorcode.h" // local code
#include <Arduino.h>

// defining the ESP32 pins for the motors by their GPIOS per the schematic 
#define Motor_1A 25 //D25 on my ESP32
#define Motor_1B 26 //D26 on my ESP32
#define Motor_2A 16 // RX2 on my ESP32
#define Motor_2B 17 // TX2 on my ESP32

// Core  motor  methods 


/* Please keep in mind that  methods depend on which motor is on the right side and which is on the left*
* I am assuming Motor 1 is on the right and Motor2 is on the left; if for some reason it's connected wrogn to the microController 
; all I need to do is switch the logic
for the turnRight(), turnLeft()
*/


// Method that initially  states  what type of pins each of the GPIOs are/
void setUpMotors(){
    pinMode(Motor_1A,OUTPUT);
    pinMode(Motor_1B,OUTPUT);
    pinMode(Motor_2A,OUTPUT);
    pinMode(Motor_2B,OUTPUT);
}

// Method to move forward

void driveFwd(){
    digitalWrite(Motor_1A, HIGH);
    digitalWrite(Motor_1B, LOW);
    digitalWrite(Motor_2B,LOW);
    digitalWrite(Motor_2A, HIGH);
}

// Method to move backwards(reverse the polarity of the fwd pins)
void driveBwd(){
 digitalWrite(Motor_1A, LOW);
    digitalWrite(Motor_1B,HIGH);
    digitalWrite(Motor_2B,HIGH);
    digitalWrite(Motor_2A, LOW);
}

/* Method for turning right 
*Motor 2 stops
*Motor 1 keeps spinning 
*Motor 1 is shorted/both set to high to account for edge cases where a sharp right is needed
*/
void turnRight(){
    digitalWrite(Motor_1A, HIGH);
    digitalWrite(Motor_1B, HIGH);
    digitalWrite(Motor_2B,HIGH);
    digitalWrite(Motor_2A, LOW);
}

/* Method for turning left 
*Motor 1 stops
*Motor 2 keeps spinning 
*Motor 2 is shorted/both set to high to account for edge cases where a sharp left is needed
*/
void turnLeft(){
     digitalWrite(Motor_1A, HIGH);
    digitalWrite(Motor_1B, LOW);
    digitalWrite(Motor_2B,HIGH);
    digitalWrite(Motor_2A, HIGH);

}

//Method to stop the motors gently 
void stopMotor(){
     digitalWrite(Motor_1A, LOW);
    digitalWrite(Motor_1B, LOW);
    digitalWrite(Motor_2B,LOW);
    digitalWrite(Motor_2A, LOW);
}

// Method to aggressive and quickly stop the method 
// I understand the logic for this could have worked for the stopMotor(), but I believe it's best to have this for edge cases
void brakeMotor(){
     digitalWrite(Motor_1A, HIGH);
    digitalWrite(Motor_1B, HIGH);
    digitalWrite(Motor_2B,HIGH);
    digitalWrite(Motor_2A,HIGH );
}

// Method for when the robot is stuck in a corner and can't really turn left or right
// This method doesn't rely on which motor is right or left
// Essentially you want 1 motor moving forward and another moving backwards
// I chose motor 1 to move forward, and motor 2 to move backward.
void uTurn(){
    digitalWrite(Motor_1A, HIGH);
    digitalWrite(Motor_1B, LOW);
    digitalWrite(Motor_2B,HIGH);
    digitalWrite(Motor_2A, LOW);
}