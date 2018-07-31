class Solution {
public:
    bool detectCapitalUse(string word) {
        int i = word.length();
        bool done = false;
        bool allUpper = false;
        bool allLower = false;
        bool normal = false;
        int begin = 0;
        int end = i-1;
        if (word == "")
            return false;
        if (i == 1)
            return true;
        if (islower(word[0])){
            allLower = true;
        }
        else if (!islower(word[0]) && islower(word[1])){
            normal = true;
        }
        else{
            allUpper = true;
        }
        while (!done){
            if (allUpper){
                if (isupper(word[begin]) && isupper(word[end])){
                    begin ++;
                    end --;
                }
                else
                    return false;
            }
            else if (allLower){
                if (islower(word[begin]) && islower(word[end])){
                    begin ++;
                    end --;
                }
                else
                    return false;
            }
            else if (normal){
                if (begin == 0){
                    if (isupper(word[begin]) && islower(word[end])){
                        begin ++;
                        end --;
                    }
                    else
                        return false;
                }
                else{
                    if (islower(word[begin]) && islower(word[end])){
                        begin ++;
                        end --;
                    }
                    else
                        return false;
                }
            }
            if (begin > end)
                done = true;
            else if (begin == end){
                if (allUpper){
                    if (isupper(word[begin]))
                        done = true;
                    else return false;
                }
                else if (allLower || normal){
                    if (islower(word[begin]))
                        done = true;
                    else return false;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
