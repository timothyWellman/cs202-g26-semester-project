wav: audioprocessor.h compressor.o echo.o gainadjustment.o lowpassfilter.o normalization.o fileManager.o wavHeader.o wavfile.o
	g++ -o wav compressor.o echo.o gainadjustment.o lowpassfilter.o normalization.o fileManager.o wavHeader.o wavfile.o

compressor.o: compressor.cpp compressor.h normalization.o
	g++ -c compressor.cpp 

echo.o: echo.cpp echo.h normalization.o
	g++ -c echo.cpp

gainadjustment.o: gainadjustment.cpp gainadjustment.h audioprocessor.o
	g++ -c gainadjustment.cpp

lowpassfilter.o: lowpassfilter.cpp lowpassfilter.h normalization.o
	g++ -c lowpassfilter.cpp 

normalization.o: normalization.cpp normalization.h audioprocessor.o
	g++ -c normalization.cpp

fileManager.o: fileManager.cpp fileManager.h
	g++ -c fileManager.cpp

wavHeader.o: wavheader.cpp wavheader.h
	g++ -c wavheader.cpp

wavfile.o: wavfile.cpp wavfile.h wavHeader.o
	g++ -c wavfile.cpp

clean:
	rm *.o *.h.gch