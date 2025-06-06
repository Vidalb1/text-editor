CXX = g++
CXXFLAGS = -Wall

proj: proj.cpp TextEditor.o Document.o Line.o
	$(CXX) $(CXXFLAGS) proj.cpp TextEditor.o Document.o Line.o -o proj

TextEditor.o: TextEditor.h TextEditor.cpp Document.o Line.o
	$(CXX) $(CXXFLAGS) -c TextEditor.cpp

Document.o: Document.h Document.cpp Line.o
	$(CXX) $(CXXFLAGS) -c Document.cpp

Line.o: Line.h Line.cpp
	$(CXX) $(CXXFLAGS) -c Line.cpp

val:
	valgrind ./proj

run:
	./proj

clean:
	rm *~
