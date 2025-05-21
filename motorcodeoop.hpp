/*Author: Gerald Onyedika  */
 /*Project: Autonomous Vaccum Robot */


 // Including the guard
 #ifndef MOTORCODEOOP_HPP
#define MOTORCODEOOP_HPP

#include <Arduino.h>

namespace Vacuum {

class Motor {

    private:
    // Private variables in the .cpp file
    int pin1A, pin1B, pin2A, pin2B;

    
public:
    //  Motor's Constructor
    Motor(int pin1A, int pin1B, int pin2A, int pin2B);

    // Public getters
    void getFwd();
    void getBwd();
    void getRight();
    void getLeft();
    void getStop();
    void getBrake();
    void getUTurn();

private:
// Private logic methods in the .cpp file
    void setupPins();
    void driveFwd();
    void driveBwd();
    void turnRight();
    void turnLeft();
    void stopMotor();
    void brakeMotor();
    void uTurn();

};

} // namespace Vacuum

#endif
