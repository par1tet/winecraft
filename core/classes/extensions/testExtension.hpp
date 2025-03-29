#include<classes/extensions/extension.hpp>
#include<string.h>

#ifndef testExtension
#define testExtension

class TestExtension : public Extension {
public:
    TestExtension(std::string exName) : Extension() {
        this->exName = exName;
    }

    void gameFrame();

    std::string exName;
};


#endif