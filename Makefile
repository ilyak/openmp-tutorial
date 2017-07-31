CXX= g++
CXXFLAGS= -fopenmp

PROGS= 00-hello \
       01-header-and-env \
       02-parallel \
       03-parallel-cout \
       04-nested \
       05-parallel-for \
       06-scoping \
       07-firstprivate \
       08-lastprivate \
       09-single-master-critical \
       10-mutex \
       11-barrier \
       12-atomic \
       13-reduction \
       14-scheduling \
       15-ordered \
       16-loop-dependencies \
       17-sections

all: $(PROGS)

clean:
	rm -f *.o $(PROGS)

.PHONY: all clean
