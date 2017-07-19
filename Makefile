CXX= clang++
CXXFLAGS= -Wall -L/usr/local/lib -fopenmp -lomp

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
       10-barrier \
       11-atomic \
       12-reduction \
       13-scheduling \
       14-ordered \
       15-loop-dependencies \
       16-sections

all: $(PROGS)

clean:
	rm -f *.o $(PROGS)

.PHONY: all clean
