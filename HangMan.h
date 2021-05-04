#ifndef HangMan_h
#define HangMan_h
#define WIDTH 33
#include <vector>
using namespace std;

class HangMan{
public:
    HangMan(){ }
    HangMan(string ans);
    void PrintMessage(string word);
    void PrintWall();
    void PrintAlphabet();
    void CheckAnswer(char c);
    void PrintAnswer();
    bool IsWin = false;
    bool IsLose = false;
    
private:
    vector<char> alphabet= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    vector<char> AnswerSperateWord;
    string answer;
    int guesses = 0;
    void PrintLine();
    void PrintHangman(int guess,int layer);
};


#endif
