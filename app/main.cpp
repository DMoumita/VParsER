#include <iostream>
#include <cstdio>
#include <svLogger.h>
#include <svRoot.h>

using namespace std;

int svParse(const int argc, const char** argv);

int main(const int argc, const char **argv)
{
    SINGLETON<svLogger>::getInstance().init(svLogger::ELogType::WARN);
    SINGLETON<svRoot>::getInstance().init();

    svParse(argc, argv);

    SINGLETON<svRoot>::getInstance().decompile();

    SINGLETON<svLogger>::getInstance().finalize();
    SINGLETON<svRoot>::getInstance().finalize();

    return 0;    
}
