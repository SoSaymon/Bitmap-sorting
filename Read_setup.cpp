#include "Read_setup.h"
std::map<std::string, std::string> create_map()
{
    try
    {
        std::ifstream handler("setup.ini");
        std::map<std::string, std::string> setup;

        if (handler)
        {
            std::string line;
            while (std::getline(handler, line))
            {
                if (line [0] == '#') continue;

                const std::size_t sign_pos = line.find_first_of('=');
                const std::string value = line.substr(0, sign_pos); // tu gdzies rtim
                const std::string key = line.substr(sign_pos + 1, line.size() - sign_pos - 1); // tu gdzies trim

                setup.emplace(value, key); // mozna tez setup.emplace(std::move(value), std::move(key)), wymaga #include <utility>
            }

            return setup;
        }
        else
        {
            throw std::runtime_error("ERROR! You can't open this file (setup.ini)");
        }
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
}

void Read_setup::read_map(std::map<std::string, std::string>& setup)
{
	
	for(const auto& [key, value] : setup)
	{
		if (key == "content_dir")
		{
			this->content_dir = value;
		}
		else if (key == "bitmaps_dir")
		{
			this->bitmaps_dir = value;
		}
		else if (key == "output_dir")
		{
			this->output_dir = value;
		}
		else if (key == "min_ref")
		{
			this->min_ref = std::atoi(reinterpret_cast<const char*>(value.c_str()));
		}
		else if (key == "max_ref")
		{
			this->max_ref = std::atoi(reinterpret_cast<const char*>(value.c_str()));
		}
	}
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