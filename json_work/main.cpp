#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <iostream>
#include <string>
#include <vector>
#include <experimental/filesystem>
#include <fstream>
#include <iomanip>

#include "json.hpp"


namespace fs = std::experimental::filesystem;
using nlohmann::json;

struct person {
	std::string name;
	std::string surname;
	std::string city;
	std::string street;
	std::string postcode;
};

person create_person() {
	person p;
	std::cout << "Name : ";
	std::cin >> p.name;
	std::cout << "Surname : ";
	std::cin >> p.surname;
	std::cout << "City : ";
	std::cin >> p.city;
	std::cout << "Street : ";
	std::cin >> p.street;
	std::cout << "Postcode : ";
	std::cin >> p.postcode;
	return p;
}

json transform_to_json(const person& p) {
	json j;
	j["Name"] = p.name;
	j["Surname"] = p.surname;
	j["Addres"]["City"] = p.city;
	j["Addres"]["Street"] = p.street;
	j["Addres"]["Postcode"] = p.postcode;
	return j;
}

fs::path create_dir_for_data() {
	auto p = fs::current_path();
	fs::create_directory(p / "json_obj");
	return (p / "json_obj");
}

void send_json_to_dir(fs::path p, json j) {
	std::fstream fout;
	fout.open(p.string(), std::ios::out);
	fout << std::setw(4) << j;
	fout.close();
}

int main() {
	person p1 = create_person();
	person p2 = create_person();
	json j1 = transform_to_json(p1);
	json j2 = transform_to_json(p2);
	auto p = create_dir_for_data();
	send_json_to_dir(p / "j1.txt", j1);
	send_json_to_dir(p / "j2.txt", j2);
	return 0;
}