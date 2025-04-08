#include <iostream>
#include "actuatorcontroller.h"
#include <thread>
#include <vector>
#include <string>
#include <math.h>

// 减速比
#define MOTOR_REDUCTION_RATIO_1 101.0
#define MOTOR_REDUCTION_RATIO_2 36.0

// 01 02 03 04 05 06 07
// 08 09 10 11 12 13 14
// 15 16 17 18 19 20 21
// 22 23 24 25 26 27 28

int main()
{
    // Initialize the controller
    ActuatorController* pController = ActuatorController::initController();
    if (!pController)
    {
        std::cerr << "Failed to initialize the Actuator Controller." << std::endl;
        return -1;
    }

    Actuator::ErrorsDefine ec;
    // Find connected actuators
    const std::vector<ActuatorController::UnifiedID> uIDArray = pController->lookupActuators(ec);
    if (uIDArray.empty())
    {
        std::cerr << "未找到足够的执行器。连接错误代码: " << std::hex << ec << std::endl;
        return -1;
    }

    for (const auto& actuator : uIDArray)
    {
        const uint8_t id = actuator.actuatorID;
        const std::string& ipAddress = actuator.ipAddress;

        std::cout << "电机ID: " << static_cast<int>(id) << " IP地址: " << ipAddress << std::endl;

        // Enable actuator
        if (!pController->enableActuator(id, ipAddress))
        {
            std::cerr << "电机使能失败: ID " << static_cast<int>(id) << std::endl;
            continue;
        }
        std::cout << "电机使能成功" << std::endl;

        // Activate profile position mode
        pController->activateActuatorMode(id, Actuator::Mode_Profile_Pos);
        std::cout << "电机激活成功,模式: 位置模式" << std::endl;

        // Retrieve actuator properties
        const double actuatorPosition = pController->getPosition(id, false, ipAddress);
        std::cout << "电机位置: " << actuatorPosition << " 转(输入端)" << std::endl;

        const double ratio = (id % 7 < 4) ? MOTOR_REDUCTION_RATIO_1 : MOTOR_REDUCTION_RATIO_2;
        std::cout << "电机减速比: " << ratio << std::endl;

        const double actuatorPositionReal = actuatorPosition / ratio;
        std::cout << "电机位置: " << actuatorPositionReal << " 转(输出端)" << std::endl;
        std::cout << "电机位置: " << actuatorPositionReal * 2 * M_PI << " 弧度(输出端)" << std::endl;
        std::cout << "电机位置: " << actuatorPositionReal * 360 << " 度(输出端)" << std::endl;

        // Disable actuator after use
        pController->disableActuator(id, ipAddress);
    }

    return 0;
}
