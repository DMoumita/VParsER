#pragma once
#include <iostream>
#include <string>
#include <svTokenCoord.h>

using namespace std;

class svBase
{
    public:
        enum eNodeType {BASE, ROOT, FILE, MODULE, DECL, BLOCK, EXPR, ALWAYS};

    private:
        eNodeType _type  = eNodeType::BASE;
        string    _name  = "";
        svTokenCoord coord_;

    protected:
        inline void setType_(const eNodeType t) { _type = t; }

    public:
        svBase(const string& s = "", const eNodeType t = BASE);
        svBase(const eNodeType);
        virtual ~svBase() {}

        const eNodeType getType(void) const { return _type;        }

        const string& getName(void) const   { return _name;        }
        string& getName(void)               { return _name;        }

        const svTokenCoord&
	    getTokenCoord(void) const       { return coord_;       }

        virtual bool update(const svBase*)  { return false;        }

        virtual void decompile(std::ostream& os = std::cout) const = 0;
};
