//Inspired by Quxbot, developed by Viderizer and Tyler Allen
#include <iostream>
#include <cstdio>
#include "ircbot.h"

std::vector<std::string> Respond(const std::string& s);

int main(int argc, char *[])
{
  const std::string bot_name = "violet";
  const std::string server_name = "irc.zeronode.net";
  const std::string channel_name = "#Hive6";
  const int port = 6667; //No SSH
  //const int port = 6697; //With SSH, but then the IRC bot does not work?

  //my_bot will be alive the entire program
  const IrcBot my_bot(
    bot_name,
    channel_name,
    port,
    server_name,
    Respond,
    argc > 1
  );
}

std::vector<std::string> Respond(const std::string& s)
{
  //Display the raw message to respond to
  std::cout << s << '\n';

  //Generate a response
  std::vector<std::string> v;

  if (s.find("JOIN") != std::string::npos)
  {
    //Welcome message
    if (s.find(":richel") != std::string::npos
     || s.find(":Bilderbikkel") != std::string::npos
     || s.find(":bilderbikkel") != std::string::npos
     || s.find(":assert") != std::string::npos
     )
    {
      v.push_back("Welcome master!");
    }
  }
  if (s.find("ain't that so?") != std::string::npos)
  {
    v.push_back("Yes, it is exactly like that!");
  }
  return v;
}
