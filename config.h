// ReSharper disable once CppMissingIncludeGuard
#include <string>
#ifndef CONFIG_H
#define CONFIG_H

namespace cnf
{
	//Always do a backslash before a backslash
	//Set a hard path to the directory with all contents
	inline constexpr std::string_view content_dir = R"(C:\Users\SoSaymon\Desktop\Archiwum)";
	//Set a hard path to directory with bitmaps
	inline constexpr std::string_view bitmaps_dir = R"(C:\Users\SoSaymon\Desktop\Archiwum\Images_Wyniki)";
	//Set a hard path to output directory
	inline constexpr std::string_view output_dir = R"(C:\Users\SoSaymon\Desktop\Archiwum\Images_NOK)";
}
#endif // CONFIG_H
