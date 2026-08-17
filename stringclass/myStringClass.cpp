#include<stdio.h>
#include<conio.h>
#include <string>
using namespace std;
class MyString
{
    string Name;
 
    public: 
    MyString(const string name):Name(name){};

    int strLenth(const string &str);
    bool strCmpar(const string &str1,const string &str2);
};
int MyString::strLenth(const string &str)
{
    int strcount = 0;
    const char *p = str.c_str();
    while (*p != '\0')
    {
        strcount++;
        p++;
    }
    return strcount;
}
bool MyString:: strCmpar(const string &str1,const string &str2)
{
    while(str1.c_str() != nullptr)
    {
        if(str1.c_str() == str2.c_str())
        {
            continue;
        }else 
        {
           return false;
        }
        return true;
    }
}

int main() 
{
    
}