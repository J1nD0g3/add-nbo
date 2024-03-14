CC=gcc
TARGET=add-nbo
OBJS=add-nbo.o

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)

add-nbo.o : add-nbo.c
	$(CC) -c -o add-nbo.o add-nbo.c

clean:
	rm $(OBJECT) $(TARGET)
