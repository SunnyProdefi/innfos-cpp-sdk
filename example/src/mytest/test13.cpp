#include <iostream>
#include "actuatorcontroller.h"
#include <thread>
#include <chrono>
#include <math.h>

using namespace std;

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
            if (actuator.actuatorID != 13)
            {
                continue;
            }
            pController->enableActuator(actuator.actuatorID, actuator.ipAddress);
            cout << "Actuator enabled." << endl;

            pController->activateActuatorMode(actuator.actuatorID, Actuator::Mode_Profile_Pos);
            cout << "Profile position mode activated." << endl;

            pController->setPosition(actuator.actuatorID, 0.0);
            cout << "Actuator moved to zero position." << endl;
            cout << "Waiting for 5 seconds..." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));

            pController->setPosition(actuator.actuatorID, 36);
            cout << "Actuator moved to -0.03391996 position." << endl;
            cout << "Waiting for 5 seconds..." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));

            pController->setPosition(actuator.actuatorID, -36);
            cout << "Actuator moved to 3.108997 position." << endl;
            cout << "Waiting for 5 seconds..." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));

            pController->disableActuator(actuator.actuatorID, actuator.ipAddress);
            cout << "Actuator disabled." << endl;
            cout << "Waiting for 5 seconds..." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    }
}