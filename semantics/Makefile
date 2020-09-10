INCLUDES = -Iinclude -I../om/include -I../common/include

SRCS =  src/svBase.cpp        \
	src/svRoot.cpp        \
	src/svFile.cpp        \
	src/svModule.cpp      \
	src/svDeclBase.cpp    \
	src/svPort.cpp        \
	src/svWire.cpp        \
	src/svReg.cpp         \
	src/svAssignExpr.cpp  \
	src/svAssignCombo.cpp \
	src/svInstExpr.cpp    \
	src/svExprBase.cpp    \
	src/svExprOp.cpp      \
	src/svExprConst.cpp   \
	src/svSelectOp.cpp

OBJS = $(SRCS:%.cpp=%.o)

$(LIB): $(OBJS)
	ld -r -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJS)

purge: clean
	rm -f $(LIB)
