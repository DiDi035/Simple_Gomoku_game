#include"Function.h"
using namespace std;
struct PLAYER
{
	char name[100];
	int NumOfPlayedGame;
	int NumOfWonGame;
};
int main()
{
	int NumPlayer;
	int dai, rong;
	int turn = 0;
	int rule;
	char player;
	PLAYER nguoichoi[5];
	int tick = 1;
	char matrix[60][60];
	loading();
	system("cls");
	AboutScreen();
	for (int k = 1; k <= 7; k++)
	{
		system("cls");
		TextColor(k);
		gotoxy(1, k);
		SplashScreen();
		Sleep(600);
	}
	int i;
	gotoxy(45, 15);
	system("pause");
	int n, out = 0;
	int h, w;
	int playagain = 0;
	while (1)
	{
		if (playagain == 0)
		{
			system("cls"); 
			gotoxy(1, 7);
			SplashScreen();
			cout << setw(68) << "1 - P vs P mode" << endl;

			cout << setw(68) << "2 - P vs C mode" << endl;

			cout << setw(68) << "3 - Option" << endl;

			cout << setw(68) << "4 - Player statistic" << endl;

			cout << setw(68) << "0 - Exit" << endl;
			Sleep(500);
			cout << setw(68) << "Enter your selection: ";
			cin >> n;
		}
		if (n == 0)
		{
			int n0;
			system("cls");
			gotoxy(1, 7);
			SplashScreen();
			cout << setw(68) << "Are you sure?" << endl;
			cout << setw(68) << "1 - Yes" << endl;
			cout << setw(68) << "2 - No" << endl;
			Sleep(500);
			cout << setw(68) << "Enter your selection: ";
			cin >> n0;
			if (n0 == 1)
			{
				return 0;
			}
		}
		else if (n == 1)
		{
			while (1)
			{
				system("cls");
				gotoxy(50, 2);
				cout << "Choose your rule: \n";
				gotoxy(50, 3);
				cout << "1 - NORMAL \n";
				gotoxy(50, 4);
				cout << "2 - TWO-WAY-BLOCKED \n";
				gotoxy(50, 5);
				cout << "Your selection: ";
				cin >> rule;
				system("cls");
				if (rule == 2)
				{
					gotoxy(60, 0);
					cout << " RULE: TWO-WAY-BLOCKED";
				}
				else
				{
					gotoxy(60, 0);
					cout << " RULE: NORMAL";
				}
				gotoxy(60, 2);
				cout << "~~~~~~~INSTRUCTION~~~~~~~";
				gotoxy(60, 3);
				cout << "1 - Press W, S, A, D to move UP, DOWN, LEFT and RIGHT";
				gotoxy(60, 4);
				cout << "2 - Press K to tick";
				gotoxy(60, 5);
				cout << "3 - Press O to save your current game";
				gotoxy(60, 6);
				cout << "4 - Press q to go back to menu";
				gotoxy(60, 7);
				cout << "Note: X always goes first";
				gotoxy(60, 8);
				cout << "Have a good time <3 We love you all" << endl;
				gotoxy(60, 10);
				cout << "Enter the height of board (maximum 30): ";
				cin >> h;
				gotoxy(60, 11);
				cout << "Enter the width of board (maximum 30) : ";
				cin >> w;
				while (h > 30 || w > 30)
				{
					gotoxy(60, 10);
					cout << "Enter the height of board (maximum 30): ";
					cin >> h;
					gotoxy(60, 11);
					cout << "Enter the width of board (maximum 30) : ";
					cin >> w;
				}
				gotoxy(60, 12);
				cout << "Who want to go first?";
				gotoxy(60, 13);
				if (tick == 1)
				{
					cout << "1 - X          2 - O";
					gotoxy(60, 14);
					cout << "Your selection: ";
					int choice;
					cin >> choice;
					if (choice == 2)
					{
						player = 'X';
						gotoxy(60, 15);
						cout << "O goes first";
					}
					else
					{
						player = 'O';
						gotoxy(60, 15);
						cout << "X goes first";
					}
				}
				else if (tick == 2)
				{
					cout << "1 - #          2 - @";
					gotoxy(60, 14);
					cout << "Your selection: ";
					int choice;
					cin >> choice;
					if (choice == 2)
					{
						player = '#';
						gotoxy(60, 15);
						cout << "@ goes first";
					}
					else
					{
						player = '@';
						gotoxy(60, 15);
						cout << "# goes first";
					}
				}
				else
				{
					cout << "1 - X          2 - O";
					gotoxy(60, 14);
					cout << "Your selection: ";
					int choice;
					cin >> choice;
					if (choice == 2)
					{
						player = 'X';
						gotoxy(60, 15);
						cout << "O goes first";
					}
					else
					{
						player = 'O';
						gotoxy(60, 15);
						cout << "X goes first";
					}
				}
				gotoxy(0, 0);
				draw(h, w, matrix);
				setup(h, w, matrix);
				gameplay_(h, w, matrix, tick, player, rule, turn);
				system("cls");
				gotoxy(45, 2);
				if (ReturnOrNot() == 0)
					break;
			}
		}
		else if (n == 2)
		{
		int e;
			system("cls");
			gotoxy(1, 7);
			SplashScreen();
			cout << setw(68) << "Chosse player: " << endl;
			cout << setw(68) << "1 - player 1" << endl;

			cout << setw(68) << "2 - player 2" << endl;

			cout << setw(68) << "3 - player 3" << endl;

			cout << setw(68) << "4 - player 4" << endl;

			cout << setw(68) << "0 - Back to menu" << endl;
			Sleep(500);
			cout << setw(68) << "Enter your selection: ";
			cin >> e;
			int m;
			if (e == 1)
			{
				ifstream loadnguoichoi;
				loadnguoichoi.open("SavePlayer1.txt");
				loadnguoichoi >> nguoichoi[0].name;
				loadnguoichoi.close();
				system("cls");
				gotoxy(45, 2);
				cout << "Current player: " << nguoichoi[0].name << endl;
				gotoxy(45, 3);
				cout << "Add player?  1 - YES      2 - NO" << endl;
				gotoxy(45, 4);
				cout << "Your selection: ";
				cin >> m;
				if (m == 1)
				{
					system("cls");
					gotoxy(45, 2);
					cout << "Enter player name: ";
					cin.ignore(1000, '\n');
					cin.get(nguoichoi[0].name, 100, '\n');
					nguoichoi[0].NumOfPlayedGame = 0;
					nguoichoi[0].NumOfWonGame = 0;
					ofstream nguoiplay;
					nguoiplay.open("SavePlayer1.txt");
					nguoiplay << nguoichoi[0].name;
					nguoiplay.close();
					ofstream gamethang, gamechoi;
					gamethang.open("NumOfWonGame1.txt");
					gamethang << nguoichoi[0].NumOfWonGame;
					gamethang.close();
					gamechoi.open("NumOfPlayedGame1.txt");
					gamechoi << nguoichoi[0].NumOfPlayedGame;
					gamechoi.close();
					e = 1;
				}
			}
			else if (e == 2)
			{
				ifstream loadnguoichoi;
				loadnguoichoi.open("SavePlayer2.txt");
				loadnguoichoi >> nguoichoi[1].name;
				loadnguoichoi.close();
				system("cls");
				gotoxy(45, 2);
				cout << "Current player: " << nguoichoi[1].name << endl;
				gotoxy(45, 3);
				cout << "Add player?  1 - YES      2 - NO" << endl;
				gotoxy(45, 4);
				cout << "Your selection: ";
				cin >> m;
				if (m == 1)
				{
					system("cls");
					gotoxy(45, 2);
					cout << "Enter player name: ";
					cin.ignore(1000, '\n');
					cin.get(nguoichoi[1].name, 100, '\n');
					ofstream nguoiplay;
					nguoiplay.open("SavePlayer2.txt");
					nguoiplay << nguoichoi[1].name;
					nguoiplay.close();
					nguoichoi[1].NumOfPlayedGame = 0;
					nguoichoi[1].NumOfWonGame = 0;
					ofstream gamethang, gamechoi;
					gamethang.open("NumOfWonGame2.txt");
					gamethang << nguoichoi[1].NumOfWonGame;
					gamethang.close();
					gamechoi.open("NumOfPlayedGame2.txt");
					gamechoi << nguoichoi[1].NumOfPlayedGame;
					gamechoi.close();
					e = 2;
				}
			}
			else if (e == 3)
			{
				ifstream loadnguoichoi;
				loadnguoichoi.open("SavePlayer3.txt");
				loadnguoichoi >> nguoichoi[2].name;
				loadnguoichoi.close();
				system("cls");
				gotoxy(45, 2);
				cout << "Current player: " << nguoichoi[2].name << endl;
				gotoxy(45, 3);
				cout << "Add player?  1 - YES      2 - NO" << endl;
				gotoxy(45, 4);
				cout << "Your selection: ";
				cin >> m;
				if (m == 1)
				{
					system("cls");
					gotoxy(45, 2);
					cout << "Enter player name: ";
					cin.ignore(1000, '\n');
					cin.get(nguoichoi[2].name, 100, '\n');
					ofstream nguoiplay;
					nguoiplay.open("SavePlayer3.txt");
					nguoiplay << nguoichoi[2].name;
					nguoiplay.close();
					nguoichoi[2].NumOfPlayedGame = 0;
					nguoichoi[2].NumOfWonGame = 0;
					ofstream gamethang, gamechoi;
					gamethang.open("NumOfWonGame3.txt");
					gamethang << nguoichoi[2].NumOfWonGame;
					gamethang.close();
					gamechoi.open("NumOfPlayedGame3.txt");
					gamechoi << nguoichoi[2].NumOfPlayedGame;
					gamechoi.close();
					e = 3;
				}
			}
			else if (e == 4)
			{
				ifstream loadnguoichoi;
				loadnguoichoi.open("SavePlayer4.txt");
				loadnguoichoi >> nguoichoi[3].name;
				loadnguoichoi.close();
				system("cls");
				gotoxy(45, 2);
				cout << "Current player: " << nguoichoi[3].name << endl;
				gotoxy(45, 3);
				cout << "Add player?  1 - YES      2 - NO" << endl;
				gotoxy(45, 4);
				cout << "Your selection: ";
				cin >> m;
				if (m == 1)
				{
					system("cls");
					gotoxy(45, 2);
					cout << "Enter player name: ";
					cin.ignore(1000, '\n');
					cin.get(nguoichoi[3].name, 100, '\n');
					ofstream nguoiplay;
					nguoiplay.open("SavePlayer4.txt");
					nguoiplay << nguoichoi[3].name;
					nguoiplay.close();
					nguoichoi[3].NumOfPlayedGame = 0;
					nguoichoi[3].NumOfWonGame = 0;
					ofstream gamethang, gamechoi;
					gamethang.open("NumOfWonGame4.txt");
					gamethang << nguoichoi[3].NumOfWonGame;
					gamethang.close();
					gamechoi.open("NumOfPlayedGame4.txt");
					gamechoi << nguoichoi[3].NumOfPlayedGame;
					gamechoi.close();
					e = 4;
				}
			}
			else
			{
				out = 1;
			}
			while (out == 0)
			{
				out = 0;
			    system("cls");
				gotoxy(63, 2);
				cout << "~~~~~~~INSTRUCTION~~~~~~~";
				gotoxy(63, 3);
				cout << "1 - Press W, S, A, D to move UP, DOWN, LEFT and RIGHT";
				gotoxy(63, 4);
				cout << "2 - Press K to tick";
				gotoxy(63, 5);
				cout << "3 - Press O to save your current game";
				gotoxy(63, 6);
				cout << "4 - Press q to go back to menu";
				gotoxy(63, 7);
				cout << "Note: X always goes first";
				gotoxy(63, 8);
				cout << "Have a good time <3 We love you all" << endl;
				gotoxy(63, 15);
				cout << "******* " << nguoichoi[e - 1].name << " -  X *******" << endl;
				gotoxy(63, 17);
				cout << "******* COMPUTER  -  O *******" << endl;
				gotoxy(63, 10);
				cout << "Enter the height of board (maximum 30): ";
				cin >> h;
				gotoxy(63, 11);
				cout << "Enter the width of board (maximum 30) : ";
				cin >> w;
				while (h > 30 || w > 30)
				{
					gotoxy(63, 10);
					cout << "Enter the height of board (maximum 30): ";
					cin >> h;
					gotoxy(63, 11);
					cout << "Enter the width of board (maximum 30) : ";
					cin >> w;
				}
				gotoxy(0, 0);
				draw(h, w, matrix);
				setup(h, w, matrix);
				player = 'O';
				ComVsPlayer(h, w, e, matrix, nguoichoi, player);
				system("cls");
				gotoxy(45, 2);
				if (ReturnOrNot() == 0)
					break;
			}
		}
		else if (n == 3)
		{
			while (1)
			{
				int out = 0;
				system("cls");
				gotoxy(1, 7);
				SplashScreen();
				cout << setw(68) << "1 - Player icon (PvP)" << endl;
				cout << setw(68) << "2 - Load Game" << endl;
				cout << setw(68) << "0 - Back" << endl;
				Sleep(500);
				cout << setw(68) << "Enter your selection: ";
				cin >> n;
				if (n == 1)
				{
					int dau;
					system("cls");
					gotoxy(42, 2);
					cout << "1 - Default (player 1: X       player 2: O) \n";
					gotoxy(42, 4);
					cout << "2 - player 1: #       player 2: @ \n";
					gotoxy(42, 6);
					cout << "0 - Back \n";
					gotoxy(42, 8);
					cout << "Your selection: ";
					cin >> dau;
					if (dau == 1)
					{
						tick = dau;
						system("cls");
						gotoxy(40, 3);
						cout << "The icon have been changed successfully \n";
						system("pause");
						break;
					}
					if (dau == 2)
					{
						tick = dau;
						system("cls");
						gotoxy(40, 3);
						cout << "The icon have been changed successfully \n";
						gotoxy(40, 4);
						system("pause");
						break;
					}
				}
				else if (n == 2)
				{
					system("cls");
					gotoxy(1, 7);
					SplashScreen();
					cout << setw(68) << "1 - PvP" << endl;
					cout << setw(68) << "2 - PvC" << endl;
					cout << setw(68) << "Enter your selection: ";
					cin >> n;
					if (n == 1)
					{
						system("cls");
						gotoxy(1, 7);
						SplashScreen();
						cout << setw(68) << "1 - <SAVE FILE 1>\n";
						cout << setw(68) << "2 - <SAVE FILE 2>\n";
						cout << setw(68) << "3 - <SAVE FILE 3>\n";
						cout << setw(68) << "4 - <SAVE FILE 4>\n";
						cout << setw(68) << "0 - go back to menu\n";
						cout << setw(68) << "Choose your selection: ";
						cin >> n;
						if (n == 1)
						{
							system("cls");
							LoadTurn1(player);
							load1(matrix, dai, rong);
							LoadGame1(dai, rong, tick, rule);
							gameplay_(dai, rong, matrix, tick, player, rule, turn);
							if (ReturnOrNot() == 0)
								break;
							else
							{
								n = 1;
								playagain++;
								break;
							}
						}
						else if (n == 2)
						{
							system("cls");
							LoadTurn2(player);
							load2(matrix, dai, rong);
							LoadGame2(dai, rong, tick, rule);
							gameplay_(dai, rong, matrix, tick, player, rule, turn);
							if (ReturnOrNot() == 0)
								break;
							else
							{
								n = 1;
								playagain++;
								break;
							}
						}
						else if (n == 3)
						{
							system("cls");
							LoadTurn3(player);
							load3(matrix, dai, rong);
							LoadGame3(dai, rong, tick, rule);
							gameplay_(dai, rong, matrix, tick, player, rule, turn);
							if (ReturnOrNot() == 0)
								break;
							else
							{
								n = 1;
								playagain++;
								break;
							}
						}
						else if (n == 4)
						{
							system("cls");
							LoadTurn4(player);
							load4(matrix, dai, rong);
							LoadGame4(dai, rong, tick, rule);
							gameplay_(dai, rong, matrix, tick, player, rule, turn);
							if (ReturnOrNot() == 0)
								break;
							else
							{
								n = 1;
								playagain++;
								break;
							}
						}
						else break;
					}
					else if (n == 2)
					{
						system("cls");
						gotoxy(1, 7);
						SplashScreen();
						cout << setw(68) << "1 - <SAVE FILE 1>\n";
						cout << setw(68) << "2 - <SAVE FILE 2>\n";
						cout << setw(68) << "3 - <SAVE FILE 3>\n";
						cout << setw(68) << "4 - <SAVE FILE 4>\n";
						cout << setw(68) << "0 - go back to menu\n";
						cout << setw(68) << "Choose your selection: ";
						cin >> n;
						if (n == 1)
						{
							system("cls");
							loadCom1(matrix, dai, rong);
							LoadPvC1(dai, rong, NumPlayer, nguoichoi);
							ComVsPlayer(dai, rong, NumPlayer, matrix, nguoichoi, 'O');
						}
						else if (n == 2)
						{
							system("cls");
							loadCom2(matrix, dai, rong);
							LoadPvC2(dai, rong, NumPlayer, nguoichoi);
							ComVsPlayer(dai, rong, NumPlayer, matrix, nguoichoi, 'O');
						}
						else if (n == 3)
						{
							system("cls");
							loadCom3(matrix, dai, rong);
							LoadPvC3(dai, rong, NumPlayer, nguoichoi);
							ComVsPlayer(dai, rong, NumPlayer, matrix, nguoichoi, 'O');
						}
						else if (n == 4)
						{
							system("cls");
							loadCom4(matrix, dai, rong);
							LoadPvC4(dai, rong, NumPlayer, nguoichoi);
							ComVsPlayer(dai, rong, NumPlayer, matrix, nguoichoi, 'O');
						}
						else break;
					}
				}
				else break;
			}
		}
		else if (n == 4)
		{
			while (1)
			{
				system("cls");
				gotoxy(1, 7);
				SplashScreen();
				cout << setw(68) << "1 - player 1" << endl;

				cout << setw(68) << "2 - player 2" << endl;

				cout << setw(68) << "3 - player 3" << endl;

				cout << setw(68) << "4 - player 4" << endl;

				cout << setw(68) << "0 - Back to menu" << endl;
				cout << setw(68) << "Chosse player: ";
				cin >> n;
				if (n == 1)
				{
					system("cls");
					ifstream nguoichoigame, sogamethang, sogamechoi;
					nguoichoigame.open("SavePlayer1.txt");
					nguoichoigame >> nguoichoi[0].name;
					nguoichoigame.close();
					sogamechoi.open("NumOfPlayedGame1.txt");
					sogamechoi >> nguoichoi[0].NumOfPlayedGame;
					sogamechoi.close();
					sogamethang.open("NumOfWonGame1.txt");
					sogamethang >> nguoichoi[0].NumOfWonGame;
					sogamethang.close();
					cout << setw(68) << "Player name: " << nguoichoi[0].name << endl;
					cout << setw(68) << "Number of played game: " << nguoichoi[0].NumOfPlayedGame << endl;
					cout << setw(68) << "Number of won game: " << nguoichoi[0].NumOfWonGame << endl;
					cout << setw(68) << "0 - Back to menu" << endl;
					cin >> n;
					if (n == 0) break;
				}
				else if (n == 2)
				{
					system("cls");
					ifstream nguoichoigame, sogamethang, sogamechoi;
					nguoichoigame.open("SavePlayer2.txt");
					nguoichoigame >> nguoichoi[1].name;
					nguoichoigame.close();
					sogamechoi.open("NumOfPlayedGame2.txt");
					sogamechoi >> nguoichoi[1].NumOfPlayedGame;
					sogamechoi.close();
					sogamethang.open("NumOfWonGame2.txt");
					sogamethang >> nguoichoi[1].NumOfWonGame;
					sogamethang.close();
					cout << setw(68) << "Player name: " << nguoichoi[1].name << endl;
					cout << setw(68) << "Number of played game: " << nguoichoi[1].NumOfPlayedGame << endl;
					cout << setw(68) << "Number of won game: " << nguoichoi[1].NumOfWonGame << endl;
					cout << setw(68) << "0 - Back to menu" << endl;
					cin >> n;
					if (n == 0) break;
				}
				else if (n == 3)
				{
					system("cls");
					ifstream nguoichoigame, sogamethang, sogamechoi;
					nguoichoigame.open("SavePlayer3.txt");
					nguoichoigame >> nguoichoi[2].name;
					nguoichoigame.close();
					sogamechoi.open("NumOfPlayedGame3.txt");
					sogamechoi >> nguoichoi[2].NumOfPlayedGame;
					sogamechoi.close();
					sogamethang.open("NumOfWonGame3.txt");
					sogamethang >> nguoichoi[2].NumOfWonGame;
					sogamethang.close();
					cout << setw(68) << "Player name: " << nguoichoi[2].name << endl;
					cout << setw(68) << "Number of played game: " << nguoichoi[2].NumOfPlayedGame << endl;
					cout << setw(68) << "Number of won game: " << nguoichoi[2].NumOfWonGame << endl;
					cout << setw(68) << "0 - Back to menu" << endl;
					cin >> n;
					if (n == 0) break;
				}
				else if (n == 4)
				{
					system("cls");
					ifstream nguoichoigame, sogamethang, sogamechoi;
					nguoichoigame.open("SavePlayer4.txt");
					nguoichoigame >> nguoichoi[3].name;
					nguoichoigame.close();
					sogamechoi.open("NumOfPlayedGame4.txt");
					sogamechoi >> nguoichoi[3].NumOfPlayedGame;
					sogamechoi.close();
					sogamethang.open("NumOfWonGame4.txt");
					sogamethang >> nguoichoi[3].NumOfWonGame;
					sogamethang.close();
					cout << setw(68) << "Player name: " << nguoichoi[3].name << endl;
					cout << setw(68) << "Number of played game: " << nguoichoi[3].NumOfPlayedGame << endl;
					cout << setw(68) << "Number of won game: " << nguoichoi[3].NumOfWonGame << endl;
					cout << setw(68) << "0 - Back to menu" << endl;
					cin >> n;
					if (n == 0) break;
				}
				else break;
			}
		}
	}
	system("pause");
	return 0;
}