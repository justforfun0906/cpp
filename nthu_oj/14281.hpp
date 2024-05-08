#ifndef _FUNC_H
#define _FUNC_H
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>  
using namespace std;

class Codec {
public:
    Codec(string s): encoded(false), code_str(s) { }
    virtual ~Codec() { } // virtual destructor; do nothing
    virtual void encode() = 0;
    virtual void decode() = 0;
    void show(ostream& os) const {
        os << code_str;
    }
    bool is_encoded() const { return encoded; }
protected:
    bool encoded;
    string code_str;
};
class DummyCodec: public Codec {
public:
    DummyCodec(string s): Codec(s) { }
    void encode() override {
        encoded = true;
    }
    void decode() override {
        encoded = false;
    }
};
class RleCodec: public Codec {
public:
    RleCodec(string s): Codec(s) { }
    void encode() override {
        stringstream ss;
        int cnt = 0;
        char prev = 0;
        for(auto c: code_str){
            if(c!=prev){
                if(cnt>0){
                    if(cnt>2){
                        ss << cnt << prev;
                    } else if(cnt==2){
                        ss << prev << prev;
                    } else {
                        ss << prev;
                    }
                }
                prev = c;
                cnt = 1;
            }else{
                cnt++;
            }
        }
        if(cnt>0){
            if(cnt>2){
                ss << cnt << prev;
            } else if(cnt==2){
                ss << prev << prev;
            } else {
                ss << prev;
            }
        }
        encoded = true;
        code_str = ss.str();
    }
    void decode() override {
        string res;
        string cnt = "";
        for(int i=0;i<code_str.size();i++){
            if(isdigit(code_str[i])){
                cnt += code_str[i];
            }else{
                if(!cnt.empty()){
                    int num = stoi(cnt);
                    for(int j=0;j<num;j++){
                        res += code_str[i];
                    }
                    cnt.clear();
                }else{
                    res += code_str[i];
                }
            }
        }
        code_str = res;
        encoded = false;
    }
};
Codec* getCodec(const string& type, const string& is){
    if (type == "Dummy") {
        return new DummyCodec(is);
    } else if (type == "RLE") {
        return new RleCodec(is);
    }
    return nullptr;
}

#endif
