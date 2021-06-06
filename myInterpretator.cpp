#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct myInterpretator
{
    string type;
    string name;
    string strValue;
    int value;
    double dValue;
    bool bValue;
} type[50];

int number(string str, int i);
string Str(string str, int i);
double dNumber(string str, int i);
bool bNumber(string str, int i);
void for1(vector<string> &str1, int &counter, int i, int &reserv2, int &reserv1);
void for2(vector<string> &str1, int &counter, int i, int &reserv2, int &reserv1);
void for3(vector<string> &str1, int &counter, int i, int &reserv2, int &reserv1);
void for4(vector<string> &str1, int &counter, int i, int &reserv2, int &reserv1);
void  if1(vector<string> &str1, int counter, int i, int &reserv2, int &reserv1);
void  if2(vector<string> &str1, int counter, int i, int &reserv2, int &reserv1);
void  if3(vector<string> &str1, int counter, int i, int &reserv2, int &reserv1);
void  if4(vector<string> &str1, int counter, int i, int &reserv2, int &reserv1);
void  if5(vector<string> &str1, int counter, int i, int &reserv2, int &reserv1);
void  if6(vector<string> &str1, int counter, int i, int &reserv2, int &reserv1);

int main()
{

    int i = 0;
    string str;
    string address = ("myFile.txt");
    ifstream fin;
    fin.open(address);

    if (!fin.is_open())
    {
        cout << "ERROR" << endl;
    }
    else
    {
        while (!fin.eof())
        {
            str = "";
            fin >> str;
            if (str == "seisu")
            {
                ++i;
                type[i].type = str;
                fin >> str;
                type[i].name = str;
                fin >> str;

                if (str == "=")
                {
                    fin >> str;
                    istringstream(str) >> type[i].value;
                }
                else
                {
                    continue;
                }
            }

            if (str == "daburu")
            {
                ++i;
                type[i].type = str;
                fin >> str;
                type[i].name = str;
                fin >> str;
                if (str == "=")
                {
                    fin >> str;
                    istringstream(str) >> type[i].dValue;
                }
                else
                {
                    continue;
                }
            }

            if (str == "sutor")
            {
                ++i;
                type[i].type = str;
                fin >> str;
                type[i].name = str;
                fin >> str;
                if (str == "=")
                {
                    fin >> str;
                    type[i].strValue = str;
                }
                else
                {
                    continue;
                }
            }

            if (str == "buul")
            {
                ++i;
                type[i].type = str;
                fin >> str;
                type[i].name = str;
                fin >> str;
                if (str == "=")
                {
                    fin >> str;
                    if (str == "0" && "false")
                    {
                        type[i].bValue = 0;
                    }
                    else
                    {
                        type[i].bValue = 1;
                    }
                }
            }

            if (str == "fairu")
            {
                fin >> str;
                if (str == "<<")
                {
                    fin >> str;
                    for (int j = 0; j <= i+2; ++j)
                    {
                        if (str == type[j].name)
                        {
                                if (type[j].type == "sutor")
                                {
                                    cout << type[j].strValue << endl;
                                    
                                }

                                if (type[j].type == "daburu")
                                {
                                    cout << type[j].dValue << endl;
                                }

                                if (type[j].type == "seisu")
                                {
                                    cout << type[j].value << endl;
                                }

                                if (type[j].type == "buul")
                                {
                                    cout << type[j].bValue << endl;
                                }
                        }
                    }

                    fin >> str;
                    if (str == "<<")
                    {
                        fin >> str;
                        for (int j = 0; j <= i; ++j)
                        {
                            if (str == type[j].name)
                            {
                                if (type[j].type == "sutor")
                                {
                                    cout << type[j].strValue << endl;
                                }

                                if (type[j].type == "daburu")
                                {
                                    cout << type[j].dValue << endl;
                                }

                                if (type[j].type == "seisu")
                                {
                                    cout << type[j].value << endl;
                                }

                                if (type[j].type == "buul")
                                {
                                    cout << type[j].bValue << endl;
                                }
                            }
                        }
                    }
                }
            }

            for (int j = 0; j <= i; ++j)

            {
                if (str == type[j].name)
                {

                    if (type[j].type == "daburu")
                    {
                        fin >> str;
                        if (str == "=")
                        {
                            fin >> str;
                            double y = dNumber(str, i);
                            fin >> str;

                            if (str == ";")
                            {
                                type[j].dValue = y;
                            }
                            if (str == "+")
                            {
                                fin >> str;
                                type[j].dValue = y + dNumber(str, i);
                            }

                            if (str == "/")
                            {
                                fin >> str;
                                type[j].dValue = y / dNumber(str, i);
                            }

                            if (str == "*")
                            {
                                fin >> str;
                                type[j].dValue = y * dNumber(str, i);
                            }
                        }
                    }

                    if (type[j].type == "sutor")
                    {
                        fin >> str;
                        if (str == "=")
                        {
                            fin >> str;
                            string y = Str(str, i);
                            fin >> str;
                            if (str == ";")
                            {
                                type[j].strValue = y;
                            }
                            if (str == "+")
                            {
                                fin >> str;
                                type[j].strValue = y + " "+ Str(str, i);
                            }
                        }
                    }

                    if (type[j].type == "buul")
                    {
                        fin >> str;
                        if (str == "=")
                        {
                            fin >> str;
                            bool y = bNumber(str, i);
                            fin >> str;
                            if (str == ";")
                            {
                                type[j].bValue = y;
                            }
                            if (str == "+")
                            {
                                fin >> str;
                                type[j].bValue = y + bNumber(str, i);
                            }
                        }
                    }

                    if (type[j].type == "seisu")
                    {
                        fin >> str;
                        if (str == "=")
                        {
                            fin >> str;
                            int y = number(str, i);
                            fin >> str;
                            if (str == ";")
                            {
                                type[j].value = y;
                            }
                            if (str == "+")
                            {
                                fin >> str;
                                type[j].value = y + number(str, i);
                            }

                            if (str == "/")
                            {
                                fin >> str;
                                type[j].value = y / number(str, i);
                            }
                            if (str == "*")
                            {
                                fin >> str;
                                type[j].value = y * number(str, i);
                            }
                        }
                    }
                }
            }

            if (str == "nyuro")
            {
                fin >> str;
                if (str == ">>")
                {
                    fin >> str;
                    for (int j = 0; j <= i; ++j)
                    {
                        if (str == type[j].name)
                        {
                            if (type[j].type == "sutor")
                            {
                                cin >> type[j].strValue;
                            }

                            if (type[j].type == "daburu")
                            {
                                cin >> type[j].dValue;
                            }

                            if (type[j].type == "seisu")
                            {
                                cin >> type[j].value;
                            }

                            if (type[j].type == "buul")
                            {
                                cin >> type[j].bValue;
                            }
                        }
                    }
                }
                else
                {
                    cout << "error: no match for 'operator<<'" << endl;
                }
            }

            if (str == "totte")
            {
                int reserv1 = 0;
                int reserv2 = 0;
                fin >> str;
                fin >> str;
                if (str == "seisu")
                {
                    ++i;
                    type[i].type = str;
                    fin >> str;
                    type[i].name = str;
                    fin >> str;

                    if (str == "=")
                    {
                        fin >> str;
                        istringstream(str) >> type[i].value;
                        reserv1 = type[i].value;
                    }
                    else
                    {
                        type[i].value = 0;
                    }
                }
                else
                {
                    for (int j = 0; j < i; ++j)
                    {
                        if (str == type[j].name)
                        {
                            reserv1 = type[j].value;
                        }
                    }
                }

                fin >> str;
                fin >> str;
                fin >> str;

                if (str == "<=")
                {
                    fin >> str;
                    reserv2 = number(str, i);
                    fin >> str;
                    fin >> str;
                    if (str == "++")
                    {
                        fin >> str;
                        fin >> str;
                        fin >> str;

                        vector<string> str1;
                        int counter = 0;
                        while (str != "}")
                        {
                            fin >> str;
                            str1.push_back(str);
                            ++counter;
                        }
                        for1(str1, counter, ++i, reserv2, reserv1);
                    }
                }

                if (str == ">=")
                {
                    fin >> str;
                    reserv2 = number(str, i);
                    fin >> str;
                    fin >> str;
                    if (str == "--")
                    {
                        fin >> str;
                        fin >> str;
                        fin >> str;

                        vector<string> str1;
                        int counter = 0;
                        while (str != "}")
                        {
                            fin >> str;
                            str1.push_back(str);
                            ++counter;
                        }
                        for2(str1, counter, ++i, reserv2, reserv1);
                    }
                }

                if (str == "<")
                {
                    fin >> str;
                    reserv2 = number(str, i);
                    fin >> str;
                    fin >> str;
                    if (str == "++")
                    {
                        fin >> str;
                        fin >> str;
                        fin >> str;

                        vector<string> str1;
                        int counter = 0;
                        while (str != "}")
                        {
                            fin >> str;
                            str1.push_back(str);
                            ++counter;
                        }
                        for3(str1, counter, ++i, reserv2, reserv1);
                    }
                }

                if (str == ">")
                {
                    fin >> str;
                    reserv2 = number(str, i);
                    fin >> str;
                    fin >> str;
                    if (str == "--")
                    {
                        fin >> str;
                        fin >> str;
                        fin >> str;

                        vector<string> str1;
                        int counter = 0;
                        while (str != "}")
                        {
                            fin >> str;
                            str1.push_back(str);
                            ++counter;
                        }
                        for4(str1, counter, ++i, reserv2, reserv1);
                    }
                }
            }

            if (str == "moso")
            {
                fin >> str;
                fin >> str;
                int res1 = 0;
                int res2 = 0;
                res1 = number(str, i);
                fin >> str;
                if (str == "==")
                {
                    fin >> str;
                    res2 = number(str, i);
                    vector<string> str3;
                    int counter = 0;
                    while (str != "}")
                    {
                        fin >> str;
                        str3.push_back(str);
                        ++counter;
                    }
                    if1(str3, counter, i, res2, res1);
                }
                 if (str == "<=")
                {
                    fin >> str;
                    res2 = number(str, i);
                    vector<string> str3;
                    int counter = 0;
                    while (str != "}")
                    {
                        fin >> str;
                        str3.push_back(str);
                        ++counter;
                    }
                    if2(str3, counter, i, res2, res1);
                }

                    if (str == ">=")
                {
                    fin >> str;
                    res2 = number(str, i);
                    vector<string> str3;
                    int counter = 0;
                    while (str != "}")
                    {
                        fin >> str;
                        str3.push_back(str);
                        ++counter;
                    }
                    if3(str3, counter, i, res2, res1);
                }
                    if (str == ">")
                {
                    fin >> str;
                    res2 = number(str, i);
                    vector<string> str3;
                    int counter = 0;
                    while (str != "}")
                    {
                        fin >> str;
                        str3.push_back(str);
                        ++counter;
                    }
                    if4(str3, counter, i, res2, res1);
                }
                    if (str == "<")
                {
                    fin >> str;
                    res2 = number(str, i);
                    vector<string> str3;
                    int counter = 0;
                    while (str != "}")
                    {
                        fin >> str;
                        str3.push_back(str);
                        ++counter;
                    }
                    cout<< str3[0];
                    if5(str3, counter, i, res2, res1);
                }
                    if (str == "!=")
                {
                    fin >> str;
                    res2 = number(str, i);
                    vector<string> str3;
                    int counter = 0;
                    while (str != "}")
                    {
                        fin >> str;
                        str3.push_back(str);
                        ++counter;
                    }
                    if6(str3, counter, i, res2, res1);
                }
            }
        }
    }
}

int number(string str, int i)
{
    for (int j = 0; j <= i; ++j)
    {
        if (str == type[j].name)
        {
            return type[j].value;
        }
    }
    int x;
    istringstream(str) >> x;
    return x;
}

string Str(string str, int i)
{
    for (int j = 0; j <= i; ++j)
    {
        if (str == type[j].name)
        {
            return type[j].strValue;
        }
    }

    return str;
}

double dNumber(string str, int i)
{
    for (int j = 0; j <= i; ++j)
    {

        if (str == type[j].name)
        {
            return type[j].dValue;
        }
    }
    double x;
    istringstream(str) >> x;
    return x;
}

bool bNumber(string str, int i)
{
    for (int j = 0; j <= i; ++j)
    {
        if (str == type[j].name)
        {
            return type[j].bValue;
        }
    }

    bool x;
    istringstream(str) >> x;
    return x;
}

void for1(vector<string> &str1, int &counter, int i, int &reserv2, int &reserv1)
{
    for (reserv1; reserv1 <= reserv2; ++reserv1)
    {
        for (int k = 0; k <= counter; ++k)
        {
            if (str1[k] == "seisu")
            {
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;

                if (str1[k] == "=")
                {
                    ++k;
                    type[i].value = number(str1[k], i);
                }
                else
                {
                    continue;
                }
            }

            for (int j = 0; j <= i; ++j)

            {

                if (str1[k] == type[j].name)
                {

                    if (type[j].type == "daburu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            double y = dNumber(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].dValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;

                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].dValue = y / dNumber(str1[k], i);
                            }

                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].dValue = y * dNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "sutor")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            string y = Str(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].strValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].strValue = y + Str(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "buul")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            bool y = bNumber(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].bValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].bValue = y + bNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "seisu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            int y = number(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].value = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].value = y + number(str1[k], i);
                            }
                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].value = y - number(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].value = y / number(str1[k], i);
                            }
                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].value = y * number(str1[k], i);
                            }
                        }
                    }
                }
            }

            if (str1[k] == "fairu")
            {
                ++k;
                if (str1[k] == "<<")
                {
                    ++k;
                    for (int j = 0; j <= i; ++j)
                    {
                        if (str1[k] == type[j].name)
                        {
                                if (type[j].type == "sutor")
                                {
                                    cout << type[j].strValue << endl;
                                }

                                if (type[j].type == "daburu")
                                {
                                    cout << type[j].dValue << endl;
                                }

                                if (type[j].type == "seisu")
                                {
                                    cout << type[j].value << endl;
                                }

                                if (type[j].type == "buul")
                                {
                                    cout << type[j].bValue << endl;
                                }
                        }
                    }
                    ++k;
                    if (str1[k] == "<<")
                    {
                        ++k;
                        for (int j = 0; j <= i; ++j)
                        {
                            if (str1[k] == type[j].name)
                            {
                                if (type[j].type == "sutor")
                                {
                                    cout << type[j].strValue << endl;
                                }

                                if (type[j].type == "daburu")
                                {
                                    cout << type[j].dValue << endl;
                                }

                                if (type[j].type == "seisu")
                                {
                                    cout << type[j].value << endl;
                                }

                                if (type[j].type == "buul")
                                {
                                    cout << type[j].bValue << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void for2(vector<string> &str1, int &counter, int i, int &reserv2, int &reserv1)
{
    for (reserv1; reserv1 >= reserv2; --reserv1)
    {
        for (int k = 0; k <= counter; ++k)
        {
            if (str1[k] == "seisu")
            {
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;

                if (str1[k] == "=")
                {
                    ++k;
                    type[i].value = number(str1[k], i);
                }
                else
                {
                    continue;
                }
            }

            for (int j = 0; j <= i; ++j)

            {

                if (str1[k] == type[j].name)
                {

                    if (type[j].type == "daburu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            double y = dNumber(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].dValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;

                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].dValue = y / dNumber(str1[k], i);
                            }

                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].dValue = y * dNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "sutor")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            string y = Str(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].strValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].strValue = y + Str(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "buul")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            bool y = bNumber(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].bValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].bValue = y + bNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "seisu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            int y = number(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].value = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].value = y + number(str1[k], i);
                            }
                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].value = y - number(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].value = y / number(str1[k], i);
                            }
                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].value = y * number(str1[k], i);
                            }
                        }
                    }
                }
            }

            if (str1[k] == "fairu")
            {
                ++k;
                if (str1[k] == "<<")
                {
                    ++k;
                    for (int j = 0; j <= i; ++j)
                    {
                        if (str1[k] == type[j].name)
                        {
                                if (type[j].type == "sutor")
                                {
                                    cout << type[j].strValue << endl;
                                }

                                if (type[j].type == "daburu")
                                {
                                    cout << type[j].dValue << endl;
                                }

                                if (type[j].type == "seisu")
                                {
                                    cout << type[j].value << endl;
                                }

                                if (type[j].type == "buul")
                                {
                                    cout << type[j].bValue << endl;
                                }
                        }
                    }
                    ++k;
                    if (str1[k] == "<<")
                    {
                        ++k;
                        for (int j = 0; j <= i; ++j)
                        {
                            if (str1[k] == type[j].name)
                            {
                                if (type[j].type == "sutor")
                                {
                                    cout << type[j].strValue << endl;
                                }

                                if (type[j].type == "daburu")
                                {
                                    cout << type[j].dValue << endl;
                                }

                                if (type[j].type == "seisu")
                                {
                                    cout << type[j].value << endl;
                                }

                                if (type[j].type == "buul")
                                {
                                    cout << type[j].bValue << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void for3(vector<string> &str1, int &counter, int i, int &reserv2, int &reserv1)
{
    for (reserv1; reserv1 < reserv2; ++reserv1)
    {
        for (int k = 0; k <= counter; ++k)
        {
            if (str1[k] == "seisu")
            {
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;

                if (str1[k] == "=")
                {
                    ++k;
                    type[i].value = number(str1[k], i);
                }
                else
                {
                    continue;
                }
            }

            for (int j = 0; j <= i; ++j)

            {

                if (str1[k] == type[j].name)
                {

                    if (type[j].type == "daburu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            double y = dNumber(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].dValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;

                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].dValue = y / dNumber(str1[k], i);
                            }

                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].dValue = y * dNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "sutor")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            string y = Str(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].strValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].strValue = y + Str(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "buul")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            bool y = bNumber(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].bValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].bValue = y + bNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "seisu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            int y = number(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].value = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].value = y + number(str1[k], i);
                            }
                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].value = y - number(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].value = y / number(str1[k], i);
                            }
                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].value = y * number(str1[k], i);
                            }
                        }
                    }
                }
            }

            if (str1[k] == "fairu")
            {
                ++k;
                if (str1[k] == "<<")
                {
                    ++k;
                    for (int j = 0; j <= i; ++j)
                    {
                        if (str1[k] == type[j].name)
                        {
                                if (type[j].type == "sutor")
                                {
                                    cout << type[j].strValue << endl;
                                }

                                if (type[j].type == "daburu")
                                {
                                    cout << type[j].dValue << endl;
                                }

                                if (type[j].type == "seisu")
                                {
                                    cout << type[j].value << endl;
                                }

                                if (type[j].type == "buul")
                                {
                                    cout << type[j].bValue << endl;
                                }
                        }
                    }
                    ++k;
                    if (str1[k] == "<<")
                    {
                        ++k;
                        for (int j = 0; j <= i; ++j)
                        {
                            if (str1[k] == type[j].name)
                            {
                                if (type[j].type == "sutor")
                                {
                                    cout << type[j].strValue << endl;
                                }

                                if (type[j].type == "daburu")
                                {
                                    cout << type[j].dValue << endl;
                                }

                                if (type[j].type == "seisu")
                                {
                                    cout << type[j].value << endl;
                                }

                                if (type[j].type == "buul")
                                {
                                    cout << type[j].bValue << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void for4(vector<string> &str1, int &counter, int i, int &reserv2, int &reserv1)
{
    for (reserv1; reserv1 > reserv2; --reserv1)
    {
        for (int k = 0; k <= counter; ++k)
        {
            if (str1[k] == "seisu")
            {
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;

                if (str1[k] == "=")
                {
                    ++k;
                    type[i].value = number(str1[k], i);
                }
                else
                {
                    continue;
                }
            }

            for (int j = 0; j <= i; ++j)

            {

                if (str1[k] == type[j].name)
                {

                    if (type[j].type == "daburu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            double y = dNumber(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].dValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;

                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].dValue = y / dNumber(str1[k], i);
                            }

                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].dValue = y * dNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "sutor")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            string y = Str(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].strValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].strValue = y + Str(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "buul")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            bool y = bNumber(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].bValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].bValue = y + bNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "seisu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            int y = number(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].value = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].value = y + number(str1[k], i);
                            }
                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].value = y - number(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].value = y / number(str1[k], i);
                            }
                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].value = y * number(str1[k], i);
                            }
                        }
                    }
                }
            }

            if (str1[k] == "fairu")
            {
                ++k;
                if (str1[k] == "<<")
                {
                    ++k;
                    for (int j = 0; j <= i; ++j)
                    {
                        if (str1[k] == type[j].name)
                        {
                            if (type[j].type == "sutor")
                            {
                                cout << type[j].strValue << " ";
                            }

                            if (type[j].type == "daburu")
                            {
                                cout << type[j].dValue << " ";
                            }

                            if (type[j].type == "seisu")
                            {
                                cout << type[j].value << " ";
                            }

                            if (type[j].type == "buul")
                            {
                                cout << type[j].bValue << " ";
                            }
                        }
                    }
                    ++k;
                    if (str1[k] == "<<")
                    {
                        ++k;
                        for (int j = 0; j <= i; ++j)
                        {
                            if (str1[k] == type[j].name)
                            {
                                if (type[j].type == "sutor")
                                {
                                    cout << type[j].strValue << endl;
                                }

                                if (type[j].type == "daburu")
                                {
                                    cout << type[j].dValue << endl;
                                }

                                if (type[j].type == "seisu")
                                {
                                    cout << type[j].value << endl;
                                }

                                if (type[j].type == "buul")
                                {
                                    cout << type[j].bValue << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void if1(vector<string> &str1, int counter, int i, int &reserv2, int &reserv1)
{  
    if (reserv1 == reserv2)
    {
       for (int k = 0; k <= counter; ++k)
        {  
            if (str1[k] == "seisu")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;

                if (str1[k] == "=")
                {
                    ++k;
                    type[i].value = number(str1[k], i);
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "daburu")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    istringstream(str1[k]) >> type[i].dValue;
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "sutor")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    type[i].strValue = str1[k];
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "buul")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    if (str1[k] == "0" && "false")
                    {
                        type[i].bValue = 0;
                    }
                    else
                    {
                        type[i].bValue = 1;
                    }
                }
            }

            for (int j = 0; j <= i; ++j)

            {

                if (str1[k] == type[j].name)
                {

                    if (type[j].type == "daburu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            double y = dNumber(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].dValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;

                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].dValue = y / dNumber(str1[k], i);
                            }

                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].dValue = y * dNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "sutor")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            string y = Str(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].strValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].strValue = y + Str(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "buul")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            bool y = bNumber(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].bValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].bValue = y + bNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "seisu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            int y = number(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].value = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].value = y + number(str1[k], i);
                            }
                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].value = y - number(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].value = y / number(str1[k], i);
                            }
                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].value = y * number(str1[k], i);
                            }
                        }
                    }
                }
            }

            if (str1[k] == "fairu")
            {
                ++k;
                if (str1[k] == "<<")
                {
                    ++k;
                    for (int j = 0; j <= i; ++j)
                    {
                        if (str1[k] == type[j].name)
                        {
                            if (type[j].type == "sutor")
                            {
                                cout << type[j].strValue << " ";
                            }

                            if (type[j].type == "daburu")
                            {
                                cout << type[j].dValue << " ";
                            }

                            if (type[j].type == "seisu")
                            {
                                cout << type[j].value << " ";
                            }

                            if (type[j].type == "buul")
                            {
                                cout << type[j].bValue << " ";
                            }
                        }
                    }
                    ++k;
                    
                    if (str1[k] == "<<")
                    {
                        ++k;
                        for (int j = 0; j <= i; ++j)
                        {
                            if (str1[k] == type[j].name)
                            {
                                if (type[j].type == "sutor")
                                {
                                    cout << type[j].strValue << endl;
                                }

                                if (type[j].type == "daburu")
                                {
                                    cout << type[j].dValue << endl;
                                }

                                if (type[j].type == "seisu")
                                {
                                    cout << type[j].value << endl;
                                }

                                if (type[j].type == "buul")
                                {
                                    cout << type[j].bValue << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void  if2(vector<string> &str1, int counter, int i, int &reserv2, int &reserv1)
{
      if (reserv1 <= reserv2)
    {
        for (int k = 0; k <= counter; ++k)
        {
            if (str1[k] == "seisu")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;

                if (str1[k] == "=")
                {
                    ++k;
                    type[i].value = number(str1[k], i);
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "daburu")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    istringstream(str1[k]) >> type[i].dValue;
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "sutor")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    type[i].strValue = str1[k];
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "buul")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    if (str1[k] == "0" && "false")
                    {
                        type[i].bValue = 0;
                    }
                    else
                    {
                        type[i].bValue = 1;
                    }
                }
            }

            for (int j = 0; j <= i; ++j)

            {

                if (str1[k] == type[j].name)
                {

                    if (type[j].type == "daburu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            double y = dNumber(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].dValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;

                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].dValue = y / dNumber(str1[k], i);
                            }

                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].dValue = y * dNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "sutor")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            string y = Str(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].strValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].strValue = y + Str(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "buul")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            bool y = bNumber(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].bValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].bValue = y + bNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "seisu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            int y = number(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].value = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].value = y + number(str1[k], i);
                            }
                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].value = y - number(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].value = y / number(str1[k], i);
                            }
                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].value = y * number(str1[k], i);
                            }
                        }
                    }
                }
            }

            if (str1[k] == "fairu")
            {
                ++k;
                if (str1[k] == "<<")
                {
                    ++k;
                    for (int j = 0; j <= i; ++j)
                    {
                        if (str1[k] == type[j].name)
                        {
                            if (type[j].type == "sutor")
                            {
                                cout << type[j].strValue << " ";
                            }

                            if (type[j].type == "daburu")
                            {
                                cout << type[j].dValue << " ";
                            }

                            if (type[j].type == "seisu")
                            {
                                cout << type[j].value << " ";
                            }

                            if (type[j].type == "buul")
                            {
                                cout << type[j].bValue << " ";
                            }
                        }
                    }
                    ++k;
                    if (str1[k] == "<<")
                    {
                        ++k;
                        for (int j = 0; j <= i; ++j)
                        {
                            if (str1[k] == type[j].name)
                            {
                                if (type[j].type == "sutor")
                                {
                                    cout << type[j].strValue << endl;
                                }

                                if (type[j].type == "daburu")
                                {
                                    cout << type[j].dValue << endl;
                                }

                                if (type[j].type == "seisu")
                                {
                                    cout << type[j].value << endl;
                                }

                                if (type[j].type == "buul")
                                {
                                    cout << type[j].bValue << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void  if3(vector<string> &str1, int counter, int i, int &reserv2, int &reserv1)
{
    if (reserv1 >= reserv2)
    {
        for (int k = 0; k <= counter; ++k)
        {
            if (str1[k] == "seisu")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;

                if (str1[k] == "=")
                {
                    ++k;
                    type[i].value = number(str1[k], i);
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "daburu")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    istringstream(str1[k]) >> type[i].dValue;
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "sutor")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    type[i].strValue = str1[k];
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "buul")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    if (str1[k] == "0" && "false")
                    {
                        type[i].bValue = 0;
                    }
                    else
                    {
                        type[i].bValue = 1;
                    }
                }
            }

            for (int j = 0; j <= i; ++j)

            {

                if (str1[k] == type[j].name)
                {

                    if (type[j].type == "daburu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            double y = dNumber(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].dValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;

                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].dValue = y / dNumber(str1[k], i);
                            }

                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].dValue = y * dNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "sutor")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            string y = Str(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].strValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].strValue = y + Str(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "buul")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            bool y = bNumber(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].bValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].bValue = y + bNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "seisu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            int y = number(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].value = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].value = y + number(str1[k], i);
                            }
                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].value = y - number(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].value = y / number(str1[k], i);
                            }
                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].value = y * number(str1[k], i);
                            }
                        }
                    }
                }
            }

            if (str1[k] == "fairu")
            {
                ++k;
                if (str1[k] == "<<")
                {
                    ++k;
                    for (int j = 0; j <= i; ++j)
                    {
                        if (str1[k] == type[j].name)
                        {
                            if (type[j].type == "sutor")
                            {
                                cout << type[j].strValue << " ";
                            }

                            if (type[j].type == "daburu")
                            {
                                cout << type[j].dValue << " ";
                            }

                            if (type[j].type == "seisu")
                            {
                                cout << type[j].value << " ";
                            }

                            if (type[j].type == "buul")
                            {
                                cout << type[j].bValue << " ";
                            }
                        }
                    }
                    ++k;
                    if (str1[k] == "<<")
                    {
                        ++k;
                        for (int j = 0; j <= i; ++j)
                        {
                            if (str1[k] == type[j].name)
                            {
                                if (type[j].type == "sutor")
                                {
                                    cout << type[j].strValue << endl;
                                }

                                if (type[j].type == "daburu")
                                {
                                    cout << type[j].dValue << endl;
                                }

                                if (type[j].type == "seisu")
                                {
                                    cout << type[j].value << endl;
                                }

                                if (type[j].type == "buul")
                                {
                                    cout << type[j].bValue << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void  if4(vector<string> &str1, int counter, int i, int &reserv2, int &reserv1)
{
    if (reserv1 > reserv2)
    {
        for (int k = 0; k <= counter; ++k)
        {
            if (str1[k] == "seisu")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;

                if (str1[k] == "=")
                {
                    ++k;
                    type[i].value = number(str1[k], i);
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "daburu")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    istringstream(str1[k]) >> type[i].dValue;
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "sutor")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    type[i].strValue = str1[k];
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "buul")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    if (str1[k] == "0" && "false")
                    {
                        type[i].bValue = 0;
                    }
                    else
                    {
                        type[i].bValue = 1;
                    }
                }
            }

            for (int j = 0; j <= i; ++j)

            {

                if (str1[k] == type[j].name)
                {

                    if (type[j].type == "daburu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            double y = dNumber(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].dValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;

                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].dValue = y / dNumber(str1[k], i);
                            }

                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].dValue = y * dNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "sutor")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            string y = Str(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].strValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].strValue = y + Str(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "buul")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            bool y = bNumber(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].bValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].bValue = y + bNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "seisu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            int y = number(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].value = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].value = y + number(str1[k], i);
                            }
                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].value = y - number(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].value = y / number(str1[k], i);
                            }
                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].value = y * number(str1[k], i);
                            }
                        }
                    }
                }
            }

            if (str1[k] == "fairu")
            {
                ++k;
                if (str1[k] == "<<")
                {
                    ++k;
                    for (int j = 0; j <= i; ++j)
                    {
                        if (str1[k] == type[j].name)
                        {
                            if (type[j].type == "sutor")
                            {
                                cout << type[j].strValue << " ";
                            }

                            if (type[j].type == "daburu")
                            {
                                cout << type[j].dValue << " ";
                            }

                            if (type[j].type == "seisu")
                            {
                                cout << type[j].value << " ";
                            }

                            if (type[j].type == "buul")
                            {
                                cout << type[j].bValue << " ";
                            }
                        }
                    }
                    ++k;
                    if (str1[k] == "<<")
                    {
                        ++k;
                        for (int j = 0; j <= i; ++j)
                        {
                            if (str1[k] == type[j].name)
                            {
                                if (type[j].type == "sutor")
                                {
                                    cout << type[j].strValue << endl;
                                }

                                if (type[j].type == "daburu")
                                {
                                    cout << type[j].dValue << endl;
                                }

                                if (type[j].type == "seisu")
                                {
                                    cout << type[j].value << endl;
                                }

                                if (type[j].type == "buul")
                                {
                                    cout << type[j].bValue << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void  if5(vector<string> &str1, int counter, int i, int &reserv2, int &reserv1)
{
    if (reserv1 < reserv2)
    {
        for (int k = 0; k <= counter; ++k)
        {
            if (str1[k] == "seisu")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;

                if (str1[k] == "=")
                {
                    ++k;
                    type[i].value = number(str1[k], i);
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "daburu")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    istringstream(str1[k]) >> type[i].dValue;
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "sutor")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    type[i].strValue = str1[k];
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "buul")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    if (str1[k] == "0" && "false")
                    {
                        type[i].bValue = 0;
                    }
                    else
                    {
                        type[i].bValue = 1;
                    }
                }
            }

            for (int j = 0; j <= i; ++j)

            {

                if (str1[k] == type[j].name)
                {

                    if (type[j].type == "daburu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            double y = dNumber(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].dValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;

                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].dValue = y / dNumber(str1[k], i);
                            }

                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].dValue = y * dNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "sutor")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            string y = Str(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].strValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].strValue = y + Str(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "buul")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            bool y = bNumber(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].bValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].bValue = y + bNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "seisu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            int y = number(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].value = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].value = y + number(str1[k], i);
                            }
                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].value = y - number(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].value = y / number(str1[k], i);
                            }
                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].value = y * number(str1[k], i);
                            }
                        }
                    }
                }
            }

            if (str1[k] == "fairu")
            {
                ++k;
                if (str1[k] == "<<")
                {
                    ++k;
                    for (int j = 0; j <= i; ++j)
                    {
                        if (str1[k] == type[j].name)
                        {
                            if (type[j].type == "sutor")
                            {
                                cout << type[j].strValue << " ";
                            }

                            if (type[j].type == "daburu")
                            {
                                cout << type[j].dValue << " ";
                            }

                            if (type[j].type == "seisu")
                            {
                                cout << type[j].value << " ";
                            }

                            if (type[j].type == "buul")
                            {
                                cout << type[j].bValue << " ";
                            }
                        }
                    }
                    ++k;
                    if (str1[k] == "<<")
                    {
                        ++k;
                        for (int j = 0; j <= i; ++j)
                        {
                            if (str1[k] == type[j].name)
                            {
                                if (type[j].type == "sutor")
                                {
                                    cout << type[j].strValue << endl;
                                }

                                if (type[j].type == "daburu")
                                {
                                    cout << type[j].dValue << endl;
                                }

                                if (type[j].type == "seisu")
                                {
                                    cout << type[j].value << endl;
                                }

                                if (type[j].type == "buul")
                                {
                                    cout << type[j].bValue << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void  if6(vector<string> &str1, int counter, int i, int &reserv2, int &reserv1)
{
    if (reserv1 != reserv2)
    {
        for (int k = 0; k <= counter; ++k)
        {
            if (str1[k] == "seisu")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;

                if (str1[k] == "=")
                {
                    ++k;
                    type[i].value = number(str1[k], i);
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "daburu")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    istringstream(str1[k]) >> type[i].dValue;
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "sutor")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    type[i].strValue = str1[k];
                }
                else
                {
                    continue;
                }
            }

            if (str1[k] == "buul")
            {
                ++i;
                type[i].type = str1[k];
                ++k;
                type[i].name = str1[k];
                ++k;
                if (str1[k] == "=")
                {
                    ++k;
                    if (str1[k] == "0" && "false")
                    {
                        type[i].bValue = 0;
                    }
                    else
                    {
                        type[i].bValue = 1;
                    }
                }
            }

            for (int j = 0; j <= i; ++j)

            {

                if (str1[k] == type[j].name)
                {

                    if (type[j].type == "daburu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            double y = dNumber(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].dValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;

                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].dValue = y + dNumber(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].dValue = y / dNumber(str1[k], i);
                            }

                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].dValue = y * dNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "sutor")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            string y = Str(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].strValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].strValue = y + Str(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "buul")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            bool y = bNumber(str1[k], i);
                            ++k;
                            if (str1[k] == ";")
                            {
                                type[j].bValue = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].bValue = y + bNumber(str1[k], i);
                            }
                        }
                    }

                    if (type[j].type == "seisu")
                    {
                        ++k;
                        if (str1[k] == "=")
                        {
                            ++k;
                            int y = number(str1[k], i);
                            ++k;

                            if (str1[k] == ";")
                            {
                                type[j].value = y;
                            }
                            if (str1[k] == "+")
                            {
                                ++k;
                                type[j].value = y + number(str1[k], i);
                            }
                            if (str1[k] == "-")
                            {
                                ++k;
                                type[j].value = y - number(str1[k], i);
                            }

                            if (str1[k] == "/")
                            {
                                ++k;
                                type[j].value = y / number(str1[k], i);
                            }
                            if (str1[k] == "*")
                            {
                                ++k;
                                type[j].value = y * number(str1[k], i);
                            }
                        }
                    }
                }
            }

            if (str1[k] == "fairu")
            {
                ++k;
                if (str1[k] == "<<")
                {
                    ++k;
                    for (int j = 0; j <= i; ++j)
                    {
                        if (str1[k] == type[j].name)
                        {
                            if (type[j].type == "sutor")
                            {
                                cout << type[j].strValue << " ";
                            }

                            if (type[j].type == "daburu")
                            {
                                cout << type[j].dValue << " ";
                            }

                            if (type[j].type == "seisu")
                            {
                                cout << type[j].value << " ";
                            }

                            if (type[j].type == "buul")
                            {
                                cout << type[j].bValue << " ";
                            }
                        }
                    }
                    ++k;
                    if (str1[k] == "<<")
                    {
                        ++k;
                        for (int j = 0; j <= i; ++j)
                        {
                            if (str1[k] == type[j].name)
                            {
                                if (type[j].type == "sutor")
                                {
                                    cout << type[j].strValue << endl;
                                }

                                if (type[j].type == "daburu")
                                {
                                    cout << type[j].dValue << endl;
                                }

                                if (type[j].type == "seisu")
                                {
                                    cout << type[j].value << endl;
                                }

                                if (type[j].type == "buul")
                                {
                                    cout << type[j].bValue << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


