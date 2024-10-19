#include "F100cBot.hpp"
#include <iostream>
using Diplomacy::Discord_API;
static std::ostream& operator<<(std::ostream& stream, const json_t* json) {
  char* json_str = json_dumps(json, JSON_INDENT(2));
  if (json_str) {
    stream << json_str;
    free(json_str);
  }
  return stream;
}
int main() {
  Discord_API api{};
  json_t*     data = api.get_request("/gateway");
  std::cout << data << '\n';
  return 0;
}
