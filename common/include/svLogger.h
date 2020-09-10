#pragma once

// System Headers
#include <fstream>
#include <iostream>
#include <string>

// OM Headers
#include <singleton.h>

using namespace std;

// Short-cut for logging messages ######################################################################
#define SVLOG(a , b) SINGLETON<svLogger>::getInstance()(svLogger::EMsgType::a, svLogger::ELogType::b)
// #####################################################################################################

class svLogger : public SINGLETON<svLogger>
{
    public:
       friend class SINGLETON<svLogger>;

       enum EMsgType { SYN, SEM, GEN };
       enum ELogType { ALL, INFO=ALL, WARN, ERR, NONE };

    protected:
        svLogger(void);
        svLogger(std::string&);

    private:
        std::ostream* outStream_ = NULL;
        ELogType      level_     = WARN;
        bool          print_     = false;

	int           warnNo_    = 0;
	int           errNo_     = 0;

        void _decide_(const ELogType);
        void header(void);
        void summary(void);

    public:
        virtual ~svLogger() {}

        void init(const string& fName, const ELogType l=ELogType::ALL);
        void init(const ELogType l=ELogType::ALL);
        void finalize(void);

        svLogger& operator()( const EMsgType, const ELogType);

        template <typename T>
        svLogger& operator<<(const T& v)
        {
            if(print_ && (outStream_ != NULL)) (*outStream_) << v;
            return *this;
        }

        svLogger &operator <<(std::ostream& (*os)(std::ostream&))
        {
            if(print_ && (outStream_ != NULL)) (*outStream_) << os;
            return *this;
        }
};
