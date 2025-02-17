class Solution {
public:
    string longestNiceSubstring(string s) {
        int maxLength = 0;
        string longestNiceStr = "";
        for (int i = 0; i < s.size(); ++i) {
            unordered_set<char> charSet;
            for (int j = i; j < s.size(); ++j) {
                charSet.insert(s[j]);
                bool isNice = true;
                for (char c : charSet) {
                    if (isalpha(c) && (charSet.find(toupper(c)) == charSet.end() || charSet.find(tolower(c)) == charSet.end())) {
                        isNice = false;
                        break;
                    }
                }
                if (isNice) {
                    int currentLength = j - i + 1;
                    if (currentLength > maxLength) {
                        maxLength = currentLength;
                        longestNiceStr = s.substr(i, currentLength);
                    }
                }
            }
        }
        return longestNiceStr;
    }
};
