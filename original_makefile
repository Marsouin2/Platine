# Exec name
EXEC = exec/Platine

# Directories
SRC_DIR = code/src
INC_DIR = code/include

SRC_EXT = cpp
OBJ_EXT = o

SRCS = $(wildcard $(SRC_DIR)/*.$(SRC_EXT))
OBJS = $(SRCS:$(SRC_DIR)/%.$(SRC_EXT)=$(SRC_DIR)/%.$(OBJ_EXT))

# Options
CXX = g++
CXXFLAGS = -I$(INC_DIR) -I/opt/homebrew/opt/sfml@2/include -Wall -std=c++17 -Iexternals

LDFLAGS = -L/opt/homebrew/opt/sfml@2/lib
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Default rule
all: $(EXEC)

# Generate exec
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(LDFLAGS) $(SFML_LIBS)

$(SRC_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.$(SRC_EXT)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.$(OBJ_EXT) $(EXEC)

.PHONY: all clean