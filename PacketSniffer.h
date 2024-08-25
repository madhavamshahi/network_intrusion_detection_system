#ifndef PACKET_SNIFFER_H
#define PACKET_SNIFFER_H

#include <pcap.h>
#include <string>
#include "RuleEngine.h"

class PacketSniffer
{
public:
    PacketSniffer(const std::string &device);
    void startSniffing(RuleEngine &ruleEngine);

private:
    std::string device;
    pcap_t *handle;
    static void packetHandler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
};

#endif
