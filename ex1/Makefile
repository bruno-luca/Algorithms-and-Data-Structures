# Dichiarazione di variabili
CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = bin/main_ex1
SRCDIR = src
SOURCES_RUN = $(SRCDIR)/main.c $(SRCDIR)/sorting.c $(SRCDIR)/utils.c
HEADERS = $(wildcard $(SRCDIR)/*.h)
OBJECTS_RUN = $(SOURCES_RUN:.c=.o)

# Regola di compilazione per l'eseguibile del comando run
$(TARGET): $(OBJECTS_RUN) | bin
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS_RUN)

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Target per compilare
compile: $(TARGET)

# Target per eseguire
run: bin compile
	./$(TARGET) ./data/records.csv ./data/sorted_records.csv 5 1

# Target per creare l'eseguibile senza avviarlo
build: $(TARGET)

# Pulizia dei file oggetto e dell'eseguibile
clean:
	rm -f $(TARGET) $(OBJECTS_RUN)
	# rm -f ./data/sorted*.csv ./data/*anal*.csv

bin:
	mkdir -p bin
