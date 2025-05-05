# Diretórios
SRC_DIR := src
BUILD_DIR := build

# Arquivo final
TARGET := $(BUILD_DIR)/programa.exe

# Fontes
SRC_FILES := $(SRC_DIR)/main.c \
             $(SRC_DIR)/dados/dados.c \
             $(SRC_DIR)/livroDeReceitas/livro.c \
             $(SRC_DIR)/receita/receita.c

# Includes
INCLUDES := -I$(SRC_DIR)/livroDeReceitas -I$(SRC_DIR)/receita -I$(SRC_DIR)/dados

# Compilador e flags
CC := gcc
CFLAGS := -Wall $(INCLUDES)

# Regra principal
all: $(TARGET)

# Compila e gera o executável
$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Limpa o executável
clean:
	del /Q $(BUILD_DIR)\*.exe 2>nul || exit 0

# Regra para rodar o programa no Windows (CMD)
run:
	if not exist $(TARGET) $(MAKE) all
	chcp 65001 >nul
	$(TARGET)
