#include <svBlock.h>

svBlock::svBlock()
    : svBase("", svBase::eNodeType::BLOCK)
    , svBlockContext()
{ }

svBlock::svBlock(const svBase& b)
    : svBase(b)
    , svBlockContext()
{
    setType_(svBase::eNodeType::BLOCK);
}

void svBlock::decompile(std::ostream& os) const
{
   os << "begin" << std::endl;
   for(TbaseList::const_iterator it = stmtList_.begin();
       it != stmtList_.end(); ++it)
   {
       (*it)->decompile(os);
       os << std::endl;
   }
   os << "end" << std::endl;
}
