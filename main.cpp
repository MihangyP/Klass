#include <iostream>
#include <fstream>

typedef std::string string;

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << " Usage: Klass <ClassName>" << std::endl;
		return (1);
	}
	std::fstream	cpp_file;
	std::fstream	hpp_file;
	string			cpp_name = std::string(av[1]) + ".cpp";
	string			hpp_name = std::string(av[1]) + ".hpp";

	std::ifstream	file1(cpp_name.c_str());
	if (file1.is_open())
	{
		std::cerr << "[ERROR] : The file " << cpp_name << "already exists" << std::endl;
		return (1);
	}
	cpp_file.open(cpp_name, std::fstream::out | std::fstream::app);
	if (!cpp_file.is_open())
	{
		std::cerr << "[ERROR] : Cannot open " << cpp_name << " file" << std::endl;
		return (1);
	}	
	std::ifstream	file2(hpp_name.c_str());
	if (file2.is_open())
	{
		std::cerr << "[ERROR] : The file " << hpp_name << "already exists" << std::endl;
		return (1);
	}
	hpp_file.open(hpp_name, std::fstream::out | std::fstream::app);
	if (!cpp_file.is_open())
	{
		std::cerr << "[ERROR] : Cannot open " + hpp_name + " file" << std::endl;
		return (1);
	}	

	cpp_file.close();
	hpp_file.close();
	return (0);
}
