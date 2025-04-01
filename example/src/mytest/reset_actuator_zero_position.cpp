#include <iostream>
#include "actuatorcontroller.h"
#include <thread>
#include <chrono>
using namespace std;

// 01 02 03 04 05 06 07
// 08 09 10 11 12 13 14
// 15 16 17 18 19 20 21
// 22 23 24 25 26 27 28

int main(int argc, char *argv[])
{
    ActuatorController *pController = ActuatorController::initController();
    Actuator::ErrorsDefine ec;

    std::vector<ActuatorController::UnifiedID> uIDArray = pController->lookupActuators(ec);

    if (uIDArray.size() > 0)
    {
        for (auto actuator : uIDArray)
        {
            cout << "Actuator found with ID: " << (int)actuator.actuatorID << " and IP address: " << actuator.ipAddress << endl;
            if (actuator.actuatorID != 27)
            {
                continue;
            }
            pController->enableActuator(actuator.actuatorID, actuator.ipAddress);
            cout << "Actuator enabled." << endl;

            pController->activateActuatorMode(actuator.actuatorID, Actuator::Mode_Profile_Pos);
            cout << "Actuator mode set to Profile Position." << endl;

            double currentPosition = pController->getPosition(actuator.actuatorID, true, actuator.ipAddress);
            cout << "Current position of actuator " << (int)actuator.actuatorID << " is " << currentPosition << " revolutions." << endl;

            cout << "Waiting for 5 seconds..." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));

            pController->activateActuatorMode(actuator.actuatorID, Actuator::Mode_Homing);
            cout << "Actuator mode set to Homing." << endl;
            pController->setHomingPosition(actuator.actuatorID, currentPosition, actuator.ipAddress);
            cout << "New zero position set for actuator " << (int)actuator.actuatorID << " at " << currentPosition << " revolutions." << endl;

            pController->saveAllParams(actuator.actuatorID);
            cout << "Zero position saved successfully." << endl;

            pController->activateActuatorMode(actuator.actuatorID, Actuator::Mode_Profile_Pos);
            pController->setPosition(actuator.actuatorID, 0.0);
            cout << "Actuator moved to new zero position." << endl;
            cout << "Waiting for 3 seconds..." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));

            pController->disableActuator(actuator.actuatorID, actuator.ipAddress);
            cout << "Actuator disabled." << endl;
        }
    }
    else
    {
        cout << "No actuators found. Connected error code: " << hex << ec << endl;
    }

    return 0;
}
