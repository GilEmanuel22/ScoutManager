#include "pch.h"
#include "Player.h"

IMPLEMENT_SERIAL(Player, Person, 1)

Player::Player(string name, int age, int speed, int jump, int stamina) : Person(name, age)
{
	this->speed = speed;
	this->jump = jump;
	this->stamina = stamina;
	this->time_contract = time_contract_for_player();//time_contract_for_player- מקבל את age של השחקן ולפי זה מחשב לכמה זמן אנחנו רוצים את זה.
	this->salary = CalulateSalary();// !מקבל את פרק הזמן שהשחקן משחק אצלנו ולפי זה מחשב לו מחיר התחלתי !
}
//Player::Player(Player& f) : Person (f.getname(),f.getage())
//{
//	this->hight = f.hight;
//	this->speed = f.speed;
//	this->weight = f.weight;
//	this->jump = f.jump;
//	this->stamina = f.stamina;
//
//}



int Player::getspeed()
{
	return speed;
}


int Player::getjump()
{
	return jump;
}
int Player::getstamina()
{
	return stamina;
}
double Player::CalulateSalary()
{
	if ((speed < standard) || (jump < standard) || (stamina < standard) || (time_contract == 0))
	{
		this->salary = 0;
	}
	else
	{
		this->salary= start_salary_for_player();
			 if (speed >= standard)
			 {
			  if (speed <= 13)
				  salary *= 1.02;
			  if (speed <= 15)
				  salary *= 1.05;
			  if (speed <= 20)
				 salary *= 1.07;
			 }
			 if  (jump >= standard)
			 {
			  if (jump <= 13)
				  salary *= 1.02;
			  if (jump <= 15)
				  salary *= 1.03;
			  if (jump <= 20)
				  salary *= 1.05;

			 }
			if  (stamina >= standard)
			{
			 if (stamina <= 13)
				 salary *= 1.01;
			 if (stamina <= 15)
				salary *= 1.02;
			 if (stamina <= 20)
				 salary *= 1.05;
			}
		}
	return salary;
	

}

int Player::time_contract_for_player()
{

	
	if (age <= 20&&age>=18)
	{
		time_contract = 5;
		
	}
	else if (age <= 23 && age >20)
	{
		time_contract = 4;
		

	}
	else if (age <= 26 && age > 23)
	{
		time_contract = 4;


	}
	else if (age <= 30 && age > 26)
	{
		time_contract = 2;

	}
	 if (age > 30||age<18)
	 {
		time_contract = 0;
	 }
	return time_contract;

}

double Player::start_salary_for_player()
{
	

	if (time_contract == 5)
	{

		salary = 5000;
	}
	else if (time_contract == 4)
	{

		salary = 10000;

	}
	else if (time_contract == 2)
	{

		salary = 15000;

	}
	else if (time_contract == 0)
	{

		salary = 0;

	}
	return salary;
}

double Player::change_salary()
{
	salary = 0;
	time_contract= time_contract_for_player();
	salary =Player:: CalulateSalary();
	salary = CalulateSalary();
	return salary;
}

