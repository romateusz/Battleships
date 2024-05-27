#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <stdlib.h>
#include "terminal.h"
#include <windows.h>


void clearDisplay(){
    system("cls");
    Sleep(50);
}

void displayBoards(std::string nick, int boardlen, std::vector<std::vector<int>> &playerBoard, std::vector<std::vector<int>> &AIBoard){
    std::cout << "Plansza gracza " << nick;
    for(int i = 0; i < 16 * 3 - nick.size(); i++) std::cout << " ";
    std::cout << "Plansza AI\n";   


    for(int i = -1; i < boardlen + 1; i++){
        if (i == -1) std::cout << "   ";
        else if(i == 0) std::cout << " | ";
        else std::cout << " " << i << " ";
    }

    for (int i = 0; i < 16 - boardlen; i++) std::cout << "   ";

    for(int i = -1; i < boardlen + 1; i++){
        if (i == -1) std::cout << "   ";
        else if(i == 0) std::cout << " | ";
        else std::cout << " " << i << " ";
    }
    std::cout << "\n";

    for(int i = -1; i < boardlen + 1; i++){
        if (i == -1) std::cout << "   ";
        else if(i == 0) std::cout << " | ";
        else if(i >= 10) std::cout << "----";
        else std::cout << "---";
    }
    for (int i = 0; i < 16 - boardlen; i++) std::cout << "   ";

    for(int i = -1; i < boardlen + 1; i++){
        if (i == -1) std::cout << "   ";
        else if(i == 0) std::cout << " | ";
        else if(i >= 10) std::cout << "----";
        else std::cout << "---";
    }
    std::cout << "\n";


    std::string tab[16] = {"A", "B", "C", "D", "E", "F",
     "G", "H", "I", "J", "K", "L", "M", "N", "O", "P"};

    for(int i = 0; i < boardlen; i++){
        for(int j = -1; j < boardlen + 1; j++){
            if (j == -1) std::cout << " " << tab[i] << " ";
            else if(j == 0) std::cout << " | ";
            else{
                if(playerBoard[i][j-1] == 1) std::cout << " # ";
                else if(playerBoard[i][j-1] == 2) std::cout << " O ";
                else if(playerBoard[i][j-1] == 3) std::cout << " X ";
                else std::cout << "   ";

                if(j > 9) std::cout << " ";
            }
        }
        for(int i = 0; i < 16 - boardlen; i++) std::cout << "   ";

        for(int j = -1; j < boardlen + 1; j++){
            if (j == -1) std::cout << " " << tab[i] << " ";
            else if(j == 0) std::cout << " | ";
            else{
                if(AIBoard[i][j-1] == 3) std::cout << " X ";
                // else if(AIBoard[i][j-1] == 1) std::cout << " # ";   // DebugOnly
                else if(AIBoard[i][j-1] == 2) std::cout << " O ";
                else std::cout << "   ";

                if(j > 9) std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    for (int i = 0; i < 6; i++) std::cout << "---";
    std::cout<< "\n";
}

bool goodPositioning(int boardlen ,int wsp1, int wsp2, char orient, int dl, std::vector<std::vector<int>> &board){
    bool invade = false;
    if(orient == 'g'){
        if(wsp1 - dl >= 0 ){
            for(int i = 0; i < dl; i++){
                if(board[wsp1-i-1][wsp2-1] == 1) invade = true;
            }
            if(invade == false){
                for(int i = 0; i < dl; i++){
                    board[wsp1-i-1][wsp2-1] = 1;
                }
                return true;
            }
            else return false;
        }
        else return false;
    }
    else if(orient == 'd'){ 
        if(wsp1 + dl - 1 <= boardlen) 
        {
            for(int i = 0; i < dl; i++){
                if(board[wsp1+i-1][wsp2-1] == 1) invade = true;;
            }
            if(invade == false){
                for(int i = 0; i < dl; i++){
                    board[wsp1+i-1][wsp2-1] = 1;
                }
                return true;
            }
            else return false;
        }
        else return false;
    }
    else if(orient == 'l'){
        if(wsp2 - dl >=0 ){

            for(int i = 0; i < dl; i++){
                if(board[wsp1-1][wsp2-i-1] == 1) invade = true;;
            }
            if(invade == false){
                for(int i = 0; i < dl; i++){
                    board[wsp1-1][wsp2-i-1] = 1;
                }
                return true;
            }
            else return false;
        } 
        else return false;
    }
    else{
        if(wsp2 + dl - 1 <= boardlen){


            for(int i = 0; i < dl; i++){
                if(board[wsp1-1][wsp2+i-1] == 1) invade = true;;
            }
            if(invade == false){
                for(int i = 0; i < dl; i++){
                    board[wsp1-1][wsp2+i-1] = 1;
                }
                return true;
            }
            else return false;
        }
        else return false;
    }
}


bool isNum(const std::string& str) {
    for (char znak : str) {
        if (!isdigit(znak)) {
            return false;
        }
    }
    return true;
}

bool isLett(char znak) {
    return isalpha(znak) != 0;
}

void setupGame(){
    std::cout << "Witaj w grze Statki!\n";
    std::cout << "--------------------\n";
    std::string nick = "aaaaaaaaaaaaaaaa";
    std::string inf = "";
    int boardlen = 212;
    while(nick.size() > 14){
        std::cout << inf;
        std::cout << "Podaj swój nick: ";
        std::cin >> nick;
        inf = "Podałeś za długi nickname! (maks. znaków 14)\n";
    }
    inf = "";
    bool exp = false;
    std::string sboardlen;
    while(!exp){
        clearDisplay();
        std::cout << inf;
        std::cout << "Podaj długość kwadratowej planszy na której chcesz zagrać (6-16): ";
        std::cin >> sboardlen;
        if (std::cin.fail()) std::cout << "Wystapil blad podczas wczytywania liczby.\n";
        else{
            if (isNum(sboardlen)) {
                boardlen = stoi(sboardlen);
                if (boardlen < 6 || boardlen > 16) inf = "Podałeś niepoprawną długość planszy!\n";
                else exp = true;
            } 
        else {
            std::cout << "Wczytana wartość nie jest liczbą.\n";
        }
        }
    }

    std::vector<std::vector<int>> playerBoard;
    std::vector<std::vector<int>> AIBoard;
    std::vector<int> tab;
    for(int i=0; i<boardlen; i++) tab.push_back(0);
    for(int i = 0; i<boardlen; i++)
    {
        playerBoard.push_back(tab);
        AIBoard.push_back(tab);
    }
    clearDisplay();
    displayBoards(nick, boardlen, playerBoard, AIBoard);
    
    char ws1;
    std::string ws2;
    int wsp1, wsp2, ori;
    char orient;
    inf = "";
    exp = false;
    for(int dl = 6; dl > 1; dl--){
        while(!exp){
            std::cout << inf;
            std::cout << "Podaj po spacji współrzędne statku o rozmiarze " << dl << " oraz jego orientację (g,d,l,p) np.: A 2 d\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
            std::cin >> ws1 >> ws2 >> orient;
            if (std::cin.fail()) {
                std::cout << "Wystapil blad podczas wczytywania danych.\n";
            }
            else {
                if (!(isLett(ws1) && isNum(ws2) && isLett(orient))) {
                    inf = "Błędny format danych.\n";
                    continue;
                }
            }

            if(ws1 >= 'A' && ws1 <= 'A' + boardlen - 1){
                wsp1 = ws1 + 1 - 'A';
                wsp2 = stoi(ws2);
                if(wsp2 > 0 && wsp2 <=  boardlen){
                    if(orient == 'g' || orient == 'd' || orient == 'l' || orient == 'p')
                        if(goodPositioning(boardlen, wsp1, wsp2, orient, dl, playerBoard)){ 
                            exp = true;
                            inf = "";
                        }
                        else {
                            std::cout << "Podany statek nie spełnia warunków rozgrywki!\n";
                            continue;
                        }
                    else inf = "Podałeś niepoprawną orientację!\n";
                }
                else inf = "Podałeś niepoprawną współrzędną cyfrową!\n";
            }
            else inf = "Podałeś niepoprawną współrzędną literową!\n";
        }
        exp = false;
        while(!exp){
            std::random_device rd;
            std::mt19937 r(rd());
            wsp1 = r() % boardlen + 1;
            wsp2 = r() % boardlen + 1;
            ori = r() % 4 + 1;
            if(ori == 1) orient = 'g';
            else if(ori == 2) orient = 'd';
            else if(ori == 3) orient = 'l';
            else orient = 'p';
            if(goodPositioning(boardlen, wsp1, wsp2, orient, dl, AIBoard)){ 
                exp = true;
            }
        }
        clearDisplay();
        displayBoards(nick, boardlen, playerBoard, AIBoard);
        exp = false;
    }
    game(nick, boardlen, playerBoard, AIBoard);
}

int shoot(std::vector<std::vector<int>> &board, int wsp1, int wsp2, bool player){
    if(!player){
        if(board[wsp1-1][wsp2-1] == 1){
                board[wsp1-1][wsp2-1] = 3;
                return 3;
            }
            else{
                board[wsp1-1][wsp2-1] = 2;
                return 2;
            }
    }
    else{
        if(board[wsp1-1][wsp2-1] == 1){
                board[wsp1-1][wsp2-1] = 3;
                return 3;
            }
        else if(board[wsp1-1][wsp2-1] == 0){
                board[wsp1-1][wsp2-1] = 2;
                return 2;
            }
        else return 1;
    }
}

void playRound(std::string nick, int boardlen, std::vector<std::vector<int>> &playerBoard, std::vector<std::vector<int>> &AIBoard, int numRound, std::vector<int> &score, std::vector<std::pair<int, int>> &AIshoots, std::vector<int>  &prevShoots, std::vector<std::pair<int, int>> &playerShoots){
    clearDisplay();
    std::cout << "Runda " << numRound << "\n"; 
    std::cout << "Wynik gracza " << nick << ": " << score[0] << "   Wynik AI: " << score[1] << "\n";
    displayBoards(nick, boardlen, playerBoard, AIBoard);
    if (prevShoots[0] != -1) std::cout << "Twój strzał: " << char(prevShoots[0] + 'A' - 1) << " " << prevShoots[1] << "   strzał bota: "<< char(prevShoots[2]+ 'A' - 1) << " " << prevShoots[3] << "\n\n";
    char ws1, ws2;
    int wsp1, wsp2, retVal;
    std::string inf = "";
    bool exp = true;
    bool exp2 = true;
    bool player = true;
    while (exp){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
        std::cout << inf;
        std::cout << "Podaj współrzędne twojego strzału w tej rundzie np.(A 1):\n";
        std::cin >> ws1 >> ws2;
        if (std::cin.fail()) {
                std::cout << "Wystapil blad podczas wczytywania danych.\n";
            }
        else {
            if (!(isLett(ws1) && isdigit(ws2))) {
                std::cout << "Błędny format danych.\n";
                continue;
            }
            }
        if(ws1 >= 'A' && ws1 <= 'A' + boardlen - 1){
            wsp2 = ws2 - '0';
            if(wsp2 >= 1 && wsp2 <= boardlen)
            {
                wsp1 = ws1 - 'A' + 1;
                for (int i = 0; i < playerShoots.size(); i++){
                    if(playerShoots[i].first == wsp1 && playerShoots[i].second == wsp2){
                        exp2 = false;
                        playerShoots.erase(playerShoots.begin() + i);
                    }
                }
                if(exp2){
                    inf = "Podano strzelone już pole!\n";
                    continue;
                }
                retVal = shoot(AIBoard, wsp1, wsp2, player);
                exp = false;
                if(retVal == 3) score[0]++;
            }
            else inf = "Podano niepoprawną współrzędną cyfrową!\n";
        }
        else inf = "Podano niepoprawną współrzędną literową!\n";
    }
    prevShoots[0] = wsp1;
    prevShoots[1] = wsp2;

    //poniżej strzał przez AI
    int ran;
    std::pair<int,int> fetchPair;
    std::random_device rd;
    std::mt19937 r(rd());
    player = false;

    ran = r() % (AIshoots.size());
    fetchPair = AIshoots[ran];
    wsp1 = fetchPair.first;
    wsp2 = fetchPair.second;
    AIshoots.erase(AIshoots.begin() + ran);
    retVal = shoot(playerBoard, wsp1, wsp2, player);
    if(retVal == 3) score[1]++;
    prevShoots[2] = wsp1;
    prevShoots[3] = wsp2;
}

void game(std::string nick, int boardlen, std::vector<std::vector<int>> &playerBoard, std::vector<std::vector<int>> &AIBoard){
    clearDisplay();
    displayBoards(nick, boardlen, playerBoard, AIBoard);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    std::cout << "Wpisz start, aby wystartować rozgrywkę!\n";
    bool exp = true;
    std::string s;
    while(exp){
        std::cin >> s;
        if(s == "start" || s == "START") exp = false;
        std::cout << "Wpisz start, aby wystartować rozgrywkę!\n";
    }
    system("cls");
    std::cout << "-----------\nSTART GRY!\n\n";
    int i = 3;
    Sleep(1000);
    while (i >= 0){
        system("cls");
        std::cout << i << "\n";
        Sleep(1000);
        i--;
    }
    int numRound = 1;
    std::vector<int> score;
    score.push_back(0);
    score.push_back(0);
    // stała wartość
    int max_p = 20;
    std::vector<std::pair<int, int>> AIshoots;
    std::vector<std::pair<int, int>> playerShoots;
    for(int i = 1; i< boardlen + 1; i++){
        for (int j = 1; j < boardlen + 1; j++){
            AIshoots.push_back(std::make_pair(i, j));
            playerShoots.push_back(std::make_pair(i, j));
        }
    }
    std::vector<int> prevShoots = {-1, -1, -1, -1};

    while(score[0] < max_p && score[1] < max_p){
        playRound(nick, boardlen, playerBoard, AIBoard, numRound, score, AIshoots, prevShoots, playerShoots);
        numRound++;
    }

    clearDisplay();
    displayBoards(nick, boardlen, playerBoard, AIBoard);
    if (score[0] == score[1]) std::cout << "\n>> REMIS! <<\n";
    else if(score[0] > score[1]) std::cout << "\n>> GRATULACJE! WYGRAŁEŚ ROZGRYWKĘ! <<\n";
    else std::cout << "\n>> PORAŻKA! <<\n";
    std::cout << "Wynik rozgrywki to: " << nick << " " << score[0] << ", AI " << score[1] << "\n";
    int exitVal = -1;
    std::string inf = "";
    while(exitVal < 0){
        std::cout << inf;
        std::cout << "Jeżeli chcesz rozpocząć nową rozgrywkę wpisz poniżej: NOWA, jeżeli chcesz zakończyć wpisz: EXIT\n";
        std::cin >> s;
        if(s == "NOWA") exitVal = 1;
        else if (s == "EXIT") exitVal = 0;
        else inf = "Wpisano niepoprawny napis!\n";
    }
    if(exitVal == 1) setupGame();
}