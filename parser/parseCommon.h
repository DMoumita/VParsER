#pragma once

#include <string>
#include <list>
#include <vector>

using namespace std;

class TRange
{
    public:
        int lRange, rRange;

	TRange() : lRange(0), rRange(0) {}
	~TRange();
};

class TPortAssign
{
    public:
        string port;
        string assign;

	TPortAssign() : port(""), assign("") {}
	~TPortAssign() {}
};

class TPortAssignList
{
    public:
        vector<string>* port;
        vector<string>* assign;

	TPortAssignList() : port(NULL), assign(NULL) {}
	~TPortAssignList() {}

};
