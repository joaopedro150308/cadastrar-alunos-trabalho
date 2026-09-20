CC = gcc
CFLAGS = -Wall -Wextra
TARGET = app

# Pasta onde o app.exe ficará (BUILDPATH)
BDPATH = build

all: $(TARGET)

$(TARGET): main.o
	$(CC) $(CFLAGS) $(BDPATH)/$^ -o $(BDPATH)/$@

main.o: app/main.c
	$(CC) $(CFLAGS) -c $^ -o $(BDPATH)/$@

clean:
	del /q $(BDPATH)\ *.o