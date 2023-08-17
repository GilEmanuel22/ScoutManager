#pragma once
#include "Person.h"

class Player : public Person 
{
	DECLARE_SERIAL(Player)

	public:

		Player()
		{

		}

	Player(string name, int age, int speed, int jump, int stamina);
	Player(Player &f);

	int getspeed();
	int getjump();
	int getstamina();
	/*virtual*/ double CalulateSalary();
	/*virtual*/ double start_salary_for_player();
	double change_salary();
	/*virtual*/ int time_contract_for_player();
	


	void Serialize(CArchive& ar)
	{
		Person::Serialize(ar);

		if (ar.IsStoring())
		{
			ar << speed;
			ar << jump;
			ar << stamina;
		
		}
		else 
		{
			ar >> speed;
			ar >> jump;
			ar >> stamina;
		}
	}

	protected:

	int speed;
	int jump;
	int stamina;
	

};

