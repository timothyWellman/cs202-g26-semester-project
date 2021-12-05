wav: audioprocessor.o compressor.o echo.o gainadjustment.o lowpassfilter.o normalization.o fileManager.o wavHeader.o wavfile.o
	g++ -o wav audioprocessor.o compressor.o echo.o gainadjustment.o lowpassfilter.o normalization.o fileManager.o wavHeader.o wavfile.o

audioprocessor.o: audioprocessor.h
	g++ -c audioprocessor.h

compressor.o: compressor.cpp
	g++ -c compressor.cpp compressor.h

echo.o: echo.cpp
	g++ -c echo.cpp echo.h

gainadjustment.o: gainadjustment.cpp
	g++ -c gainadjustment.cpp gainadjustment.h

lowpassfilter.o: lowpassfilter.cpp
	g++ -c lowpassfilter.cpp lowpassfilter.h

normalization.o: normalization.cpp
	g++ -c normalization.cpp normalization.h

fileManager.o: fileManager.cpp
	g++ -c fileManager.cpp fileManager.h

wavHeader.o: wavheader.cpp
	g++ -c wavheader.cpp wavheader.h

wavfile.o: wavfile.cpp
	g++ -c wavfile.cpp wavfile.h

clean:
	rm *.o *.h.gch