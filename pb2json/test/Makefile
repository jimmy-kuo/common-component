
CXX=g++

CXXFLAGS=-Wall -O2 

PBINC=/usr/local/include
PBLIB=/usr/local/lib/libprotobuf.a

INCS=-I./ -I../src -I../../rapidjson/ -I${PBINC}
LIBS=${PBLIB} -lpthread

%.o : %.cpp
	${CXX} -c ${CXXFLAGS} ${INCS} $< -o $@

%.o : %.cc
	${CXX} -c ${CCFLAGS} ${INCS} $< -o $@
	
CORE_OBJECTS := Benchmark.o demo.o msg.pb.o ../src/pb2json.o

all: exe
clean:
	-rm -f *.o *.so *.a demo ../src/pb2json.o
exe:  ${CORE_OBJECTS}
	${CXX} -o demo ${CORE_OBJECTS} $(LIBS)
