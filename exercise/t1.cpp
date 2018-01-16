#include <iostream>
#include <string>
using namespace std;

int computeDiffTreeNum(string& str1, string& str2) {
    int count = 1;
    if (str1.length() <= 1) return 1;
    for (int i = 1; i < str1.length(); i++) {
        size_t posInStr2 = str2.find(str1[i]);
        if (str1[i - 1] == str2[posInStr2 + 1]) count *= 2;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    using namespace std;
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << computeDiffTreeNum(str1, str2);
    return 0;
}