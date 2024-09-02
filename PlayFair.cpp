#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Hàm tạo ma trận 5x5 từ khóa
vector<vector<char>> createMatrix(const string &key) {
    vector<vector<char>> matrix(5, vector<char>(5)); // Tạo ma trận 5x5
    string processedKey = "";
    bool alphabet[26] = {false}; // Đánh dấu các chữ cái đã xuất hiện
    alphabet['J' - 'A'] = true;  // Gộp J với I

    // Điền khóa vào ma trận
    for (char c : key) {
        c = toupper(c);
        if (c == 'J') c = 'I'; // Thay J bằng I
        if (!alphabet[c - 'A']) {
            processedKey += c;
            alphabet[c - 'A'] = true;
        }
    }

    // Điền các chữ cái còn lại vào ma trận
    for (char c = 'A'; c <= 'Z'; c++) {
        if (!alphabet[c - 'A']) {
            processedKey += c;
        }
    }

    // Chuyển từ processedKey thành ma trận 5x5
    int k = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = processedKey[k++];
        }
    }

    return matrix;
}

// Hàm tìm vị trí của ký tự trong ma trận
pair<int, int> findPosition(const vector<vector<char>> &matrix, char c) {
    if (c == 'J') c = 'I'; // Gộp J với I
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == c) {
                return {i, j};
            }
        }
    }
    return {-1, -1}; // Không tìm thấy (lý thuyết là không bao giờ xảy ra)
}

// Hàm xử lý plaintext thành các cặp ký tự
string processPlaintext(const string &plaintext) {
    string processedText = "";
    for (char c : plaintext) {
        if (isalpha(c)) {
            processedText += toupper(c);
        }
    }

    // Xử lý để tạo các cặp ký tự
    string pairs = "";
    for (size_t i = 0; i < processedText.length(); i++) {
        pairs += processedText[i];
        if (i + 1 < processedText.length() && processedText[i] == processedText[i + 1]) {
            pairs += 'X'; // Chèn X nếu hai ký tự giống nhau
        } else if (i + 1 < processedText.length()) {
            pairs += processedText[++i];
        }
    }
    
    // Nếu số ký tự lẻ, thêm X vào cuối
    if (pairs.length() % 2 != 0) {
        pairs += 'X';
    }

    return pairs;
}

// Hàm mã hóa với thuật toán Playfair
string playfairEncrypt(const string &plaintext, const vector<vector<char>> &matrix) {
    string ciphertext = "";
    string pairs = processPlaintext(plaintext);

    for (size_t i = 0; i < pairs.length(); i += 2) {
        char first = pairs[i];
        char second = pairs[i + 1];
        pair<int, int> pos1 = findPosition(matrix, first);
        pair<int, int> pos2 = findPosition(matrix, second);

        // Cùng hàng
        if (pos1.first == pos2.first) {
            ciphertext += matrix[pos1.first][(pos1.second + 1) % 5];
            ciphertext += matrix[pos2.first][(pos2.second + 1) % 5];
        }
        // Cùng cột
        else if (pos1.second == pos2.second) {
            ciphertext += matrix[(pos1.first + 1) % 5][pos1.second];
            ciphertext += matrix[(pos2.first + 1) % 5][pos2.second];
        }
        // Khác hàng, khác cột
        else {
            ciphertext += matrix[pos1.first][pos2.second];
            ciphertext += matrix[pos2.first][pos1.second];
        }
    }

    return ciphertext;
}

int main() {
    string plaintext = "BEAUTYISINTHEE";
    string key = "ITSASMA";

    // Tạo ma trận Playfair từ khóa
    vector<vector<char>> matrix = createMatrix(key);

    // Mã hóa plaintext bằng thuật toán Playfair
    string ciphertext = playfairEncrypt(plaintext, matrix);

    // In kết quả
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
