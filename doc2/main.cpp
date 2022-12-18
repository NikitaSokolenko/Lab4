#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
using namespace std;
// проверка, чтобы строка состояла только из прописных букв
int main(int argc, char **argv)
{
	string key;
	string text;
	unsigned op;
	cout<<"Cipher ready. Input key: ";
	cin>>key;
	modAlphaCipher cipher(key);
	cout<<"Key loaded\n";
	do {
		cout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
		cin>>op;
		if (op > 2) {
			cout<<"Illegal operation\n";
		} else if (op >0) {
			cout<<"Cipher ready. Input text: ";
			cin>>text;
			if (op==1) {
				cout<<"Encrypted text: "<<cipher.encrypt(text)<<endl;
			} else {
				cout<<"Decrypted text: "<<cipher.decrypt(text)<<endl;
			}
		}
	} while (op!=0);
	return 0;
}
