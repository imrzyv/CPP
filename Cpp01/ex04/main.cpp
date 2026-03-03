#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error: Cannot open input file." << std::endl;
        return 1;
    }

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
    {
        std::cerr << "Error: Cannot create output file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        std::string result;
        size_t pos = 0;
        size_t found;

        while ((found = line.find(s1, pos)) != std::string::npos)
        {
            result += line.substr(pos, found - pos);
            result += s2;
            pos = found + s1.length();
        }

        result += line.substr(pos);
        outfile << result;

        if (!infile.eof())
            outfile << std::endl;
    }

    infile.close();
    outfile.close();

    return 0;
}