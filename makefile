wav: fileManager.o wavHeader.o wavfile.o
	g++ -o wav fileManager.o wavHeader.o wavfile.o

fileManager.o: fileManager.cpp
	g++ -c fileManager.cpp fileManager.h

wavHeader.o: wavheader.cpp
	g++ -c wavheader.cpp wavheader.h

wavfile.o: wavfile.cpp
	g++ -c wavfile.cpp wavfile.h

clean:
	rm *.o