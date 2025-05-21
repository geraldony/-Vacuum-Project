/* Author: Gerald Onyedika */
/* Project: Autonomous Vaccum Robot */

// Including the motorcode.h file  and arduino functions
#include "motorcodeoop.hpp" 
#include <Arduino.h>

// Using a name space  to avoid potential confusions
namespace Vacuum{
    
    class Motor{
        
    // some important private variables
    private:
        int pin1A, pin1B, pin2A, pin2B;
    
       
        public:

        // Constructor for the motor that takes in GPIO pins of each of the motors and sets their mode
        Motor(int pin1A, int pin1B, int pin2A, int pin2B ){
            this->pin1A = pin1A;
            this->pin1B = pin1B;
            this->pin2A = pin2A;
            this->pin2B = pin2B;
            setupPins();
        }
        // My public getters. It's not necessary but this is how I was taught OOP with Java so I follow this
        
        // getter for moving forward
        void getFwd(){
            driveFwd();
         }

         // getter for moving backward
         void getBwd(){
            driveBwd();
         }

         // getter for turning right
         void getRight(){
            turnRight();
         }

         // getter for turning left
         void getLeft(){
            turnLeft();
         }

        // getter for braking
         void getBrake(){
            brakeMotor();
         }

        //getter for gently stopping 
         void getStop(){
            stopMotor();
         }

        // getter for U-turn
         void getUTurn(){
            uTurn();
         }

    private:
    
    // method to setup the pinType  of the pins. Motors are always output pins.
     void setupPins(){
        pinMode(pin1A, OUTPUT);
        pinMode(pin1B, OUTPUT);
        pinMode(pin2A, OUTPUT);
        pinMode(pin2B, OUTPUT);
     };

    // Method to drive forward(make sure on the hardware whatever pin1A and pin2A are connected to the positive rail unless the wheel goes reverse)
void driveFwd(){
    digitalWrite(pin1A, HIGH);
    digitalWrite(pin1B, LOW);
    digitalWrite(pin2B,LOW);
    digitalWrite(pin2A, HIGH);
}

// Method to move backwards(reverse the polarity of the fwd pins)
void driveBwd(){
 digitalWrite(pin1A, LOW);
    digitalWrite(pin1B,HIGH);
    digitalWrite(pin2B,HIGH);
    digitalWrite(pin2A, LOW);
}

/* Method for turning right 
*Motor 2 stops
*Motor 1 keeps spinning 
*Motor 1 is shorted/both set to high to account for edge cases where a sharp right is needed
*/
void turnRight(){
    digitalWrite(pin1A, HIGH);
    digitalWrite(pin1B, HIGH);
    digitalWrite(pin2B,HIGH);
    digitalWrite(pin2A, LOW);
}

/* Method for turning left 
*Motor 1 stops
*Motor 2 keeps spinning 
*Motor 2 is shorted/both set to high to account for edge cases where a sharp left is needed
*/
void turnLeft(){
     digitalWrite(pin1A, HIGH);
    digitalWrite(pin1B, LOW);
    digitalWrite(pin2B,HIGH);
    digitalWrite(pin2A, HIGH);

}

//Method to stop the motors gently 
void stopMotor(){
     digitalWrite(pin1A, LOW);
    digitalWrite(pin1B, LOW);
    digitalWrite(pin2B,LOW);
    digitalWrite(pin2A, LOW);
}

// Method to aggressive and quickly stop the method 
// I understand the logic for this could have worked for the stopMotor(), but I believe it's best to have this for edge cases
void brakeMotor(){
     digitalWrite(pin1A, HIGH);
    digitalWrite(pin1B, HIGH);
    digitalWrite(pin2B,HIGH);
    digitalWrite(pin2A,HIGH );
}

// Method for when the robot is stuck in a corner and can't really turn left or right
// This method doesn't rely on which motor is right or left
// Essentially you want 1 motor moving forward and another moving backwards
// I chose motor 1 to move forward, and motor 2 to move backward.
void uTurn(){
    digitalWrite(pin1A, HIGH);
    digitalWrite(pin1B, LOW);
    digitalWrite(pin2B,HIGH);
    digitalWrite(pin2A, LOW);
}

};
}
