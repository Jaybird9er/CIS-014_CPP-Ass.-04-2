#include <iostream>
#include <string>
using namespace std;

/**
* PURPOSE:
*   removes all consecutive duplicate English letters in a string
* PARAMETER:
*   input, a string consisting of English letters
* RETURN VALUE
*   a string that has been sanitized of consecutive duplicate letters or a NULL value
*/

string deduplicate(string str)
{
    bool hasLetters = true;
    int i = 0;
    while (hasLetters && str.length() >= 1)
    {
        if(i == 0)
        {
            if(str[i] == str[i + 1])
            {
                str.erase(0, 2);
            }
            else if(str.length() == i + 1)
            {
                hasLetters = false;
            }
            else
            {
                i++;
            }
        }
        else if(i > 0)
        {
            if(str[i] == str[i + 1])
            {
                str.erase(0, 2);
                i++;
            }
            else if(str.length() == i + 1)
            {
                hasLetters = false;
            }
            else
            {
                i++;
            }
        }
        else
        {
            hasLetters = false;
        }

    }
    return str;
}
int main()
{
    cout << deduplicate("AABB") << endl; // should return a NULL string
    cout << deduplicate("A") << endl; // "A"
    cout << deduplicate("ABBA") << endl; // should return a NULL string
    cout << deduplicate("AAA") << endl; // "A"
    cout << deduplicate("AKA") << endl; // "AKA" because there is no consecutive pair.
    cout << deduplicate("KCCK") << endl;
    cout << deduplicate("ZZZ") << endl;
    cout << deduplicate("KKCCD") << endl;
    return 0;
}
