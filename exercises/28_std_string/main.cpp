#include "../exercise.h"
#include <string>

// READ: 字符串 <https://zh.cppreference.com/w/cpp/string/basic_string>

int main(int argc, char **argv) {
    using namespace std::string_literals;

    // "Hello"s 带有后缀 s，触发了 std::string_literals 运算符重载
    auto hello = "Hello"s; 
    // "world" 是传统的 C 风格字符串字面量
    auto world = "world";

    // 1. hello 的类型是 std::string
    ASSERT((std::is_same_v<decltype(hello), std::string>), "Fill in the missing type.");

    // 2. world 的类型是 const char*（由 const char[6] 衰减而来）
    ASSERT((std::is_same_v<decltype(world), const char*>), "Fill in the missing type.");

    // 3. 拼接后的完整字符串
    ASSERT(hello + ", " + world + '!' == "Hello, world!", "Fill in the missing string.");

    return 0;
}

