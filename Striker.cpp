#include "pch.h"
#include "Striker.h"
IMPLEMENT_SERIAL(Striker, Person, 1)

Striker::Striker(string name, int age, int speed, int jump, int stamina, int finish, int shoot, int pass, int heading, int moovment) :

	Player(name, age, speed, jump, stamina)
{
	this->finish = finish;
	this->pass = pass;
	this->shoot = shoot;
	this->heading = heading;
	this->moovment = moovment;
	//this->time_contract = time_contract_for_player(age);//time_contract_for_player- מקבל את age של השחקן ולפי זה מחשב לכמה זמן אנחנו רוצים את זה.
	//this->salary = start_salary_for_player(time_contract);// !מקבל את פרק הזמן שהשחקן משחק אצלנו ולפי זה מחשב לו מחיר התחלתי !
}

void Striker::Serialize(CArchive& ar)
{
	Player::Serialize(ar);


	if (ar.IsLoading())
	{
		ar >> finish >> pass>> shoot>> heading>> moovment;

	}
	else if (ar.IsStoring())
	{
		ar << finish << pass << shoot << heading << moovment;
	}

}


double Striker :: CalulateSalary()
{
	

	if ((finish < standard || pass < standard || shoot < standard || heading < standard || moovment < standard) || (time_contract == 0))
		 salary=  0;
	if (finish >= standard)
	{
		if (finish <= 13)
			salary *= 1.02;
		if (finish <= 15)
			salary *= 1.05;
		if (finish <= 20)
			salary *= 1.07;
	}
	if (pass >= standard)
	{
		if (pass <= 13)
			salary *= 1.02;
		if (pass <= 15)
			salary *= 1.03;
		if (pass <= 20)
			salary *= 1.05;

	}
	if (shoot >= standard)
	{
		if (shoot <= 13)
			salary *= 1.01;
		if (shoot <= 15)
			salary *= 1.02;
		if (shoot <= 20)
			salary *= 1.05;

	}
	if (heading >= standard)
	{
		if(heading<=13)
			salary *= 1.01;
		if (heading <= 15)
		salary *= 1.03;
		if (heading <= 20)
		salary *= 1.06;
	}
	if (moovment >= standard)
	{
		if (moovment<=13)
		salary *= 1.02;
		if (moovment <= 15)
			salary *= 1.04;
		if (moovment <= 20)
			salary *= 1.06;
	}
	
	return salary;
}