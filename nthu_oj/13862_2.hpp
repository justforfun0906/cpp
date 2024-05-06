#include<iostream>
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

        Person() {
            this->name = "";
            this->age = 0;
            this->gender = MALE;
            this->personality = "";
            this->parentA = nullptr;
            this->parentB= nullptr;
            this->mate = nullptr;
            this->child = nullptr;
        }
        void describe(string* arr, int now, int len);
        Person* getRelative (string* arr, int now, int len);
        string info() {
            return 
                "Name:" + this->name + ",\n" + 
                "Age:" + to_string(this->age) + ",\n" +
                "Gender:" + table[this->gender] + ",\n" +
                "Personality:" + this->personality + "\n\n";
        };
};
void Person::describe(string* arr, int now, int len){
    Person* target = getRelative(arr, 0, len-2);
    if(arr[len-2]=="Name"){
        target->name = arr[len-1];
    }else if(arr[len-2]=="Age"){
        target->age = stoi(arr[len-1]);
    }else if(arr[len-2]=="Personality"){
        target->personality += target->personality=="" ? arr[len-1] : " " + arr[len-1];
    }else if(arr[len-2]=="Gender"){
        target->gender = arr[len-1]=="MALE"?MALE:FEMALE;
    }
}
//arr is a array of string.
Person* Person::getRelative(string* arr, int now, int len){
    if(now==len) return this;
    if(arr[now]=="ParentA"){
        if(this->parentA==nullptr){
            this->parentA = new Person();
            this->parentA->child = this;
            //new person's pointer are default to nullptr
            if(this->parentB!=nullptr){//not likely to happen
                this->parentA->mate = this->parentB;
                this->parentB->mate = this->parentA;
            }
        }
        return this->parentA->getRelative(arr, now+1, len);
    }else if(arr[now]=="ParentB"){
        if(this->parentB==nullptr){
            this->parentB = new Person();
            this->parentB->child = this;
            if(this->parentA!=nullptr){
                this->parentB->mate = this->parentA;
                this->parentA->mate = this->parentB;
            }
        }
        return this->parentB->getRelative(arr, now+1, len);
    }else if(arr[now]=="Mate"){
        if(this->mate==nullptr){
            this->mate = new Person();
            this->mate->mate = this;
            this->mate->child = this->child;
            if(this->child!=nullptr){
                if(this->child->parentB==nullptr){
                    //this->child has no parentB but a child must have one parent
                    //->it has parentA but no parentB
                    this->child->parentB = this->mate;
                }else{//this-> child has parentB but no parentA
                    //FIXME: really important case ==
                    this->child->parentA = this->mate;
                }
            }
        }
        return this->mate->getRelative(arr, now+1, len);
    }else if(arr[now]=="Child"){
        if(this->child == nullptr){
            this->child = new Person();
            this->child->parentA = this;
            this->child->parentB = this->mate;
            //guarantee by the problem description
            if(this->mate!=nullptr){
                this->mate->child = this->child;
            }
        }
        return this->child->getRelative(arr, now+1, len);
    }
}
