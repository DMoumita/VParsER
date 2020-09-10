#pragma once

// System Headers
#include <iostream>
#include <vector>

// OM Headers
#include <svBlockContext.h>
#include <svModule.h>

using namespace std;

class svFile : public svBase
             , public svBlockContext
{
    private:
        vector<string> _modList;

    public:
        svFile(const std::string& fName = "");
        virtual ~svFile() {}

        void add(svModule* m);

        virtual void decompile(std::ostream& os = std::cout) const;
};
