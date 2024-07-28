#include <iostream>
#include <string>
using namespace std;

class Animal
{private:
	string name;
	int id;
	string habitat;
public:
	Animal(string n = "", int i = 0, string h = "") { name = n;id = i;habitat = h; }
	void displayDetails()
	{
		cout << "\nAnimal Details"<<endl;
			cout<<"Animal Name : "<<name<< ",\tAnimal ID : " << id<< "\tAnimal Habitat : " << habitat;
	}
	void modifyDetails()
	{
		cout << "Enter Animal Name : ";
		cin >> name;
		cout << "Enter Animal ID : ";
		cin >> id;
		cout << "Enter Animal Habitat : ";
		cin >> habitat;
	}
};
class Mammal :public Animal
{
	string dietType;
public:
	Mammal(string n="", int i=0, string h="", string dT="") :Animal(n, i, h)
	{
		dietType = dT;
	}
	void displayDetails()
	{
		Animal::displayDetails();
		cout << "\tAnimal Diet Type : " << dietType;
	}
	void modifyDetails()
	{
		Animal::modifyDetails();
		cout << "Enter Diet Type (Herbivore/Carnivore/omnivore) : ";
		cin >> dietType;
	}
};
class Bird : public Animal
{
	string wingSpan;
public:
	Bird(string n = "", int i = 0, string h = "", string wS="") :Animal(n, i, h)
	{
		wingSpan = wS;
	}
	void displayDetails()
	{
		Animal::displayDetails();
		cout << "\tAnimal Wing Span : " << wingSpan<<" meter";
	}
	void modifyDetails()
	{
		Animal::modifyDetails();
		cout << "Enter Wing Span in meters :";
		cin >> wingSpan;
	}
};
int main()
{
	Mammal mammal;
	Bird bird;
	while (true)
	{
		char animal_type;
		cout << "Add new Animal (Mammal/Bird)? (M/B): ";
		cin >> animal_type;
		if (tolower(animal_type) != 'm' && tolower(animal_type) != 'b')
		{
			cout << "Invalid Input! Enter M for Mammal and B for Bird\n";
			continue;

		}
		else if (tolower(animal_type) == 'm')
		{
			mammal.modifyDetails();
		}
		else if (tolower(animal_type) == 'b')
		{
			bird.modifyDetails();
		}
		char add_new;
		cout << "Add new Animal (Yes/No)? (Y/N): ";
		cin >> add_new;
		if (tolower(add_new) != 'y')
			break;
	}

	

	return 0;
}