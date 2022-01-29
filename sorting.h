#ifndef SORTING_H
#define SORTING_H
#include <filesystem>
#include "config.h"
namespace fs = std::filesystem;
class Sorting
{
private:
	fs::path content_dir_ = cnf::content_dir;
	fs::path bitmaps_dir_ = cnf::bitmaps_dir;
	fs::path output_dir_ = cnf::output_dir;
	std::basic_string<char> filename;

public:
	Sorting();
	~Sorting();
	auto create_dir(std::string path, const std::string dir_name) const -> void;
	auto get_filename() ->std::vector<std::u8string>;
};
#endif


