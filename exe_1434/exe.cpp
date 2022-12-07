#include <iostream>
#include <string>

static_assert(_MSC_VER == 1934);

std::string GetStringOld(const char* p);

__declspec(noinline) std::string GetStringNew(const char* p) {
    return std::string(p);
}

__declspec(noinline) void dirty_stack() {
    char trash[32];
    memset(trash, '@', sizeof(trash) - 1);
    trash[sizeof(trash) - 1] = '\0';
    std::cout << trash << '\n';
}

__declspec(noinline) void nobug_new() {
    std::cout << GetStringNew("01234567#$").c_str() << '\n';
}

__declspec(noinline) void bug_old() {
    std::cout << GetStringOld("01234567#$").c_str() << '\n';
}

int main() {
    dirty_stack();
    bug_old();
    dirty_stack();
    nobug_new();
    return 0;
}