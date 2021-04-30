#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;
void make_cifred_text_file(string pathFile);

int main()
{
    make_cifred_text_file("hewoWorld.txt");
}

void make_cifred_text_file(string pathFile)
{
    ifstream inFile;
    ofstream outFile;
    string myText;
    char filename[255];
    struct tm *tm;
    time_t now;
    now = time(0);
    tm = localtime(&now);
    sprintf(filename, "files/file_%02d%02d%04d.txt", tm->tm_mon + 1, tm->tm_mday, tm->tm_year + 1900);

    inFile.open(pathFile);
    outFile.open(filename);

    if (!inFile)
    {
        cout << "Unable to open file";
        exit(1);
    }
    while (getline(inFile, myText))
    {
        for (int i = 0; i < myText.length(); i++)
        {
            outFile << setfill('0') << setw(3) << int(myText[i]) << " ";
            cout << setfill('0') << setw(3) << int(myText[i]) << " ";
        }
        outFile << endl;
        cout << endl;
    }
    outFile.close();
    inFile.close();
}