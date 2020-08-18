# my bad; -pedantic is for C compilers,
# I'll exclude that one from now on
CXXFLAGS = -Wall -Wextra

all: circle_client commodity_client string_things
.PHONY: all

circle_client: circle_client.cpp circle.o
	$(CXX) *.o $< -o $@ $(CXXFLAGS)

commodity_client: commodity_client.cpp commodity.o
	$(CXX) *.o $< -o $@ $(CXXFLAGS)

circle.o: circle.cpp

commodity.o: commodity.cpp

string_things: string_things.cpp

.PHONY: clean
clean:
	rm -f *.o *_client string_things
