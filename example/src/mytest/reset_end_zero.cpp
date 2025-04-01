#include <iostream>
#include "actuatorcontroller.h"
#include <thread>
#include <chrono>

// 01 02 03 04 05 06 07
// 08 09 10 11 12 13 14
// 15 16 17 18 19 20 21
// 22 23 24 25 26 27 28

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
            if ((int)actuator.actuatorID == 06)
            {
                // Retrieve actuator properties
                const double actuatorPosition = pController->getPosition(actuator.actuatorID, false, actuator.ipAddress);
                std::cout << "电机位置: " << actuatorPosition << " 转" << std::endl;

                // Enable and disable the actuator
                pController->enableActuator(actuator.actuatorID, actuator.ipAddress);
                cout << "Actuator enabled." << endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                pController->disableActuator(actuator.actuatorID, actuator.ipAddress);
                cout << "Actuator disabled." << endl;
            }
            else
            {
                continue;
            }
        }
    }
}