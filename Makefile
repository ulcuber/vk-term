CC=g++
FLAGS=-O3 -std=gnu++17
LINKS=-lcurl
EXECUTABLE=bin/run

DOXYGEN_DOCS=docs/doxygen

all: $(EXECUTABLE)

$(EXECUTABLE): obj/main.o obj/Client.o obj/App.o
	$(CC) $(FLAGS) obj/main.o obj/Client.o obj/App.o -o $@ $(LINKS)

obj/main.o: src/main.cpp
	$(CC) $(FLAGS) -c src/main.cpp -o $@ $(LINKS)
obj/Client.o: src/Client.cpp
	$(CC) $(FLAGS) -c src/Client.cpp -o $@ $(LINKS)
obj/App.o: src/App.cpp
	$(CC) $(FLAGS) -c src/App.cpp -o $@ $(LINKS)

$(DOXYGEN_DOCS):
	doxygen Doxyfile

docs: $(DOXYGEN_DOCS)

clean:
	rm -rf ./obj/*

clean-docs:
	rm -rf $(DOXYGEN_DOCS)

clean-exe:
	rm -rf $(EXECUTABLE)

clean-all: clean clean-docs clean-exe
