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
    if (arr[now] == "ParentA"){
        if(this->parentA == nullptr){
            this->parentA = new Person();
            this->parentA->child = this;
            if(this->parentB != nullptr){
                this->parentA->mate = this->parentB;
                this->parentB->mate = this->parentA;
            }
        }
        this->parentA->describe(arr, now + 1, len);
    }
    if (arr[now] == "ParentB"){
        if(this->parentB == nullptr){
            this->parentB = new Person();
            this->parentB->child = this;
            if(this->parentA != nullptr){
                this->parentA->mate = this->parentB;
                this->parentB->mate = this->parentA;
            }
        }
        this->parentB->describe(arr, now + 1, len);
    }
    if (arr[now] == "Mate"){
        if(this->mate == nullptr){
            this->mate = new Person();
            this->mate->mate = this;
            this->mate->child = this->child;
            if(this->child!=nullptr){
                if(this->child->parentB == nullptr)this->child->parentB = this->mate;
                else this->child->parentA = this->mate;
            }
        }
        this->mate->describe(arr, now + 1, len);
    }
    if (arr[now] == "Child"){
        if(this->child == nullptr){
            this->child = new Person();
            this->child->parentA = this;
            if(this->mate != nullptr){
                this->child->parentB = this->mate;
            }
        }
        this->child->describe(arr, now + 1, len);
    }
    else{
        if(arr[now]=="Name"){
            this->name = arr[now + 1];
        }
        if(arr[now]=="Age"){
            this->age = stoi(arr[now + 1]);
        }
        if(arr[now]=="Personality"){
            this->personality += " "+arr[now + 1];
        }
        if(arr[now]=="Gender"){
            if(arr[now + 1] == "MALE"){
                this->gender = MALE;
            }else{
                this -> gender = FEMALE;
            }
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
            if(this->parentB != nullptr){
                this->parentA->mate = this->parentB;
                this->parentB->mate = this->parentA;
            }
        }
        return this->parentA->getRelative(arr, now + 1, len);
    }
    if (arr[now] == "ParentB"){
        if(this->parentB == nullptr){
            this->parentB = new Person();
            this->parentB->child = this;
            if(this->parentA != nullptr){
                this->parentA->mate = this->parentB;
                this->parentB->mate = this->parentA;
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
            if(this->mate != nullptr&&this->child->parentB == nullptr){
                this->child->parentB = this->mate;
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