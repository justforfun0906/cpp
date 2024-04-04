#include<bits/stdc++.h>
using namespace std;

enum Gender {
    MALE,
    FEMALE
};

const string table[2] = {"MALE", "FEMALE"};

class Person {
    public:
        string name;
        int age;
        Gender gender;
        string personality;
        Person *parentA, *parentB, *mate, *child;

        Person();
        void describe(string* arr, int now, int len);
        Person* getRelative (string* arr, int now, int len);
        string info();
};
void Person::describe(string* arr, int now, int len) {
    Person* end = this->getRelative(arr, 0, len - 2);
    if(arr[len-2]=="Name"){
        end->name = arr[len-1];
    }
    if(arr[len-2]=="Age"){
        end->age = stoi(arr[len-1]);
    }
    if(arr[len-2]=="Personality"){
        end->personality += " "+arr[len-1];
    }
    if(arr[len-2]=="Gender"){
        if(arr[len-1] == "MALE"){
            end -> gender = MALE;
        }else{
            end -> gender = FEMALE;
        }
    }
    return;
}
Person* Person::getRelative(string* arr, int now, int len) {
    if (now == len) return this;
    if (arr[now] == "ParentA"){
        if(this->parentA == nullptr){
            this->parentA = new Person();
            this->parentA->child = this;
            this->parentA->mate = this->parentB;
            if(this->parentB != nullptr){
                this->parentB->mate = this->parentA;
            }
        }
        return this->parentA->getRelative(arr, now + 1, len);
    }
    if (arr[now] == "ParentB"){
        if(this->parentB == nullptr){
            this->parentB = new Person();
            this->parentB->child = this;
            this->parentB->mate = this->parentA;
            if(this->parentA != nullptr){
                this->parentA->mate = this->parentB;
            }
        }
        return this->parentB->getRelative(arr, now + 1, len);
    }
    if (arr[now] == "Mate"){
        if(this->mate == nullptr){
            this->mate = new Person();
            this->mate->mate = this;
            this->mate->child = this->child;
            if(this->child != nullptr){
                if(this->child->parentB==nullptr)this->child->parentB = this->mate;
                else this->child->parentA = this->mate;
            }
        }
        return this->mate->getRelative(arr, now + 1, len);
    }
    if (arr[now] == "Child"){
        if(this->child == nullptr){
            this->child = new Person();
            this->child->parentA = this;
            this->child->parentB = this->mate;
            if(this->mate != nullptr){
                this->mate->child = this->child;
            }
        }
        return this->child->getRelative(arr, now + 1, len);
    }
    return nullptr;
}
Person::Person(){
    this->name = "";
    this->age = 0;
    this->gender = MALE;
    this->personality = "";
    this->parentA = nullptr;
    this->parentB= nullptr;
    this->mate = nullptr;
    this->child = nullptr;
}
string Person::info() {
    return 
        "Name:" + this->name + ",\n" + 
        "Age:" + to_string(this->age) + ",\n" +
        "Gender:" + table[this->gender] + ",\n" +
        "Personality:" + this->personality + "\n\n";
}