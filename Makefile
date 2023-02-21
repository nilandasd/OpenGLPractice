COMPILER = g++
VERSION = -std=c++11
BUILD_FLAGS = -g -Wall $(VERSION)
LINK_FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
TARGET = engine
VENDOR_FOLDER = vendor
BUILD = $(COMPILER) -c
LINK = $(COMPILER) -o

GLAD = $(VENDOR_FOLDER)/glad/glad.cpp
STB_IMAGE = $(VENDOR_FOLDER)/stb_image/stb_image.cpp
IMGUI = $(wildcard $(VENDOR_FOLDER)/imgui/*.cpp)
VENDOR_SRC = $(GLAD) $(STB_IMAGE) $(IMGUI)
ENGINE_SRC = $(wildcard *.cpp) $(wildcard tests/*.cpp)
SRC = $(ENGINE_SRC) $(VENDOR_SRC)
OBJS = $(subst .cpp,.o, $(SRC))

ALL: $(TARGET)

run: spotless $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS) 
	$(LINK) $(TARGET) *.o $(LINK_FLAGS)

%.o: %.cpp
	$(BUILD) $< $(BUILD_FLAGS)

spotless: clean
	rm engine || true

clean:
	rm -r engine.dSYM || true
	rm *.o || true
