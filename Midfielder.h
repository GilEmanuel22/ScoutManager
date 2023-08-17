#pragma once
#include "Player.h"

class Midfielder : public Player
{
	DECLARE_SERIAL(Midfielder)

	public:
		Midfielder()
		{}
		double CalulateSalary();
			Midfielder(string name, int age, int speed, int jump, int stamina, int pass, int power, int longshoot, int longpass);
			void Serialize(CArchive& ar)override;

	private:
		int pass;
		int power;
		int longshoot;
		int longpass;



};

