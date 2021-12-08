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
        
        manager.readFile(filename);
        WavFile file(manager.getwavHeader(), manager.getData());
        
        cout << manager.getwavHeader();
        cout << file.getWavHeader() << endl;

        cout << "File metadata:" << endl;
        cout << endl;

        cout << "Filename       : " << filename << endl;
        cout << "Sample Rate    : " << file.getWavHeader().sampleRate << endl;
        cout << "Bits Per Sample: " << file.getWavHeader().bitsPerSample << endl;
        cout << "Stereo or Mono : " << (file.getWavHeader().numChannels == 1 ? "Mono":"Stereo") << endl;
        cout << endl;
        
        cout << file.getWavHeader().subChunk2Size;
        string action;

        while(action != "q" || action != "quit"){
            cout << "\nWhat would you like to do?" << endl;
            cout << endl;

            cout << "(N) Normalize" << endl;
            cout << "(E) Echo" << endl;
            cout << "(G) Adjust Gain" << endl;
            cout << "(L) Low-Pass Filter" << endl;
            cout << "(C) Compress / Limit" << endl;
            cout << "(Q) Quit" << endl;

            
            cin >> action;

            AudioProcessor* choice = nullptr;

            if(action == "n" || action == "N"){
                choice = new Normalization();
            }
            else if(action == "e" || action == "E"){
                choice = new Echo();//delay in seconds, loss of return
                cout << "How much would you like the delay to be? (This is going to be in seconds)" << endl;
                float delay;
                cin >> delay;
                cout << "What would you like the decay to be?" << endl;
                float decay;
                cin >> decay;
                
                Echo echo(delay, decay);

            }
            else if(action == "g" || action == "G"){
                choice = new GainAdjustment();//scaling factor
                cout << "How much would you like the adjustment to be?" << endl;
                float scale;
                cin >> scale;

                GainAdjustment gAdjustment(scale);

            }
            else if(action == "l" || action == "L"){
                cout << "What would you like your threshold frequency to be? Enter your value in hertz." << endl;
                unsigned int freq = 5000;
                cin >> freq;
                cout << "Would you like to normalize the audio after? y/n" << endl;
                string normalize;
                bool isNormalizing;
                cin >> normalize;
                if (normalize == "y") isNormalizing = true;
                else if (normalize == "n") isNormalizing = false; 
                choice = new LowPassFilter(freq, isNormalizing);//threshold frequency, if normalizing
                
            }
            else if(action == "c" || action == "C"){

                cout << "How compressed do you want this? Enter a number between 1-100 or 0 for default." << endl;
                float threshold;
                cin >> threshold;
                threshold*=100;
                cout << "Would you like to normalize the audio after? y/n" << endl;
                string normalize;
                bool isNormalizing;
                cin >> normalize;
                if (normalize == "y") isNormalizing = true;
                else if (normalize == "n") isNormalizing = false; 

                choice = new Compressor(threshold, isNormalizing);//threshold volume [0.0,1.0], if normalizing, 
            }
            else if(action == "q" || action == "Q"){
                return 0;
            }
            else{
                cout << "Input is invalid." << endl;
                continue;
            }
            choice->processFile(file);

            cout << "What name would you like the file to be saved as?" << endl;
            string outputFileName = "";
            cin >> outputFileName;

            vector<float> newData(file.getBuffer(), file.getBuffer()+file.getWavHeader().subChunk2Size);
            manager.setData(newData);
            manager.setwavHeader(file.getWavHeader());
            manager.saveFile(outputFileName+".wav");
            main();
        }

    }
    else{
        cout << "Filename is invalid.\n\n";
        main();
    }

    return 0;
}