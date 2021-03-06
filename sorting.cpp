#include "sorting.h"
#include <iostream>
#include <vector>
#include <string>
namespace fs = std::filesystem;
Sorting::Sorting()
{
	Read_setup r1;
	this->content_dir_ = r1.get_content_dir();
	this->bitmaps_dir_ = r1.get_bitmaps_dir();
	this->output_dir_ = r1.get_output_dir();
	this->min_ref = r1.get_min_ref();
	this->max_ref = r1.get_max_ref();
}

Sorting::~Sorting()
{}

auto Sorting::create_dir() const -> void
{
	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator {bitmaps_dir_})
	{
		if (fs::is_empty(dir_entry) || !dir_entry.is_directory()) continue;

		fs::path path_str = output_dir_ / dir_entry.path().filename();
		fs::create_directory(path_str);
		for (int i = this->min_ref; i <= this->max_ref; i++)
		{
			fs::path ref_path = fs::path("REF" + std::to_string(i));
			fs::create_directory(path_str / ref_path);
		}
	}
}

auto Sorting::get_filename() -> std::pair<std::vector<fs::path>, std::vector<fs::path>>
{
	std::vector<fs::path> vector_path;
	std::vector<fs::path> vector_filename;
	std::filesystem::path path;
	std::pair<std::vector<fs::path>, std::vector<fs::path>> path_and_filename;

	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{bitmaps_dir_})
	{
		if (dir_entry.is_directory())
		{
			continue;
		}
		else if (dir_entry.is_regular_file())
		{
			path = dir_entry.path().filename();
			vector_filename.push_back(path);
			path = dir_entry.path();
			vector_path.push_back(path);
			path_and_filename = std::make_pair(vector_filename, vector_path);
		}
	}
	return path_and_filename;
}

auto Sorting::copy_files() -> void
{
	std::pair<std::vector<fs::path>, std::vector<fs::path>> vector_pair = get_filename();
	std::vector<fs::path> filenames = vector_pair.first;
	std::vector<fs::path> paths = vector_pair.second;
	unsigned short i = 0;
	size_t str_length = 0;
	std::size_t pos = 0;
	std::string temp;
	std::string ref;
	std::string path_str;
	std::string date;
	fs::path path;

	remove_DS_Store();
	create_dir();
	std::cout << "Your sorted files are available under these paths:\n";
	for(const auto& it : filenames)
	{
		temp = it.string();
		str_length = temp.length();
		pos = temp.find(".bmp");
		if (pos < 60)
		{
			if (str_length == 48)
			{
				pos = temp.find("2D");
				if (pos < 16)
				{
					pos = temp.find("REF");
					ref = temp.substr(pos, 4);
					date = temp.substr(16, 10);
					path_str = (output_dir_ / date /  ref / temp).string();
					path = path_str;
					fs::copy_file(paths.at(i), path, fs::copy_options::skip_existing);
					std::cout << path << "\n";
				}
			}
		}
		i++;
	}
}

auto Sorting::remove_DS_Store() -> void
{
	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator {bitmaps_dir_})
	{
		if (dir_entry.path().filename() == ".DS_Store")
		{
			fs::remove(dir_entry);
		}
	}
}
