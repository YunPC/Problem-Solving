#include <iostream>
#include <string>

using namespace std;

int main(){
    int num;
    cin >> num;
    int count = 0;
    for(int idx = 1; idx <= num; idx++)
    {
        string str = to_string(idx);
        if (str.find("4") != string::npos)
        {
            count++;
        }
    }

    cout << count;
}