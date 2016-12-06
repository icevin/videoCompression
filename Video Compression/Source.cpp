#include <iostream>
#include <vector>
#include <filesystem>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <string>

#define DEBUG 1

using namespace std;

vector<string> getAllFilesFromList(string filepath) {
	vector<string> filenames;
	#ifdef debug
	filepath = "C:\\Users\\Kevin\\Videos\\Dashcam\\Work\\list.txt";
	#endif
	
	ifstream fileList;
	fileList.open(filepath);
	do {
		string z, buf;
		fileList >> z;
		istringstream buffer(z);
		buffer >> buf;
		filenames.push_back(buf);
	} while (!fileList.eof());

	return filenames;
}

void transcodeVidsInList(vector<string> list) {
	string filesystemInBase = "C:\\Users\\Kevin\\Videos\\Dashcam\\Work\\";
	string filesystemOutBase = "C:\\Users\\Kevin\\Videos\\Dashcam\\Output\\";
	string exe = "C:\\Users\\Kevin\\Videos\\Dashcam\\Work\\CLI\\HandBrakeCLI.exe";
	string executed;

	for (int i = 0; i < list.size(); i++)
	{
		executed = exe + " -i " + filesystemInBase + list[i] + " -o " + filesystemOutBase + list[i];
		system(executed.c_str());
	}
}

int main() {
	vector<string> output = getAllFilesFromList("C:\\Users\\Kevin\\Videos\\Dashcam\\Work\\list.txt");
	for (int i = 0; i < output.size(); i++)
		cout << output[i] << endl;
	cout << output.size() << endl;
	transcodeVidsInList(output);
	return 0;
}

//CONTENTS OF LIST.TXT
/*
2016_0820_191118_708.MP4
2016_0820_191417_709.MP4
2016_0820_191716_710.MP4
2016_0820_192015_711.MP4
2016_0820_192314_712.MP4
2016_0820_192613_713.MP4
2016_0820_192912_714.MP4
2016_0820_193510_716.MP4
2016_0820_193809_717.MP4
2016_0820_194108_718.MP4
2016_0820_194706_720.MP4
2016_0820_195005_721.MP4
2016_0820_195304_722.MP4
2016_0820_201058_728.MP4
2016_0820_201357_729.MP4
2016_0820_201955_731.MP4
2016_0820_202254_732.MP4
2016_0820_202553_733.MP4
2016_0820_202852_734.MP4
2016_0820_203151_735.MP4
2016_0820_203450_736.MP4
2016_0820_203749_737.MP4
2016_0820_204048_738.MP4
2016_0820_204347_739.MP4
2016_0820_204646_740.MP4
2016_0820_204945_741.MP4
2016_0820_205244_742.MP4
2016_0820_205543_743.MP4
2016_0821_105411_010.MP4
2016_0821_105710_011.MP4
2016_0821_110009_012.MP4
2016_0821_110308_013.MP4
2016_0821_110607_014.MP4
2016_0821_110906_015.MP4
2016_0821_111205_016.MP4
2016_0821_111504_017.MP4
2016_0821_111803_018.MP4
2016_0821_112102_019.MP4
2016_0821_112401_020.MP4
2016_0821_112729_021.MP4
2016_0821_113029_022.MP4
2016_0821_113805_023.MP4
2016_0821_114105_024.MP4
2016_0821_114404_025.MP4
2016_0821_134236_026.MP4
2016_0821_134536_027.MP4
2016_0821_134835_028.MP4
2016_0821_135134_029.MP4
2016_0821_135534_030.MP4
2016_0821_142702_039.MP4
2016_0821_143001_040.MP4
2016_0821_143300_041.MP4
2016_0821_143559_042.MP4
2016_0821_170824_043.MP4
2016_0821_171124_044.MP4
2016_0821_171423_045.MP4
2016_0821_171722_046.MP4
2016_0821_172021_047.MP4
2016_0821_172320_048.MP4
2016_0821_172619_049.MP4
2016_0821_195020_050.MP4
2016_0821_195320_051.MP4






*/