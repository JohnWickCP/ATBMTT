#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Hàm mã hóa văn bản sử dụng mã hóa hoán vị
string columnarTranspositionEncrypt(string plaintext, int key) {
    // Tạo một bảng 2D với số cột bằng key
    vector<vector<char>> table(key);
    
    // Điền ký tự vào các cột của bảng
    for (size_t i = 0; i < plaintext.length(); ++i) {
        table[i % key].push_back(plaintext[i]);
    }

    // Đọc bảng theo từng cột để tạo chuỗi mã hóa
    string ciphertext;
    for (int col = 0; col < key; ++col) {
        for (char c : table[col]) {
            ciphertext += c;
        }
    }

    return ciphertext;
}

int main() {
    string plaintext = "WHENINROMEDOASTHER";
    int key = 5;

    string ciphertext = columnarTranspositionEncrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
