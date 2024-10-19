#ifndef F100CBOT_HPP
#define F100CBOT_HPP
#include "secrets.hpp"
#include <curl/curl.h>
#include <curl/easy.h>
#include <jansson.h>
#include <libwebsockets.h>
namespace Diplomacy {
constexpr const char* DISCORD_API_URL = "https://discord.com/api/v10";
class Discord_API {
  CURL*       curl    = curl_easy_init();
  curl_slist* headers = nullptr;
public:
  Discord_API();
  ~Discord_API();
public:
  json_t* get_request(const char* url);
  void post_request(const char* url);
};
} // namespace Diplomacy
#endif
