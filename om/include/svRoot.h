#pragma once

// System Headers
#include <iostream>
#include <string>
#include <vector>

// OM Headers
#include <svFile.h>
#include <singleton.h>

using namespace std;

class svRoot : public SINGLETON<svRoot>
             , public svBase
{
    public:
       friend class SINGLETON<svRoot>;

    protected:
        svRoot();

    private:
        typedef vector<svFile> TFileList;
        TFileList fileList_;

    public:
        virtual ~svRoot() { }

	void init(void);
	void finalize(void);

        svModule* find(const string& modName);

        svFile& add(const svFile&);
        void add(svModule*);

        virtual void decompile(std::ostream& os = std::cout) const;
};
