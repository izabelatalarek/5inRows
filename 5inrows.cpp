#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int n = 0; //columns
int m = 0; // rows
string inputCoordinates;
int actualPlayerNumber{ 1 };

struct player
{
    string mark;
    int playerNumber;
};



int enterRowsandColumns()
{
    cout << "Enter number of rows ";
    cin >> m;
    cout << "Enter number of columns ";
    cin >> n;

    return n, m;
}


vector<vector<string>> createGameBoard(int n, int m) //vector of vector
{
    vector<vector<string>> board;
    for (int i = 0; i < n + 1; i++)
    {
        vector<string> rows;
        for (int j = 0; j < m + 1; j++)
        {
            string temp{};
            temp.push_back(char('A') + i - 1);

            if (j == 0 && i == 0)
            {
                rows.push_back(" ");
            }
            else if (j == 0 && i >= 0)
            {
                rows.push_back(temp);
            }
            else if (j >= 0 && i == 0)
            {
                rows.push_back(to_string(j));
            }
            else
            {
                rows.push_back("0");
            }
        }
        board.push_back(rows);
    }
    return board;
}

void drawBoard(vector<vector<string>> board)
{

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << " " << board[i][j];
        }
        cout << endl;
    }
}

string getMove()
{
    cout << "Enter coordinates to make a move (letter and number): ";
    (cin >> inputCoordinates).get();
    transform(inputCoordinates.begin(), inputCoordinates.end(), inputCoordinates.begin(), toupper);

    return inputCoordinates;
}

int numbersToInt(string inputCoordinates)
{
    int toInt = 0;
    string temp;

    for (int i = 1; i < inputCoordinates.size(); i++)
    {
        temp = inputCoordinates[i] ++;
    }

    toInt = stoi(temp);
    return toInt;
}

bool coordinatesOutside(string inputCoordinates, int m, int n, int otherInput)

{
    int toInt1 = otherInput;

    if ((inputCoordinates[0] > char('A') + m - 1) || (toInt1 < 1 || toInt1 > n))
    {
        cout << "Coordinates out of board or you entered a bad format!Try again: ";
        getMove();
    }

    else
    {
        return true;
    }
}

void implementMark(vector<vector<string>> board, string inputCoordinates, int xx, int yy, player actualPlayer)
{



    // int x{};
    //int y{};


    if (board[xx][yy] == "0")
    {
        board[xx][yy] = actualPlayer.mark;
        cout << endl << board[xx][yy] << endl;
       
    }
}

bool takenCoordinates(string inputCoordinates, vector<vector<string>> board, int otherInput, player actualPlayer)
{
    int y = otherInput; //columns

    char arr = inputCoordinates[0];
    int x = (int)arr - 65 + 1; //rows


   // board[3][4] = "X"; //EXAMPLE

    if (board[x][y] != "0")
    {
        //return false;
        cout << "These coordinates are taken. Choose another one: ";
        getMove();
    }
    else
    {
        implementMark(board, inputCoordinates, x, y, actualPlayer);
        return true;
    }
}

bool isBoardFull(vector<vector<string>> board)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0;j < n; j++)
        {
            if (board[i][j] == "0")
            {
             return false;
            }
            else if ((board[i][j]== board[m][n]) && (board[i][j] != "0"))
            {
                cout << "The board if full";
                return true;
            }
        }
    }

}





int main()
{
    player player1;
    player1.mark = "X";

    player player2;
    player2.mark = "O";


    enterRowsandColumns();
    vector<vector<string>> tablica;
    tablica = createGameBoard(m, n);
    drawBoard(tablica);



    /*   getMove();
       coordinatesOutside(inputCoordinates, m, n, numbersToInt(inputCoordinates));
       takenCoordinates(inputCoordinates, tablica, numbersToInt(inputCoordinates)); */

    for (;;)
    {
        if (actualPlayerNumber == 1)
        {
            getMove();
            coordinatesOutside(inputCoordinates, m, n, numbersToInt(inputCoordinates));
            takenCoordinates(inputCoordinates, tablica, numbersToInt(inputCoordinates), player1);

            actualPlayerNumber = 2;
        }
        else if (actualPlayerNumber == 2)
        {
            getMove();
            coordinatesOutside(inputCoordinates, m, n, numbersToInt(inputCoordinates));
            takenCoordinates(inputCoordinates, tablica, numbersToInt(inputCoordinates), player2);

            actualPlayerNumber = 1;
        }

        drawBoard(tablica);
    }


}