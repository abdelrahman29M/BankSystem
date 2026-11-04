#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDepositeScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalanceScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"

class clsTransactionScreen : protected clsScreen
{
private:

	enum enTransactionsScreen {
		eDepostie = 1, eWithDraw = 2,
		eShowTotalBalance = 3, eTransfer = 4, eTransferLog = 5, eShowMainMenue = 6
	};

	static short ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do [1] To [6] ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 To 6 ?");
		return Choice;
	}

	static void _GoBackToTranactionsMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";

		system("pause>0");
		ShowTransactionScreen();
	}

	static void _ShowDepositeScreen()
	{
		//cout << "\nDeposite Screen will be here...\n";

		clsDepositeScreen::ShowDepositeScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "\nWithdraw Screen will be here...\n";
		clsWithdrawScreen::ShowWithDrawScreen();
	}

	static void _ShowTotalBalanceScreen()
	{
		//cout << "\nTotalBalance Screen will be here...\n";
		clsTotalBalanceScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _ShowMainMenueScreen()
	{
		//clsMainScreen::ShowMainMenue();
	}

	static void _PerformTransactionMenueOption(enTransactionsScreen TransactionsScreen)
	{
		switch (TransactionsScreen)
		{
		case enTransactionsScreen::eDepostie:
		{
			system("cls");
			_ShowDepositeScreen();
			_GoBackToTranactionsMenue();
			break;
		}
		case enTransactionsScreen::eWithDraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTranactionsMenue();
			break;
		}
		case enTransactionsScreen::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTranactionsMenue();
			break;
		}
		case enTransactionsScreen::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTranactionsMenue();
			break;
		}
		case enTransactionsScreen::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTranactionsMenue();
			break;
		}
		case enTransactionsScreen::eShowMainMenue:
		{
			//do nothing here the main screen will handle it :-)
		}
		}
	}

public:

	static void ShowTransactionScreen()
	{
		if (!CheckAccessRigths(clsUser::enPermissions::pTransactions))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\t Transactions Screen");

		cout << setw(37) << left << "" << "=======================================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Screen\n";
		cout << setw(37) << left << "" << "=======================================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposite.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "=======================================================\n";

		_PerformTransactionMenueOption(enTransactionsScreen(ReadTransactionsMenueOption()));
	}

};

