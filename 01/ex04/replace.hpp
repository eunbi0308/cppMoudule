#pragma once

# define GREEN "\033[0;92m"
# define YELLOW "\e[38;5;208m"
# define RED "\033[1;91m"
# define GREY "\033[0;90m"
# define DEFAULT "\033[0m"

# include <iostream>
# include <fstream>
# include <string>

void	replaceFile(const std::string filename, const std::string s1, const std::string s2);