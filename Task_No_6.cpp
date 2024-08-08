#include <iostream>
#include <string>

using namespace std;

class Animal
{
private:
    string name;
    string id;
    string habitat;

public:
    Animal(string n = "", string i = "", string h = "")
    {
        name = n;
        id = i;
        habitat = h;
    }
    string getId()
    {
        return id;
    }
    void displayDetails()
    {
        cout << "\nAnimal Name : " << name << ",\nAnimal ID : " << id << "\nAnimal Habitat : " << habitat;
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
    void modifyDetailsById(string targetID)
    {
        if (getId() == targetID)
        {
            cout << "Enter Animal Name : ";
            cin >> name;
            cout << "Enter Animal ID : ";
            cin >> id;
            cout << "Enter Animal Habitat : ";
            cin >> habitat;
        }
        else
            cout << "Animal with " << targetID << " is not found.";
    }
};
class Mammal : public Animal
{
    string dietType;

public:
    Mammal(string n = "", string i = "", string h = "", string dT = "") : Animal(n, i, h)
    {
        dietType = dT;
    }
    void displayDetails()
    {
        cout << "\nMammal Details";
        Animal::displayDetails();
        cout << "\nAnimal Diet Type : " << dietType;
    }
    void modifyDetails()
    {
        Animal::modifyDetails();
        cout << "Enter Diet Type (Herbivore/Carnivore/omnivore) : ";
        cin >> dietType;
    }
    void modifyDetailsById(string targetId)
    {
        if (getId() == targetId)
        {
            Animal::modifyDetailsById(targetId);
            cout << "Enter Diet Type (Herbivore/Carnivore/Omnivore) : ";
            cin >> dietType;
            cout << "Details modified successfully!" << endl;
        }
        else
        {
            cout << "Mammal with ID " << targetId << " not found." << endl;
        }
    }
};
class Bird : public Animal
{
    string wingSpan;

public:
    Bird(string n = "", string i = "", string h = "", string wS = "") : Animal(n, i, h)
    {
        wingSpan = wS;
    }
    void displayDetails()
    {
        cout << "\nBird Details";
        Animal::displayDetails();
        cout << "\nAnimal Wing Span : " << wingSpan << " meter";
    }
    void modifyDetails()
    {
        Animal::modifyDetails();
        cout << "Enter Wing Span in meters :";
        cin >> wingSpan;
    }
    void modifyDetailsById(string targetId)
    {
        if (getId() == targetId)
        {
            Animal::modifyDetailsById(targetId);
            cout << "Enter Wing Span in meters :";
            cin >> wingSpan;
            cout << "Details modified successfully!" << endl;
        }
        else
        {
            cout << "Bird with ID " << targetId << " not found." << endl;
        }
    }
};
int main()
{

    const int AllAnimal = 100;
    Mammal mammal[AllAnimal];
    Bird bird[AllAnimal];

    int newMammal = 0;
    int newBird = 0;
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
            if (newMammal < AllAnimal)
            {
                mammal[newMammal].modifyDetails();
                newMammal++;
            }
        }
        else if (tolower(animal_type) == 'b')
        {
            if (newBird < AllAnimal)
                bird[newBird].modifyDetails();
            newBird++;
        }
        char add_new;
        cout << "Add new Animal (Yes/No)? (Y/N): ";
        cin >> add_new;
        if (tolower(add_new) != 'y')
            break;
    }

    while (true)
    {
        char modifyChoice;
        cout << "\nModify animal details? (Y/N): ";
        cin >> modifyChoice;
        if (tolower(modifyChoice) != 'y')
        {
            break;
        }

        string targetId;
        cout << "Enter the ID of the animal to modify: ";
        cin >> targetId;

        for (int i = 0; i < newMammal; i++)
        {
            mammal[i].modifyDetailsById(targetId);
        }

        for (int i = 0; i < newBird; i++)
        {
            bird[i].modifyDetailsById(targetId);
        }
    }

    for (int i = 0; i < newMammal; i++)
    {
        mammal[i].displayDetails();
    }
    cout << "\n";
    for (int i = 0; i < newBird; i++)
    {
        bird[i].displayDetails();
    }
    return 0;
}
