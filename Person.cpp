#include "pch.h"
#include "Person.h"
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

IMPLEMENT_SERIAL(Person, CObject, 1)   // (Person)

Person::Person(string name, int age)
{
	this->name = name;

	this->age = age;


}
void Person::setName(const string name)
{

	this->name = name;
}
const string Person::getName() const
{
	return name;
}
const int Person::getage() const
{
	return age;
}
double Person::getsalary()
{
	return salary;
}
int Person::gettime_contract()
{
	return time_contract;
}

void Person::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	//string NAME((CT2CA)name);
	/*CString name;
		string NAME;*/
		//string *my_name=&NAME;
	 //string NAME;
		//string *my_name=&name;
	//my_name = reinterpret_cast<string*>(&name);

	

	const char* theName = name.c_str();
	CString cName(theName);


	


	if (ar.IsStoring())
	{

		
		ar << cName;
		ar << age;
		ar << salary;
		ar << time_contract;

	}
	else
	{
	
		ar >> cName;

		char tempName[100];

		sprintf_s(tempName, "%S", cName);
		std::stringstream inputString(tempName);
		string s;
		inputString >> name;

		ar >> age;
		ar >> salary;
		ar >> time_contract;
	}
}
