LEX = flex
YACC = bison

INCLUDES = -I. -I../om/include -I../common/include

SRCS =  svLex.l  \
	svYacc.y \

OBJS := $(SRCS:%.l=%.o)
OBJS := $(OBJS:%.y=%.o)

GEN := $(SRCS:%.l=%.cpp)
GEN += $(SRCS:%.l=%.hpp)
GEN += $(SRCS:%.l=%.output)

$(LIB): $(OBJS)
	ld -r -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.cpp: %.l
	$(LEX) -o$@ $<

%.cpp: %.y
	$(YACC) -dvtl -o $@ $<

svLex.cpp: svYacc.cpp

clean:
	rm -f $(OBJS) svLex.cpp svYacc.cpp svYacc.hpp svYacc.output

purge: clean
	rm -f $(OBJS) $(LIB)
