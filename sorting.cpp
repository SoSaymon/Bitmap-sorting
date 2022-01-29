#include "sorting.h"
#include <iostream>
#include <vector>

namespace fs = std::filesystem;
Sorting::Sorting()
{}

Sorting::~Sorting()
{}

auto Sorting::create_dir(std::string path, const std::string dir_name) const -> void
{
	path += dir_name;
	fs::path mkdir_path = path;
	fs::create_directory(mkdir_path);
}

auto Sorting::get_filename() -> std::vector<std::u8string>
{
	std::vector<std::u8string> vector_path;
	std::filesystem::path path;

	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{content_dir_})
	{
		if (dir_entry.path().filename() == ".DS_Store")
		{
			fs::remove(dir_entry);
		}
		if (dir_entry.is_regular_file())
		{
			std::cout << dir_entry << "\n";

			path = dir_entry.path().filename();
			vector_path.push_back(path.u8string());
		}
		std::cout << dir_entry << "\n";
	}
	return vector_path;
}
