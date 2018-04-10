#include "stdafx.h"
#include "Console.h"
#include <iostream>

void Console::Clear()
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD topLeft = { 0, 0 };
  CONSOLE_SCREEN_BUFFER_INFO screen;
  DWORD written;
  GetConsoleScreenBufferInfo(handle, &screen);
  FillConsoleOutputCharacterA(handle, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
  FillConsoleOutputAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
  SetConsoleCursorPosition(handle, topLeft);
}

void Console::Resize(int x, int y)
{
  HWND console = GetConsoleWindow();
  RECT rect;
  GetWindowRect(console, &rect);
  MoveWindow(console, rect.left, rect.top, x, y, TRUE);
}

void Console::SetCursorPosition(short x, short y)
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD pos = { x, y };
  SetConsoleCursorPosition(handle, pos);
}

COORD Console::GetCursorPosition()
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO screen;
  GetConsoleScreenBufferInfo(handle, &screen);
  return screen.dwCursorPosition;
}

void Console::ShowConsoleCursor(bool show)
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cursor;
  GetConsoleCursorInfo(handle, &cursor);
  cursor.bVisible = show;
  SetConsoleCursorInfo(handle, &cursor);
}

COORD Console::GetSize()
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO screen;
  GetConsoleScreenBufferInfo(handle, &screen);
  return screen.dwSize;
}

void Console::SetTitle(const std::string& title)
{
  SetConsoleTitle(std::wstring(title.begin(), title.end()).c_str());
}

void Console::SetColor(Color color)
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(handle, (WORD)color);
}

void Console::Write(const std::string& text, Color color)
{
  SetColor(color);
  std::cout << text;
}

void Console::Write(const std::string& text)
{
  Console::Write(text, Color::WHITE);
}

void Console::WriteCentered(const std::string& text, Color color)
{
  Console::Write(CenterString(text), color);
}

void Console::WriteCentered(const std::string& text)
{
  Console::WriteCentered(text, Color::WHITE);
}

void Console::WriteLine(const std::string& text, Color color)
{
  Write(text, color);
  std::cout << std::endl;
}

void Console::WriteLine(const std::string& text)
{
  Console::WriteLine(text, Color::WHITE);
}

void Console::WriteLineCentered(const std::string& text, Color color)
{
  Console::WriteLine(CenterString(text), color);
}

void Console::WriteLineCentered(const std::string& text)
{
  Console::WriteLineCentered(text, Color::WHITE);
}

void Console::WriteList(const std::vector<std::string>& text, Color color)
{
  for (const std::string& s : text)
  {
    WriteLine(s, color);
  }
}

void Console::WriteList(const std::vector<std::string>& text)
{
  for (const std::string& s : text)
  {
    WriteLine(s, Color::WHITE);
  }
}

void Console::WriteListCentered(const std::vector<std::string>& text, Color color)
{
  for (const std::string& s : text)
  {
    WriteLineCentered(s, color);
  }
}

void Console::WriteListCentered(const std::vector<std::string>& text)
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

std::string Console::ReadLinePrompt(const std::string& prompt, Color color)
{
  Console::Write(prompt, color);
  return Console::ReadLine();
}

std::string Console::ReadLinePrompt(const std::string& prompt)
{
  Console::Write(prompt);
  return Console::ReadLine();
}

std::string Console::CenterString(const std::string& str)
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO screen;
  int columns;
  GetConsoleScreenBufferInfo(handle, &screen);
  columns = screen.srWindow.Right - screen.srWindow.Left + 1;
  std::string output;
  int padding = (columns / 2) - (str.size() / 2);
  for (int i = 0; i < padding; ++i)
  {
    output += ' ';
  }
  return output + str;
}