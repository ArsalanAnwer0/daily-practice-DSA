#include <iostream>
#include <string>
using namespace std;

class Hero {
private:
    string name;
    int health;

public:
    // Constructor to initialize name and health
    Hero(string heroName, int heroHealth) {
        name = heroName;
        health = heroHealth;
    }

    // Overloading the << operator to print Hero details
    friend ostream& operator<<(ostream& os, const Hero& hero) {
        os << "Hero Name: " << hero.name << ", Health: " << hero.health;
        return os;
    }
};

int main() {
    // Creating two Hero objects
    Hero hero1("Thor", 100);
    Hero hero2("Hulk", 120);

    // Printing Hero objects
    cout << hero1 << endl;
    cout << hero2 << endl;

    return 0;
}
