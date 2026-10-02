class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        vector<char> stack;
        int top = -1;

        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stack.push_back(s[i]);
                top++;
            }
            else
            {
                if(top == -1 || (s[i] == ')' && stack[top] != '(') || (s[i] == '}' && stack[top] != '{') || (s[i] == ']' && stack[top] != '['))
                {
                    return false;
                }

                stack.pop_back();
                top--;
            }
        }

        return top == -1;
    }
};