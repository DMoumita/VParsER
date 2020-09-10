#include <svAlways.h>

svAlways::svAlways()
    : svBase(ALWAYS)
{ }

svAlways::svAlways(const TSensList& s)
    : svBase(ALWAYS)
    , sensList_(s)
{ }

void svAlways::decompile(std::ostream& os) const
{
    os << "always";
    if (!sensList_.empty()) {
       os << " @(";
       int count  = sensList_.size();
       for(TSensList::const_iterator it = sensList_.begin();
             it != sensList_.end(); ++it)
       {
	   count --;
           (*it).decompile(os);
	   if (count >0) 
		os << " or ";
       }
       os << ")" << std::endl;
    }
    if (stmtOrBlock_ == NULL) return;
        stmtOrBlock_->decompile(os);
}
