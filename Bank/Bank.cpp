// Name:		Klead Fusha
// Summary:		This is a bank program. It will ask
//				the user the starting balance for
//				his accounts than it will prompt through
//				a menu to enter the date and all the
//				transaction for that date. It will then
//				calculate and print everything into a 
//				file.


#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
#include <numeric>
#include <algorithm>


using namespace std;

ofstream ofs("Bank.txt");

// Global variables
string myname = "Fusha Klead";
string dat = "May 5";
string crnum = "CIS2541-001";
string lab = "Bank";
string sum = "Bank Program";
string eof = "EOF MESSAGE";
string lnu = "_____________________________"
"___________________________________________________";
string pipe = "|";
string lnu2 = "|___________________________"
"___________________________________________________|";
string cong = "Congratulations! You have printed the data to the file. Bye!";
string astrsk = "*************************************";
string dashes = "-------------------------------------";


// Variables for this program only
string choice1 = "1. Checking Deposit";
string choice2 = "2. Checking Withdrawl";
string choice3 = "3. Savings Deposit";
string choice4 = "4. Savings Withdrawl";
string choice5 = "5. IRA deposit";
string choice6 = "6. Mortgage Payment";
string choice7 = "7. Credit Card Payment";
string choice8 = "8. Go to other date ";
string choice9 = "9. Quit";
string menuttl = "    Welcome to your Bank account";
string prompt = "Please enter a choice from the menu:";
string errmsg = "Please enter a valid choice from the menu!";
string errmsg2 = "ERROR! You should enter a positive numeric value!";
string errmsg3 = "You can't use a negative value as a deposit!";
string errmsg4 = "Choose withdraw from the menu!";
string errmsg5 = "Error! You have already entered the checking deposits on ";
string errmsg6 = "Error! You have already entered the checking withdrawls on ";
string errmsg7 = "Error! You have already entered the savings deposits on ";
string errmsg8 = "Error! You have already entered the saving withdrawls on ";
string errmsg9 = "Error! You have already entered the IRA deposit on ";
string errmsg10 = "Error! You have already enterd the mortgage payment on ";
string errmsg11 = "Error! You have already entered the credit card payments on ";
string errmsg12 = "Error! You are trying to withdraw more"
" than you have on your account! ";
string errfrmt = "The date format should be MM/DD/YYYY";
string entrdt = "Enter date:               ";
string trnsdt = "Date of transaction:      ";
string colon = ": ";
string prdate = "Date";
string prchck = "Checking";
string prsvng = "Savings";
string prira = "IRA";
string prmrtg = "Mortgage";
string prcred = "Credit Card";
string lnu3 = "|___________|____________|____________"
"|____________|_____________|_____________|";
string lnu4 = "|	    |		 |          "
"  |		   |		 |	       |";
string lnu5 = "|  BALANCE  |		 |     "
"       |            |             |             |";
string note0 = "|Notes:									       |";
string note1 = "|	     The first line for each date shows the"
" deposits (dep)             |";
string note3 = "|	     The second line for each date"
" shows the withdraws (wdt)	       |";
string note2 = "|	     				and payments (pay)		       |";
string dollar = "$";
string dt;
string napplic = "N/A";
string strtng = "STARTING";
string balanc = "  Balance";
string depp = " dep";
string wdtt = " wdt";
string payy = " pay";
string saccnt = "		Savings account.";
string caccnt = "		Checking account.";
string iraccnt = "		IRA";
string moraccnt = "		Mortgage";
string craccnt = "		Credit Card";
string entrdep = "Enter amount deposited on ";
string entrwdt = "Enter amount withdrew on ";
string entrpay = "Enter amount payed on  ";
string strtch = "Starting balance for Checking account: ";
string strtsv = "Starting balance for Savings account: ";
string strtira = "Starting balance for IRA: ";
string strtmor = "Starting balance for Mortgage account: ";
string strtcc = "Starting balance for the Credit Card: ";

// Variables that will hold the balance for each account.
double chckbal;
double svngbal;
double irabal;
double morbal;
double crdtbal;
void menu();

// Variables that will hold the value for each transaction
double deposch = 0;
double withdch = 0;
double deposav = 0;
double withsav = 0;
double depira = 0;
double paymort = 0;
double paycrd = 0;

const char slsh = '/';
int choice;


//****************************
//* Create a line with pipes *
//****************************
void pipefunc()
{
	ofs << lnu2 << endl;
}

//**********
//* Header *
//**********
void header()
{
	ofs << lnu << endl;
	ofs << pipe
		<< left << setw(20) << myname
		<< left << setw(20) << dat
		<< left << setw(20) << crnum
		<< left << setw(18) << lab
		<< pipe << endl;
}

//**********
//* Footer *
//**********
void footer()
{
	ofs << pipe << left << setw(78) << sum << pipe << endl;
}

//*******************
//* End of the file *
//*******************
void eoff()
{
	ofs << pipe
		<< left << setw(15) << eof
		<< left << setw(18) << myname
		<< left << setw(13) << dat
		<< left << setw(15) << crnum
		<< left << setw(17) << lab
		<< pipe << endl;
}


//***************************************************
//* Prints a message to the console that everything *
//* was successful.								    *
//***************************************************
void messg()
{
	cout << string(5, '\n')
		<< string(5, '\t')
		<< cong << endl;

	cout << string(5, '\t');

	system("pause");

}


//*****************************************************************
//* This class will have banking functions. Each function will be *
//* accessed through the main menu and will be called depending on*
//* the user input. The 'chckdep' function will ask the deposit   *
//* made on a specific date previously entered on the system. The *
//* chckwth function will ask the amount of money withdrew in a   *
//* specific date previously entered on the system; and so on the *
//* other functions will represent a specific transaction.		  *
//*****************************************************************
class banking
{
public:
	void chckdep(string date, double& deposch, double& chckbal)
	{
		if (deposch != 0)
		{
			cout << string(5, '\t') << errmsg5 << date << endl;
			cout << string(5, '\t');
			system("pause");
			menu();
			
		}

		cout << endl;
		cout << string(5, '\t') << caccnt << endl;
		cout << string(5, '\t') << entrdep << date << colon;
		cin >> deposch;


		while (cin.fail() || deposch < 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			

			if (deposch < 0)
			{
				cout << string(5, '\t') << errmsg3 << endl;
				cout << string(5, '\t') << errmsg4 << endl;
				
				deposch = 0;
				cin.clear();
				cin.ignore(1000, '\n');
				cout << string(5, '\t');
				system("pause");
				menu();
				break;
			}


			cout << endl;
			cout << string(5, '\t') << errmsg2;
			cout << string(2, '\n');
			cout << string(5, '\t') << caccnt << endl;
			cout << string(5, '\t') << entrdep << date << colon;
			cin >> deposch;

		}

		chckbal += deposch;

	}

	void chckwth(string date, double& withdch, double& chckbal)
	{
		if (withdch != 0)
		{
			cout << string(5, '\t') << errmsg6 << date << endl;
			cout << string(5, '\t');
			system("pause");
			menu();
		}

		cout << endl;
		cout << string(5, '\t') << caccnt << endl;
		cout << string(5, '\t') << entrwdt << date << colon;
		cin >> withdch;

		
		while (cin.fail() || withdch > chckbal)
		{

			if (withdch > chckbal)
			{
				cout << string(5, '\t') << errmsg12 << endl;
			}

			cin.clear();
			cin.ignore(1000, '\n');
			withdch = -1;

			cout << endl;
			cout << string(5, '\t') << errmsg2;
			cout << string(2, '\n');
			cout << string(5, '\t') << caccnt << endl;
			cout << string(5, '\t') << entrwdt << date << colon;
			cin >> withdch;
		}

		if (withdch < 0)
		{
			withdch = withdch * -1;
			cin.clear();
			cin.ignore(1000, '\n');
		}


		chckbal -= withdch;

	}

	void svngdep(string date, double& deposav, double& svngbal)
	{
		if (deposav != 0)
		{
			cout << string(5, '\t') << errmsg7 << date << endl;
			cout << string(5, '\t');
			system("pause");
			menu();
		}

		cout << endl;
		cout << string(5, '\t') << saccnt << endl;
		cout << string(5, '\t') << entrdep << date << colon;
		cin >> deposav;

		while (cin.fail() || deposav < 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');

			if (deposav < 0)
			{
				cout << string(5, '\t') << errmsg3 << endl;
				cout << string(5, '\t') << errmsg4 << endl;

				deposav = 0;
				cin.clear();
				cin.ignore(1000, '\n');
				cout << string(5, '\t');
				system("pause");
				menu();
				break;
			}

			cout << endl;
			cout << string(5, '\t') << errmsg2;
			cout << string(2, '\n');
			cout << string(5, '\t') << saccnt << endl;
			cout << string(5, '\t') << entrdep << date << colon;
			cin >> deposav;
		}


		svngbal += deposav;
	}

	void svngwth(string date, double& withsav, double& svngbal)
	{

		if (withsav != 0)
		{
			cout << string(5, '\t') << errmsg8 << date << endl;
			cout << string(5, '\t');
			system("pause");
			menu();
		}

		cout << endl;
		cout << string(5, '\t') << saccnt << endl;
		cout << string(5, '\t') << entrwdt << date << colon;
		cin >> withsav;

		while (cin.fail() || withsav > svngbal)
		{
			if (withsav > svngbal)
			{
				cout << string(5, '\t') << errmsg12 << endl;
			}
			cin.clear();
			cin.ignore(1000, '\n');
			withsav = -1;

			cout << endl;
			cout << string(5, '\t') << errmsg2;
			cout << string(2, '\n');
			cout << string(5, '\t') << saccnt << endl;
			cout << string(5, '\t') << entrwdt << date << colon;
			cin >> withsav;
		}

		if (withsav < 0)
		{
			withsav = withsav * -1;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		svngbal -= withsav;

	}

	void iradep(string date, double& depira, double& irabal)
	{

		if (depira != 0)
		{
			cout << string(5, '\t') << errmsg9 << date << endl;
			cout << string(5, '\t');
			system("pause");
			menu();
		}


		cout << endl;
		cout << string(5, '\t') << iraccnt << endl;
		cout << string(5, '\t') << entrdep << date << colon;
		cin >> depira;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			depira = -1;

			cout << endl;
			cout << string(5, '\t') << errmsg2;
			cout << string(2, '\n');
			cout << string(5, '\t') << iraccnt << endl;
			cout << string(5, '\t') << entrdep << date << colon;
			cin >> depira;
		}

		irabal += depira;

	}

	void mortp(string date, double& paymort, double& morbal)
	{

		if (paymort != 0)
		{
			cout << string(5, '\t') << errmsg10 << date << endl;
			cout << string(5, '\t');
			system("pause");
			menu();
		}

		cout << endl;
		cout << string(5, '\t') << moraccnt << endl;
		cout << string(5, '\t') << entrpay << date << colon;
		cin >> paymort;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			paymort = -1;

			cout << endl;
			cout << string(5, '\t') << errmsg2;
			cout << string(2, '\n');
			cout << string(5, '\t') << moraccnt << endl;
			cout << string(5, '\t') << entrpay << date << colon;
			cin >> paymort;
		}

		morbal -= paymort;
	}

	void crdtpay(string date, double& paycrd, double& crdtbal)
	{

		if (paycrd != 0)
		{
			cout << string(5, '\t') << errmsg11 << date << endl;
			cout << string(5, '\t');
			system("pause");
			menu();
		}

		cout << endl;
		cout << string(5, '\t') << craccnt << endl;
		cout << string(5, '\t') << entrpay << date << colon;
		cin >> paycrd;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			paycrd = -1;

			cout << endl;
			cout << string(5, '\t') << errmsg2;
			cout << string(2, '\n');
			cout << string(5, '\t') << craccnt << endl;
			cout << string(5, '\t') << entrpay << date << colon;
			cin >> paycrd;
		}


		crdtbal -= paycrd;
	}


};


//****************************************************************
//* This function will print four lines on the file. The first 3 *
//* lines are the deposits, withdrawls, payments. The fourth line*
//* is a balance after that date. This function will be called   *
//* when the user enteres 8 from the main manu, which will       *
//* calculate and print all the data that was entered on the     *
//* Then it will ask the user to go to a new date. It will also  *
//* be called if the user chooses 9 and quits the program.		 *
//****************************************************************
void prntall(string date)
{

	ofs << pipe
		<< left << setw(11) << date

		<< left << setw(2) << pipe
		<< dollar
		<< right << setw(6) << deposch
		<< left << setw(4) << depp

		<< left << setw(2) << pipe
		<< dollar
		<< right << setw(6) << deposav
		<< left << setw(4) << depp

		<< left << setw(2) << pipe
		<< dollar
		<< right << setw(6) << depira
		<< left << setw(4) << depp

		<< left << setw(2) << pipe
		<< dollar
		<< right << setw(7) << paymort
		<< left << setw(4) << payy

		<< left << setw(2) << pipe
		<< dollar
		<< right << setw(7) << paycrd
		<< right << setw(4) << payy 
		<< pipe << endl;


	ofs << pipe
		<< left << setw(11) << date

		<< left << setw(2) << pipe
		<< dollar
		<< right << setw(6) << withdch
		<< left << setw(4) << wdtt

		<< left << setw(2) << pipe
		<< dollar
		<< right << setw(6) << withsav
		<< left << setw(4) << wdtt

		<< left << setw(6) << pipe
		<< left << setw(7) << napplic

		<< left << setw(6) << pipe
		<< left << setw(8) << napplic

		<< left << setw(6) << pipe
		<< left << setw(8) << napplic
		<< pipe << endl;


//	ofs << pipe
//		<< left << setw(11) << date

//		<< left << setw(6) << pipe
//		<< left << setw(7) << napplic
//
//		<< left << setw(6) << pipe
//		<< left << setw(7) << napplic
//
//		<< left << setw(6) << pipe
//		<< left << setw(7) << napplic
//
	//	<< left << setw(2) << pipe
	//	<< dollar
	//	<< right << setw(6) << paymort
	//	<< left << setw(5) << payy

	//	<< left << setw(2) << pipe
//		<< dollar
		//<< right << setw(6) << paycrd
		//<< right << setw(5) << payy
	//	<< pipe << endl;

	ofs << lnu3 << endl;

	ofs << pipe
		<< left << setw(11) << balanc

		<< left << setw(2) << pipe
		<< dollar
		<< right << setw(6) << chckbal
		<< right << setw(5) << pipe

		<< right << setw(2) << dollar
		<< right << setw(6) << svngbal
		<< right << setw(5) << pipe

		<< right << setw(2) << dollar;


	ofs << right << setw(7) << setprecision(0) << fixed << irabal;

	ofs << right << setw(4) << pipe

		<< right << setw(2) << dollar
		<< right << setw(6) << morbal
		<< right << setw(6) << pipe

		<< right << setw(2) << dollar
		<< right << setw(6) << crdtbal
		<< right << setw(6) << pipe << endl;

	ofs << lnu3 << endl;


}


//************************************************************
//* These are the menu options. They're in a function since  *
//* they'll be called in different instances, so we don't    *
//* have to re-write them.									 *
//************************************************************
void menuoptn()
{
	cout << string(2, '\n');
	cout << string(5, '\t') << astrsk << endl;
	cout << string(6, '\t') << prdate << colon << dt << endl;
	cout << string(5, '\t') << astrsk << endl;

	cout << string(5, '\t') << choice1 << endl;
	cout << string(5, '\t') << choice2 << endl;
	cout << string(5, '\t') << choice3 << endl;
	cout << string(5, '\t') << choice4 << endl;
	cout << string(5, '\t') << choice5 << endl;
	cout << string(5, '\t') << choice6 << endl;
	cout << string(5, '\t') << choice7 << endl;
	cout << string(5, '\t') << dashes << endl;
	cout << string(5, '\t') << choice8 << endl;
	cout << string(5, '\t') << choice9 << endl;
	cout << string(5, '\t') << dashes << endl;
	cout << string(5, '\t') << astrsk << endl;
}


//********************************************************
//* This function will ask the user to enter the date of *
//* the transaction in a specific format. This function  *
//* will be called right after the user has entered the  *
//* starting balances for all of his accounts; it will   *
//* also be called when the user wants to change the date*
//* on the main menu.									 *
//********************************************************
void askdt(string& date)
{
	cout << string(10, '\n');
	cout << string(5, '\t') << astrsk << endl;
	cout << string(5, '\t') << menuttl << endl;

	cout << string(5, '\t') << astrsk << endl;

	cout << string(5, '\t') << errfrmt << endl;

	cout << endl;
	cout << string(5, '\t') << trnsdt;

	
	getline(cin, date);

	while (date.size() != 10
		|| date[2] != slsh || date[5] != slsh
		|| !isdigit(date[0]) || !isdigit(date[1])
		|| !isdigit(date[3]) || !isdigit(date[4])
		|| !isdigit(date[6]) || !isdigit(date[7])
		|| !isdigit(date[8]) || !isdigit(date[9]))
	{
		cout << endl;
		cout << string(5, '\t') << errfrmt << endl;
		cout << string(5, '\t') << entrdt;
		getline(cin, date);
	}

	cin.clear();

}


//**************************************************************
//* This function will be called when the user wants to change *
//* the date so it resets all the values for the previous tran-*
//* sactions. It will reset the values when the user enters 8  *
//* on the menu; right after everything has been printed to the*
//* file regarding the previous date. These variables hold the *
//* values for each transaction that's why they should be reset*
//**************************************************************
void reset(double& deposch, double& withdch,
	double& deposav, double& withsav,
	double& depira, double& paymort,
	double& paycrd)
{
	deposch = 0;
	withdch = 0;
	deposav = 0;
	withsav = 0;
	depira = 0;
	paymort = 0;
	paycrd = 0;
}

//**************************************************************
//* The first 7 options from the menu are basically operations *
//* that the user can make on his/her accounts. The function is*
//* called after we've asked the user for the date and the star*
//* ting balance for each account. When the user wants to go to*
//* another date he/she can choose 8, and 9 to quit. We create *
//* an object to access all the functions that we've stored in *
//* a class.												   *
//**************************************************************
void menu()
{


	do
	{
		menuoptn();

		cout << endl;
		cout << string(5, '\t') << prompt;
		cin >> choice;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			choice = -1;
		}

		banking bnkobj;

		switch (choice)
		{
		case 1:
			bnkobj.chckdep(dt, deposch, chckbal);
			break;

		case 2:
			bnkobj.chckwth(dt, withdch, chckbal);
			break;

		case 3:
			bnkobj.svngdep(dt, deposav, svngbal);
			break;

		case 4:
			bnkobj.svngwth(dt, withsav, svngbal);
			break;

		case 5:
			bnkobj.iradep(dt, depira, irabal);
			break;

		case 6:
			bnkobj.mortp(dt, paymort, morbal);
			break;
		case 7:

			bnkobj.crdtpay(dt, paycrd, crdtbal);
			break;

		case 8:
			prntall(dt);
			reset(deposch, withdch, deposav, withsav, depira, paymort, paycrd);
			cin.ignore();
			askdt(dt);
			menuoptn();
			break;

		case 9:
			prntall(dt);
			break;


		default: cout << string(1, '\n')
			<< string(5, '\t') << errmsg;
			cout << string(2, '\n');

		}

	} while (choice != 9);


}


//****************************************************
//* This function will print the header of the table *
//* on the file, including the starting balance.     *
//****************************************************
void hdr()
{
	ofs << note0 << endl;
	ofs << note1 << endl;
	ofs << note2 << endl;
	ofs << note3 << endl;

	pipefunc();

	ofs << lnu4 << endl;

	ofs << left << setw(3) << pipe
		<< left << setw(9) << strtng
		<< left << setw(3) << pipe
		<< left << setw(10) << chckbal
		<< left << setw(3) << pipe
		<< left << setw(10) << svngbal
		<< left << setw(3) << pipe
		<< left << setw(10) << setprecision(0) << fixed << irabal;


	ofs << left << setw(3) << pipe
		<< left << setw(11) << morbal
		<< left << setw(2) << pipe
		<< left << setw(12) << crdtbal
		<< pipe << endl;

	ofs << lnu5 << endl;
	ofs << lnu3 << endl;

	ofs << left << setw(3) << pipe
		<< left << setw(9) << prdate
		<< left << setw(3) << pipe
		<< left << setw(10) << prchck
		<< left << setw(3) << pipe
		<< left << setw(10) << prsvng
		<< left << setw(3) << pipe
		<< left << setw(10) << prira
		<< left << setw(3) << pipe
		<< left << setw(11) << prmrtg
		<< left << setw(2) << pipe
		<< left << setw(12) << prcred
		<< pipe << endl;
	ofs << lnu3 << endl;

}


//**************************************************
//* This function will ask the user the starting   *
//* balance for each account. We're importing by   *
//* reference because we want to change the value  *
//* of the original value, since we're going to    *
//* print it in the next function we'll call.      *
//**************************************************
void starting(double& chckbal, double& svngbal,
	double& irabal, double& morbal, double& crdtbal)
{
	cout << string(5, '\n');
	cout << string(5, '\t') << astrsk << endl;
	cout << string(5, '\t') << menuttl << endl;
	cout << string(5, '\t') << astrsk << endl;

	cout << string(5, '\t') << strtch;
	cin >> chckbal;

	while (cin.fail() || crdtbal < 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		crdtbal = -1;

		cout << endl;
		cout << string(5, '\t') << errmsg2;
		cout << string(2, '\n');
		cout << string(5, '\t') << strtcc;

		cin >> crdtbal;

	}


	cout << string(5, '\t') << strtsv;
	cin >> svngbal;

	while (cin.fail() || svngbal < 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		svngbal = -1;

		cout << endl;
		cout << string(5, '\t') << errmsg2;
		cout << string(2, '\n');
		cout << string(5, '\t') << strtsv;

		cin >> svngbal;
	}

	cout << string(5, '\t') << strtira;
	cin >> irabal;

	while (cin.fail() || irabal < 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		irabal = -1;

		cout << endl;
		cout << string(5, '\t') << errmsg2;
		cout << string(2, '\n');
		cout << string(5, '\t') << strtira;

		cin >> irabal;
	}

	cout << string(5, '\t') << strtmor;
	cin >> morbal;

	while (cin.fail() || morbal < 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		morbal = -1;

		cout << endl;
		cout << string(5, '\t') << errmsg2;
		cout << string(2, '\n');
		cout << string(5, '\t') << strtmor;

		cin >> morbal;
	}

	cout << string(5, '\t') << strtcc;
	cin >> crdtbal;

	while (cin.fail() || crdtbal < 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		crdtbal = -1;

		cout << endl;
		cout << string(5, '\t') << errmsg2;
		cout << string(2, '\n');
		cout << string(5, '\t') << strtcc;

		cin >> crdtbal;
	}

	cout << string(2, '\n');


}


//***********************************************************
//* The first three functions print the header to the file. *
//* The 'starting' function which is called next, asks the  *
//* user to enter the starting balance for each account.    *
//* The askdt function will ask the user for the date. The  *
//* hdr function will print the header to the table on file *
//* menu will show a menu on the console, which will perform*
//* operations if the user chooses options 1-7. Option 8    *
//* print the data to the file and call the askdt function  *
//* which will change the date for the transactions and re- *
//* display the menu with the date just entered on the top  *
//* 9 will quit and print the last transactions in the file.*
//***********************************************************
int main()
{
	header();
	pipefunc();
	pipefunc();

	starting(chckbal, svngbal, irabal, morbal, crdtbal);
	cin.ignore();
	askdt(dt);

	hdr();

	menu();

	messg();
	pipefunc();
	footer();
	pipefunc();
	pipefunc();
	eoff();
	pipefunc();
	ofs.close();

	return 0;
}