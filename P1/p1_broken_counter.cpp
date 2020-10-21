#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int main()
{
    int num;
    int initial_num;
    int multiplier = 1;
    int digit_num = 0;
    int remainder;
    int four_count = 0;
    std::cin >> num;
    initial_num = num;
    while (num > 0)
    {
        remainder = num % 10;
        num /= 10;
        switch (digit_num)
        {
        case 0:
            if(remainder >= 4)
                four_count++;
            digit_num++;
            break;
        case 1:
            if(remainder >= 4)
            {
                four_count += 10 + (remainder-1);
        
            }
            else
            {
                four_count += remainder;
            }
            digit_num++;
            break;
        default:
            multiplier = multiplier*9 + pow(10, digit_num-1);
            if(remainder >= 4)
            {
                four_count += pow(10, digit_num)+ (remainder-1)*multiplier;
                
            }
            else
            {
                four_count += remainder*multiplier;
                
            }
            digit_num++;
            break;
        }
    
    }
    
    cout << initial_num - four_count << endl;

    return 0;
}