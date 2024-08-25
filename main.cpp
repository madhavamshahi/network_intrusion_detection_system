#include "PacketSniffer.h"
#include "RuleEngine.h"
#include <iostream>

int main()
{
    std::string device = "en0";
    PacketSniffer sniffer(device);
    RuleEngine ruleEngine;

    std::cout << "Starting packet capture on device: " << device << std::endl;

    sniffer.startSniffing(ruleEngine);

    return 0;
}
