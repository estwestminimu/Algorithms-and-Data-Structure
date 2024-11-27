#Kompilator
CXX = g++

#Flagi
CXXFLAGS = -Wall -std=c++11

#Plik zrodłowe
SRCS = main.cpp

#Koncowy plik wykonywalny
TARGET = main.out



$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)


.PHONY : clean

clean :
	$(RM) $(TARGET) *.o core
