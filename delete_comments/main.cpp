#include <iostream>
#include <fstream>
#include <iterator>
#include <regex>
#include <string>

int main() {
	std::fstream fin;
	fin.open("./test.cpp", std::ios::in);
	std::istreambuf_iterator <char> in(fin);
	std::istreambuf_iterator <char> end;
	std::regex pattern (R"(//.*)");
	std::regex pattern1(R"(/\*.*\*/)");
	std::string str;
	std::string s;
	while (std::getline(fin, s)) {
		str += s;
		str += '\n';
	}
	fin.close();
	s.clear();
	s =  std::regex_replace(str, pattern, R"()");;
	std::fstream fout;
	fout.open("./test.cpp", std::ios::out | std::ios_base::trunc);
	fout <<  std::regex_replace(s, pattern1, R"()");
	fout.close();
	return 0;
}
