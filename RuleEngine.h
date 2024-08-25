#ifndef RULE_ENGINE_H
#define RULE_ENGINE_H

#include <string>
#include <vector>
#include <pcap.h>

class RuleEngine
{
public:
    RuleEngine();
    bool matchRules(const u_char *packet, int length);
    void addRule(const std::string &rule);

private:
    std::vector<std::string> rules;
};

#endif
