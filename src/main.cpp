#include "discord-diplomacy.hpp"
#include <curl/curl.h>
#include <jansson.h>
int main() {
  Diplomacy::Discord_API api{};
  api.make_request("/users/@me");
  return 0;
}
/*
// Replace with your actual bot token and channel ID
#define CHANNEL_ID "1296193144161046561"
// Callback function for handling the response data
size_t write_callback(void* ptr, size_t size, size_t nmemb, void* stream) {
  strcat((char*)stream, (char*)ptr);
  return size * nmemb;
}
// Function to send a message to a specific channel
void send_discord_message(const char* message) {
  CURL*    curl;
  CURLcode res;
  char     url[512], data[1024], response[2048] = {0};
  // Prepare the Discord API URL for sending a message
  snprintf(url, sizeof(url), "https://discord.com/api/v9/channels/%s/messages", CHANNEL_ID);
  // Prepare the JSON payload
  snprintf(data, sizeof(data), "{\"content\":\"%s\"}", message);
  // Initialize curl
  curl = curl_easy_init();
  if (curl) {
    struct curl_slist* headers = NULL;
    // Set the required headers for Discord API
    headers = curl_slist_append(headers, "Content-Type: application/json");
    char auth_header[512];
    snprintf(auth_header, sizeof(auth_header), "Authorization: Bot %s", DISCORD_TOKEN);
    headers = curl_slist_append(headers, auth_header);
    // Set the curl options
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
    // Perform the HTTP POST request
    res = curl_easy_perform(curl);
    // Check for errors
    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    } else {
      printf("Response from Discord: %s\n", response);
    }
    // Clean up
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
  }
}
*/
