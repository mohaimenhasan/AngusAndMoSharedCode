class Solution {
public:
    string reverseString(string s) {
        if (s.length() == 0) return s;
        int begin = 0;
        int end = s.length()-1;
        while (begin < end){
            char temp = s[begin];
            s[begin] = s[end];
            s[end] = temp;
            begin ++;
            end --;
        }
        return s;
    }
};
