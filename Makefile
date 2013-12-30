EXECUTABLE:=exec

INCLUDES:=.
SRCDIR:=
LIBDIR:=
LIBS:=

CC:=g++
CFLAGS:=-g -Wall -O2
CPPFLAGS+=$(CFLAGS)
CPPFLAGS+=-MMD

SRCS:=$(wildcard *.cpp) $(wildcard $(addsuffix /*.cpp, $(SRCDIR)))
OBJS:=$(patsubst %.cpp, %.o, $(SRCS))
DEPS:=$(patsubst %.o, %.d, $(OBJS))

.PHONY : all deps objs clean

all : $(EXECUTABLE)
deps : $(DEPS)
objs : $(OBJS)
clean :
	@rm -rf *.o
	@rm -rf *.d

-include $(DEPS)
$(EXECUTABLE) : $(OBJS)
	$(CC) -o $(EXECUTABLE) $(OBJS) $(addprefix -I, $(INCLUDES)) $(addprefix -L, $(LIBDIR) $(addprefix -l, $(LIBS)))
