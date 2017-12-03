// 20_valid_parentheses.cpp

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk = {};
        for (int i = 0, e = s.size(); i < e; ++i) {
            switch (s[i]) {
                case ')':
                    if (stk.empty() || stk.top() != '(') 
                        return false;
                    stk.pop();
                    break;
                case '}':
                    if (stk.empty() || stk.top() != '{') 
                        return false;
                    stk.pop();
                    break;
                case ']':
                    if (stk.empty() || stk.top() != '[') 
                        return false;
                    stk.pop();
                    break;
                default:
                    stk.push(s[i]);
                    break;
            }
        }
    return stk.empty();
    }
};


/*
#define ISCLOSE(c) (c == ')' || c == ']' || c == '}')
#define CLOSE(c) ( c == '(' ? ')' : ( c == '{' ? '}' : ( c == '[' ? ']' : '0' ) ) )

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> ps;
        for (int i = 0, size = s.length(); i < size ; ++i) {
            if (ISCLOSE(s[i])) {
                if (ps.empty()) return false;
                if (CLOSE(ps.top()) != s[i]) return false;
                ps.pop();
            } else {
                ps.push(s[i]);
            }
            
        }
        return ps.empty();
    }
};
*/


