#include <iomanip>
#include <iostream>
#include <string>
#include <curl/curl.h>

#include "Client.hpp"
#include "../vendor/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

namespace vk
{
static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    ((string *)userp)->append((char *)contents, realsize);
    return realsize;
}

Client::Client(const string t)
{
    token = t;
    version = new string("5.80");
    base_url = new string("https://api.vk.com/method/");
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

Client::~Client()
{
    curl_global_cleanup();
}

json Client::account_getCounters()
{
    json params;
    return request("account.getCounters"s, params);
}

json Client::account_getCounters(json params)
{
    return request("account.getCounters"s, params);
}

json Client::account_setOnline()
{
    json params;
    return request("account.setOnline"s, params);
}

json Client::account_setOnline(json params)
{
    return request("account.setOnline"s, params);
}

json Client::account_setOffline()
{
    json params;
    return request("account.setOffline"s, params);
}

json Client::messages_getConversations(json params)
{
    return request("messages.getConversations"s, params);
}

json Client::request(const string method, json params)
{
    readBuffer.clear();

    CURL *curl = curl_easy_init();

    if (curl)
    {
        CURLcode res;

        string *url = new string(*base_url);
        url->append(method);
        url->append("?v="s);
        url->append(*version);
        url->append("&access_token="s);
        url->append(token);

        string data = params.dump();

        curl_easy_setopt(curl, CURLOPT_URL, url->c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)data.size());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            cerr << curl_easy_strerror(res) << endl;
            throw new runtime_error(curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);

        json j = json::parse(readBuffer);

        if (json vkError = j["error"]; !vkError.is_null())
        {
            cerr << setw(4) << vkError << endl;
            throw new runtime_error("VK error");
        }

        return j["response"];
    }

    throw new runtime_error("curl_easy_init() failed");
}
} // namespace vk
