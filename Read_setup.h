#ifndef READ_SETUP_H
#define READ_SETUP_H
#include <string>
#include <fstream>
#include <iostream>
#include <map>
class Read_setup
{
private:
	std::string_view content_dir;
	std::string_view bitmaps_dir;
	std::string_view output_dir;
	int min_ref;
	int max_ref;
public:
	Read_setup();
	~Read_setup(){}
	std::string& trim(std::string& str);
	std::map<std::string, std::string> create_map();
	void read_map(std::map<std::string, std::string>& setup);
	std::string_view get_content_dir() { return this->content_dir; }
	std::string_view get_bitmaps_dir() { return this->bitmaps_dir; }
	std::string_view get_output_dir() { return this->output_dir; }
	int get_min_ref() { return this->min_ref; }
	int get_max_ref() { return this->max_ref; }
};
#endif


