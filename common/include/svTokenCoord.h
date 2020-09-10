#pragma once

#include <iostream>
#include <string>

class svCoord
{
    private:
        unsigned int line_, col_;

    public:
        svCoord(const unsigned int l, const unsigned int c)
            : line_(l), col_(c)
        { }

        virtual ~svCoord() {}

        const unsigned int getLineNo_(void) const
        { return line_; }

        const unsigned int getColNo_(void) const
        { return col_; }

        friend std::ostream& operator<<(std::ostream& os, const svCoord& c)
        {
           os << '(' << c.line_ << ", " << c.col_ << ')';
           return os;
        }
};

class svTokenCoord
{
    private:
        std::string  filename_;
        svCoord start_, end_;

    public:
        svTokenCoord(void)
           : filename_("")
           , start_(0, 0)
           , end_(0, 0)
        { }

        svTokenCoord( const std::string& f
                    , const unsigned int sl
                    , const unsigned int sc
                    , const unsigned int el
                    , const unsigned int ec )
           : filename_(f)
           , start_(sl, sc)
           , end_(el, ec)
        {}

        svTokenCoord( const std::string& f
                    , const svCoord      s
                    , const svCoord      e )
           : filename_(f)
           , start_(s)
           , end_(e)
        {}

        virtual ~svTokenCoord() {}

        const std::string& getFilename(void) const
        { return filename_; }

        const svCoord& getStartCoord(void) const
        { return start_; }

        const svCoord& getEndCoord(void) const
        { return end_; }

        friend std::ostream& operator<<(std::ostream& os, const svTokenCoord& t)
        {
           os << t.start_ << " --> " << t.end_ << " @ " << t.filename_;
           return os;
        }
};
