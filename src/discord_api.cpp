#include "discord-diplomacy.hpp"
#include <cstdlib>
#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>
#include <string>
namespace Diplomacy {
Discord_API::Discord_API() {
  if (!curl) exit(-1);
  headers = curl_slist_append(headers, "Content-Type: application/json");
  headers = curl_slist_append(headers, "Authorization: Bot " DISCORD_TOKEN);
  headers = curl_slist_append(headers, "User-Agent: DiscordBot (https://github.com/F100cTomas/discord-diplomacy, 1.0)");
}
Discord_API::~Discord_API() {
  curl_slist_free_all(headers);
  curl_easy_cleanup(curl);
}
void Discord_API::make_request(const char* url) {
  std::string discord_url = DISCORD_API_URL;
  discord_url.append(url);
  curl_easy_setopt(curl, CURLOPT_URL, discord_url.c_str());
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  curl_easy_perform(curl);
  std::cout << '\n' << discord_url;
}
} // namespace Diplomacy
