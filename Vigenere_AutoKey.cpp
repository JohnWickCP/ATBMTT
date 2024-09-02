#include <iostream>
#include <string>

using namespace std;
// Hàm để cộng Key vs planitext
string generateAutoKey(string plaintext, string key) {
    string autoKey = key + plaintext;  
    return autoKey.substr(0, plaintext.length()); // Xóa bớt string để bằng vs length của plaintext
}

string vigenereAutoKeyEncrypt(string plaintext, string key) {
    string ciphertext;
    string autoKey = generateAutoKey(plaintext, key); 

    for (size_t i = 0; i < plaintext.length(); i++) {
        char plainChar = plaintext[i];
        char keyChar = autoKey[i];

        char encryptedChar = ((plainChar - 'A') + (keyChar - 'A')) % 26 + 'A';
        ciphertext += encryptedChar;
    }
    return ciphertext;
}

int main() {
    string plaintext = "MONEYISAGOODSER";
    string key = "EVERYONE";
    
    string ciphertext = vigenereAutoKeyEncrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
