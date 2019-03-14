#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert1(string s, int numRows) {
    int idx = 0, num = s.size();
    int numCols = 0;
    string res = "";
    // char resArr[1000][1000] = { ' ' };       // something weird...
    char resArr[1000][1000] = { 0 };

    while (idx < num) {
        for (int row = 0; row < numRows && idx < num; ++row) {
            // cout << row << " " << numCols << " " << s[idx] << endl;
            resArr[row][numCols] = s[idx++];
        }
        numCols++;

        int tmpCols = numCols;
        for (int col = 0; col < numRows - 2; ++col) {
            for (int row = 0; row < numRows; ++row) {
                if (row == numRows - 2 - col && idx < num) {
                    // cout << row << " " << col + tmpCols <<
                    //    " " << s[idx] << endl;
                    resArr[row][col + tmpCols] = s[idx++];
                }
            }
            numCols++;
        }
    }

    // cout << numRows << " " << numCols << endl;
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            // if (resArr[row][col] != ' ') {       // something weird...
            if (resArr[row][col]) {
                res += resArr[row][col];
            }

            // cout << resArr[row][col];
        }
        // cout << endl;
    }

    return res;
}

string convert(string s, int numRows) {
    if (numRows == 1) return s;

    vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }

    string ret;
    for (string row : rows) ret += row;
    return ret;
}


int main() {
    string s = "PAYPALISHIRING";
    // cin >> s;

    int rows = 3;
    // cin >> rows;

    string res = convert(s, rows);
    cout << res << endl;

    return 0;
}
