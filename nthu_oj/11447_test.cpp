#include<bits/stdc++.h>
#include "11447.hpp"
using namespace std;
using namespace oj;
namespace oj
{
	String::String(const std::string &str_)
		:str(str_){}

	String::String(const String &rhs)
		:str(rhs.str){}

	String& String::operator=(const String &rhs)
	{
		str=rhs.str;
		return *this;
	}

	std::ostream& operator<<(std::ostream &os,const String &str)
	{
		return os<<str.str;
	}
}
int main(){
    map<int,String> ma;
    insert(ma,1,"a");
    cout<<ma.at(1)<<endl;
    insert(ma,2,"b");
    insert(ma,3,"c");
    output(ma,1,3);
}