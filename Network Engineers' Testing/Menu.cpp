#include "Menu.h"

//Присвоение уникального идентификатора пользователя
std::size_t InitialMenu::CreateMemberID()
{
	using namespace my_header_namespace;

	bool breaker{ true };
	std::size_t _memberID;
	do
	{
		_memberID = RandNumber(std::size_t(2), std::size_t((std::numeric_limits<std::size_t>::max)()));
		breaker = true;
		for (const auto& i : member)
		{
			if (i->GetMemberID() == _memberID)
			{
				breaker = false;
				break;
			}
		}
	} while (breaker != true);
	return _memberID;
}

const std::type_info& InitialMenu::Registration()
{
	std::cin.ignore();
	std::string login{}, password{}, full_name{};
	std::cout << "Пожалуйста, введите логин (0 - выход в меню): ";
	std::getline(std::cin, login);
	if (ExitTo(login))
	{
		std::system("cls");
		return typeid(false);
	}
	CharacterRemover(login, ' ');
	for (const auto& i : member)
	{
		if (i->GetLogin() == login)
		{
			std::cout << "Логин уже занят!";
			AnyKey();
			return typeid(false);
		}
	}
	std::cout << "Пожалуйста, введите пароль (0 - выход в меню): ";
	std::getline(std::cin, password);
	if (ExitTo(password))
	{
		std::system("cls");
		return typeid(false);
	}
	std::cout << "Пожалуйста, введите Ваше ФИО (0 - выход в меню): ";
	std::getline(std::cin, full_name);
	if (ExitTo(full_name))
	{
		std::system("cls");
		return typeid(false);
	}
	CharacterRemover(full_name, ' ');
	if (login.empty() || password.empty() || full_name.empty())
	{
		std::cout << "Ошибка регистрации!";
		AnyKey();
		return typeid(false);
	}

	std::size_t _memberID = CreateMemberID();

	if (member.emplace_back(std::make_unique<Student>(login, password, full_name, _memberID)))
	{
		std::cout << "Вы успешно зарегестрировались!";
		MemberID = _memberID;
		Saver(member.back());
		AnyKey();
		return typeid(*member.back());
	}
	else
	{
		std::cout << "Ошибка регистрации!";
		AnyKey();
		return typeid(false);
	}
}

const std::type_info& InitialMenu::SignIn()
{
	std::cin.ignore();
	std::string login{}, password{};
	std::cout << "Пожалуйста, введите логин (0 - выход в меню): ";
	std::getline(std::cin, login);
	if (ExitTo(login))
	{
		std::system("cls");
		return typeid(false);
	}
	std::cout << "Пожалуйста, введите пароль (0 - выход в меню): ";
	std::getline(std::cin, password);
	if (ExitTo(password))
	{
		std::system("cls");
		return typeid(false);
	}
	for (const auto& i : member)
	{
		if (i->GetLogin() == login && i->GetPassword() == password)
		{
			std::cout << "Вы успешно вошли в систему!";
			MemberID = i->GetMemberID();
			AnyKey();
			return typeid(*i);
		}
	}
	std::cout << "Комбинация логина и пароля не найдена!";
	AnyKey();
	return typeid(false);
}

const std::type_info& InitialMenu::operator()()
{
	using namespace my_header_namespace;

	InitialSetup(member);
	signed int item{ 0 };
	while (true)
	{
		std::cout << "Добро пожаловать в Network Engineers' Testing!\n\n"
			<< "Пожалуйста, выберите:\n1 - Регистрация\n2 - Вход в систему\n0 - Выход из программы\n\n";
		item = NumberInput(0, 2);
		std::system("cls");
		if (item > 1)
		{
			const std::type_info& typeinfo = SignIn();
			if (typeinfo != typeid(false))
			{
				return typeinfo;
			}
		}
		else if (item > 0)
		{
			const std::type_info& typeinfo = Registration();
			if (typeinfo != typeid(false))
			{
				return typeinfo;
			}
		}
		else if (item > -1)
		{
			std::exit(0);
		}
		std::system("cls");
	}
}

void AdministratorMenu::ShowMembers()
{
	if (member.size() == 1 || member.empty())
	{
		std::cout << "Список пользователей пуст!";
	}
	else
	{
		std::size_t i{ 1 };
		std::for_each(++member.begin(), member.end(), [&](const std::unique_ptr<IMember>& _member) {
			std::cout << i << ". Логин: " << _member->GetLogin() << ". ФИО: " << _member->GetFullName() << '\n';
			i++; });
	}
}

void AdministratorMenu::RedactingTheFullName()
{
	using namespace my_header_namespace;

	ShowMembers();
	std::cout << "\n\nВведите номер пользователя, которому необходимо сменить ФИО (0 - выход в меню): ";
	std::size_t num = NumberInput(std::size_t(0), member.size() - 1);
	if (ExitTo(num))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите ФИО (0 - выход в меню): ";
	std::string full_name{};
	std::cin.ignore();
	std::getline(std::cin, full_name);
	if (ExitTo(full_name))
	{
		std::system("cls");
		return;
	}
	CharacterRemover(full_name, ' ');
	if (full_name.empty())
	{
		std::cout << "Ошибка!";
		AnyKey();
		return;
	}
	else
	{
		member[num]->SetFullName(full_name);
		std::cout << "ФИО успешно изменено!";
		Saver(member[num]);
		AnyKey();
	}
}

void AdministratorMenu::RedactingTheLogin()
{
	using namespace my_header_namespace;

	ShowMembers();
	std::cout << "\n\nВведите номер пользователя, которому необходимо сменить логин (0 - выход в меню): ";
	std::size_t num = NumberInput(std::size_t(0), member.size() - 1);
	if (ExitTo(num))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите логин (0 - выход в меню): ";
	std::string login{};
	std::cin.ignore();
	std::getline(std::cin, login);
	if (ExitTo(login))
	{
		std::system("cls");
		return;
	}
	CharacterRemover(login, ' ');
	for (const auto& i : member)
	{
		if (i->GetLogin() == login && login != member[num]->GetLogin())
		{
			std::cout << "Логин уже занят!";
			AnyKey();
			return;
		}
	}
	if (login.empty())
	{
		std::cout << "Ошибка!";
		AnyKey();
		return;
	}
	else
	{
		member[num]->SetLogin(login);
		std::cout << "Логин успешно изменён!";
		Saver(member[num]);
		AnyKey();
	}
}

void AdministratorMenu::DeleteUser()
{
	using namespace my_header_namespace;

	ShowMembers();
	if (member.size() == 1 || member.empty())
	{
		AnyKey();
		return;
	}
	std::cout << "\n\nВведите номер пользователя, которого необходимо удалить (0 - выход в меню): ";
	std::size_t num = NumberInput(std::size_t(0), member.size() - 1);
	if (ExitTo(num))
	{
		std::system("cls");
		return;
	}
	std::system("cls");
	std::cout << "Вы хотите удалить пользователя " << member[num]->GetLogin() << ": "
		<< member[num]->GetFullName() << std::endl << "Вы точно хотите это сделать?\n1 - да\n0 - нет\n";
	int choice = NumberInput(0, 1);
	if (choice == 0)
	{
		AnyKey();
		return;
	}
	else
	{
		if (FileRemover(member[num]))
		{
			member.erase(member.begin() + (num));
			std::cout << "Пользователь успешно удалён!";
		}
		else
		{
			std::cout << "Ошибка!";
		}
		AnyKey();
	}
}

void AdministratorMenu::ShowStatistics()
{
	if (member.size() == 1 || member.empty())
	{
		std::cout << "Список пользователей пуст!";
	}
	else
	{
		std::size_t i{ 1 };
		std::for_each(++member.begin(), member.end(), [&](const std::unique_ptr<IMember>& _member) {
			std::cout << i << ". Логин: " << _member->GetLogin() << ". ФИО: " << _member->GetFullName() << ":\n";
			if (_member->GetResult().empty())
			{
				std::cout << "Пользователь еще не проходил тесты!\n";
			}
			else
			{
				for (auto& i : _member->GetResult())
				{
					std::cout << i << '\n';
				}
			}
			i++; });
	}
	AnyKey();
}

void AdministratorMenu::ResetTheUserPassword()
{
	using namespace my_header_namespace;

	ShowMembers();
	std::cout << "\n\nВведите номер пользователя, которому необходимо сбросить пароль (0 - выход в меню): ";
	std::size_t num = NumberInput(size_t(0), member.size() - 1);
	if (ExitTo(num))
	{
		std::system("cls");
		return;
	}
	std::string temporarypass;
	for (std::size_t i = 0; i < 5; i++)
	{
		temporarypass += RandNumber(97, 122);
	}
	member[num]->SetPassword(temporarypass);
	Saver(member[num]);
	std::cout << "\n\nПользователю присвоен временный пароль " << temporarypass << std::endl
		<< "\nСообщите его пользователю и порекомедуйте в скором времени сменить его!";
	AnyKey();
}

void AdministratorMenu::ChangeAdminLogNPass()
{
	std::string newlogin{}, newpass{}, newname{};
	std::cin.ignore();
	std::cout << "Пожалуйста, введите новый логин (0 - выход в меню): ";
	std::getline(std::cin, newlogin);
	if (ExitTo(newlogin))
	{
		std::system("cls");
		return;
	}
	CharacterRemover(newlogin, ' ');
	for (const auto& i : member)
	{
		if (i->GetLogin() == newlogin)
		{
			std::cout << "Логин уже занят!";
			AnyKey();
			return;
		}
	}
	std::cout << "Пожалуйста, введите новый пароль (0 - выход в меню): ";
	std::getline(std::cin, newpass);
	if (ExitTo(newpass))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите новое имя (текущее - " << member[0]->GetFullName() << "): ";
	std::getline(std::cin, newname);
	if (ExitTo(newname))
	{
		std::system("cls");
		return;
	}
	CharacterRemover(newname, ' ');
	if (newlogin.empty() || newpass.empty() || newname.empty())
	{
		std::cout << "Ошибка!";
		AnyKey();
		return;
	}
	member[0]->Set(newlogin, newpass, newname);
	Saver(member[0]);
	std::cout << "Данные успешно обновлены!";
	AnyKey();
}

void AdministratorMenu::ShowAllMembers()
{
	std::size_t I{ 1 };
	for (auto& i : member)
	{
		std::cout << I << ". Логин: " << i->GetLogin() << ". ФИО: " << i->GetFullName() << '\n';
		I++;
	}
	AnyKey();
}

void AdministratorMenu::operator()()
{
	using namespace my_header_namespace;

	int item{ 0 };
	do
	{
		std::cout << "Пожалуйста, выберите:\n1 - Редактировать ФИО пользователя\n2 - Редактировать логин пользователя\n"
			<< "3 - Удалить пользователя\n4 - Просмотр статистики по пользователям\n5 - Сбросить пароль пользователю\n"
			<< "6 - Изменить логин и пароль администратора\n7 - Список всех пользователей\n0 - Выход из программы\n\n";
		item = NumberInput(0, 7);
		std::system("cls");
		if (item > 6)
		{
			ShowAllMembers();
		}
		else if (item > 5)
		{
			ChangeAdminLogNPass();
		}
		else if (item > 4)
		{
			ResetTheUserPassword();
		}
		else if (item > 3)
		{
			ShowStatistics();
		}
		else if (item > 2)
		{
			DeleteUser();
		}
		else if (item > 1)
		{
			RedactingTheLogin();
		}
		else if (item > 0)
		{
			RedactingTheFullName();
		}
	} while (item != 0);
}

bool StudentMenu::testing(const test::Question& question, int& score, int& number)
{
	using namespace my_header_namespace;

	std::cout << number << ". " << question.GetQuestion() << "\n\n";
	std::vector<std::string> questions = question.GetBadAnswers();
	questions.emplace_back(question.GetAnswer());
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(questions.begin(), questions.end(), g); //Меняем порядок вариантов ответов
	int num{ 1 }, antwoord{ 0 };
	for (const auto& i : questions)
	{
		std::cout << num << " - " << i << '\n'; num++;
	}
	std::cout << "\nВведите ответ (0 - выход): ";
	antwoord = NumberInput(std::size_t(0), questions.size());
	if (ExitTo(antwoord))
	{
		return false;
	}
	if (questions[antwoord - 1] == question.GetAnswer())
	{
		score++;
	}
	number++;
	std::system("cls");
	return true;
}

void StudentMenu::after_test(int& score, int layer)
{
	std::string result = std::to_string(score) + '/' + std::to_string(10);
	std::cout << "Вы набрали " << result << " балов.";
	result = ("Уровень " + std::to_string(layer) + ": " + result);
	result += ("  " + std::to_string(GetLocalTime()[0]) + '.' + std::to_string(GetLocalTime()[1]) + '.'
		+ std::to_string(GetLocalTime()[2]) + ' ' + std::to_string(GetLocalTime()[3]) + ':'
		+ std::to_string(GetLocalTime()[4]));
	for (auto& i : member)
	{
		if (i->GetMemberID() == MemberID)
		{
			i->AddResult(result);
			Saver(i);
			break;
		}
	}
}

void StudentMenu::Test()
{
	using namespace my_header_namespace;

	int item{ 0 };
	do
	{
		std::cout << "Пожалуйста, выберите тест:\n\n1 - Базовые основы компьютерных сетей и владения ПК\n\n"
			<< "2 - Основы работы с компюьтерными сетями и сетевым оборудованием; Основы коммутации и маршрутизации\n\n"
			<< "3 - Профессиональный уровень владения сетевым оборудованием и компьютерными сетями; Расширенное изучение "
			<< "принципов коммутации и маршрутизации"
			<< "\n\n0 - Выход в предыдущий пункт меню\n\n";
		item = NumberInput(0, 3);
		std::system("cls");
		if (item > 2)
		{
			int score{ 0 }, number{ 1 }, layer{ 3 };
			bool stopper{ false };
			for (const auto& i : ThirdTest)
			{
				if (!testing(i, score, number))  //Выходим из теста при нажатии "0"
				{
					stopper = true;
					break;
				}
			}
			if (!stopper)
			{
				after_test(score, layer);
			}
			AnyKey();
		}
		else if (item > 1)
		{
			int score{ 0 }, number{ 1 }, layer{ 2 };
			bool stopper{ false };
			for (const auto& i : SecondTest)
			{
				if (!testing(i, score, number))  //Выходим из теста при нажатии "0"
				{
					stopper = true;
					break;
				}
			}
			if (!stopper)
			{
				after_test(score, layer);
			}
			AnyKey();
		}
		else if (item > 0)
		{
			int score{ 0 }, number{ 1 }, layer{ 1 };
			bool stopper{ false };
			for (const auto& i : FirstTest)
			{
				if (!testing(i, score, number))  //Выходим из теста при нажатии "0"
				{
					stopper = true;
					break;
				}
			}
			if (!stopper)
			{
				after_test(score, layer);
			}
			AnyKey();
		}
	} while (item != 0);
}

void StudentMenu::ShowResult()
{
	for (const auto& i : member)
	{
		if (i->GetMemberID() == MemberID)
		{
			std::cout << i->GetFullName() << "\n\n";
			if (i->GetResult().empty())
			{
				std::cout << "Статистика пуста!";
			}
			else
			{
				std::size_t I{ 0 };
				for (const auto& y : i->GetResult())
				{
					I++;
					std::cout << I << ". " << y << '\n';
				}
			}
			break;
		}
	}
	AnyKey();
}

void StudentMenu::ChangePassword()
{
	std::cin.ignore();
	std::string oldpass, newpass;
	std::cout << "Пожалуйста, введите старый пароль (0 - выход): ";
	std::getline(std::cin, oldpass);
	if (ExitTo(oldpass))
	{
		std::system("cls");
		return;
	}
	for (auto& i : member)
	{
		if (i->GetMemberID() == MemberID && i->GetPassword() == oldpass)
		{
			std::cout << "Пожалуйста, введите новый пароль: ";
			std::getline(std::cin, newpass);
			if (ExitTo(newpass))
			{
				std::system("cls");
				return;
			}
			if (!newpass.empty())
			{
				i->SetPassword(newpass);
				std::cout << "Пароль успшно изменён!";
				Saver(i);
				AnyKey();
				return;
			}
			else
			{
				std::cout << "Ошибка!";
				AnyKey();
				return;
			}
		}
	}
	std::cout << "Пароли не совпадают! Обратитесь к администратору, если забыли пароль.";
	AnyKey();
}

void StudentMenu::operator()()
{
	using namespace my_header_namespace;

	int item{ 0 };
	do
	{
		std::cout << "Пожалуйста, выберите:\n1 - Пройти тест\n2 - Просмотреть свою статистику\n3 - Поменять пароль\n"
			<< "0 - Выход из программы\n\n";
		item = NumberInput(0, 3);
		std::system("cls");
		if (item > 2)
		{
			ChangePassword();
		}
		else if (item > 1)
		{
			ShowResult();
		}
		else if (item > 0)
		{
			Test();
		}
	} while (item != 0);
}