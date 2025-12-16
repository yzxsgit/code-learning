class Solution {
public:
    string replaceSpaces(string &str) {
        string a;
        for (auto c : str)
            if(c == ' ')
                a = a + "%20";
            else a = a + c;
        return a;
    }
};
