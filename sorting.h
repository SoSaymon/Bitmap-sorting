#ifndef SORTING_H
#define SORTING_H
#include <filesystem>
#include "config.h"
#include <string>
namespace fs = std::filesystem;
class Sorting
{
private:
	fs::path content_dir_ = cnf::content_dir;
	fs::path bitmaps_dir_ = cnf::bitmaps_dir;
	fs::path output_dir_ = cnf::output_dir;

public:
	Sorting();
	~Sorting();
	auto create_dir() const -> void;
	auto get_filename()->std::pair<std::vector<fs::path>, std::vector<fs::path>>;
	auto copy_files() -> void;
	auto remove_DS_Store() -> void;
};
#endif