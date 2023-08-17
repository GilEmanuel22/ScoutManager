#pragma once
#include "Player.h"

class Goalkeeper : public Player
{
	DECLARE_SERIAL(Goalkeeper)

	public:
		Goalkeeper()
		{
		}

		 double CalulateSalary();
		 Goalkeeper(string name, int age, int speed, int jump, int stamina, int reflex, int one_on_one, int leadering, int throwing);
	int getreflex();
	int getone_on_one();
	int getleadering();
	int getthrowing();
	void Serialize(CArchive& ar)override;

	private:
		int reflex;
		int one_on_one;
		int leadering;
		int throwing;


};

