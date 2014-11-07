CC = g++
TARGET = driver.exe
$(TARGET): UI.o SmugglerShip.o TradeItem.o CinReader.o driver.o
	$(CC)-o $(TARGET) UI.o SmugglerShip.o TradeItem.o driver.o

UI.o: UI.h UI.cpp
	$(CC) -c UI.cpp
	
SmugglerShip.o: SmugglerShip.h SmugglerShip.cpp
	$(CC) -c SmugglerShip.cpp
	
TradeItem.o: TradeItem.h TradeItem.cpp
	$(CC) -c TradeItem.cpp
	
CinReader.o: CinReader.h CinReader.cpp
	$(CC) -c CinReader.cpp
	
driver.o: driver.cpp
	$(CC) -c driver.cpp
	
clean:
	del*.o

cleanall:
	del8.o$(TARGET)