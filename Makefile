.PHONY: all run clean

SOURCE := src/main.cpp src/wiggle.hpp
BINARY := wiggle

all: $(BINARY)

$(BINARY): $(SOURCE)
	$(CXX) -o $@ $^

run:
	./$(BINARY)

clean:
	rm -f ./$(BINARY)
