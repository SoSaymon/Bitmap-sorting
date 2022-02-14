#ifndef SORTING_H
#define SORTING_H
#include <filesystem>
#include "config.h"
#include "Read_setup.h"
class Sorting
{
private:
	std::filesystem::path content_dir_ = cnf::content_dir;
	std::filesystem::path bitmaps_dir_ = cnf::bitmaps_dir;
	std::filesystem::path output_dir_ = cnf::output_dir;
	int min_ref;
	int max_ref;

public:
	Sorting();
	~Sorting();
	auto create_dir() const -> void;
	auto get_filename()->std::pair<std::vector<std::filesystem::path>, std::vector<std::filesystem::path>>;
	auto copy_files() -> void;
	auto remove_DS_Store() -> void;
};
#endif