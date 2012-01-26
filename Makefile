CC=g++
LINKS=-lmingw32 -lSDLmain -lSDL -lSDL_image -lSDL_ttf
SOURCE=source
BUILD=build
ALLOBJ=$(BUILD)/Game.o $(BUILD)/Screen.o $(BUILD)/Input.o $(BUILD)/Sprite.o $(BUILD)/Entity.o $(BUILD)/Player.o $(BUILD)/Debug.o $(BUILD)/GUI.o $(BUILD)/States.o

game : $(ALLOBJ)
	$(CC) -o game $(ALLOBJ) $(LINKS)

$(BUILD)/Game.o : $(SOURCE)/Game.cpp
	$(CC) -o $(BUILD)/Game.o -c $(SOURCE)/Game.cpp

$(BUILD)/Screen.o : $(SOURCE)/Screen.cpp
	$(CC) -o $(BUILD)/Screen.o -c $(SOURCE)/Screen.cpp

$(BUILD)/Input.o : $(SOURCE)/Input.cpp
	$(CC) -o $(BUILD)/Input.o -c $(SOURCE)/Input.cpp

$(BUILD)/Sprite.o : $(SOURCE)/Sprite.cpp
	$(CC) -o $(BUILD)/Sprite.o -c $(SOURCE)/Sprite.cpp

$(BUILD)/Entity.o : $(SOURCE)/Entity.cpp $(BUILD)/Sprite.o
	$(CC) -o $(BUILD)/Entity.o -c $(SOURCE)/Entity.cpp

$(BUILD)/Player.o : $(SOURCE)/Player.cpp $(SOURCE)/Entity.cpp
	$(CC) -o $(BUILD)/Player.o -c $(SOURCE)/Player.cpp
	
$(BUILD)/Debug.o : $(SOURCE)/Debug.cpp
	$(CC) -o $(BUILD)/Debug.o -c $(SOURCE)/Debug.cpp
	
$(BUILD)/GUI.o : $(SOURCE)/GUI.cpp
	$(CC) -o $(BUILD)/GUI.o -c $(SOURCE)/GUI.cpp
	
$(BUILD)/States.o : $(SOURCE)/States.cpp
	$(CC) -o $(BUILD)/States.o -c $(SOURCE)/States.cpp