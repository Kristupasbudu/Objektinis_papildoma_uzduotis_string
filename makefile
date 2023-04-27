CXX=g++
CXXFLAGS=-O1
RM=rm -f

SRCS=1vector.cpp Myfunc1.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: main.exe

main.exe: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(OBJS) main.exe