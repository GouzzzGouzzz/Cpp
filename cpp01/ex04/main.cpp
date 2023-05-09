#include <iostream>
#include <fstream>

static std::string replace_line(std::string line, std::string s1, std::string s2)
{
	std::string temp, newline;
	int offset = 0;
	if (line.find(s1))
	{
		temp = &line[line.find(s1)];
		while (temp.compare(0,s2.size(), s2) == 0)
		{
			temp = temp[1];
			temp = &temp[temp.find(s1)];
		}
		offset = line.size() - temp.size(); // not good
		temp.erase(0, s1.size());
		temp.insert(0, s2);
		std::cout << "temp=" <<temp << "offest is "<< offset << std::endl;
	}
	else
		return (line);
	newline.append(line, 0, offset);
	newline.append(temp);
	std::cout << "after proc="<< newline << "||"<< std::endl;
	return newline;
}

int replace(std::ifstream *in, std::ofstream *out, char *search, char *rep)
{
	std::string s1, s2, line;
	s1 = search;
	s2 = rep;
	while (std::getline((*in), line,'\n'))
	{
		line = replace_line(line, s1, s2);
		line = replace_line(line, s1, s2);
		line = replace_line(line, s1, s2);
		std::cout << "line= "<<line << std::endl;
		break;
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
	out_file.open(name.append(".replace"), std::ios::out);
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
