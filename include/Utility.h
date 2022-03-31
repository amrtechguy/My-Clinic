#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>

void display_msg(std::string msg = "")
{
	std::cout << "\nMessage-> " << msg << "\n" << std::endl;
}

#endif