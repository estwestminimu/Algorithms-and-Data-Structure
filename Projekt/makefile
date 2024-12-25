#Kompilator
CXX = g++

#Flagi
CXXFLAGS = -Wall -std=c++11


# Pliki źródłowe
SOURCES = main.cpp test.cpp quickhull.cpp
HEADERS = Point.h quickhull.h test.h

#Koncowy plik wykonywalny
TARGET = main.out

# Uruchomienie
run: $(TARGET)
	./$(TARGET)

# Kompilacja
all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ $(SOURCES)

.PHONY : clean

clean :
	$(RM) $(TARGET) *.o core




