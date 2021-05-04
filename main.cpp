#include <iostream>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */
#include "HangMan.h"
#include "QuestionDatabase.h"

using namespace std;

int main(){
    srand(time(NULL));
    char wordguess;
    int level;
    cout << "PLEASE CHOOSE A LEVEL(1~3): ";
    cin >> level;
    string ans;
    switch (level) {
        case 1:
            ans = QuestionDataLv1[rand()%QuestionDataLv1.size()];
            break;
        case 2:
            ans = QuestionDataLv2[rand()%QuestionDataLv2.size()];
            break;
        case 3:
            ans = QuestionDataLv3[rand()%QuestionDataLv3.size()];
            break;
        default:
            break;
    }
    //cout << ans << endl;
    HangMan H1(ans);

    while(!H1.IsWin){
        system("clear");
        H1.PrintMessage("HANG MAN");
        H1.PrintWall();
        H1.PrintMessage("Available letters");
        H1.PrintAlphabet();
        H1.PrintMessage("Guess the word");
        H1.PrintAnswer();
        cout << "> ";
        cin >> wordguess;
        H1.CheckAnswer(wordguess);
        if(H1.IsLose){
            system("clear");
            H1.PrintMessage("HANG MAN");
            H1.PrintWall();
            H1.PrintMessage("Available letters");
            H1.PrintAlphabet();
            H1.PrintMessage("Guess the word");
            H1.PrintAnswer();
            cout << "YOU LOSE!!" << endl;
            cout << "THE ANSWER IS " << ans << endl;
            break;
        }
    }
    if(H1.IsWin){
        system("clear");
        H1.PrintMessage("HANG MAN");
        H1.PrintWall();
        H1.PrintMessage("Available letters");
        H1.PrintAlphabet();
        H1.PrintMessage("Guess the word");
        H1.PrintAnswer();
        cout << "YOU WIN!!" << endl;
    }
    return 0;
}

/*
+---------------------------------+
|             HANG MAN            |
+---------------------------------+
|               |                 |
|               |                 |
|               O                 |
|              /|\                |
|               |                 |
|              / \                |
|         +----------+            |
|         |          |            |
+---------------------------------+
|        Available letters        |
+---------------------------------+
|     A B C D E F G H I J K L M   |
|     N O P Q R S T U V W X Y Z   |
+---------------------------------+
|         Guess the word          |
+---------------------------------+
| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |
+---------------------------------+
>
*/
