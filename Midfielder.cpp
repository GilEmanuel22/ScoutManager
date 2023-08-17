#include "pch.h"
#include "Midfielder.h"
IMPLEMENT_SERIAL(Midfielder, Person, 1)

Midfielder:: Midfielder(string name, int age, int speed, int jump, int stamina,int pass,int power,int longshoot,int longpass) :

	Player(name, age, speed, jump, stamina)
{
	this->pass = pass;
	this->power = power;
	this->longpass = longpass;
	this->longshoot = longshoot;
	
}

void Midfielder::Serialize(CArchive& ar)
{
	Player::Serialize(ar);


	if (ar.IsLoading())
	{
		ar >> pass >> power>> longpass>> longshoot;

	}
	else if (ar.IsStoring())
	{
		ar << pass << power << longpass << longshoot;
	}
}


double Midfielder::CalulateSalary()//  מחשב לפי הסטנדרטים שלנו אם לאביעמוד בהם אז לא יקבל חוזה ואם כן יחשב לפי השכר ההתחלתי שלו כמה מגיע לו לפי הנתונים שלו  
{


	if ((pass < standard || power < standard || longpass < standard || longshoot < standard) || (time_contract == 0))
		salary = 0;
	if (pass >= standard)
	{
		if (pass <= 13)
			salary *= 1.03;
		if (pass <= 15)
			salary *= 1.05;
		if (pass <= 20)
			salary *= 1.07;
	}
	if (power >= standard)
	{
		if (power <= 13)
			salary *= 1.02;
		if (power <= 15)
			salary *= 1.03;
		if (power <= 20)
			salary *= 1.05;

	}
	if (longshoot >= standard)
	{
		if (longshoot <= 13)
			salary *= 1.03;
		if (longshoot <= 15)
			salary *= 1.05;
		if (longshoot <= 20)
			salary *= 1.07;

	}
	

	
	return salary;
}


