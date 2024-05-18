#include "11447.hpp"
#include <bits/stdc++.h>
std::ostream &oj::operator<<(std::ostream &os,const std::map<int,String> &ma){
    for(auto it:ma){
        os<<it.second<<' ';
    }
    return os;
}
//String != string, it's a struct declared in hpp
void oj::insert(std::map<int,String> &ma,int key,const std::string &str){
    //if key exists, append str to the front of the original string
    if(ma.count(key)){
        auto it = ma.find(key);
        it->second.str = str+it->second.str;
    }else{
        //
        ma.insert({key,String(str)});
    }
}
void oj::output(const std::map<int,String> &ma,int begin,int end){
    for(int i=begin;i<=end;i++){
        if(ma.count(i)){
            std::cout<<ma.at(i)<<' ';
        }
    }
}
void oj::erase(std::map<int,String> &ma,int begin,int end){
    for(int i=begin;i<=end;i++){
        ma.erase(i);
    }
}