#include "Member.h"
#include "Menu.h"
#include <memory>
#include <vector>
#include <typeinfo>
#include <cstddef>

int main()
{
	std::size_t MemberID{ 0 };
	std::vector<std::unique_ptr<IMember>> member;

	const std::type_info& typeinfo = InitialMenu(member, MemberID)();

	if (typeinfo == typeid(Administrator))
	{
		(void)AdministratorMenu(member)();
	}
	if (typeinfo == typeid(Student))
	{
		StudentMenu(member, MemberID)();
	}

	return 0;
}