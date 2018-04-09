#include "stdafx.h"
#include "Console.h"
#include <iostream>

HANDLE Console::console_handle_;

void Console::Clear()
{
  COORD topLeft = { 0, 0 };
  CONSOLE_SCREEN_BUFFER_INFO screen;
  DWORD written;
  GetConsoleScreenBufferInfo(console_handle_, &screen);
  FillConsoleOutputCharacterA(console_handle_, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
  FillConsoleOutputAttribute(console_handle_, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
  SetConsoleCursorPosition(console_handle_, topLeft);
}

void Console::Resize(int x, int y)
{
  HWND console = GetConsoleWindow();
  RECT rect;
  GetWindowRect(console, &rect);
  MoveWindow(console, rect.left, rect.top, x, y, TRUE);
}

void Console::SetTitle(std::string title)
{
  SetConsoleTitle(std::wstring(title.begin(), title.end()).c_str());
}

void Console::SetColor(Color color)
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(console_handle_, (WORD)color);
}

void Console::Write(std::string text, Color color)
{
  SetColor(color);
  std::cout << text;
}

void Console::Write(std::string text)
{
  Console::Write(text, Color::WHITE);
}

void Console::WriteCentered(std::string text, Color color)
{
  Console::Write(CenterString(text), color);
}

void Console::WriteCentered(std::string text)
{
  Console::WriteCentered(text, Color::WHITE);
}

void Console::WriteLine(std::string text, Color color)
{
  Write(text, color);
  std::cout << std::endl;
}

void Console::WriteLine(std::string text)
{
  Console::WriteLine(text, Color::WHITE);
}

void Console::WriteLineCentered(std::string text, Color color)
{
  Console::WriteLine(CenterString(text), color);
}

void Console::WriteLineCentered(std::string text)
{
  Console::WriteLineCentered(text, Color::WHITE);
}

void Console::WriteList(std::vector<std::string> text, Color color)
{
  for (const std::string& s : text)
  {
    WriteLine(s, color);
  }
}

void Console::WriteList(std::vector<std::string> text)
{
  for (const std::string& s : text)
  {
    WriteLine(s, Color::WHITE);
  }
}

void Console::WriteListCentered(std::vector<std::string> text, Color color)
{
  for (const std::string& s : text)
  {
    WriteLineCentered(s, color);
  }
}

void Console::WriteListCentered(std::vector<std::string> text)
{
  for (const std::string& s : text)
  {
    WriteLineCentered(s, Color::WHITE);
  }
}

std::string Console::ReadLine()
{
  std::string input;
  std::getline(std::cin, input);
  return input;
}

std::string Console::ReadLinePrompt(std::string prompt, Color color)
{
  Console::Write(prompt, color);
  return Console::ReadLine();
}

std::string Console::ReadLinePrompt(std::string prompt)
{
  Console::Write(prompt);
  return Console::ReadLine();
}

void Console::SetConsoleHandle(HANDLE handle)
{
  console_handle_ = handle;
}

void Console::CloseConsoleHandle()
{
  CloseHandle(console_handle_);
}

std::string Console::CenterString(std::string str)
{
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  int columns;
  GetConsoleScreenBufferInfo(console_handle_, &csbi);
  columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
  std::string output;
  int padding = (columns / 2) - (str.size() / 2);
  for (int i = 0; i < padding; ++i)
  {
    output += ' ';
  }
  return output + str;
}