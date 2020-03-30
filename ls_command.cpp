#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <iostream>
#include <experimental/filesystem>
#include <chrono>

namespace fs = std::experimental::filesystem;

void view_directory(const fs::path& path) {
	if (fs::exists(path) && fs::is_directory(path)) {
		for (const auto& entry : fs::directory_iterator(path)) {
			auto status = entry.status();
			auto ftime = fs::last_write_time(entry.path());
			auto cftime = decltype(ftime)::clock::to_time_t(ftime);
			if (fs::is_directory(status))
				std::cout << "directory " << entry.path().filename().string() << "      " << std::asctime(std::localtime(&cftime));
			else
				std::cout << "file      " << entry.path().filename().string() << "      " << std::asctime(std::localtime(&cftime));
		}
	}
}

int main() {
	fs::path dir = fs::current_path();
	std::cout << dir.string() << std::endl;
	view_directory(dir);
	return 0;
}