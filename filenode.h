#ifndef FILENODE_H
#define FILENODE_H

#include <vector>

class FileNode
{
public:
    FileNode();

private:
    std::vector<FileNode> child_nodes;
};

#endif // CPPFILE_H
