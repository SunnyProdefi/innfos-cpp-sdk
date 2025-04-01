#include <iostream>
#include "actuatorcontroller.h"
#include <thread>
#include <signal.h>
#include <string.h>
#include <chrono>
using namespace std;

int main(int argc, char *argv[]) {
  // 初始化控制器
  ActuatorController *pController = ActuatorController::initController();
  Actuator::ErrorsDefine ec;

  // 查找连接的执行器并返回所有执行器的 UnifiedID
  std::vector<ActuatorController::UnifiedID> uIDArray =
      pController->lookupActuators(ec);

  // 检查是否找到至少两个执行器
  if (uIDArray.size() >= 2) {
    // 获取第一个和第二个执行器
    ActuatorController::UnifiedID actuator1 = uIDArray.at(0);
    ActuatorController::UnifiedID actuator2 = uIDArray.at(1);

    // 使能两个执行器
    pController->enableActuator(actuator1.actuatorID, actuator1.ipAddress);
    pController->enableActuator(actuator2.actuatorID, actuator2.ipAddress);

    // 激活两个执行器的 Profile Position 模式
    pController->activateActuatorMode(actuator1.actuatorID,
                                      Actuator::Mode_Profile_Pos);
    pController->activateActuatorMode(actuator2.actuatorID,
                                      Actuator::Mode_Profile_Pos);

    // 设置两个执行器的位置
    cout << "将执行器1的位置设置为0转,执行器2的位置设置为0转。" << endl;
    pController->setPosition(actuator1.actuatorID, 0);
    pController->setPosition(actuator2.actuatorID, 0);
    std::this_thread::sleep_for(std::chrono::seconds(5));

    cout << "将执行器1的位置设置为101转,执行器2的位置设置为101转。" << endl;
    pController->setPosition(actuator1.actuatorID, 101);
    pController->setPosition(actuator2.actuatorID, 101);
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // 进一步移动执行器
    cout << "将执行器1的位置设置为101转,执行器2的位置设置为101转。" << endl;
    pController->setPosition(actuator1.actuatorID, 101);
    pController->setPosition(actuator2.actuatorID, 101);
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // cout << "将执行器1的位置设置为202转,执行器2的位置设置为202转。" << endl;
    // pController->setPosition(actuator1.actuatorID, 202);
    // pController->setPosition(actuator2.actuatorID, 202);
    // std::this_thread::sleep_for(std::chrono::seconds(5));

    // 复位执行器位置
    cout << "将执行器1的位置设置为0转,执行器2的位置设置为0转。" << endl;
    pController->setPosition(actuator1.actuatorID, 0);
    pController->setPosition(actuator2.actuatorID, 0);
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // 禁用所有连接的执行器
    pController->disableAllActuators();
    // 确保所有执行器已关闭
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  } else {
    cout << "未找到足够的执行器。连接错误代码：" << hex << ec << endl;
  }

  return 0;
}
