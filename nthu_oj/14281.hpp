#ifndef _FUNC_H
#define _FUNC_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Codec {
public:
    Codec(string s): encoded{false}, code_str{s} { }
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
    DummyCodec(string is): Codec(is){ };
    virtual ~DummyCodec() { }
    virtual void encode() override{
        encoded = true;
    }
    void decode() override{
        encoded = false;
    }
};
class RleCodec: public Codec {
    RleCodec(string is): Codec(is){ };
};
Codec* getCodec(const string& type, const string& is){//is = input string
    if (type == "Dummy") {
        return new DummyCodec(is);
    } else if (type == "RLE") {
        return new RleCodec(is);
    }
    return nullptr;
}

#endif
