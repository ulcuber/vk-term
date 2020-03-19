#pragma once

#include <string>

#include "../vendor/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

namespace vk
{
class Client
{
public:
    Client(const string);
    ~Client();

    json account_getCounters();
    json account_getCounters(json params);
    json account_setOnline();
    json account_setOnline(json params);
    json account_setOffline();

    json messages_getConversations(json params);

protected:
    string *version;
    string *base_url;

    string token;
    string readBuffer;

    json request(const string, json params);
};
} // namespace vk
