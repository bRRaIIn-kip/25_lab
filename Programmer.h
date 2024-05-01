#include <iostream>
#include "Person.h"

class Programmer : public Person
{
protected:
	float wages;
	std::string post;
public:
	void SetPOST(std::string Post) { post = Post; }
	void SetWAGES(float Wages) { wages = Wages; }

	std::string GetPOST() { return post; }
	float GetWAGES() { return wages; }

	Programmer(std::string Name, int Age, float Wages, std::string Post) : wages(Wages), post(Post) {name = Name;age = Age;}
	Programmer(){}


	virtual void Print() const {std::cout << "Name: " << name << "\tAge: " << age << "\tWages: " << wages << "\tPost: " << post << std::endl;}
	~Programmer() {}
};

