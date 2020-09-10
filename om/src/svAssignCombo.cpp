#include <svAssignCombo.h>

svAssignCombo::svAssignCombo(svAssignExpr* s)
    : svExprBase(COMBO)
{
    if(s != NULL) setChild(s);
}

svAssignCombo::~svAssignCombo()
{
    svExprBase::TChildList& childList = getSubExprs();
    for(svExprBase::TChildList::iterator it = childList.begin();
        it != childList.end(); ++it)
    {
        delete (*it);
    }
}

svAssignCombo& svAssignCombo::append(svAssignExpr* b)
{
    if(b != NULL) setChild(b);
    return *this;
}

svAssignCombo& svAssignCombo::append(svAssignCombo& b)
{
    svExprBase::TChildList& childList = b.getSubExprs();

    for(svExprBase::TChildList::const_iterator it = childList.begin();
        it != childList.end(); ++it)
    {
        setChild(*it);
    }

    b.clearChild();

    return *this;
}

void svAssignCombo::decompile(std::ostream& os) const
{
    const svExprBase::TChildList& childList = getSubExprs();

    if(childList.size() == 1)
    {
        childList[0]->decompile(os);
        return;
    }

    string dlm = "";
    
    //os << "Myassign " << std::endl;
    os << std::endl;

    for(svExprBase::TChildList::const_iterator it = childList.begin();
        it != childList.end(); ++it)
    {
        const svExprBase::TChildList& l = (*it)->getSubExprs();
        os << dlm << "    ";
        l[0]->decompile(os);
        os << " = ";
        l[1]->decompile(os);
    
        dlm = ",\n";
    }
    os << ";" << std::endl;
}
