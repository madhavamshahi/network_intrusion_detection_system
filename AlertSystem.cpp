#include "AlertSystem.h"
#include <iostream>
#include <fstream>

void AlertSystem::logAlert(const std::string &alert)
{
    std::ofstream logFile("alerts.log", std::ios::app);
    if (logFile.is_open())
    {
        logFile << alert << std::endl;
        logFile.close();
    }
    std::cout << "Alert: " << alert << std::endl;
}
