#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

vector<string> split_string(string s, string delim)
{
    int de_length = delim.length();
    vector<string> output;
    //check if substring exists

    for (int i = 0; i < s.length(); i++)
    {
        if (s.substr(i, de_length).compare(delim) == 0)
        {
            output.push_back(s.substr(0, i));
            string next_string = s.substr(i + de_length, s.length());
            cout << next_string << "next string " << endl;
            if (next_string.length() > de_length)
            {
                vector<string> final_output = split_string(next_string, delim);
                output.insert(output.end(), final_output.begin(), final_output.end());
            }
            else
            {
                output.push_back(next_string);
            }
            break;
        }
    }
    if (output.size() < 1)
    {
        output.push_back(s);
    }
    return output;
}
