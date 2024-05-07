#ifndef _FUNC_H
#define _FUNC_H
#include <iostream>
#include <string>
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

};
class RleCodec: public Codec {

};
Codec* getCodec(const string& type, const string& is);

#endif
