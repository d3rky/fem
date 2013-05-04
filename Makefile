CC=g++
CFLAGS=-c -Wall

SOURCE_DIR=src
BUILD_DIR=build

# define .cpp for modules
FINITE_CPP = $(SOURCE_DIR)/fe/AbstractFiniteElement.cpp $(SOURCE_DIR)/fe/LinearFiniteElement.cpp
FINITE_CPP += $(SOURCE_DIR)/fe/FiniteElementFactory.cpp

BAR_CPP = $(SOURCE_DIR)/bar/BarDiscret.cpp
SOLVER_CPP = $(SOURCE_DIR)/solver/GaussSeidel.cpp
UTILS_CPP = $(SOURCE_DIR)/utils/Utils.cpp
CONDITION_CPP = $(SOURCE_DIR)/boundary_condition/DerichleBoundaryCondition.cpp
MAIN_CPP = $(SOURCE_DIR)/main.cpp

SOURCES=$(CONDITION_CPP) $(BAR_CPP) $(SOLVER_CPP) $(UTILS_CPP) $(FINITE_CPP) $(MAIN_CPP)
OBJECTS=$(SOURCES:.cpp=.o)

all: mke

debug: CFLAGS+=-g -DDEBUG
debug: mke

mke: object_dir $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BUILD_DIR)/mke
	rm -rf $(SOURCE_DIR)/**/*.o

object_dir:
	mkdir -p build

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(SOURCE_DIR)/**/*.o
	rm -rf $(SOURCE_DIR)/*.o
