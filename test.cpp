#include <iostream>
#include <string>

using namespace std;

class Human {
   public:
    int age;
    int weight;
    string name;

    void Print() {
        cout << "Name: '" << name << "', Age: " << age << ", Weight: " << weight << endl;
    }
};

class Point {
   public:
    int x;
    int y;
    int z;
};

int main() {
    Human firstHuman;

    firstHuman.age = 25;
    firstHuman.weight = 70;
    firstHuman.name = "Ivan";

    firstHuman.Print();
    
    return 0;
}