#include <iostream>

#include "Client.hpp"
#include "App.hpp"

using namespace std;
using namespace vk;

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    cout << "No token provided" << endl
         << "Usage:" << endl
         << "bin <token>" << endl;
    return 1;
  }

  string token = string(argv[1]);

  Client *client = new Client(token);
  App *app = new App(client);

  app->handle();

  return 0;
}
