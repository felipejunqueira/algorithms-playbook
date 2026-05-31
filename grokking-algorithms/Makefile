CC = gcc
CFLAGS = -Wall -Wextra
TARGET = main
SRC = main.c

.PHONY: c p clean

c:
	@$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
	@clear
	@./$(TARGET)

p:
	@clear
	@python3 cobra.py

clean:
	rm -f $(TARGET)
