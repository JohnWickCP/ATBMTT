#include <iostream>
#include <string>
using namespace std;

string encryptCaesar(string text, int key) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (islower(c)) {
            c = (c - 'a' + key) % 26 + 'a';
        }
        else if (isupper(c)) {
            c = (c - 'A' + key) % 26 + 'A';
        }
        result += c;
    }
    return result;
}

int main() {
    string text = "LOVEISBLINDLOVEI";
    int key = 21;

    string encryptedText = encryptCaesar(text, key);
    cout << "En: " << encryptedText << endl;

    return 0;
}
