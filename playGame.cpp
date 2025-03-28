#include <iostream>
#include <ctime>
using namespace std;

char space[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void drawBoard();
void playerMove();
void compMove();
int checkWin();
int drawMatch();
int main()
{
  int numPos, c = 0;
  bool run = true;
  drawBoard();
  while(run)
  {
    playerMove();
    drawBoard();
    if (drawMatch() == 1)
    {
      cout << "\nMatch is DRAWN\n";
      run=false;
    }
    if (checkWin() == 1)
    {
      cout << "\nYou WIN :)\n";
      run=false;
    }

    if (checkWin() == -1)
    {
      cout << "\nYou loose :(\n";
      run=false;
    }
    compMove();
    drawBoard();
    if (drawMatch() == 1)
    {
      cout << "\nMatch is DRAWN\n";
      run=false;
    }
    if (checkWin() == 1)
    {
      cout << "\nYou WIN :)\n";
      run=false;
    }

    if (checkWin() == -1)
    {
      cout << "\nYou loose :(\n";
      run=false;
    }
  }
  return 0;
}
void playerMove()
{
  int num;

  do
  {
    cout << "Enter a positon : ";
    cin >> num;
    if (space[num - 1] == ' ')
    {
      space[num - 1] = 'X';
      break;
    }

  } while (!num > 0 || !num < 8);
}
void compMove()
{
  srand(time(0));
  int pos = rand() % 9;
  do
  {
    if (space[pos] == ' ')
    {
      space[pos] = 'O';
      return;
    }
    else
    {
      pos = rand() % 9;
    }
  } while (1);
}
int checkWin()
{
  int c = 0;

  // ROW Cases
  if ((space[0] == 'X' && space[1] == 'X' && space[2] == 'X') ||
      (space[3] == 'X' && space[4] == 'X' && space[5] == 'X') ||
      (space[6] == 'X' && space[7] == 'X' && space[8] == 'X'))
  {
    c = 1;
  }
  // COLUMN cases
  else if ((space[0] == 'X' && space[3] == 'X' && space[6] == 'X') ||
           (space[1] == 'X' && space[4] == 'X' && space[7] == 'X') ||
           (space[2] == 'X' && space[5] == 'X' && space[8] == 'X'))
  {
    c = 1;
  }
  // Diagonal cases
  else if ((space[0] == 'X' && space[4] == 'X' && space[8] == 'X') ||
           (space[2] == 'X' && space[4] == 'X' && space[6] == 'X'))
  {
    c = 1;
  }

  if ((space[0] == 'O' && space[1] == 'O' && space[2] == 'O') ||
      (space[3] == 'O' && space[4] == 'O' && space[5] == 'O') ||
      (space[6] == 'O' && space[7] == 'O' && space[8] == 'O'))
  {
    c = -1;
  }
  else if ((space[0] == 'O' && space[3] == 'O' && space[6] == 'O') ||
           (space[1] == 'O' && space[4] == 'O' && space[7] == 'O') ||
           (space[2] == 'O' && space[5] == 'O' && space[8] == 'O'))
  {
    c = -1;
  }
  else if ((space[0] == 'O' && space[4] == 'O' && space[8] == 'O') ||
           (space[2] == 'O' && space[4] == 'O' && space[6] == 'O'))
  {
    c = -1;
  }

  return c;
}
int drawMatch()
{
  bool full = true;
  for (int i = 0; i < 9; i++)
  {
    if (space[i] == ' ')
      full = false;
  }
  if (full && checkWin() == 0)
  {
    return 1;
  }
  return -1;
}
void drawBoard()
{

  cout << "\n";

  cout << " " << space[0] << " " << "|" << " " << space[1] << " " << "|" << " " << space[2] << "   \n";
  cout << "   " << "|" << "   " << "|" << "    \n";
  cout << "---" << "|" << "---" << "|" << "---\n";

  cout << " " << space[3] << " " << "|" << " " << space[4] << " " << "|" << " " << space[5] << "   \n";
  cout << "   " << "|" << "   " << "|" << "    \n";
  cout << "---" << "|" << "---" << "|" << "---\n";

  cout << " " << space[6] << " " << "|" << " " << space[7] << " " << "|" << " " << space[8] << "   \n";
  cout << "   " << "|" << "   " << "|" << "    \n";

  cout << "\n";
}