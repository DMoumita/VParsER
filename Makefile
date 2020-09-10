CC = g++
CFLAGS = -g -Wall -std=c++11
INCLUDES = -I. -Iom/include -Icommon/include
EXEC = vper

export CC
export CFLAGS

SRCS = app/main.cpp

OBJS = $(SRCS:%.cpp=%.o)

SUBDIRS =	common      \
		om          \
		parser      \

LIBDIR = .libs
LIBS = $(SUBDIRS:%=$(LIBDIR)/%.lib)

$(EXEC): libs $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS) -lstdc++

libs:
	@mkdir -p $(LIBDIR)
	@for dir in $(SUBDIRS); do \
		echo "Making $$dir.lib ...."; \
	        $(MAKE) -C $$dir LIB=../$(LIBDIR)/$$dir.lib; \
	done

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@for dir in $(SUBDIRS); do \
	        $(MAKE) -C $$dir LIB=../$(LIBDIR)/$$dir.lib clean; \
	done
	rm -f $(OBJS)
	rm -f $(EXEC)

purge: clean
	@for dir in $(SUBDIRS); do \
	        $(MAKE) -C $$dir LIB=../$(LIBDIR)/$$dir.lib purge; \
	done
	rm -f cscope.out
	rm -f $(EXEC)
