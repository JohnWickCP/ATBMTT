#include <iostream>
#include <string>
using namespace std;

//test
string encryptCaesar(string text, int key) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        // Mã hóa chữ thường
        if (islower(c)) {
            c = (c - 'a' + key) % 26 + 'a';
        }
        // Mã hóa chữ hoa
        else if (isupper(c)) {
            c = (c - 'A' + key) % 26 + 'A';
        }
        result += c;
    }
    return result;
}

// Hàm giải mã Caesar
string decryptCaesar(string text, int key) {
    return encryptCaesar(text, 26 - key); 
}
int main() {
    string text;
    int key;

    // Nhập chuỗi cần mã hóa hoặc giải mã
    cout << "Nhap text: ";
    getline(cin, text);

    // Nhập giá trị key
    cout << "Nhap key: ";
    cin >> key;

    // Mã hóa văn bản
    string encryptedText = encryptCaesar(text, key);
    cout << "En: " << encryptedText << endl;

    // Giải mã văn bản
    string decryptedText = decryptCaesar(encryptedText, key);
    cout << "De: " << decryptedText << endl;

    return 0;
}
