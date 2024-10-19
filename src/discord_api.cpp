#include "F100cBot.hpp"
#include <cstdlib>
#include <curl/curl.h>
#include <curl/easy.h>
#include <fstream>
#include <iostream>
#include <jansson.h>
#include <sstream>
#include <string>
namespace Diplomacy {
static size_t callback_function(char* ptr, size_t, size_t nmemb, void* userdata) {
  std::string& out = *reinterpret_cast<std::string*>(userdata);
  out.append(ptr, nmemb);
  return nmemb;
}
Discord_API::Discord_API() {
  if (!curl) exit(-1);
  headers = curl_slist_append(headers, "Content-Type: application/json");
  headers = curl_slist_append(headers, "Accept: application/json");
  headers = curl_slist_append(headers, "Authorization: Bot " DISCORD_TOKEN);
  headers = curl_slist_append(headers, "User-Agent: DiscordBot (https://github.com/F100cTomas/discord-diplomacy, 1.0)");
}
Discord_API::~Discord_API() {
  curl_slist_free_all(headers);
  curl_easy_cleanup(curl);
}
json_t* Discord_API::get_request(const char* url) {
  std::string discord_url = DISCORD_API_URL;
  discord_url.append(url);
  curl_easy_setopt(curl, CURLOPT_URL, discord_url.c_str());
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  std::string jsonString{};
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, reinterpret_cast<void*>(&jsonString));
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback_function);
  if (curl_easy_perform(curl) != CURLE_OK) exit(-1);
  json_error_t error;
  json_t*      out = json_loads(jsonString.c_str(), static_cast<size_t>(0), &error);
  if (out == nullptr) exit(-1);
  return out;
}
void Discord_API::post_request(const char* url) {
  std::string discord_url = DISCORD_API_URL;
  discord_url.append(url);
  curl_easy_setopt(curl, CURLOPT_URL, discord_url.c_str());
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  curl_easy_setopt(curl, CURLOPT_POST, 1L);
  std::ifstream     file{"./build/data.json"};
  std::stringstream ss{};
  ss << file.rdbuf();
  std::string json{ss.str()};
  std::cout << '\n' << json << "<- JSON";
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json.c_str());
  curl_easy_perform(curl);
  std::cout << '\n' << discord_url << '\n';
}
} // namespace Diplomacy
