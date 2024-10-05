#pragma once
#include <vector>
#include <string>

template<typename T>
constexpr auto ctrl(T x) { return (x & 0x1F); }

constexpr int EDITOR_ROW_START = 3;

extern int screen;
extern int cursor_x;
extern int cursor_y;
extern std::vector<std::string> lines;