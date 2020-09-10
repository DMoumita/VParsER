#include <svTypes.h>
#include <svLogger.h>

svLogger::svLogger(void)
    : outStream_(NULL)
{
    outStream_ = &(std::cout);
}

svLogger::svLogger(std::string& fileName)
    : outStream_(NULL)
{
    outStream_ = new ofstream(fileName);
}

void svLogger::init(const ELogType l)
{
    level_ = l;
    header();
}

void svLogger::init(const string& fName, const ELogType l)
{
    outStream_ = new ofstream(fName);
    level_ = l;
    header();
}

void svLogger::finalize(void)
{
    summary();
    outStream_ = NULL;
}

void svLogger::_decide_(const ELogType m)
{
    if(level_ == ALL)  { print_ = true;        return; }
    if(level_ == WARN) { print_ = (m != INFO); return; }
    if(level_ == ERR)  { print_ = (m == ERR);  return; }
    print_ = false;
}

svLogger& svLogger::operator()(const EMsgType l, const ELogType m)
{
    if(outStream_ == NULL) return *this;

    ostream& os = (*outStream_);

    _decide_(m);
    
    if(!print_) return *this;

    os << "[";

    switch(m)
    {
        case INFO : os << "INFO"; break;
        case ERR  : errNo_++;  os << "ERR "; break;
        case WARN : warnNo_++; os << "WARN"; break;
        default   : break;
    }

    switch(l)
    {
        case SYN : os << "::SYNTAX"; break;
        case SEM : os << "::SEMANTIC"; break;
        default   : break;
    }

    os << "] ";

    return *this;
}

void svLogger::header(void)
{
    if(outStream_ == NULL) return;

    ostream& os = (*outStream_);

    os << "                System Verilog Parser                     " << std::endl;
    os << "                Ver : " << VERSION         << std::endl << std::endl;
}

void svLogger::summary(void)
{
    if(outStream_ == NULL) return;

    ostream& os = (*outStream_);

    os << std::endl << "Compilation complete with " << warnNo_
       << " warnings and " << errNo_ << " errors." << std::endl;
}
