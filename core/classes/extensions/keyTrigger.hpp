#include<string.h>
#include<functional>

using namespace std;

#ifndef entityclass
#define entityclass

class keyTrigger {
public:
    using CallbackType = function<void(void)>; 

    void keyTrigger(string key, CallbackType callback);

private:
    string _key;
    CallbackType _callback;
};

#endif