#include <iostream>
#include <fstream>

static std::string replace_line(std::string line, std::string s1, std::string s2)
{
	int temp, offset = 0;
	std::string edit_line = line;
	while (1)
	{
		temp = edit_line.find(s1);
		if (temp < 0)
			break;
		line.erase(temp + offset, s1.size());
		line.insert(temp + offset, s2);
		offset += s2.size();
		edit_line.erase(temp, s1.size());
	}
	return line.append("\n");
}

static int replace(std::ifstream *in, std::ofstream *out, char *search, char *rep)
{
	std::string s1, s2, line;
	s1 = search;
	s2 = rep;
	while (std::getline((*in), line,'\n'))
	{
		line = replace_line(line, s1, s2);
		out->write(line.c_str(),line.size());
	}

	return 1;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Program need 3 arguments, not more, not less" << std::endl;
		return 0;
	}
	std::string name;
	std::ifstream in_file (argv[1]);
	std::ofstream out_file;
	name = argv[1];
	if (!in_file)
	{
		std::cout << "Error while opening the file" << std::endl;
		return 0;
	}
	out_file.open(name.append(".replace").c_str(), std::ios::out);
	if (!out_file)
	{
		std::cout << "Error while creating the file" << std::endl;
		in_file.close();
		return (0);
	}
	if (replace(&in_file, &out_file, argv[2], argv[3]) == -1)
		std::cout << "An error occured" << std::endl;
	in_file.close();
	out_file.close();

}
