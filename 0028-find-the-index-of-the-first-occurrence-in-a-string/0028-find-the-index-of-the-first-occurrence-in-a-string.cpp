class Solution {
public:
    int strStr(string haystack, string needle) {

        if (haystack.size() < needle.size())
            return -1;

        int len = needle.length();

        for (int i = 0; i <= haystack.size() - len; i++) {

            int count = 1;
            int j = i + 1;

            if (haystack[i] == needle[0]) {

                for (; j < i + len; j++) {

                    if (needle[count] != haystack[j])
                        break;

                    count++;
                }

                if (j == i + len)
                    return i;
            }
        }

        return -1;
    }
};