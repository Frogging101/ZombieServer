SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
LD_FLAGS = -lenet 
CC_FLAGS = -g
TITLE = server

$(TITLE): $(OBJS)
	g++ -o $@ $^ $(LD_FLAGS)
%.o: %.cpp
	g++ $(CC_FLAGS) -c $<

clean:
	rm *.o
	rm $(TITLE)

run:
	./$(TITLE)
