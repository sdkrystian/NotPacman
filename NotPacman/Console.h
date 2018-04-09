#pragma once
#include <windows.h>
#include <string>
#include <vector>

enum class Color
{
  BLACK = 0,
  BLUE = 1,
  GREEN = 2,
  AQUA = 3,
  RED = 4,
  PURPLE = 5,
  YELLOW = 6,
  WHITE = 7,
  GRAY = 8,
  LIGHT_BLUE = 9,
  LIGHT_GREEN = 10,
  LIGHT_AQUA = 11,
  LIGHT_RED = 12,
  LIGHT_PURPLE = 13,
  LIGHT_YELLOW = 14,
  BRIGHT_WHITE = 15
};

class Console
{
public:
  static void Clear();
  static void Resize(int x, int y);
  static void SetTitle(std::string title);
  static void SetColor(Color color);
  static void Write(std::string text, Color color);
  static void Write(std::string text);
  static void WriteCentered(std::string text, Color color);
  static void WriteCentered(std::string text);
  static void WriteLine(std::string text, Color color);
  static void WriteLine(std::string text);
  static void WriteLineCentered(std::string text, Color color);
  static void WriteLineCentered(std::string text);
  static void WriteList(std::vector<std::string> text, Color color);
  static void WriteList(std::vector<std::string> text);
  static void WriteListCentered(std::vector<std::string> text, Color color);
  static void WriteListCentered(std::vector<std::string> text);
  static std::string ReadLine();
  static std::string ReadLinePrompt(std::string prompt, Color color);
  static std::string ReadLinePrompt(std::string prompt);
  static void SetConsoleHandle(HANDLE handle);
  static void CloseConsoleHandle();
private:
  static HANDLE console_handle_;
  static std::string CenterString(std::string str);
};