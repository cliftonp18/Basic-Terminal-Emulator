// mypipe.h

#pragma  once
#include <array>
#include <string>

class mypipe {
private:
    std::array<int, 2> fd;

public:
    mypipe();
    ~mypipe();

    void redirect();
    std::string read();
};
