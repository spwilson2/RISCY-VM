#TODO: Add header change detection
# Allow directories
CC:=gcc
CFLAGS:=-c -Wall
LDFLAGS:=
SOURCES:= main.c parse.c
OBJECTS:=$(SOURCES:.c=.o)
EXECUTABLE:=a.out

all: $(SOURCES) $(EXECUTABLE)
	    
$(EXECUTABLE): $(OBJECTS) 
	    $(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	    $(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
