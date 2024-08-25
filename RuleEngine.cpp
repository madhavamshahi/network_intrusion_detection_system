#include "RuleEngine.h"
#include <iostream>
#include <cstring>

RuleEngine::RuleEngine()
{
    // Example rule, can add more and make it more refined
    addRule("malicious_payload");
}

void RuleEngine::addRule(const std::string &rule)
{
    rules.push_back(rule);
}

bool RuleEngine::matchRules(const u_char *packet, int length)
{
    for (const auto &rule : rules)
    {
        if (std::search(packet, packet + length, rule.begin(), rule.end()) != packet + length)
        {
            std::cout << "Suspicious activity detected!" << std::endl;
            return true;
        }
    }
    return false;
}
