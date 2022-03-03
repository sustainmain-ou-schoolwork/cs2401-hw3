CXX = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o assignment.o date_time.o planner.o

a.out: $(OBJS) node.h
	$(CXX) $(CFLAGS) $(OBJS) -o $@

main.o: main.cc assignment.h planner.h node.h
	$(CXX) $(CFLAGS) -c main.cc -o $@

assignment.o: assignment.cc assignment.h
	$(CXX) $(CFLAGS) -c assignment.cc -o $@

date_time.o: date_time.cc date_time.h
	$(CXX) $(CFLAGS) -c date_time.cc -o $@

planner.o: planner.cc planner.h date_time.h assignment.h node.h
	$(CXX) $(CFLAGS) -c planner.cc -o $@

clean:
	rm -rf $(OBJS) a.out