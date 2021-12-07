#include <iostream>
#include "stringBasic.h"


int main() {
    StringBasic str1, str2, str3;
    StringBasic str4("Ido"), str5("C++"), str6("Python");
    
    std::cout << "str1 " << str1 << " lenght: " << str1.getLenght() << std::endl;
    std::cout << "str2 " << str2 << " lenght: " << str2.getLenght() << std::endl;
    std::cout << "str3 " << str3 << " lenght: " << str3.getLenght() << std::endl;
    std::cout << "str4 " << str4 << " lenght: " << str4.getLenght() << std::endl;
    std::cout << "str5 " << str5 << " lenght: " << str5.getLenght() << std::endl;
    std::cout << "str6 " << str6 << " lenght: " << str6.getLenght() << std::endl;

    try {
        str1[2] = 'c';
    }
    catch (std::out_of_range& e) {
        std::cout << "Tried to str[2] = 'c'  ";
        std::cout << e.what() << std::endl;
    }

    std::cout << "str4[1] = " << str4[1] << std::endl;
    
    str1 += str6;
    str2 += "new string";
    str3 += 't';
    str4 += str6;
    str5 += "++";
    str6 += 'n';

    std::cout << "str1 " << str1 << " lenght: " << str1.getLenght() << std::endl;
    std::cout << "str2 " << str2 << " lenght: " << str2.getLenght() << std::endl;
    std::cout << "str3 " << str3 << " lenght: " << str3.getLenght() << std::endl;
    std::cout << "str4 " << str4 << " lenght: " << str4.getLenght() << std::endl;
    std::cout << "str5 " << str5 << " lenght: " << str5.getLenght() << std::endl;
    std::cout << "str6 " << str6 << " lenght: " << str6.getLenght() << std::endl;


    str1 = str1 + str6;
    str2 = StringBasic(str2 + " new string");
    str3 = str3 + 't';

    std::cout << "str1 " << str1 << " lenght: " << str1.getLenght() << std::endl;
    std::cout << "str2 " << str2 << " lenght: " << str2.getLenght() << std::endl;
    std::cout << "str3 " << str3 << " lenght: " << str3.getLenght() << std::endl;

    str1.insert(str5, str1.getLenght());
    str5.replace(StringBasic("++"), StringBasic("P"));

    std::cout << "str1 " << str1 << " lenght: " << str1.getLenght() << std::endl;
    std::cout << "str5 " << str5 << " lenght: " << str5.getLenght() << std::endl;
}