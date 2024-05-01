#include <string>

class Person {
protected:
	std::string name;
	int age;
public:
	void Setname(std::string Name) { name = Name; }
	void Setage(int Age) { age = Age; }

	std::string Getname() { return name; }
	int Getage() { return age; }

	~Person() {}
};
