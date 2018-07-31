class Solution {
public:
    bool detectCapitalUse(string word) {
      bool allupperCase = false;
      bool alllowerCase = false;
      bool normalCase = false;
      if (word == "")
          return false;
      if (word.length() == 1)
          return true;
      for (int i = 0; i < word.length(); i++){
        if (i == 0){
            if (islower(word[i]))
                alllowerCase = true;
            else if (islower(word[i+1]))
                normalCase = true;
            else
                allupperCase = true;
        }
        else if (alllowerCase){
            if (!islower(word[i]))
                return false;
        }
        else if (allupperCase){
            if (islower(word[i]))
                return false;
        }
        else{
            if (i > 0){
                if (!islower(word[i]))
                    return false;
            }
        }

      }
        return true;
    }
};
