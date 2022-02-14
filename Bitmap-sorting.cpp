#include "sorting.h"
#include <iostream>
#include "Read_setup.h"

auto init_program() -> void;

auto main() -> int
{
    init_program();
	Sorting s1;
	s1.copy_files();
    
}

auto init_program() -> void
{
    std::cout << "|---------------------------------|\n";
    std::cout << "|----------Bitmap sorting---------|\n";
    std::cout << "|-----Made by Szymon Chirowski----|\n";
    std::cout << "|---(C)2022 All rights reserved---|\n";
    std::cout << "|---------------------------------|\n";
}
