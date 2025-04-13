CXX = g++
CXXFLAGS = -std=c++11 -Wall

EXEC = dino.exe

SOURCES = src/dino.cpp

all: $(EXEC)

$(EXEC): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	del $(EXEC)  # windows
	# rm -f $(EXEC)  # Linux/Mac