#include <iostream>
#include "actuatorcontroller.h"
#include <thread>
#include <signal.h>
#include <string.h>
#include <chrono>
using namespace std;

int main(int argc, char *argv[])
{
    // Initialize the controller
    ActuatorController * pController = ActuatorController::initController();
    Actuator::ErrorsDefine ec;
    
    // Find the connected actuators and return the UnifiedID of all actuators found.
    std::vector<ActuatorController::UnifiedID> uIDArray = pController->lookupActuators(ec);
    
    // Check if at least two actuators are found
    if(uIDArray.size() >= 2)
    {
        // Get the first and second actuators
        ActuatorController::UnifiedID actuator1 = uIDArray.at(0);
        ActuatorController::UnifiedID actuator2 = uIDArray.at(1);
        
        // Enable both actuators
        pController->enableActuator(actuator1.actuatorID, actuator1.ipAddress);
        pController->enableActuator(actuator2.actuatorID, actuator2.ipAddress);
        
        // Activate profile position mode for both actuators
        pController->activateActuatorMode(actuator1.actuatorID, Actuator::Mode_Profile_Pos);
        pController->activateActuatorMode(actuator2.actuatorID, Actuator::Mode_Profile_Pos);
        
        // Set positions for both actuators
        cout << "Setting actuator 1 position to 10 revolutions and actuator 2 to 5 revolutions." << endl;
        pController->setPosition(actuator1.actuatorID, 10);
        pController->setPosition(actuator2.actuatorID, 5);
        std::this_thread::sleep_for(std::chrono::seconds(4));
        
        cout << "Setting actuator 1 position to -10 revolutions and actuator 2 to -5 revolutions." << endl;
        pController->setPosition(actuator1.actuatorID, -10);
        pController->setPosition(actuator2.actuatorID, -5);
        std::this_thread::sleep_for(std::chrono::seconds(3));
        
        // Disable all connected actuators
        pController->disableAllActuators();
        // Ensure that all actuators have been closed
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    else
    {
        cout << "Not enough actuators found. Connected error code:" << hex << ec << endl;
    }
    
    return 0;
}
