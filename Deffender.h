#pragma once
#include "Player.h"


class Deffender : public Player
{
	DECLARE_SERIAL(Deffender)

	public:
		Deffender() {}
			double CalulateSalary();
			Deffender(string name, int age, int speed, int jump, int stamina, int power, int tackles, int saving, int brave, int head);
			int getpower();
			int gettackles();
			int getbrave();
			int getheading();
			int getsaving();
			void Serialize(CArchive& ar)override;

	private:
		int power;
		int tackles;
		int saving;
		int brave;
		int heading;

};

