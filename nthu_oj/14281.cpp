#include <iostream>
#include "14281.hpp"
using namespace std;
ostream& operator<<(ostream& os, Codec& data)
{
    data.show(os);
    return os;
}

void encode_decode(Codec & data)
{
    if (!data.is_encoded())
        data.encode();
    else
        data.decode();
}


int main()
{
    string input_string;
    cin >> input_string;

    Codec** CodecPtr = new Codec*[2];

    CodecPtr[0] = getCodec("Dummy",input_string);
    encode_decode(*CodecPtr[0]);
    cout << "Dummy encoding: ";
    cout << *CodecPtr[0] << endl;
    encode_decode(*CodecPtr[0]);
    cout << "Dummy decoding: ";
    cout << *CodecPtr[0] << endl;

    CodecPtr[1] = getCodec("RLE",input_string);
    encode_decode(*CodecPtr[1]);
    cout << "RLE encoding: ";
    cout << *CodecPtr[1] << endl;
    encode_decode(*CodecPtr[1]);
    cout << "RLE decoding: ";
    cout << *CodecPtr[1] << endl;

    delete CodecPtr[0];
    delete CodecPtr[1];
    delete [] CodecPtr;
}
