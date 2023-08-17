#include "pch.h"
#include "Goalkeeper.h"

IMPLEMENT_SERIAL(Goalkeeper, Player, 1)

Goalkeeper::Goalkeeper(string name, int age, int speed, int jump, int stamina, int reflex, int one_on_one, int leadering, int throwing) :
	Player(name, age, speed, jump, stamina)
{
	this->reflex = reflex;
	this->one_on_one = one_on_one;
	this->leadering = leadering;
	this->throwing = throwing;
//	this->time_contract = time_contract_for_player(age);//time_contract_for_player- מקבל את age של השחקן ולפי זה מחשב לכמה זמן אנחנו רוצים את זה.
//	this->salary = Player::CalulateSalary();// !מקבל את פרק הזמן שהשחקן משחק אצלנו ולפי זה מחשב לו מחיר התחלתי !
}
int Goalkeeper::getreflex()
{
	return reflex;
}
int Goalkeeper::getone_on_one()
{
	return one_on_one;
}
int Goalkeeper::getleadering()
{
	return leadering;
}
int Goalkeeper::getthrowing()
{
	return throwing;
}

void Goalkeeper::Serialize(CArchive& ar)
{
	Player::Serialize(ar);


	if (ar.IsLoading())
	{
		ar >> reflex >> one_on_one>> leadering>> throwing;

	}
	else if (ar.IsStoring())
	{
		ar << reflex << one_on_one << leadering << throwing;
	}
}

double Goalkeeper::CalulateSalary()
{
	

	if ((reflex < standard) || (one_on_one < standard) || (leadering < standard) || (throwing < standard) || (time_contract == 0))
		salary=0;
	if (reflex >= standard)
	{
		if (reflex <= 13)
			salary *= 1.02;
		if (reflex <= 15)
			salary *= 1.05;
		if (reflex <= 20)
			salary *= 1.07;
	}
	if (one_on_one >= standard)
	{
		if (one_on_one <= 13)
			salary *= 1.02;
		if (one_on_one <= 15)
			salary *= 1.03;
		if (one_on_one <= 20)
			salary *= 1.05;

	}
	if (leadering >= standard)
	{
		if (leadering <= 13)
			salary *= 1.01;
		if (leadering <= 15)
			salary *= 1.02;
		if (leadering <= 20)
			salary *= 1.05;

	}
	if (throwing >= standard)
	{
		if (throwing <= 13)
			salary *= 1.01;
		if (throwing <= 15)
			salary *= 1.02;
		if (throwing <= 20)
			salary *= 1.05;

	}
	

	return salary;
}
