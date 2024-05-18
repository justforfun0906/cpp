#include "11447.hpp"
#include <iostream>
#include <string>
std::ostream &oj::operator<<(std::ostream &os,const std::map<int,String> &ma){
    for(auto it:ma){
        os<<it.second<<' ';
    }
    return os;
}
//String != string, it's a struct declared in hpp
void oj::insert(std::map<int,String> &ma,int key,const std::string &str){
    if(ma.count(key)){
        auto it = ma.find(key);
        it->second.str = str+it->second.str;
    }
}
void oj::output(const std::map<int,String> &ma,int begin,int end){
    for(auto it:ma){
        if(it.first >=begin && it.first<=end){
            std::cout<<it.second.str<<' ';
        }
        std::cout<<'\n';
    }
}
void oj::erase(std::map<int,String> &ma,int begin,int end){
    for(auto it:ma){
        if(it.first >= begin && it.first<=end){
            ma.erase(it.first);
        }
    }
}