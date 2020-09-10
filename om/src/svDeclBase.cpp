#include <svDeclBase.h>

svDeclBase::svDeclBase(const string& pName, const EDeclType t)
    : svBase(pName, DECL)
    , declType_(t)
    , range_(NULL)
    , init_(NULL)
{ }

bool svDeclBase::update(const svDeclBase* b)
{
    bool ret = false;

    const svDeclBase* p = dynamic_cast<const svDeclBase*>(b);

    if(p == NULL) return false;

    if(range_ == NULL)
    {
        range_ = p->range_;
        ret = true;
    }

    if(p->init_)
    {
        init_ = p->init_;
	ret = true;
    }

    return ret;
}

void svDeclBase::decompile(std::ostream& os) const
{
    if (range_) range_->decompile(os);
    os << " " << getName();
    if (dim_) dim_->decompile(os);
    if(init_) 
    {
        os << " = ";
        init_->decompile(os);
    }
}
