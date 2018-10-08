#target: dependencies
#	rule to build
#

# Work cited: https://askubuntu.com/questions/433943/how-to-clean-executable-using-make-clean
# 	      https://www.cs.bu.edu/teaching/cpp/writing-makefiles/

CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -g
CXXFLAGS += -Wall 
#CXXFLAGS += -O3
#CXXFLAGS += -pedantic-errors
#LDFLAGS = -lboost_date_time

OBJS = fileManip.o mainFileManip.o
SRCS = fileManip.cpp mainFileManip.cpp
HEADERS = fileManip.hpp

fileManip: ${OBJS}
	${CXX} ${CXXFLAGS} -o fileManip fileManip.o mainFileManip.o 

fileManip.o: fileManip.cpp ${HEADERS}
	 ${CXX} ${CXXFLAGS} -c fileManip.cpp

fileManip.o: fileManip.hpp

clean: ${OBJS}
	-rm *.o ${OBJS} fileManip
