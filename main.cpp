#include "globalstorage.h"
#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

/*
bool has_any_dir(std::string path)
{
    for (auto &p : fs::directory_iterator(path))
    {
        if (p.is_directory())
        {
            return true;
        }
    }
    return false;
}

void print_file_names(std::string path)
{
    if (has_any_dir(path))
    {
        for (auto &p : fs::directory_iterator(path))
        {
            if (p.is_directory())
            {
                std::cout << "Go to folder: \n"
                          << path << "\\" << p.path().filename().string() << "\n\n";
                print_file_names(path + "\\" + p.path().filename().string());
            }
        }
    }

    for (auto &p : fs::directory_iterator(path))
    {
        std::cout << p << "\tis directory: " << p.is_directory() << std::endl;
    }
    std::cout << std::endl;
}
*/

int main(int argc, const char **argv)
{
    if (argc < 2)
    {
        std::cout << "Error!\n";
        std::cin.get();
        return 0;
    }

    if (!GlobalStorage::instance().init(argc, argv))
    {
        std::cerr << "Cannot init the analyzer! Check analyzer --help\nPress any key to continue...";
        std::cin.get();
        return -1;

    }

    std::cin.get();
    return 0;
}
