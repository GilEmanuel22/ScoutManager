#pragma once
#include "Person.h"

class Manager : public Person
{
	DECLARE_SERIAL(Manager)

	public:
		Manager(string name, int age, int career_years, int game_manegment, int tactics, int motivation);
Manager()
{}
		int Calulatecontract();
		int getcareer_years();
		int getgame_managment();
		int gettactics();
		int getmotivation();
		double CalulateSalary();
		double start_salary_for_manager();
		double change_salary();
		void Serialize(CArchive& ar)override;


private:
	int career_years;
	int game_managment;
	int tactics;
	int motivation;
}; 
