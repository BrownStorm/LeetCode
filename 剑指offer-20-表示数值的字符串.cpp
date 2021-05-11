class Solution {
public:
    bool isNumber(string s) {
        vector<map<char, int>>states = {
            map<char, int> { {' ', 0} ,{'s', 1} ,{'d', 2}, {'.', 4} },          // 0.
            map<char, int> { {'d', 2},{'.', 4} },                               // 1.
            map<char, int> { {'d', 2}, {'.', 3}, {'e', 5},{' ', 8} },           // 2.
            map<char, int> { {'d', 3},{'e', 5},{' ', 8} },                      // 3.
            map<char, int> { {'d', 3} },                                        // 4.
            map<char, int> { {'s', 6},{'d', 7} },                               // 5.
            map<char, int> { {'d', 7} },                                        // 6.
            map<char, int> { {'d', 7},{' ', 8} },                               // 7.
            map<char, int> { {' ', 8 } }                                        // 8.
        };
        int p = 0;
        char t;
        for (char c : s) {
            if (c >= '0' && c <= '9') t = 'd';
            else if (c == '+' | c == '-') t = 's';
            else if (c == 'e' | c == 'E') t = 'e';
            else if (c == '.' | c == ' ') t = c;
            else t = '?';
            auto state = states[p].find(t);
            if (state == states[p].end()) return false;
            p = (int)(state->second);
        }
        return p == 2 || p == 3 || p == 7 || p == 8;
    }
};