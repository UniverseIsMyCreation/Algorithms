#include <cstring>
#include <iostream>

bool isPalindrome(string s){
        int64_t len = s.size();
        int64_t right_pointer = 0;
        int64_t left_pointer = len-1;
        while(true){
            while(!(tolower(s[right_pointer]) >= 'a' && tolower(s[right_pointer]) <= 'z'
                    || s[right_pointer] >= '0' && s[right_pointer] <= '9')){
                right_pointer++;
                if (right_pointer >= len)
                    break;
            }
            while(!(tolower(s[left_pointer]) >= 'a' && tolower(s[left_pointer]) <= 'z'
                    || s[left_pointer] >= '0' && s[left_pointer] <= '9')){
                left_pointer--;
                if (left_pointer < 0)
                    break;
            }
            if (right_pointer >= left_pointer)
                break;
            if (tolower(s[right_pointer]) != tolower(s[left_pointer]))
                return false;
            right_pointer++;
            left_pointer--;
        }
        return true;
    }
