// Copyright 2018 Krystian Stasiowski

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
  Console() = delete;
  Console(const Console&) = delete;
  Console& operator=(const Console&) = delete;
  Console(Console&&) = delete;
  Console& operator=(Console&&) = delete;
  static void Clear();
  static void Resize(int x, int y);
  static void SetCursorPosition(short x, short y);
  static COORD GetCursorPosition();
  static COORD GetSize();
  static void ShowConsoleCursor(bool show);
  static void SetTitle(const std::string& title);
  static void SetColor(Color color);
  static void Write(const std::string& text, Color color);
  static void Write(const std::string& text);
  static void WriteCentered(const std::string& text, Color color);
  static void WriteCentered(const std::string& text);
  static void WriteLine(const std::string& text, Color color);
  static void WriteLine(const std::string& text);
  static void WriteLineCentered(const std::string& text, Color color);
  static void WriteLineCentered(const std::string& text);
  static void WriteList(const std::vector<std::string>& text, Color color);
  static void WriteList(const std::vector<std::string>& text);
  static void WriteListCentered(const std::vector<std::string>& text, Color color);
  static void WriteListCentered(const std::vector<std::string>& text);
  static std::string ReadLine();
  static std::string ReadLinePrompt(const std::string& prompt, Color color);
  static std::string ReadLinePrompt(const std::string& prompt);
private:
  static std::string CenterString(const std::string& str);
};