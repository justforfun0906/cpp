#include <iostream>
using namespace std;
class Zoo {
public:
  int animalCount;
  Zoo() { animalCount = 0; }
  void born(string name) {//called by animals
    animalCount += 1;
    cout << "New " << name << " Born!\n";
    cnt();
  }
  void dead(string name) {//called by animals
    animalCount -= 1;
    cout << "One " + name + " Dead!\n";
    cnt();
  }
  void cnt() { cout << "Now Zoo have " << (animalCount) << " animals!\n"; }
};
class Animal {
public:
  Zoo *belong;
  string species;
  int legs;
  Animal(Zoo *zoo, string name); // TODO
  virtual void barking() = 0;
  virtual void throwBall() = 0;
  virtual void carton() = 0;
  void printSpecies() { cout << this->species << "\n"; }
  virtual ~Animal() {
    cout<<"deleting "<<species<<endl;
    if (this->belong != NULL)
      this->belong->dead(this->species);
  }; // Please Ensure that you know what this destructure is.
};
Animal::Animal(Zoo *zoo, string name){
  zoo->born(name);
  this->species = name;
  this->belong = zoo;
}
class Dog : public virtual Animal {
public:
  Dog(Zoo *zoo); // TODO
  void barking() { cout << "woof!\n"; }
  void throwBall() { cout << "it looks happy!\n"; }
  virtual void carton(){};
  ~Dog(); // TODO
};
Dog::Dog(Zoo *zoo):Animal(zoo, "Dog"){
  //call the animal construction function
  this->legs = 4;
}
Dog::~Dog(){
  //call the destruction function of the base class
  //this->belong->dead("Dog");
}
class Cat : public virtual Animal {
public:
  Cat(Zoo *zoo); // TODO
  void barking() { cout << "meow!\n"; }
  void carton() { cout << "it looks so happy!\n"; }
  virtual void throwBall(){};
  ~Cat(); // TODO
};
Cat::Cat(Zoo *zoo):Animal(zoo, "Cat"){
  //call the animal construction function
  this->legs = 4;
}
Cat::~Cat(){
  //this->belong->dead("Cat");
}
class Caog : public Dog, public Cat {
public:
  Caog(Zoo *zoo);         // TODO
  virtual void barking(); // TODO
  void carton();          // TODO
  void throwBall();       // TODO
  ~Caog();                // TODO
};
Caog::Caog(Zoo *zoo):Dog(zoo),Cat(zoo),Animal(zoo, "Caog"){
  //only contain one animal base class
}
Caog::~Caog(){
  //call the destruction function of the base class
  //this->belong->dead("Caog");
}
void Caog::barking(){
  cout << "woof!woof!meow!\n";
}
void Caog::carton(){
  cout <<"it looks so happy!\n";
}
void Caog::throwBall(){
  cout << "it looks happy!\n";
}