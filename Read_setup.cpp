#include "Read_setup.h"
std::map<std::string, std::string> Read_setup::create_map()
{
	std::string t;
	try
	{
		std::fstream handler;
		handler.open("setup.ini", std::ios::in | std::ios::binary);
		if (handler.good())
		{
			std::size_t pos;
			std::string buffer;
			std::string key;
			std::string value;
			std::map <std::string, std::string> setup;
			handler.seekg(0);
			while (!(handler.eof()))
			{
				std::getline(handler, buffer);
				if (buffer [0] == '#')
					continue;

				pos = buffer.find('=');
				if (pos <= 99)
				{
					value = buffer.substr((pos + 1), (buffer.length() - (pos + 2)));
					value = trim(value);
					key = buffer.substr(0, pos);
					key = trim(key);
					setup.insert(std::pair<std::string, std::string>(key, value));
				}

			}
			handler.close();
			return setup;
		}
		else
		{
			throw "ERROR! You can't open this file (setup.ini)";
		}
	}
	catch (const std::string& e)
	{
		std::cerr << e << "\n";
	}
}
void Read_setup::read_map(std::map<std::string, std::string>& setup)
{
	std::string key;
	for(const auto& it : setup)
	{
		key = it.first;
		if (key == "content_dir")
		{
			this->content_dir = it.second;
		}
		else if (key == "bitmaps_dir")
		{
			this->bitmaps_dir = it.second;
		}
		else if (key == "output_dir")
		{
			this->output_dir = it.second;
		}
		else if (key == "min_ref")
		{
			this->min_ref = atoi(it.second.c_str());
		}
		else if (key == "max_ref")
		{
			this->max_ref = atoi(it.second.c_str());
		}
	}
	std::cout << this->content_dir << "\n" << this->bitmaps_dir << "\n" << this->output_dir << "\n" << this->min_ref <<
		"\n" << this->max_ref << "\n";
}
std::string& Read_setup::trim(std::string& str)
{
	str.erase(0, str.find_first_not_of(' '));
	return str.erase(str.find_last_not_of(' ') + 1);
}
Read_setup::Read_setup()
{
	std::map<std::string, std::string> setup = create_map();
	read_map(setup);
}