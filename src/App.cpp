#include <iostream>

#include "App.hpp"
#include "../vendor/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

App::App(Client *vkClient)
{
    client = vkClient;
}

void App::handle()
{
    counters();
}

void App::counters()
{
    json counters = client->account_getCounters();

    if (json value = counters["friends"]; value.is_number_integer())
    {
        cout << "Friends: " << value.dump() << endl;
    }

    if (json value = counters["friends_suggestions"]; value.is_number_integer())
    {
        cout << "Friends suggestions: " << value.dump() << endl;
    }

    if (json value = counters["messages"]; value.is_number_integer())
    {
        cout << "Messages: " << value.dump() << endl;
    }

    if (json value = counters["photos"]; value.is_number_integer())
    {
        cout << "Photos: " << value.dump() << endl;
    }

    if (json value = counters["videos"]; value.is_number_integer())
    {
        cout << "Videos: " << value.dump() << endl;
    }

    if (json value = counters["gifts"]; value.is_number_integer())
    {
        cout << "Gifts: " << value.dump() << endl;
    }

    if (json value = counters["events"]; value.is_number_integer())
    {
        cout << "Events: " << value.dump() << endl;
    }

    if (json value = counters["groups"]; value.is_number_integer())
    {
        cout << "Groups: " << value.dump() << endl;
    }

    if (json value = counters["notifications"]; value.is_number_integer())
    {
        cout << "Notifications: " << value.dump() << endl;
    }

    if (json value = counters["notifications"]; value.is_number_integer())
    {
        cout << "Sdk: " << value.dump() << endl;
    }

    if (json value = counters["app_requests"]; value.is_number_integer())
    {
        cout << "App requests: " << value.dump() << endl;
    }

    if (json value = counters["friends_recommendations"]; value.is_number_integer())
    {
        cout << "Friends recommendations: " << value.dump() << endl;
    }
}

void App::messages()
{
    json params;
    json messages = client->messages_getConversations(params);

    cout << messages.dump() << endl;
}
