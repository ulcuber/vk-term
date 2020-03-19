#pragma once
#include "Client.hpp"
#include "../vendor/nlohmann/json.hpp"

using namespace std;
using namespace vk;

class App
{
public:
    App(Client *vkClient);
    void handle();

protected:
    Client *client;

    void counters();
    void messages();
};
