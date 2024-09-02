#include <iostream>
#include <string>

using namespace std;

// Hàm mã hóa văn bản sử dụng bảng mã hóa
string simpleSubstitutionEncrypt(const string &plaintext, const string &cipherAlphabet) {
    string ciphertext = "";
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // Bảng chữ cái chuẩn

    for (char c : plaintext) {
        // Tìm vị trí của ký tự trong bảng chữ cái gốc
        size_t index = alphabet.find(c);
        // Nếu ký tự nằm trong bảng chữ cái, mã hóa; nếu không, giữ nguyên
        if (index != string::npos) {
            // Thay thế bằng ký tự từ bảng mã hóa
            ciphertext += cipherAlphabet[index];
        } else {
            // Giữ nguyên ký tự không nằm trong bảng chữ cái
            ciphertext += c;
        }
    }

    return ciphertext;
}

int main() {
    string plaintext = "WHENINROMEDOASTH";
    string key= "HLXQPSVKMZYCDUEGJTNFBAIWOR";

    string ciphertext = simpleSubstitutionEncrypt(plaintext, key);

    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
