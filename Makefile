CXX = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o assignment.o date_time.o planner.o

a.out: $(OBJS) node.h
	$(CXX) $(CFLAGS) $(OBJ) -o $@

main.o: main.cc assignment.h planner.h node.h
	$(CXX) $(CFLAGS) main.cc -o $@

assignment.o: assignment.cc assignment.h
	$(CXX) $(CFLAGS) assignment.cc -o $@

date_time.o: date_time.cc date_time.h
	$(CXX) $(CFLAGS) date_time.cc -o $@

planner.o: planner.cc planner.h date_time.h
	$(CXX) $(CFLAGS) planner.cc -o $@

clean:
	rm -rf $(OBJS) a.out