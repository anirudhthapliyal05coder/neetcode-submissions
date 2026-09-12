class Solution {
public:

    string encode(vector<string>& strs) {

        string encoded = "";

        for(string s : strs)
        {
            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {

        vector<string> result;

        int i = 0;

        while(i < s.size())
        {
            int j = i;

            // Find '#'
            while(s[j] != '#')
            {
                j++;
            }

            // Get length
            int length = stoi(s.substr(i, j - i));

            // Move after '#'
            i = j + 1;

            // Get actual word
            string word = s.substr(i, length);

            result.push_back(word);

            // Move to next encoded string
            i = i + length;
        }

        return result;
    }
};