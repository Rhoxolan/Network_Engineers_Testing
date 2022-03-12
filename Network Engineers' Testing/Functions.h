#pragma once
#include "Member.h"
#include "MyHeader.h"
#include <cstdlib>
#include <iostream>
#include <array>
#include <ctime>
#include <string>
#include <ShlObj.h>
#include <KnownFolders.h>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <sstream>
#include <cstddef>
#include <iostream>
#include <memory>

constexpr auto TRIendl = "\n\n\n";

void AnyKey();

//Отсекает лишние символы в конце строки
//По умолчанию - отсекает пробел при вводе логина и ФИО при регистрации или редактировании пользователя
void CharacterRemover(std::string& _string, char c);

//Используется как проверка нажатия клавиши выхода
bool ExitTo(std::string _string);

//Используется как проверка нажатия клавиши выхода
bool ExitTo(std::size_t number);

//Возвращает текущее время; [0] - year, [1] - month, [2] - day, [3] - hour, [4] - min
std::array<int, 5> GetLocalTime();

std::string Encryption(std::string _string);

std::string Decryption(std::string _string);

std::wstring PathToTheFolder();

void Saver(std::unique_ptr<IMember>& member);

bool FileRemover(std::unique_ptr<IMember>& member);

void Loader(std::vector<std::unique_ptr<IMember>>& member);

void InitialSetup(std::vector<std::unique_ptr<IMember>>& member);
