#include <iostream>
#include <fstream>
#include <string>
 
int main() {
    std::fstream fin;
    fin.open("./test.txt", std::ios::in);
    std::string s;
    std::getline(fin, s);
    int length = s.length();
    std::cout << length << std::endl;
    std::cout << fin.tellg() << std::endl;
    std::cout << "Enter a string number: ";
    int str_num;
    std::cin >> str_num;
    fin.seekg((length + 1) * str_num);
    if (!std::getline(fin, s).eof())
	    std::cout << s << std::endl;
    else
	    std::cout << "EoF reached" << std::endl;
    fin.close();
    return 0;
}
