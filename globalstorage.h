#ifndef GLOBALSTORAGE_H
#define GLOBALSTORAGE_H

#include <memory>

class GlobalStorage
{
public:
    static GlobalStorage& instance();
    bool init(int argc, const char** argv);

private:
    GlobalStorage();
    GlobalStorage(const GlobalStorage& root) = delete;
    GlobalStorage& operator = (const GlobalStorage&) = delete;
    struct GlobalData;
    std::shared_ptr<GlobalData> data;
};

#endif // GLOBALSTORAGE_H
