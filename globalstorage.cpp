#include "globalstorage.h"
#include "filenode.h"
#include <map>
#include <vector>
#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

struct GlobalStorage::GlobalData
{
    std::map<std::shared_ptr<FileNode>, int> frequency;
    std::vector<std::string> include_paths;
};

GlobalStorage::GlobalStorage() : data(std::shared_ptr<GlobalData>(new GlobalData))
{
    data->frequency = std::map<std::shared_ptr<FileNode>, int>();
    data->include_paths = std::vector<std::string>();
}

GlobalStorage& GlobalStorage::instance()
{
    static GlobalStorage self;
    return self;
}

bool GlobalStorage::init(int argc, const char **params)
{
    bool is_include = false;
    for (int i = 1; i < argc; ++i)
    {
        if (i == 1 || is_include)
        {
            if (!fs::exists(fs::path(params[i])))
            {
                std::cerr << "This path is not exists: " << params[i] << std::endl;
                return false;
            }
        }
        if (is_include)
        {
            data->include_paths.push_back(std::string(params[i]));
        }
        is_include = std::string(params[i]) == "-I";
    }
    return true;
}
