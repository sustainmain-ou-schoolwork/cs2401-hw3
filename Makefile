CXX = g++
CFLAGS = -g -Wall -std=c++11
NOMAIN = assignment.o date_time.o planner.o
MAINOBJ = main.o
TESTOBJ = test.o
OBJS = $(MAINOBJ) $(NOMAIN)
TESTOBJS = $(TESTOBJ) $(NOMAIN)

a.out: $(OBJS) node.h
	$(CXX) $(CFLAGS) $(OBJS) -o $@

$(MAINOBJ): main.cc assignment.h node.h planner.h
	$(CXX) $(CFLAGS) -c main.cc -o $@

assignment.o: assignment.cc assignment.h
	$(CXX) $(CFLAGS) -c assignment.cc -o $@

date_time.o: date_time.cc date_time.h
	$(CXX) $(CFLAGS) -c date_time.cc -o $@

planner.o: planner.cc planner.h assignment.h date_time.h node.h
	$(CXX) $(CFLAGS) -c planner.cc -o $@


test: $(TESTOBJS) node.h
	$(CXX) $(CFLAGS) $(TESTOBJS) -o $@

$(TESTOBJ): test.cc
	$(CXX) $(CFLAGS) -c test.cc -o $@


clean:
	rm -rf $(NOMAIN) $(MAINOBJ) $(TESTOBJ) a.out test