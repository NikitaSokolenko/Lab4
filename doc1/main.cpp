#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <codecvt>
#include <cstdlib>
#include <locale>
using namespace std;
int main(int argc, char **argv)
{
	locale loc("ru_RU.UTF-8");
	wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
	wstring wres;
	string res;
	string key;
	string text;
	unsigned op;
	cout<<"Cipher ready. Input key: ";
	cin>>key;
	wstring wkey = codec.from_bytes(key);
	cout<<"Key loaded\n";
	modAlphaCipher cipher(wkey);
	do {
		cout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
		cin>>op;
		if (op > 2) {
			cout<<"Illegal operation\n";
		} else if (op >0) {
			cout<<"Cipher ready. Input text: ";
			cin>>text;
			wstring wtext = codec.from_bytes(text);

			if (op==1) {
				try {
					wres = cipher.encrypt(wtext);
					res = codec.to_bytes(wres);
					cout<<"Encrypted text: "<<res<<endl;
				} catch (const cipher_error & e) {
					cerr<<"Error: "<<e.what()<<endl;
				}
			} else {
				try {
					wres = cipher.decrypt(wtext);
					res = codec.to_bytes(wres);
					cout<<"Decrypted text: "<< res <<endl;
				} catch (const cipher_error & e) {
					cerr<<"Error: "<<e.what()<<endl;
				}
			}
		}
	} while (op!=0);
	return 0;
}
