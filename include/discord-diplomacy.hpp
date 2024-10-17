#ifndef DISCORD_DIPLOMACY_HPP
#define DISCORD_DIPLOMACY_HPP
#include "secrets.hpp"
#include <curl/curl.h>
#include <curl/easy.h>
namespace Diplomacy {
constexpr const char* DISCORD_API_URL = "https://discord.com/api/v10";
class Discord_API {
  CURL*       curl    = curl_easy_init();
  curl_slist* headers = nullptr;
public:
  Discord_API();
  ~Discord_API();
public:
  void make_request(const char* url);
};
} // namespace Diplomacy
#endif
