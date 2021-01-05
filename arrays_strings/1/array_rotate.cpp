#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::stoi;
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
            //cout << next_string << "next string " << endl;
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
vector<int> split_string_to_int(string s, string delim)
{
    int de_length = delim.length();
    vector<int> output;
    //check if substring exists

    for (int i = 0; i < s.length(); i++)
    {
        if (s.substr(i, de_length).compare(delim) == 0)
        {
            output.push_back(stoi(s.substr(0, i)));
            string next_string = s.substr(i + de_length, s.length());
            //cout << next_string << "next string " << endl;
            if (next_string.length() > de_length)
            {
                vector<int> final_output = split_string_to_int(next_string, delim);
                output.insert(output.end(), final_output.begin(), final_output.end());
            }
            else
            {
                output.push_back(stoi(next_string));
            }
            break;
        }
    }
    if (output.size() < 1)
    {
        output.push_back(stoi(s));
    }
    return output;
}

void print_vector(T i)
{
    for (int j = 0; j < i.size(); j++)
    {
        cout << i[j];
    }
}
// ---------- edit below this-------------
vector<vector<int>> ReadInputCLI()
{
    int line;
    int num_cases; // 1st line number of test cases
    //each test case 2 lines

    vector<vector<int>> arrays;               // second line is array
    vector<vector<int>> test_parameters = {}; // first line is len , rot_step
    cin >> num_cases;

    for (int i = 0; i < num_cases; i++)
    {
        //reading inputs
        test_parameters.push_back({});
        cin >> line;
        test_parameters[i].push_back(line); // for number of elements
        cin >> line;
        test_parameters[i].push_back(line); // rotation step
        arrays.push_back({});
        for (int l = 0; l < test_parameters[i][0]; l++)
        {
            cin >> line;
            arrays[i].push_back(line);
        }
        for (int l = 0; l < arrays[i].size(); l++)
        {
            cout << arrays[i][l];
        }
    }

    return arrays;
}

vector<vector<int>> ReadInputTXT(string FILENAME)
{
    vector<vector<int>> arrays;               // second line is array
    vector<vector<int>> test_parameters = {}; // first line is len , rot_step

    std::ifstream file(FILENAME);
    if (file.is_open())
    {
        string line;
        int lc = 0;
        while (std::getline(file, line))
        {
            // using printf() in all tests for consistency
            //cout << line << endl;

            if (lc != 0)
            {
                //handle first line input
                if (lc % 2 != 0)
                {
                    //test_parameters.push_back({});
                    test_parameters.push_back(split_string_to_int(line, " "));
                }
                else
                {
                    //arrays.push_back({});
                    arrays.push_back(split_string_to_int(line, " "));
                }
            }
            lc = lc + 1;
        }
        file.close();
    }

    return arrays;
}

int main()
{
    //vector<vector<int>> inp_arr = ReadInputCLI();
    vector<vector<int>> inp_arr = ReadInputTXT("/home/radhakrishna/projects/goodprojects/hacker_earth_problems/arrays_strings/1/array_rotate.txt");
    print_vector<int>(inp_arr[0]);
    return 0;
}