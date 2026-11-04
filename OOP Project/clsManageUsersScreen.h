#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private:

	enum enManageUsersMenueOption {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};

	static short _ReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do [1] To [6] ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 To 6 ?");
		return Choice;
	}

	static void _GoBackToManageUsersMenue()
	{
		cout << setw(37) << left << "" << "\nPress any key to go back to ManageUsers Menue...\n";

		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowListUsersScreen()
	{
		//cout << "\nList Users Screen will be here...\n";
		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUsersScreen()
	{
		//cout << "\nAddNew Users Screen will be here...\n";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUsersScreen()
	{
		//cout << "\nDelete Users Screen will be here...\n";
		clsDeleteUsersScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUsersScreen()
	{
		//cout << "\nUpdate Users Screen will be here...\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUsersScreen()
	{
		//cout << "\nFind Users Screen will be here...\n";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersMenueOption(enManageUsersMenueOption ManageUsersMenueOption)
	{
		switch (ManageUsersMenueOption)
		{
		case enManageUsersMenueOption::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOption::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOption::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOption::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOption::eFindUser:
		{
			system("cls");
			_ShowFindUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOption::eMainMenue:
		{
			//system("cls");
			break;
		}
		}
	}

public:

	static void ShowManageUsersMenue()
	{
		if (!CheckAccessRigths(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t\t Manage Users Menue\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Users.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Users.\n";
		cout << setw(37) << left << "" << "\t[4] Update Users.\n";
		cout << setw(37) << left << "" << "\t[5] Find Users.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "=============================================\n";

		_PerformManageUsersMenueOption(enManageUsersMenueOption(_ReadManageUsersMenueOption()));

	}


};
