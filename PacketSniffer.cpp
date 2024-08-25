#include "PacketSniffer.h"
#include "RuleEngine.h"
#include <iostream>
#include <cstring>

PacketSniffer::PacketSniffer(const std::string &device) : device(device)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    handle = pcap_open_live(device.c_str(), BUFSIZ, 1, 1000, errbuf);
    if (handle == nullptr)
    {
        std::cerr << "Couldn't open device " << device << ": " << errbuf << std::endl;
        exit(1);
    }
}

void PacketSniffer::startSniffing(RuleEngine &ruleEngine)
{

    pcap_loop(handle, 0, packetHandler, reinterpret_cast<u_char *>(&ruleEngine));
}

void PacketSniffer::packetHandler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{

    const struct ether_header *eth_header;
    eth_header = (struct ether_header *)packet;

    std::cout << "Packet captured: length=" << header->len << std::endl;

    RuleEngine *ruleEngine = reinterpret_cast<RuleEngine *>(args);

    ruleEngine->matchRules(packet, header->len);
}
