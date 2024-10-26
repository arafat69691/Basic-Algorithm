#include <bits/stdc++.h>

using namespace std;

string cleanCode(const string& code) {
    stringstream input(code);
    stringstream output;
    string line;
    bool inBlockComment = false;

    while (getline(input, line)) {
        // Remove block comments
        if (inBlockComment) {
            size_t endBlock = line.find("*/");
            if (endBlock != string::npos) {
                line = line.substr(endBlock + 2);
                inBlockComment = false;
            } else {
                continue;
            }
        }

        // Remove single line comments
        size_t singleComment = line.find("//");
        if (singleComment != string::npos) {
            line = line.substr(0, singleComment);
        }

        // Check for start of block comment
        size_t startBlock = line.find("/*");
        if (startBlock != string::npos) {
            size_t endBlock = line.find("*/", startBlock + 2);
            if (endBlock != string::npos) {
                line = line.substr(0, startBlock) + line.substr(endBlock + 2);
            } else {
                line = line.substr(0, startBlock);
                inBlockComment = true;
            }
        }

        // Trim whitespace from the line
        line = regex_replace(line, regex("^\\s+|\\s+$"), "");

        // Skip empty lines
        if (!line.empty()) {
            output << line << endl;
        }
    }

    return output.str();
}

int main() {
    string code = R"(// I am a single comment and you must remove me :((
/*
I am a block comment and you must remove me
*/

#include<iostream>
using namespace std;

int main() {

int a, b;
cin >> a >> b; // Reading two variables from user (please remove me!! :( )
cout << a + b << endl;

// End of the program (remove me please :))
return 0;

})";

    string cleanedCode = cleanCode(code);
    cout << cleanedCode;

    return 0;
}
