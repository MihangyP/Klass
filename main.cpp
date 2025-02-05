#include <iostream>
#include <fstream>

typedef std::string string;

void	str_toupper(string *str)
{
	for (unsigned long i = 0; i < (*str).length(); ++i)
		(*str).at(i) = std::toupper((*str).at(i));
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << " Usage: Klass <ClassName>" << std::endl;
		return (1);
	}
	string			class_name = av[1];
	std::fstream	cpp_file;
	std::fstream	hpp_file;
	string			cpp_name = class_name + ".cpp";
	string			hpp_name = class_name + ".hpp";

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

	cpp_file << "#include \"" << hpp_name << "\"\n" << std::endl;
	cpp_file << class_name << "::" << class_name << "(void)" << std::endl;
	cpp_file << "{" << std::endl;
	cpp_file << "\t// You can put something here or not, I don't care, it's your program" << std::endl;
	cpp_file << "}" << std::endl << std::endl;
	cpp_file << class_name << "::" << "~"  << class_name << "(void)" << std::endl;
	cpp_file << "{" << std::endl;
	cpp_file << "\t// You can put something here or not, I don't care, it's your program" << std::endl;
	cpp_file <<  "}" << std::endl;

	string class_name_uppered = class_name;
	str_toupper(&class_name_uppered);
	hpp_file << "#ifndef __" << class_name_uppered << "_H__" << std::endl;
	hpp_file << "# define __" << class_name_uppered << "_H__\n" << std::endl;
	hpp_file << "class\t" << class_name << std::endl;
	hpp_file << "{" << std::endl;
	hpp_file << "\tprivate:\n" << std::endl;
	hpp_file << "\tpublic:" << std::endl;
	hpp_file << "\t\t" << class_name << "(void);" << std::endl;
	hpp_file << "\t\t" << "~" << class_name << "(void);" << std::endl << std::endl;
	hpp_file << "};\n" << std::endl;
	hpp_file << "#endif // __" << class_name_uppered << "_H__" << std::endl;

	cpp_file.close();
	hpp_file.close();
	return (0);
}
