#include <iostream>
#include "actuatorcontroller.h"
#include <thread>
#include <chrono>

using namespace std;

int main(int argc, char *argv[]) {
  ActuatorController *pController = ActuatorController::initController();
  Actuator::ErrorsDefine ec;

  std::vector<ActuatorController::UnifiedID> uIDArray =
      pController->lookupActuators(ec);

  if (uIDArray.size() > 0) {
    for (auto actuator : uIDArray) {
      cout << "Actuator found with ID: " << (int)actuator.actuatorID
           << " and IP address: " << actuator.ipAddress << endl;

      pController->enableActuator(actuator.actuatorID, actuator.ipAddress);
      cout << "Actuator enabled." << endl;

      pController->activateActuatorMode(actuator.actuatorID,
                                        Actuator::Mode_Profile_Pos);
      cout << "Profile position mode activated." << endl;

      pController->setPosition(actuator.actuatorID, 0.0);
      cout << "Actuator moved to 0 position." << endl;
      cout << "Waiting for 5 seconds..." << endl;
      std::this_thread::sleep_for(std::chrono::seconds(5));

      pController->setPosition(actuator.actuatorID, 5.0);
      cout << "Actuator moved to 5 position." << endl;
      cout << "Waiting for 5 seconds..." << endl;
      std::this_thread::sleep_for(std::chrono::seconds(5));

      pController->setPosition(actuator.actuatorID, 0.0);
      cout << "Actuator moved to 0 position." << endl;
      cout << "Waiting for 5 seconds..." << endl;
      std::this_thread::sleep_for(std::chrono::seconds(5));

      pController->setPosition(actuator.actuatorID, -5.0);
      cout << "Actuator moved to -5 position." << endl;
      cout << "Waiting for 5 seconds..." << endl;
      std::this_thread::sleep_for(std::chrono::seconds(5));

      pController->setPosition(actuator.actuatorID, 0.0);
      cout << "Actuator moved to 0 position." << endl;
      cout << "Waiting for 5 seconds..." << endl;
      std::this_thread::sleep_for(std::chrono::seconds(5));

      pController->setPosition(actuator.actuatorID, -10.0);
      cout << "Actuator moved to -10 position." << endl;
      cout << "Waiting for 5 seconds..." << endl;
      std::this_thread::sleep_for(std::chrono::seconds(5));

      pController->disableActuator(actuator.actuatorID, actuator.ipAddress);
      cout << "Actuator disabled." << endl;
      cout << "Waiting for 5 seconds..." << endl;
      std::this_thread::sleep_for(std::chrono::seconds(5));
    }
  }
}