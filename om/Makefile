INCLUDES = -Iinclude -I../common/include

SRCS =  src/svBase.cpp        \
	src/svRoot.cpp        \
	src/svFile.cpp        \
	src/svModule.cpp      \
	src/svDeclBase.cpp    \
	src/svDeclRange.cpp   \
	src/svPort.cpp        \
	src/svNet.cpp        \
	src/svReg.cpp         \
	src/svTri.cpp         \
	src/svAssignExpr.cpp  \
	src/svAssignCombo.cpp \
	src/svInstExpr.cpp    \
	src/svExprBase.cpp    \
	src/svExprOp.cpp      \
	src/svExprConst.cpp   \
	src/svBlock.cpp       \
	src/svAlways.cpp \
	src/svSelectOp.cpp\
	src/svContAssign.cpp \
	src/svNonBlkAssignExpr.cpp \
	src/svInteger.cpp \
	src/svReal.cpp \
	src/svRealTime.cpp \
	src/svTime.cpp \
	src/svMinTypMax.cpp 

OBJS = $(SRCS:%.cpp=%.o)

$(LIB): $(OBJS)
	ld -r -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJS)

purge: clean
	rm -f $(LIB)
