#include <iostream>
#include "actuatorcontroller.h"
#include <thread>
#include <vector>
#include <string>

int main() {
  // Initialize the controller
  ActuatorController* pController = ActuatorController::initController();
  if (!pController) {
    std::cerr << "Failed to initialize the Actuator Controller." << std::endl;
    return -1;
  }

  Actuator::ErrorsDefine ec;
  // Find connected actuators
  const std::vector<ActuatorController::UnifiedID> uIDArray =
      pController->lookupActuators(ec);
  if (uIDArray.empty()) {
    std::cerr << "未找到足够的执行器。连接错误代码: " << std::hex << ec
              << std::endl;
    return -1;
  }

  for (const auto& actuator : uIDArray) {
    const uint8_t id = actuator.actuatorID;
    const std::string& ipAddress = actuator.ipAddress;

    std::cout << "电机ID: " << static_cast<int>(id) << " IP地址: " << ipAddress
              << std::endl;

    // Enable actuator
    if (!pController->enableActuator(id, ipAddress)) {
      std::cerr << "电机使能失败: ID " << static_cast<int>(id) << std::endl;
      continue;
    }
    std::cout << "电机使能成功" << std::endl;

    // Activate profile position mode
    pController->activateActuatorMode(id, Actuator::Mode_Profile_Pos);
    std::cout << "电机激活成功,模式: 位置模式" << std::endl;

    pController->switchAutoRefresh(id, true, ipAddress);
    pController->setAutoRefreshInterval(id, 5, ipAddress);
    std::cout << "自动刷新已开启" << std::endl;
    std::cout << "自动刷新时间间隔设置为5ms" << std::endl;

    std::cout << "sleep 3s" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // Retrieve actuator properties
    const double actuatorPosition =
        pController->getPosition(id, false, ipAddress);
    std::cout << "电机位置: " << actuatorPosition << " 转" << std::endl;

    // Retrieve and print PID parameters
    const double actuatorPositionKp =
        pController->getPositionKp(id, false, ipAddress);
    const double actuatorPositionKi =
        pController->getPositionKi(id, false, ipAddress);
    const double actuatorPositionKd =
        pController->getPositionKd(id, false, ipAddress);
    std::cout << "电机位置环参数\n"
              << "位置环比例: " << actuatorPositionKp << "\n"
              << "位置环积分: " << actuatorPositionKi << "\n"
              << "位置环微分: " << actuatorPositionKd << std::endl;

    // Retrieve and print output limits
    const double actuatorPositionUmax =
        pController->getPositionUmax(id, false, ipAddress);
    const double actuatorPositionUmin =
        pController->getPositionUmin(id, false, ipAddress);
    std::cout << "电机位置环输出限幅\n"
              << "位置环最大输出限幅: " << actuatorPositionUmax << "\n"
              << "位置环最小输出限幅: " << actuatorPositionUmin << std::endl;

    // Retrieve additional properties
    const double positionOffset =
        pController->getPositionOffset(id, false, ipAddress);
    std::cout << "位置环的限位偏移: " << positionOffset << " 单位" << std::endl;

    const double maxPosition =
        pController->getMaximumPosition(id, false, ipAddress);
    const double minPosition =
        pController->getMinimumPosition(id, false, ipAddress);
    std::cout << "位置环的最大限位: " << maxPosition << " 单位\n"
              << "位置环的最小限位: " << minPosition << " 单位" << std::endl;

    const double cutoffFrequency =
        pController->getPositionCutoffFrequency(id, false, ipAddress);
    std::cout << "位置环低通滤波频率: " << cutoffFrequency << " Hz"
              << std::endl;

    const double acceleration =
        pController->getProfilePositionAcceleration(id, false, ipAddress);
    const double deceleration =
        pController->getProfilePositionDeceleration(id, false, ipAddress);
    const double maxVelocity =
        pController->getProfilePositionMaxVelocity(id, false, ipAddress);
    std::cout << "Profile Position模式的加速度: " << acceleration
              << " 单位/s^2\n"
              << "Profile Position模式的减速度: " << deceleration
              << " 单位/s^2\n"
              << "Profile Position模式的最大速度: " << maxVelocity << " 单位/s"
              << std::endl;

    const Actuator::ActuatorMode mode =
        pController->getActuatorMode(id, ipAddress);
    std::cout << "当前执行器模式: " << static_cast<int>(mode) << std::endl;

    // Retrieve and print other information
    const double actuatorVoltage = pController->getVoltage(id, true, ipAddress);
    const double actuatorLockEnergy =
        pController->getLockEnergy(id, true, ipAddress);
    const double actuatorMotorTemperature =
        pController->getMotorTemperature(id, true, ipAddress);
    const double actuatorInverterTemperature =
        pController->getInverterTemperature(id, true, ipAddress);
    std::cout << "电机电压: " << actuatorVoltage << " V\n"
              << "电机堵转能量: " << actuatorLockEnergy << " J\n"
              << "电机温度: " << actuatorMotorTemperature << " ℃\n"
              << "逆变器温度: " << actuatorInverterTemperature << " ℃"
              << std::endl;

    // Disable actuator after use
    pController->disableActuator(id, ipAddress);
  }

  return 0;
}
