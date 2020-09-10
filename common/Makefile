INCLUDES = -Iinclude -I../om/include

SRCS = src/svBlockContext.cpp	\
       src/svLogger.cpp

OBJS = $(SRCS:%.cpp=%.o)

$(LIB): $(OBJS)
	ld -r -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJS)

purge: clean
	rm -f $(LIB)
