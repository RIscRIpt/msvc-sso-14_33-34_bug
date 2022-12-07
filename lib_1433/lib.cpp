#include <string>

static_assert(_MSC_VER == 1933);

std::string GetStringOld(const char* p) {
    return std::string(p);
}