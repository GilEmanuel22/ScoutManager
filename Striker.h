#pragma once

#include "Player.h"

class Striker : public Player
{
	DECLARE_SERIAL(Striker)

	public :
		Striker()
		{}
		double CalulateSalary();
	 Striker(string name, int age, int speed, int jump, int stamina, int finish, int shoot, int pass, int heading, int moovment);
	 void Serialize(CArchive& ar)override;

	private:

	int finish;
	int shoot;
	int pass;
	int heading;
	int moovment;

};

