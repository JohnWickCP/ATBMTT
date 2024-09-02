#include <iostream>
#include <string>

using namespace std;

string generateKey(string plaintext, string key) {

    string repeatedKey = key;
    while (repeatedKey.length() < plaintext.length()) {
        repeatedKey += key; // Lặp lại khóa
    }
    return repeatedKey.substr(0, plaintext.length());
}

string vigenereEncrypt(string plaintext, string key) {

    string ciphertext;
    for (size_t i = 0; i < plaintext.length(); i++) {

        char plainChar = plaintext[i];
        char keyChar = key[i];

        char encryptedChar = ((plainChar - 'A') + (keyChar - 'A')) % 26 + 'A';
        ciphertext += encryptedChar;
    }
    return ciphertext;
}

int main() {
    string plaintext = "MONEYISAGOODSER";
    string key = "EVERYONE";

    for (char &ch : plaintext) {
        ch = toupper(ch);
    }
    
    for (char &ch : key) {
        ch = toupper(ch);
    }

    string repeatedKey = generateKey(plaintext, key);
    string ciphertext = vigenereEncrypt(plaintext, repeatedKey);

    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
