#include "pch.h"
#include "Deffender.h"
IMPLEMENT_SERIAL(Deffender, Player, 1)

Deffender ::Deffender(string name, int age, int speed, int jump, int stamina, int power, int tackles, int saving, int brave, int head) :
	Player(name, age, speed, jump, stamina)
{
	this->power = power;
	this->tackles = tackles;
	this->brave = brave;
	this->heading = head;
	this->saving = saving;

	//this->time_contract = time_contract_for_player(age);//time_contract_for_player- מקבל את age של השחקן ולפי זה מחשב לכמה זמן אנחנו רוצים את זה.
	//this->salary = start_salary_for_player(time_contract);// !מקבל את פרק הזמן שהשחקן משחק אצלנו ולפי זה מחשב לו מחיר התחלתי !

}
int Deffender::getpower()
{
	return power;
}
int Deffender::gettackles()
{
	return tackles;
}
int Deffender::getbrave()
{
	return brave;
}
int Deffender::getheading()
{
	return heading;
}
int Deffender::getsaving()
{
	return saving;
}

void Deffender::Serialize(CArchive& ar)
{
	
		Player::Serialize(ar);

		if (ar.IsLoading())
		{
			ar >> power >> tackles>> brave>> heading;

		}
		else if (ar.IsStoring())
		{
			ar << power << tackles << brave << heading;
		}

	
}


double Deffender::CalulateSalary()
{
	if ((power < standard || tackles < standard || brave < standard || heading < standard) || (time_contract == 0))
		salary= 0;
	if (saving >= standard)
	{
		if (saving <= 13)
			salary *= 1.02;
		if (saving <= 15)
			salary *= 1.05;
		if (saving <= 20)
			salary *= 1.07;
	}
	if (power >= standard)
	{
		if (power <= 13)
			salary *= 1.02;
		if (power <= 15)
			salary *= 1.05;
		if (power <= 20)
			salary *= 1.07;
	}
	if (tackles >= standard)
	{
		if (tackles <= 13)
			salary *= 1.02;
		if (tackles <= 15)
			salary *= 1.03;
		if (tackles <= 20)
			salary *= 1.05;

	}
	if (brave >= standard)
	{
		if (brave <= 13)
			salary *= 1.01;
		if (brave <= 15)
			salary *= 1.02;
		if (brave <= 20)
			salary *= 1.05;

	}
	if (heading >= standard)
	{
		if (heading <= 13)
			salary *= 1.01;
		if (heading <= 15)
			salary *= 1.02;
		if (heading <= 20)
			salary *= 1.05;

	}
	

	return salary;
}



