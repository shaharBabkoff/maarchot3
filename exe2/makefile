#id:324207935 email:shbabkoff123@gmail.com

CXX= g++
CXXFLAGS=-std=c++17 -Wall
SFML_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES=kosaraju_linkedList.cpp kosaraju_matrix.cpp kosaraju_stack.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

stack: kosaraju_stack.o kosaraju_stack.cpp
	$(CXX) $(CXXFLAGS)  -o stack 

list: kosaraju_linkedList.o $(OBJECTS)
	$(CXX) $(CXXFLAGS)  -o list 

matrix: kosaraju_matrix.o $(OBJECTS)
	$(CXX) $(CXXFLAGS)  -o matrix 

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o matrix test list stack