CC = gcc
CFLAGS = -Wall -Wextra -g3 -Iinclude

SRC_DIR = src
SERVICE_DIR = service
UTILS_DIR = Utils
OUT_DIR = output

OBJ_SRC_DIR = $(OUT_DIR)/src
OBJ_SERVICE_DIR = $(OUT_DIR)/service
OBJ_UTILS_DIR = $(OUT_DIR)/utils

TARGET = $(OUT_DIR)/main.exe

# todos os .c
SRC = $(wildcard $(SRC_DIR)/*.c) \
      $(wildcard $(SERVICE_DIR)/*.c) \
      $(wildcard $(UTILS_DIR)/*.c)

# objetos correspondentes
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_SRC_DIR)/%.o,$(filter $(SRC_DIR)/%,$(SRC))) \
      $(patsubst $(SERVICE_DIR)/%.c,$(OBJ_SERVICE_DIR)/%.o,$(filter $(SERVICE_DIR)/%,$(SRC))) \
      $(patsubst $(UTILS_DIR)/%.c,$(OBJ_UTILS_DIR)/%.o,$(filter $(UTILS_DIR)/%,$(SRC)))

# Detecta se é Windows
MKDIR = if not exist "$(@D)" mkdir "$(@D)"

$(TARGET): $(OBJ)
	if not exist "$(OUT_DIR)" mkdir "$(OUT_DIR)"
	$(CC) $(OBJ) -o $@

$(OBJ_SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_SERVICE_DIR)/%.o: $(SERVICE_DIR)/%.c
	$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
	$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	if exist "$(OBJ_SRC_DIR)" rmdir /S /Q "$(OBJ_SRC_DIR)"
	if exist "$(OBJ_SERVICE_DIR)" rmdir /S /Q "$(OBJ_SERVICE_DIR)"
	if exist "$(OBJ_UTILS_DIR)" rmdir /S /Q "$(OBJ_UTILS_DIR)"
	if exist "$(TARGET)" del "$(TARGET)"

run: $(TARGET)
	$(TARGET)
