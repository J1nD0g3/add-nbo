CC=gcc
TARGET=add-nbo
CXXFLAGS=-g

all: $(TARGET)

$(TARGET) : add-nbo.o
	$(CC) $^ $(LOADLIBES) $(LDLIBS) -o $@ 

clean:
	rm -f $(TARGET)
	rm -f *.o
