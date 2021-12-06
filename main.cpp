//main.cpp
//Main file for program and menu logic
//Kevin Munson

#include <iostream>

#include "fileManager.h"
#include "wavfile.h"

#include "normalization.h"
#include "echo.h"
#include "gainadjustment.h"
#include "lowpassfilter.h"
#include "compressor.h"

using namespace std;

int main(){
    // Start
    cout << "Enter the filename you wish to edit:\nor type \"quit\" to quit" << endl;
    string filename;
    cin >> filename;

    if(filename == "quit" || filename == "q"){
        return 0;
    }

    FileManager manager;

    bool canOpen = manager.canOpenFile(filename);
    if(canOpen){
        WavFile file;
        WavHeader header;

        manager.readFile(filename);

        cout << "File metadata:" << endl;
        cout << endl;

        cout << "Filename       : " << filename << endl;
        cout << "Sample Rate    : " << header.sampleRate << endl;
        cout << "Bits Per Sample: " << header.bitsPerSample << endl;
        cout << "Stereo or Mono : " << (header.numChannels == 1 ? "Mono":"Stereo") << endl;
        cout << endl;
        
        while(true){
            cout << "\nWhat would you like to do?" << endl;
            cout << endl;

            cout << "(N) Normalize" << endl;
            cout << "(E) Echo" << endl;
            cout << "(G) Adjust Gain" << endl;
            cout << "(L) Low-Pass Filter" << endl;
            cout << "(C) Compress / Limit" << endl;
            cout << "(Q) Quit" << endl;

            string action;
            cin >> action;

            if(action == "n" || action == "N"){
                Normalization normalize;
                normalize.processFile(file);
            }
            else if(action == "e" || action == "E"){
                Echo echo;
                echo.processFile(file);
            }
            else if(action == "g" || action == "G"){
                GainAdjustment adjustGain;
                adjustGain.processFile(file);
            }
            else if(action == "l" || action == "L"){
                LowPassFilter filter;
                filter.processFile(file);
            }
            else if(action == "c" || action == "C"){
                Compressor compress;
                compress.processFile(file);
            }
            else if(action == "q" || action == "Q"){
                return 0;
            }
            else{
                cout << "Input is invalid." << endl;
                continue;
            }

            manager.saveFile(filename);
            main();
        }

    }
    else{
        cout << "Filename is invalid.\n\n";
        main();
    }

    return 0;
}