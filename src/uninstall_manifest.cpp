#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>

int main(int argc, char **argv)
{   
    std::string manifest_filename;
    if (argc > 1)
    {
        manifest_filename = std::string(argv[1]);
    }
    else 
    {
        manifest_filename = "install_manifest.txt";
    }

    std::vector<std::string> file_list;
    std::ifstream manifest_file;
    manifest_file.open(manifest_filename);

    if (!manifest_file.is_open())
    {
        std::cout<<"Manifest Does Not Exist"<<std::endl;
        return -1;
    }

    while(!manifest_file.eof())
    {
        std::string filename;
        getline(manifest_file, filename);
        if (boost::filesystem::remove(filename.c_str()))
        {
            std::cout<<"Removing: "<<filename<<std::endl;
        }
        else
        {
            std::cout<<"Could Not Find: "<<filename<<std::endl;
        }
    }

    return 0;
}