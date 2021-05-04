#include <iostream>
#include <vector>
#include <cmath>
#include "HangMan.h"

using namespace std;

HangMan::HangMan(string ans){
    answer = ans;
    for(int i=0 ; i<answer.length() ; i++){
        AnswerSperateWord.push_back('_');
    }
}
void HangMan::PrintMessage(string word){
    PrintLine();
    cout << "|";
    for(int i=0; i<round((double)(WIDTH-word.length())/2) ;i++){
        cout << " ";
    }
    cout << word;
    for(int i=0; i<(WIDTH-word.length())/2 ;i++){
        cout << " ";
    }
    cout << "|" << endl;
    PrintLine();
}
void HangMan::PrintWall(){
    for (int i = 0; i < 6 ; i++){
        if(i==3 || i==5){
            cout << "|              ";
            PrintHangman(guesses,i);
            cout << "                |" << endl;
        }
        else{
            cout << "|               ";
            PrintHangman(guesses,i);
            cout << "                 |" << endl;
        }
    }
    cout << "|          +----------+           |" << endl;
    cout << "|          |          |           |" << endl;
}
void HangMan::PrintAlphabet(){
    cout << "|     ";
    for(int i=0 ; i<13 ; i++){
        cout << alphabet[i] << " ";
    }
    cout << "  |" << endl << "|     ";
    for(int i=0 ; i<13 ; i++){
        cout << alphabet[i+13] << " ";
    }
    cout << "  |" << endl;
}
void HangMan::CheckAnswer(char c){
    if(c >= 'a' && c <= 'z'){
        c -= 'a' - 'A';
    }
    alphabet[int(c)-65] = ' ';
    bool IsRight = false;
    for(int i=0 ; i<answer.length() ; i++){
        if(answer[i] == c){
            AnswerSperateWord[i] = c;
            IsRight = true;
        }
    }
    if(!IsRight){
        guesses++;
    }
    for(int i=0 ; i<AnswerSperateWord.size() ; i++){
        IsWin = true;
        if(AnswerSperateWord[i]=='_'){
            IsWin = false;
            break;
        }
    }
    if(guesses == 9){
        IsLose = true;
    }
}

void HangMan::PrintAnswer(){
    cout << "|";
    for(int i=0 ; i<((double)WIDTH-answer.length()*2)/2;i++){
        cout << " ";
    }
    for(int i=0 ; i<answer.length() ; i++){
        cout << AnswerSperateWord[i] << " ";
    }
    for(int i=0 ; i<round(((double)WIDTH-answer.length()*2)/2-1);i++){
        cout << " ";
    }
    cout << "|" << endl;
    PrintLine();
}

void HangMan::PrintLine(){
    cout << "+";
    for(int i=0 ; i<33 ; i++){
        cout << "-";
    }
    cout << "+" << endl;
}

void HangMan::PrintHangman(int guess,int layer){
    switch (layer) {
        case 0:
            if(guess >= 1){
                cout << "|";
            }
            else {
                cout << " ";
            }
            break;
        case 1:
            if(guess >= 2){
                cout << "|";
            }
            else {
                cout << " ";
            }
            break;
        case 2:
            if(guess >= 3){
                cout << "O";
            }
            else {
                cout << " ";
            }
            break;
        case 3:
            if(guess == 4){
                cout << "/  ";
            }
            else if(guess == 5){
                cout << "/| ";
            }
            else if(guess >= 6){
                cout << "/|\\";
            }
            else{
                cout << "   ";
            }
            break;
        case 4:
            if(guess >= 7){
                cout << "|";
            }
            else {
                cout << " ";
            }
            break;
        case 5:
            if(guess == 8){
                cout << "/  ";
            }
            else if(guess >= 9){
                cout << "/ \\";
            }
            else{
                cout << "   ";
            }
            break;
        default:
            break;
    }
}
