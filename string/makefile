CC := g++ -g -ggdb

TARGET := exe
CPP := $(wildcard *pp)

$(TARGET) : $(CPP)
	$(CC) $^ -Wall -pedantic -o $@

%.cpp : %.hpp

.PHONY: clean

clean:
	rm -f $(TARGET)
