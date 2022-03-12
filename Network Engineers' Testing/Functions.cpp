#include "Functions.h"

void AnyKey()
{
	std::cout << TRIendl << "Пожалуйста, нажмите любую клавишу для продолжения" << TRIendl;
	std::system("pause");
	std::system("cls");
}

//Отсекает лишние символы в конце строки
//По умолчанию - отсекает пробел при вводе логина и ФИО при регистрации или редактировании пользователя
void CharacterRemover(std::string& _string, char c)
{
	while (_string.back() == c)
	{
		_string.erase(--_string.end());
	}
}

//Используется как проверка нажатия клавиши выхода
bool ExitTo(std::string _string)
{
	if (!_string.empty())
	{
		return _string[0] == '0' && _string.size() == 1;
	}
	return false;
}

//Используется как проверка нажатия клавиши выхода
bool ExitTo(std::size_t number)
{
	return number == std::size_t(0);
}

//Возвращает текущее время; [0] - year, [1] - month, [2] - day, [3] - hour, [4] - min
std::array<int, 5> GetLocalTime()
{
	struct tm _tm;
	time_t now = time(0);
	localtime_s(&_tm, &now);
	return std::array<int, 5> {_tm.tm_year + 1900, _tm.tm_mon + 1, _tm.tm_mday, _tm.tm_hour, _tm.tm_min};
}

std::string Encryption(std::string _string)
{
	for (size_t i = 0; i < _string.length(); i++)
	{
		_string[i] += i;
	}
	return _string;
}

std::string Decryption(std::string _string)
{
	for (size_t i = 0; i < _string.length(); i++)
	{
		_string[i] -= i;
	}
	return _string;
}

std::wstring PathToTheFolder()
{
	PWSTR path = NULL;
	HRESULT pathres = SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &path); //Определение пути к папке "Документы"
	std::wstring pathtothefolder(path);
	return pathtothefolder += L"/Network Engeneers' Testing data folder";
}

void Saver(std::unique_ptr<IMember>& member)
{
	std::ofstream ofstr;
	std::wstring filename{};
	filename = PathToTheFolder() + L"/filetesting" + std::to_wstring(member->GetMemberID()) + L".netengtest";
	ofstr.open(filename);
	if (!ofstr.is_open())
	{
		std::cout << "\n\aОшибка записи программных файлов! Данные могут не сохраниться!\n";
		AnyKey();
	}
	else
	{
		ofstr << Encryption(member->GetLogin()) << std::endl
			<< Encryption(member->GetFullName()) << std::endl
			<< Encryption(member->GetPassword()) << std::endl
			<< member->GetMemberID() << std::endl;
		for (auto& y : member->GetResult())
		{
			ofstr << Encryption(y) << std::endl;
		}
	}
	ofstr.close();
}

bool FileRemover(std::unique_ptr<IMember>& member)
{
	namespace fs = std::filesystem;

	std::wstring path{ PathToTheFolder() + L"/filetesting" + std::to_wstring(member->GetMemberID()) + L".netengtest" };
	if (fs::remove(path))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Loader(std::vector<std::unique_ptr<IMember>>& member)
{
	namespace fs = std::filesystem;

	std::string login{}, password{}, full_name{}, buf{};
	std::size_t member_id{ 0 };
	std::vector<std::string> result{};
	std::ifstream ifstr;
	std::wstring::size_type n, n2;
	std::wstring path;
	for (const auto& i : fs::directory_iterator(PathToTheFolder()))
	{
		login.clear(); //Очищяем строки перед записью
		password.clear();
		full_name.clear();
		member_id = 0;

		path = i.path();
		n = path.find(L"filetesting"); // Проверка на соответствие названия файла
		n2 = path.find(L".netengtest"); // Проверка на соответствие названия файла
		if (n != std::wstring::npos && n2 != std::wstring::npos)
		{
			ifstr.open(i);
			if (ifstr.is_open())
			{
				std::getline(ifstr, login);
				std::getline(ifstr, full_name);
				std::getline(ifstr, password);
				ifstr >> member_id;
				result.clear(); //Очищаем result перед записью
				buf.clear();
				while (std::getline(ifstr, buf))
				{
					if (!buf.empty())
					{
						result.emplace_back(Decryption(buf));
					}
				}
			}
			ifstr.close();
			if (member_id == 1)
			{
				member.emplace_back(std::make_unique<Administrator>(
					Decryption(login), Decryption(password), Decryption(full_name), member_id));
				if (!result.empty())
				{
					member.back()->SetResult(result);
				}
			}
			else
			{
				member.emplace_back(std::make_unique<Student>(
					Decryption(login), Decryption(password), Decryption(full_name), member_id));
				member.back()->SetResult(result);
			}
		}
	}
}

void InitialSetup(std::vector<std::unique_ptr<IMember>>& member)
{
	namespace fs = std::filesystem;
	using namespace my_header_namespace;

	MyGraphics(1251, 1251);
	if (!fs::exists(PathToTheFolder().c_str())) //Проверка наличия папки с программными файлами
	{
		fs::create_directory(PathToTheFolder().c_str()); //Создание папки с программными файлами
	}
	std::wstring::size_type n;
	std::wstring path;
	bool checker{ false };
	for (const auto& i : fs::directory_iterator(PathToTheFolder()))
	{
		path = i.path();
		n = path.find(L"filetesting1.netengtest"); // filetesting1.netengtest - зарезервированный файл
		if (n != std::wstring::npos)               // с данными администратора
		{
			checker = true;
		}
	}
	if (checker)
	{
		Loader(member);
	}
	else
	{
		member.emplace_back(std::make_unique<Administrator>("admin", "admin", "Администратор", 1));
		Saver(member.back());
	}
}