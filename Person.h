#pragma once
#include "pch.h"
//#include <iostream>
#include <string>
using namespace std;
#define MAX_CHAR  60
#define standard 10
#define top_grade 20
//template<string t>

class Person  : public CObject
{
public:

	DECLARE_SERIAL(Person)
	

	virtual double change_salary() { return 0; }; // Prue virtual function , SERIAL
	virtual double CalulateSalary() { return 0; }; // Prue virtual function , SERIAL

	Person() {}; // Seralize

	Person(string name, int age);
	/*Person(Person& f);*/
	/*void setName(const char* name);*/
	const string  getName() const;
	void setName(const string name);
	const int getage() const;
	void setage(int age) 
	{
	this->age = age;
	}

	//virtual int  Calulatecontract()=0;

	/*string getname();
		int getage();*/
	int gettime_contract();
	double getsalary();
	virtual void Serialize(CArchive& ar)override;

protected:
	
	double salary=0;
	int age;
	string name;
	int time_contract;
private:
	
	


};

