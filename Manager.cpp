#include "pch.h"
#include "Manager.h"
IMPLEMENT_SERIAL(Manager, Person, 1)

Manager::Manager(string name, int age, int career_years, int game_manegment, int tactics, int motivation): Person(name, age)
{
	this->career_years = career_years;
	this->game_managment = game_manegment;
	this->tactics = tactics;
	this->motivation = motivation;
	this->time_contract = Calulatecontract();
	this->salary= CalulateSalary();
}

int Manager::getcareer_years()
{
	return career_years;
}
int Manager::getgame_managment()
{
	return game_managment;
}
int Manager::gettactics()
{
	return tactics;
}
int Manager::getmotivation()
{
	return motivation;
}
int Manager::Calulatecontract()
{
	
	if (career_years < 5)
	{
		this->time_contract = 0;
	}
	if (career_years >= 5 && career_years < 10)
	{
		this->time_contract = 1;
	}
	if (career_years >= 10 && career_years < 15)
	{
		this->time_contract = 2;
	}
	if (career_years >= 15 )
	{
		this->time_contract = 3;
	}
	
	return time_contract;
}
double Manager::start_salary_for_manager()
{
	
	if (time_contract == 3)
	{
		salary = 10000;
	}
	if (time_contract ==2)
	{
		salary = 8000;
	}
	if (time_contract == 1)
	{
		salary=5000;
	}
	if (time_contract ==0)
	{
		salary=0;
	}

	return salary;
}
double Manager::CalulateSalary()
{
	{
		if (( game_managment < standard || tactics < standard || motivation < standard) || (time_contract == 0) || ((this->age < 40) ))
			salary= 0;
		else {
			salary = start_salary_for_manager();
			if (game_managment >= standard)
			{
				if (game_managment <= 13)
					salary *= 1.03;
				if (game_managment <= 15)
					salary *= 1.04;
				if (game_managment <= 20)
					salary *= 1.06;

			}
			if (tactics >= standard)
			{
				if (tactics <= 13)
					salary *= 1.01;
				if (tactics <= 15)
					salary *= 1.02;
				if (tactics <= 20)
					salary *= 1.05;

			}
			if (motivation >= standard)
			{
				if (motivation <= 13)
					salary *= 1.01;
				if (motivation <= 15)
					salary *= 1.02;
				if (motivation <= 20)
					salary *= 1.04;

			}
		}

		return salary;
	}
}
double Manager::change_salary()
{
	salary = 0;
	time_contract = Calulatecontract();
	salary = Manager::CalulateSalary();
	//salary = CalulateSalary();
	return salary;
}

void Manager::Serialize(CArchive& ar)
{
	
		Person::Serialize(ar);

		if (ar.IsLoading())
		{
			ar >> age >> salary >> career_years >> game_managment >> tactics >> motivation;

		}
		else if (ar.IsStoring())
		{
			ar << age << salary << career_years << game_managment << tactics << motivation;
		}

	
}
