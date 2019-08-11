#include"Function.h"
using namespace std;
struct PLAYER
{
	char name[100];
	int NumOfPlayedGame;
	int NumOfWonGame;
};
void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoxy(int x, int y)
{
	static HANDLE  h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x,y };
	SetConsoleCursorPosition(h, c);
}
void loading()
{
	int x = 0;
	for (int i = 0; i <= 10; i++)
	{
		gotoxy(45 + x, 13);
		Sleep(500);
		TextColor(176);
		cout << "  ";
		TextColor(7);
		x = x + 3;
		gotoxy(50, 12);
		cout << " LOADING . . . " << i << "0%";
	}
}
void SplashScreen()
{
	ifstream myFile;
	myFile.open("PS.txt", ios::in);
	while (!myFile.eof())
	{
		char plashscreen;
		myFile.get(plashscreen);
		cout << plashscreen;
	}
	myFile.close();
	cout << endl;
}
void AboutScreen()
{
	char text1[] = { "This is the first project of Group 7 from Apcs 2 k18" };
	char text2[] = { "This game contains a lot of effort and hope from us " };
	char text3[] = { "1.Huynh Bao Di - 18125073"};
	char text4[] = { "2.Do Le Duan - 18125127"};
	char text5[] = { "3.Do Minh Nhut - 18125105"};
	gotoxy(35, 8);
	for (int e1 = 0; e1 <= 52; e1++)
	{
		cout << text1[e1];
		Sleep(40);
	}
	Sleep(40);
	gotoxy(35, 10);
	for (int e2 = 0; e2 <= 52; e2++)
	{
		cout << text2[e2];
		Sleep(40);
	}
	Sleep(40);
	gotoxy(49, 12);
	for (int e3 = 0; e3 < 26; e3++)
	{
		cout << text3[e3];
		Sleep(40);
	}
	Sleep(40);
	gotoxy(49, 14);
	for (int e4 = 0; e4 < 24; e4++)
	{
		cout << text4[e4];
		Sleep(40);
	}
	Sleep(40);
	gotoxy(49, 16);
	for (int e5 = 0; e5 < 26; e5++)
	{
		cout << text5[e5];
		Sleep(40);
	}
	gotoxy(44, 18);
	system("pause");

}
void draw(int height, int width, char matrix[60][60])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			matrix[i][j] = '_';
			cout << matrix[i][j] << "|";
		}
		cout << endl;
	}

}
void changeicon(int tick, char &player)
{
	if (tick == 1)
	{
		if (player == 'X')
		{
			TextColor(10);
			player = 'O';
		}
		else
		{
			TextColor(9);
			player = 'X';
		}
	}
	else if (tick == 2)
	{
		if (player == '#')
		{
			TextColor(10);
			player = '@';
		}
		else
		{
			TextColor(9);
			player = '#';
		}
	}
	else
	{
		if (player == 'X')
		{
			TextColor(10);
			player = 'O';
		}
		else
		{
			TextColor(9);
			player = 'X';
		}
	}
}
void play_er(char &player)
{
	if (player == 'X')
	{
		TextColor(10);
		player = 'O';
	}
	else
	{
		TextColor(9);
		player = 'X';
	}

}
void setup(int height, int width, char matrix[60][60])
{
	for (int i = 0; i < 2 * height; i++)
	{
		for (int j = 0; j < 2 * width; j++)
			matrix[i][j] = '_';
	}
}
int X_Win(int check)
{
	int i = 0;
	i += check;
	ifstream XWin;
	XWin.open("XWin.txt", ios::in);
	while (!XWin.eof())
	{
		char X;
		XWin.get(X);
		TextColor(9);
		cout << X;
	}
	XWin.close();
	TextColor(7);
	return i;
}
int O_Win(int check)
{
	int i = 0;
	i += check;
	ifstream OWin;
	OWin.open("OWin.txt", ios::in);
	while (!OWin.eof())
	{
		char O;
		OWin.get(O);
		TextColor(10);
		cout << O;
	}
	OWin.close();
	TextColor(7);
	return i;
}
void icon1_Win()
{
	ifstream Icon1Win;
	Icon1Win.open("# Win.txt", ios::in);
	while (!Icon1Win.eof())
	{
		char X;
		Icon1Win.get(X);
		TextColor(9);
		cout << X;
	}
	Icon1Win.close();
	TextColor(7);

}
void icon2_Win()
{
	ifstream Icon2Win;
	Icon2Win.open("@ Win.txt", ios::in);
	while (!Icon2Win.eof())
	{
		char X;
		Icon2Win.get(X);
		TextColor(10);
		cout << X;
	}
	Icon2Win.close();
	TextColor(7);
}
void SaveGame1(int sa, int ve, char matrix[60][60], int tick, int rule)
{
	ofstream DaiRong1;
	DaiRong1.open("SaveDaiRongBoard1.txt");
	DaiRong1 << sa;
	DaiRong1 << endl;
	DaiRong1 << ve;
	DaiRong1.close();
	ofstream icon;
	icon.open("icon1.txt");
	icon << tick;
	icon.close();
	ofstream luatchoi;
	luatchoi.open("Rule1.txt");
	luatchoi << rule;
	luatchoi.close();
	ofstream save1;
	save1.open("SaveGame1.txt");
	for (int check = 0; check < sa * 2; check += 2)
	{
		for (int check1 = 0; check1 < ve * 2; check1 += 2)
		{
			save1 << matrix[check][check1] << '|';
		}
		save1 << endl;
	}
	save1.close();
	gotoxy(42, 7);
	cout << "Your game has been saved to <SAVE FILE 1> ";
}
void SaveTurn1(char player, int turn)
{
	if (player == 'X') turn = 88;
	else if (player == 'O') turn = 79;
	else if (player == '#') turn = '#';
	else turn = '@';
	ofstream TurnSave1;
	TurnSave1.open("TurnSave1.txt");
	TurnSave1 << turn;
	TurnSave1.close();
}
void LoadTurn1(char &player)
{
	int turnload1;
	ifstream TurnLoad1;
	TurnLoad1.open("TurnSave1.txt");
	TurnLoad1 >> turnload1;
	TurnLoad1.close();
	player = char(turnload1);
}
void load1(char matrix[60][60], int &dai, int &rong)
{
	ifstream DaiRong1;
	DaiRong1.open("SaveDaiRongBoard1.txt");
	DaiRong1 >> dai >> rong;
	DaiRong1.close();
	ifstream load1;
	load1.open("SaveGame1.txt");
	for (int i = 0; i < dai * 2; i += 2)
	{
		for (int j = 0; j < rong * 2; j++)
		{
			load1 >> matrix[i][j];
		}
	}
	load1.close();
}
void LoadGame1(int lo, int ad, int &tick, int &rule)
{
	ifstream icon;
	icon.open("icon1.txt");
	icon >> tick;
	icon.close();
	ifstream luatchoi;
	luatchoi.open("Rule1.txt");
	luatchoi >> rule;
	luatchoi.close();
	char load;
	ifstream load1;
	load1.open("SaveGame1.txt");
	while (!load1.eof())
	{
		load1.get(load);
		if (load == 'X')
		{
			TextColor(9);
			cout << load;
			TextColor(7);
		}
		else if (load == 'O')
		{
			TextColor(10);
			cout << load;
			TextColor(7);
		}
		else if (load == '#')
		{
			TextColor(9);
			cout << load;
			TextColor(7);
		}
		else if (load == '@')
		{
			TextColor(10);
			cout << load;
			TextColor(7);
		}
		else cout << load;
	}
	load1.close();
	if (rule == 1)
	{
		gotoxy(60, 0);
		cout << "RULE: NORMAL";
	}
	else
	{
		gotoxy(60, 0);
		cout << "RULE: TWO-WAY-BLOCKED";
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
	cout << "4 - Press Q to go back to menu";
	gotoxy(60, 7);
	cout << "Note: X always goes first";
	gotoxy(60, 8);
	cout << "Have a good time <3 We love you all" << endl;
	int h, w;
	gotoxy(60, 10);
	cout << "Enter the height of board (maximum 30): " << lo;
	gotoxy(60, 11);
	cout << "Enter the width of board (maximum 30) : " << ad;
}
void SaveGame2(int sa, int ve, char matrix[60][60], int tick, int rule)
{
	ofstream DaiRong2;
	DaiRong2.open("SaveDaiRongBoard2.txt");
	DaiRong2 << sa;
	DaiRong2 << endl;
	DaiRong2 << ve;
	DaiRong2.close();
	ofstream luatchoi;
	luatchoi.open("Rule2.txt");
	luatchoi << rule;
	luatchoi.close();
	ofstream icon;
	icon.open("icon2.txt");
	icon << tick;
	icon.close();
	ofstream save2;
	save2.open("SaveGame2.txt");
	system("cls");
	for (int check = 0; check < sa * 2; check += 2)
	{
		for (int check1 = 0; check1 < ve * 2; check1 += 2)
		{
			save2 << matrix[check][check1] << "|";
		}
		save2 << endl;
	}
	save2.close();
	gotoxy(42, 7);
	cout << "Your game has been saved to <SAVE FILE 2> ";
}
void SaveTurn2(char player, int turn)
{
	if (player == 'X') turn = 88;
	else if (player == 'O') turn = 79;
	else if (player == '#') turn = '#';
	else turn = '@';
	ofstream TurnSave2;
	TurnSave2.open("TurnSave2.txt");
	TurnSave2 << turn;
	TurnSave2.close();
}
void LoadTurn2(char &player)
{
	int turnload2;
	ifstream TurnLoad2;
	TurnLoad2.open("TurnSave2.txt");
	TurnLoad2 >> turnload2;
	TurnLoad2.close();
	player = char(turnload2);
}
void load2(char matrix[60][60], int &dai, int &rong)
{
	ifstream DaiRong2;
	DaiRong2.open("SaveDaiRongBoard2.txt");
	DaiRong2 >> dai >> rong;
	DaiRong2.close();
	ifstream load1;
	load1.open("SaveGame2.txt");
	for (int i = 0; i < dai * 2; i += 2)
	{
		for (int j = 0; j < rong * 2; j++)
		{
			load1 >> matrix[i][j];
		}
	}
	load1.close();
}
void LoadGame2(int lo, int ad, int &tick, int &rule)
{
	ifstream icon;
	icon.open("icon2.txt");
	icon >> tick;
	icon.close();
	ifstream luatchoi;
	luatchoi.open("Rule2.txt");
	luatchoi >> rule;
	luatchoi.close();
	char load;
	ifstream load2;
	load2.open("SaveGame2.txt");
	while (!load2.eof())
	{
		load2.get(load);
		if (load == 'X')
		{
			TextColor(9);
			cout << load;
			TextColor(7);
		}
		else if (load == 'O')
		{
			TextColor(10);
			cout << load;
			TextColor(7);
		}
		else if (load == '#')
		{
			TextColor(9);
			cout << load;
			TextColor(7);
		}
		else if (load == '@')
		{
			TextColor(10);
			cout << load;
			TextColor(7);
		}
		else cout << load;
	}
		load2.close();
		if (rule == 1)
		{
			gotoxy(60, 0);
			cout << "RULE: NORMAL";
		}
		else
		{
			gotoxy(60, 0);
			cout << "RULE: TWO-WAY-BLOCKED";
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
		int h, w;
		gotoxy(60, 10);
		cout << "Enter the height of board (maximum 30): " << lo;
		gotoxy(60, 11);
		cout << "Enter the width of board (maximum 30) : " << ad;

}
void SaveGame3(int sa, int ve, char matrix[60][60], int tick, int rule)
{
	ofstream DaiRong3;
	DaiRong3.open("SaveDaiRongBoard3.txt");
	DaiRong3 << sa;
	DaiRong3 << endl;
	DaiRong3 << ve;
	DaiRong3.close();
	ofstream luatchoi;
	luatchoi.open("Rule3.txt");
	luatchoi << rule;
	luatchoi.close();
	ofstream icon;
	icon.open("icon3.txt");
	icon << tick;
	icon.close();
	ofstream save3;
	save3.open("SaveGame3.txt");
	system("cls");
	for (int check = 0; check < sa * 2; check += 2)
	{
		for (int check1 = 0; check1 < ve * 2; check1 += 2)
		{
			save3 << matrix[check][check1] << "|";
		}
		save3 << endl;
	}
	save3.close();
	gotoxy(42, 7);
	cout << "Your game has been saved to <SAVE FILE 3> ";
}
void SaveTurn3(char player, int turn)
{
	if (player == 'X') turn = 88;
	else if (player == 'O') turn = 79;
	else if (player == '#') turn = '#';
	else turn = '@';
	ofstream TurnSave3;
	TurnSave3.open("TurnSave3.txt");
	TurnSave3 << turn;
	TurnSave3.close();
}
void LoadTurn3(char &player)
{
	int turnload3;
	ifstream TurnLoad3;
	TurnLoad3.open("TurnSave3.txt");
	TurnLoad3 >> turnload3;
	TurnLoad3.close();
	player = char(turnload3);
}
void load3(char matrix[60][60], int &dai, int &rong)
{
	ifstream DaiRong3;
	DaiRong3.open("SaveDaiRongBoard3.txt");
	DaiRong3 >> dai >> rong;
	DaiRong3.close();
	ifstream load3;
	load3.open("SaveGame3.txt");
	for (int i = 0; i < dai * 2; i += 2)
	{
		for (int j = 0; j < rong * 2; j++)
		{
			load3 >> matrix[i][j];
		}
	}
	load3.close();
}
void LoadGame3(int lo, int ad, int &tick, int &rule)
{
	ifstream icon;
	icon.open("icon3.txt");
	icon >> tick;
	icon.close();
	ifstream luatchoi;
	luatchoi.open("Rule3.txt");
	luatchoi >> rule;
	luatchoi.close();
	char load;
	ifstream load3;
	load3.open("SaveGame3.txt");
	while (!load3.eof())
	{
		load3.get(load);
		if (load == 'X')
		{
			TextColor(9);
			cout << load;
			TextColor(7);
		}
		else if (load == 'O')
		{
			TextColor(10);
			cout << load;
			TextColor(7);
		}
		else if (load == '#')
		{
			TextColor(9);
			cout << load;
			TextColor(7);
		}
		else if (load == '@')
		{
			TextColor(10);
			cout << load;
			TextColor(7);
		}
		else cout << load;
	}
		load3.close();
		if (rule == 1)
		{
			gotoxy(60, 0);
			cout << "RULE: NORMAL";
		}
		else
		{
			gotoxy(60, 0);
			cout << "RULE: TWO-WAY-BLOCKED";
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
		int h, w;
		gotoxy(60, 10);
		cout << "Enter the height of board (maximum 30): " << lo;
		gotoxy(60, 11);
		cout << "Enter the width of board (maximum 30) : " << ad;
}
void SaveGame4(int sa, int ve, char matrix[60][60], int tick, int rule)
{
	ofstream DaiRong4;
	DaiRong4.open("SaveDaiRongBoard4.txt");
	DaiRong4 << sa;
	DaiRong4 << endl;
	DaiRong4 << ve;
	DaiRong4.close();
	ofstream luatchoi;
	luatchoi.open("Rule4.txt");
	luatchoi << rule;
	luatchoi.close();
	ofstream icon;
	icon.open("icon4.txt");
	icon << tick;
	icon.close();
	ofstream save4;
	save4.open("SaveGame4.txt");
	system("cls");
	for (int check = 0; check < sa * 2; check += 2)
	{
		for (int check1 = 0; check1 < ve * 2; check1 += 2)
		{
			save4 << matrix[check][check1] << "|";
		}
		save4 << endl;
	}
	save4.close();
	gotoxy(42, 7);
	cout << "Your game has been saved to <SAVE FILE 4> ";
}
void SaveTurn4(char player, int turn)
{
	if (player == 'X') turn = 88;
	else if (player == 'O') turn = 79;
	else if (player == '#') turn = '#';
	else turn = '@';
	ofstream TurnSave4;
	TurnSave4.open("TurnSave4.txt");
	TurnSave4 << turn;
	TurnSave4.close();
}
void LoadTurn4(char &player)
{
	int turnload4;
	ifstream TurnLoad4;
	TurnLoad4.open("TurnSave4.txt");
	TurnLoad4 >> turnload4;
	TurnLoad4.close();
	player = char(turnload4);
}
void load4(char matrix[60][60], int &dai, int &rong)
{
	ifstream DaiRong1;
	DaiRong1.open("SaveDaiRongBoard4.txt");
	DaiRong1 >> dai >> rong;
	DaiRong1.close();
	ifstream load1;
	load1.open("SaveGame4.txt");
	for (int i = 0; i < dai * 2; i += 2)
	{
		for (int j = 0; j < rong * 2; j++)
		{
			load1 >> matrix[i][j];
		}
	}
	load1.close();
}
void LoadGame4(int lo, int ad, int &tick, int &rule)
{
	ifstream icon;
	icon.open("icon4.txt");
	icon >> tick;
	icon.close();
	ifstream luatchoi;
	luatchoi.open("Rule4.txt");
	luatchoi >> rule;
	luatchoi.close();
	char load;
	ifstream load4;
	load4.open("SaveGame4.txt");
	while (!load4.eof())
	{
		load4.get(load);
		if (load == 'X')
		{
			TextColor(9);
			cout << load;
			TextColor(7);
		}
		else if (load == 'O')
		{
			TextColor(10);
			cout << load;
			TextColor(7);
		}
		else if (load == '#')
		{
			TextColor(9);
			cout << load;
			TextColor(7);
		}
		else if (load == '@')
		{
			TextColor(10);
			cout << load;
			TextColor(7);
		}
		else cout << load;
	}
		load4.close();
		if (rule == 1)
		{
			gotoxy(60, 0);
			cout << "RULE: NORMAL";
		}
		else
		{
			gotoxy(60, 0);
			cout << "RULE: TWO-WAY-BLOCKED";
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
		int h, w;
		gotoxy(60, 10);
		cout << "Enter the height of board (maximum 30): " << lo;
		gotoxy(60, 11);
		cout << "Enter the width of board (maximum 30) : " << ad;
}
void SavePvC1(int sa, int ve, int n, char matrix[60][60])
{
	ofstream NumPlayer;
	NumPlayer.open("NumPlayer1.txt");
	NumPlayer << n;
	NumPlayer.close();
	ofstream DaiRong1;
	DaiRong1.open("SaveDaiRongPvc1.txt");
	DaiRong1 << sa;
	DaiRong1 << endl;
	DaiRong1 << ve;
	DaiRong1.close();
	ofstream save1;
	save1.open("SavePvC1.txt");
	system("cls");
	for (int check = 0; check < sa; check++)
	{
		for (int check1 = 0; check1 < ve * 2; check1 += 2)
		{
			save1 << matrix[check][check1] << "|";
		}
		save1 << endl;
	}
	save1.close();
	gotoxy(42, 7);
	cout << "Your game has been saved to <SAVE FILE 1> ";
}
void loadCom1(char matrix[60][60], int &dai, int &rong)
{
	ifstream dairong;
	dairong.open("SaveDaiRongPvc1.txt");
	dairong >> dai;
	dairong >> rong;
	dairong.close();
	ifstream load;
	load.open("SavePvC1.txt");
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong * 2; j++)
		{
			load >> matrix[i][j];
		}
	}
	load.close();
}
void LoadPvC1(int lo, int ad, int &NumPlayer, PLAYER nguoichoi[5])
{
	ifstream SoNguoiChoi;
	SoNguoiChoi.open("NumPlayer1.txt");
	SoNguoiChoi >> NumPlayer;
	SoNguoiChoi.close();
	ifstream TenNguoiChoi;
	if (NumPlayer == 1)
	{
		TenNguoiChoi.open("SavePlayer1.txt");
		TenNguoiChoi >> nguoichoi[NumPlayer - 1].name;
		TenNguoiChoi.close();
	}
	else if (NumPlayer == 2)
	{
		TenNguoiChoi.open("SavePlayer2.txt");
		TenNguoiChoi >> nguoichoi[NumPlayer - 1].name;
		TenNguoiChoi.close();
	}
	else if (NumPlayer == 3)
	{
		TenNguoiChoi.open("SavePlayer3.txt");
		TenNguoiChoi >> nguoichoi[NumPlayer - 1].name;
		TenNguoiChoi.close();
	}
	else
	{
		TenNguoiChoi.open("SavePlayer4.txt");
		TenNguoiChoi >> nguoichoi[NumPlayer - 1].name;
		TenNguoiChoi.close();
	}
	char load;
	ifstream load1;
	load1.open("SavePvC1.txt");
	while (!load1.eof())
	{
		load1.get(load);
		if (load == 'X')
		{
			TextColor(9);
			cout << load;
			TextColor(7);
		}
		else if (load == 'O')
		{
			TextColor(10);
			cout << load;
			TextColor(7);
		}
		else cout << load;
	}
	load1.close();
	gotoxy(60, 2);
	cout << "~~~~~~~INSTRUCTION~~~~~~~";
	gotoxy(60, 3);
	cout << "1 - Press W, S, A, D to move UP, DOWN, LEFT and RIGHT";
	gotoxy(60, 4);
	cout << "2 - Press K to tick";
	gotoxy(60, 5);
	cout << "3 - Press O to save your current game";
	gotoxy(60, 6);
	cout << "4 - Press Q to go back to menu";
	gotoxy(60, 7);
	cout << "Note: X always goes first";
	gotoxy(60, 8);
	cout << "Have a good time <3 We love you all" << endl;
	gotoxy(63, 15);
	cout << "******* " << nguoichoi[NumPlayer - 1].name << " -  X *******" << endl;
	gotoxy(63, 17);
	cout << "******* COMPUTER  -  O *******" << endl;
	gotoxy(60, 10);
	cout << "Enter the height of board (maximum 30): " << lo;
	gotoxy(60, 11);
	cout << "Enter the width of board (maximum 30) : " << ad;
}
void SavePvC2(int sa, int ve, int n, char matrix[60][60])
{
	ofstream NumPlayer;
	NumPlayer.open("NumPlayer2.txt");
	NumPlayer << n;
	NumPlayer.close();
	ofstream DaiRong1;
	DaiRong1.open("SaveDaiRongPvc2.txt");
	DaiRong1 << sa;
	DaiRong1 << endl;
	DaiRong1 << ve;
	DaiRong1.close();
	ofstream save2;
	save2.open("SavePvC2.txt");
	system("cls");
	for (int check = 0; check < sa; check++)
	{
		for (int check1 = 0; check1 < ve * 2; check1 += 2)
		{
			save2 << matrix[check][check1] << "|";
		}
		save2 << endl;
	}
	save2.close();
	gotoxy(42, 7);
	cout << "Your game has been saved to <SAVE FILE 2> ";
}
void loadCom2(char matrix[60][60], int &dai, int &rong)
{
	ifstream dairong;
	dairong.open("SaveDaiRongPvc2.txt");
	dairong >> dai;
	dairong >> rong;
	dairong.close();
	ifstream load;
	load.open("SavePvC2.txt");
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong * 2; j++)
		{
			load >> matrix[i][j];
		}
	}
	load.close();
}
void LoadPvC2(int lo, int ad, int &NumPlayer, PLAYER nguoichoi[5])
{
	ifstream SoNguoiChoi;
	SoNguoiChoi.open("NumPlayer2.txt");
	SoNguoiChoi >> NumPlayer;
	SoNguoiChoi.close();
	ifstream TenNguoiChoi;
	if (NumPlayer == 1)
	{
		TenNguoiChoi.open("SavePlayer1.txt");
		TenNguoiChoi >> nguoichoi[NumPlayer - 1].name;
		TenNguoiChoi.close();
	}
	else if (NumPlayer == 2)
	{
		TenNguoiChoi.open("SavePlayer2.txt");
		TenNguoiChoi >> nguoichoi[NumPlayer - 1].name;
		TenNguoiChoi.close();
	}
	else if (NumPlayer == 3)
	{
		TenNguoiChoi.open("SavePlayer3.txt");
		TenNguoiChoi >> nguoichoi[NumPlayer - 1].name;
		TenNguoiChoi.close();
	}
	else
	{
		TenNguoiChoi.open("SavePlayer4.txt");
		TenNguoiChoi >> nguoichoi[NumPlayer - 1].name;
		TenNguoiChoi.close();
	}
	char load;
	ifstream load1;
	load1.open("SavePvC2.txt");
	while (!load1.eof())
	{
		load1.get(load);
		if (load == 'X')
		{
			TextColor(9);
			cout << load;
			TextColor(7);
		}
		else if (load == 'O')
		{
			TextColor(10);
			cout << load;
			TextColor(7);
		}
		else cout << load;
	}
	load1.close();
	gotoxy(60, 2);
	cout << "~~~~~~~INSTRUCTION~~~~~~~";
	gotoxy(60, 3);
	cout << "1 - Press W, S, A, D to move UP, DOWN, LEFT and RIGHT";
	gotoxy(60, 4);
	cout << "2 - Press K to tick";
	gotoxy(60, 5);
	cout << "3 - Press O to save your current game";
	gotoxy(60, 6);
	cout << "4 - Press Q to go back to menu";
	gotoxy(60, 7);
	cout << "Note: X always goes first";
	gotoxy(60, 8);
	cout << "Have a good time <3 We love you all" << endl;
	gotoxy(63, 15);
	cout << "******* " << nguoichoi[NumPlayer - 1].name << " -  X *******" << endl;
	gotoxy(63, 17);
	cout << "******* COMPUTER  -  O *******" << endl;
	gotoxy(60, 10);
	cout << "Enter the height of board (maximum 30): " << lo;
	gotoxy(60, 11);
	cout << "Enter the width of board (maximum 30) : " << ad;
}
void SavePvC3(int sa, int ve, int n, char matrix[60][60])
{
	ofstream NumPlayer;
	NumPlayer.open("NumPlayer3.txt");
	NumPlayer << n;
	NumPlayer.close();
	ofstream DaiRong1;
	DaiRong1.open("SaveDaiRongPvc3.txt");
	DaiRong1 << sa;
	DaiRong1 << endl;
	DaiRong1 << ve;
	DaiRong1.close();
	ofstream save3;
	save3.open("SavePvC3.txt");
	system("cls");
	for (int check = 0; check < sa; check++)
	{
		for (int check1 = 0; check1 < ve * 2; check1 += 2)
		{
			save3 << matrix[check][check1] << "|";
		}
		save3 << endl;
	}
	save3.close();
	gotoxy(42, 7);
	cout << "Your game has been saved to <SAVE FILE 3> ";
}
void loadCom3(char matrix[60][60], int &dai, int &rong)
{
	ifstream dairong;
	dairong.open("SaveDaiRongPvc3.txt");
	dairong >> dai;
	dairong >> rong;
	dairong.close();
	ifstream load;
	load.open("SavePvC3.txt");
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong * 2; j++)
		{
			load >> matrix[i][j];
		}
	}
	load.close();
}
void LoadPvC3(int lo, int ad, int &NumPlayer, PLAYER nguoichoi[5])
{
	ifstream SoNguoiChoi;
	SoNguoiChoi.open("NumPlayer3.txt");
	SoNguoiChoi >> NumPlayer;
	SoNguoiChoi.close();
	ifstream TenNguoiChoi;
	if (NumPlayer == 1)
	{
		TenNguoiChoi.open("SavePlayer1.txt");
		TenNguoiChoi >> nguoichoi[NumPlayer - 1].name;
		TenNguoiChoi.close();
	}
	else if (NumPlayer == 2)
	{
		TenNguoiChoi.open("SavePlayer2.txt");
		TenNguoiChoi >> nguoichoi[NumPlayer - 1].name;
		TenNguoiChoi.close();
	}
	else if (NumPlayer == 3)
	{
		TenNguoiChoi.open("SavePlayer3.txt");
		TenNguoiChoi >> nguoichoi[NumPlayer - 1].name;
		TenNguoiChoi.close();
	}
	else
	{
		TenNguoiChoi.open("SavePlayer4.txt");
		TenNguoiChoi >> nguoichoi[NumPlayer - 1].name;
		TenNguoiChoi.close();
	}
	char load;
	ifstream load3;
	load3.open("SavePvC3.txt");
	while (!load3.eof())
	{
		load3.get(load);
		if (load == 'X')
		{
			TextColor(9);
			cout << load;
			TextColor(7);
		}
		else if (load == 'O')
		{
			TextColor(10);
			cout << load;
			TextColor(7);
		}
		else cout << load;
	}
	load3.close();
	gotoxy(60, 2);
	cout << "~~~~~~~INSTRUCTION~~~~~~~";
	gotoxy(60, 3);
	cout << "1 - Press W, S, A, D to move UP, DOWN, LEFT and RIGHT";
	gotoxy(60, 4);
	cout << "2 - Press K to tick";
	gotoxy(60, 5);
	cout << "3 - Press O to save your current game";
	gotoxy(60, 6);
	cout << "4 - Press Q to go back to menu";
	gotoxy(60, 7);
	cout << "Note: X always goes first";
	gotoxy(60, 8);
	cout << "Have a good time <3 We love you all" << endl;
	gotoxy(63, 15);
	cout << "******* " << nguoichoi[NumPlayer - 1].name << " -  X *******" << endl;
	gotoxy(63, 17);
	cout << "******* COMPUTER  -  O *******" << endl;
	gotoxy(60, 10);
	cout << "Enter the height of board (maximum 30): " << lo;
	gotoxy(60, 11);
	cout << "Enter the width of board (maximum 30) : " << ad;
}
void SavePvC4(int sa, int ve, int n, char matrix[60][60])
{
	ofstream NumPlayer;
	NumPlayer.open("NumPlayer4.txt");
	NumPlayer << n;
	NumPlayer.close();
	ofstream DaiRong1;
	DaiRong1.open("SaveDaiRongPvc4.txt");
	DaiRong1 << sa;
	DaiRong1 << endl;
	DaiRong1 << ve;
	DaiRong1.close();
	ofstream save4;
	save4.open("SavePvC4.txt");
	system("cls");
	for (int check = 0; check < sa; check++)
	{
		for (int check1 = 0; check1 < ve * 2; check1 += 2)
		{
			save4 << matrix[check][check1] << "|";
		}
		save4 << endl;
	}
	save4.close();
	gotoxy(42, 7);
	cout << "Your game has been saved to <SAVE FILE 4> ";
}
void loadCom4(char matrix[60][60], int &dai, int &rong)
{
	ifstream dairong;
	dairong.open("SaveDaiRongPvc4.txt");
	dairong >> dai;
	dairong >> rong;
	dairong.close();
	ifstream load;
	load.open("SavePvC4.txt");
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong * 2; j++)
		{
			load >> matrix[i][j];
		}
	}
	load.close();
}
void LoadPvC4(int lo, int ad, int &NumPlayer, PLAYER nguoichoi[5])
{
	ifstream SoNguoiChoi;
	SoNguoiChoi.open("NumPlayer4.txt");
	SoNguoiChoi >> NumPlayer;
	SoNguoiChoi.close();
	ifstream TenNguoiChoi;
	if (NumPlayer == 1)
	{
		TenNguoiChoi.open("SavePlayer1.txt");
		TenNguoiChoi >> nguoichoi[NumPlayer - 1].name;
		TenNguoiChoi.close();
	}
	else if (NumPlayer == 2)
	{
		TenNguoiChoi.open("SavePlayer2.txt");
		TenNguoiChoi >> nguoichoi[NumPlayer - 1].name;
		TenNguoiChoi.close();
	}
	else if (NumPlayer == 3)
	{
		TenNguoiChoi.open("SavePlayer3.txt");
		TenNguoiChoi >> nguoichoi[NumPlayer - 1].name;
		TenNguoiChoi.close();
	}
	else
	{
		TenNguoiChoi.open("SavePlayer4.txt");
		TenNguoiChoi >> nguoichoi[NumPlayer - 1].name;
		TenNguoiChoi.close();
	}
	char load;
	ifstream load4;
	load4.open("SavePvC4.txt");
	while (!load4.eof())
	{
		load4.get(load);
		if (load == 'X')
		{
			TextColor(9);
			cout << load;
			TextColor(7);
		}
		else if (load == 'O')
		{
			TextColor(10);
			cout << load;
			TextColor(7);
		}
		else cout << load;
	}
	load4.close();
	gotoxy(60, 2);
	cout << "~~~~~~~INSTRUCTION~~~~~~~";
	gotoxy(60, 3);
	cout << "1 - Press W, S, A, D to move UP, DOWN, LEFT and RIGHT";
	gotoxy(60, 4);
	cout << "2 - Press K to tick";
	gotoxy(60, 5);
	cout << "3 - Press O to save your current game";
	gotoxy(60, 6);
	cout << "4 - Press Q to go back to menu";
	gotoxy(60, 7);
	cout << "Note: X always goes first";
	gotoxy(60, 8);
	cout << "Have a good time <3 We love you all" << endl;
	gotoxy(63, 15);
	cout << "******* " << nguoichoi[NumPlayer - 1].name << " -  X *******" << endl;
	gotoxy(63, 17);
	cout << "******* COMPUTER  -  O *******" << endl;
	gotoxy(60, 10);
	cout << "Enter the height of board (maximum 30): " << lo;
	gotoxy(60, 11);
	cout << "Enter the width of board (maximum 30) : " << ad;
}
void rule2dau(int x, int y, int &tren, int &duoi, int &ngangtrai, int &ngangphai, int &cheotrentrai, int &cheoduoitrai, int &cheotrenphai, int &cheoduoiphai, int &quandichdoc, int &quandichngang, int &quandichcheothuan, int &quandichcheoxuoi, char matrix[60][60], char player)
{
	int checkduoi = 0, checktren = 0, checktrai = 0, checkphai = 0, checkcheotrentrai = 0, checkcheoduoiphai = 0, checkcheotrenphai = 0, checkcheoduoitrai = 0;
	for (int check = 2; check <= 10; check += 2)
	{
		if (matrix[int(y * 2) + check][int(x)] == player && checkduoi == 0)
			duoi += 1;
		else if (matrix[int(y * 2) + check][int(x)] == '_')
			checkduoi++;
		else if (matrix[int(y * 2) + check][int(x)] != player && checkduoi == 0)
		{
			quandichdoc++;
			checkduoi++;
		}
		if (matrix[int(y * 2) - check][int(x)] == player && checktren == 0)
			tren += 1;
		else if (matrix[int(y * 2) - check][int(x)] == '_')
			checktren++;
		else if (matrix[int(y * 2) - check][int(x)] != player && checktren == 0)
		{
			quandichdoc++;
			checktren++;
		}
		if (matrix[int(y * 2)][int(x) + check] == player && checkphai == 0)
			ngangphai += 1;
		else if (matrix[int(y * 2)][int(x) + check] == '_')
			checkphai++;
		else if (matrix[int(y * 2)][int(x) + check] != player && checkphai == 0)
		{
			quandichngang++;
			checkphai++;
		}
		if (matrix[int(y * 2)][int(x) - check] == player && checktrai == 0)
			ngangtrai += 1;
		else if (matrix[int(y * 2)][int(x) - check] == '_')
			checktrai++;
		else if (matrix[int(y * 2)][int(x) - check] != player && checktrai == 0)
		{
			quandichngang++;
			checktrai++;
		}
		if (matrix[int(y * 2) - check][int(x) - check] == player && checkcheotrentrai == 0)
			cheotrentrai += 1;
		else if (matrix[int(y * 2) - check][int(x) - check] == '_')
			checkcheotrentrai++;
		else if (matrix[int(y * 2) - check][int(x) - check] != player && checkcheotrentrai == 0)
		{
			quandichcheothuan++;
			checkcheotrentrai++;
		}
		if (matrix[int(y * 2) + check][int(x) - check] == player && checkcheoduoitrai == 0)
			cheoduoitrai += 1;
		else if (matrix[int(y * 2) + check][int(x) - check] == '_')
			checkcheoduoitrai++;
		else if (checkcheoduoitrai == 0 && matrix[int(y * 2) + check][int(x) - check] != player)
		{
			quandichcheoxuoi++;
			checkcheoduoitrai++;
		}
		if (matrix[int(y * 2) - check][int(x) + check] == player && checkcheotrenphai == 0)
			cheotrenphai += 1;
		else if (matrix[int(y * 2) - check][int(x) + check] == '_')
			checkcheotrenphai++;
		else if (matrix[int(y * 2) - check][int(x) + check] != player && checkcheotrenphai == 0)
		{
			quandichcheoxuoi++;
			checkcheotrenphai++;
		}
		if (matrix[int(y * 2) + check][int(x) + check] == player && checkcheoduoiphai == 0)
			cheoduoiphai += 1;
		else if (matrix[int(y * 2) + check][int(x) + check] == '_')
			checkcheoduoiphai++;
		else if (matrix[int(y * 2) + check][int(x) + check] != player && checkcheoduoiphai == 0)
		{
			quandichcheothuan++;
			checkcheoduoiphai++;
		}
	}
}
int ReturnOrNot()
{
	int n;
	system("cls");
	gotoxy(45, 2);
	cout << "Do you want to play a new game? \n";
	gotoxy(45, 3);
	cout << " 0 - NO                1 - YES \n";
	gotoxy(45, 4);
	cout << "Your selection: ";
	cin >> n;
	return n;
}
int TCdoc(int CurDong, int CurCot, char matrix[60][60], long MangDiemTanCong[7], long MangDiemPhongNgu[7])
{
	long SoQuanTa = 0;
	long SoQuanDich = 0;
	int TongDiemTanCong;
	int TongDiemPhongThu;
	int TongDiem = 0;
	for (int dem = 0; dem <= 10; dem += 2)
	{
		if (matrix[CurDong + (dem / 2)][CurCot] == char(79))
		{
			SoQuanTa++;
		}
		else if (matrix[CurDong + (dem / 2)][CurCot] == char(88))
		{
			SoQuanDich++;
			break;
		}
		if (matrix[CurDong + (dem / 2)][CurCot] == '_' && dem != 0)
			break;
	}
	for (int dem = 0; dem <= 10; dem += 2)
	{
		if (matrix[CurDong - (dem / 2)][CurCot] == char(79))
		{
			SoQuanTa++;
		}
		else if (matrix[CurDong - (dem / 2)][CurCot] == char(88))
		{
			SoQuanDich++;
			break;
		}
		if (matrix[CurDong - (dem / 2)][CurCot] == '_' && dem != 0)
			break;
	}
	if (SoQuanDich == 2) return 0;
	TongDiemTanCong = MangDiemTanCong[SoQuanTa];
	TongDiemPhongThu = MangDiemPhongNgu[SoQuanDich];
	TongDiem += TongDiemTanCong;
	TongDiem -= TongDiemPhongThu;
	return TongDiem;
}
int TCngang(int CurDong, int CurCot, char matrix[60][60], long MangDiemTanCong[7], long MangDiemPhongNgu[7])
{
	long SoQuanTa = 0;
	long SoQuanDich = 0;
	int TongDiemTanCong;
	int TongDiemPhongThu;
	int TongDiem = 0;
	for (int dem = 0; dem <= 10; dem += 2)
	{
		if (matrix[CurDong][CurCot + dem] == char(79))
		{
			SoQuanTa++;
		}
		else if (matrix[CurDong][CurCot + dem] == char(88))
		{
			SoQuanDich++;
			break;
		}
		if (matrix[CurDong][CurCot + dem] == '_' && dem != 0)
			break;
	}
	for (int dem = 0; dem <= 10; dem += 2)
	{
		if (matrix[CurDong][CurCot - dem] == char(79))
		{
			SoQuanTa++;
		}
		else if (matrix[CurDong][CurCot - dem] == char(88))
		{
			SoQuanDich++;
			break;
		}
		if (matrix[CurDong][CurCot - dem] == '_' && dem != 0)
			break;
	}
	if (SoQuanDich == 2) return 0;
	TongDiemTanCong = MangDiemTanCong[SoQuanTa];
	TongDiemPhongThu = MangDiemPhongNgu[SoQuanDich];
	TongDiem += TongDiemTanCong;
	TongDiem -= TongDiemPhongThu;
	return TongDiem;
}
int TCcheothuan(int CurDong, int CurCot, char matrix[60][60], long MangDiemTanCong[7], long MangDiemPhongNgu[7])
{
	long SoQuanTa = 0;
	long SoQuanDich = 0;
	int TongDiemTanCong;
	int TongDiemPhongThu;
	int TongDiem = 0;
	for (int dem = 0; dem <= 10; dem += 2)
	{
		if (matrix[CurDong - (dem / 2)][CurCot - dem] == char(79))
		{
			SoQuanTa++;
		}
		else if (matrix[CurDong - (dem) / 2][CurCot - dem] == char(88))
		{
			SoQuanDich++;
			break;
		}
		if (matrix[CurDong - (dem / 2)][CurCot - dem] == '_' && dem != 0)
			break;
	}
	for (int dem = 0; dem <= 10; dem += 2)
	{
		if (matrix[CurDong + (dem / 2)][CurCot + dem] == char(79))
		{
			SoQuanTa++;
		}
		else if (matrix[CurDong + (dem / 2)][CurCot + dem] == char(88))
		{
			SoQuanDich++;
			break;
		}
		if (matrix[CurDong + (dem / 2)][CurCot + dem] == '_' && dem != 0)
			break;
	}
	if (SoQuanDich == 2) return 0;
	TongDiemTanCong = MangDiemTanCong[SoQuanTa];
	TongDiemPhongThu = MangDiemPhongNgu[SoQuanDich];
	TongDiem += TongDiemTanCong;
	TongDiem -= TongDiemPhongThu;
	return TongDiem;
}
int TCcheonguoc(int CurDong, int CurCot, char matrix[60][60], long MangDiemTanCong[7], long MangDiemPhongNgu[7])
{
	long SoQuanTa = 0;
	long SoQuanDich = 0;
	int TongDiemTanCong;
	int TongDiemPhongThu;
	int TongDiem = 0;
	for (int dem = 0; dem <= 10; dem += 2)
	{
		if (matrix[CurDong - (dem / 2)][CurCot + dem] == char(79))
		{
			SoQuanTa++;
		}
		else if (matrix[CurDong - (dem / 2)][CurCot + dem] == char(88))
		{
			SoQuanDich++;
			break;
		}
		if (matrix[CurDong - (dem / 2)][CurCot + dem] == '_' && dem != 0)
			break;
	}
	for (int dem = 0; dem <= 10; dem += 2)
	{
		if (matrix[CurDong + (dem / 2)][CurCot - dem] == char(79))
		{
			SoQuanTa++;
		}
		else if (matrix[CurDong + (dem / 2)][CurCot - dem] == char(88))
		{
			SoQuanDich++;
			break;
		}
		if (matrix[CurDong + (dem / 2)][CurCot - dem] == '_' && dem != 0)
			break;
	}
	if (SoQuanDich == 2) return 0;
	TongDiemTanCong = MangDiemTanCong[SoQuanTa];
	TongDiemPhongThu = MangDiemPhongNgu[SoQuanDich];
	TongDiem += TongDiemTanCong;
	TongDiem -= TongDiemPhongThu;
	return TongDiem;
}
int PTdoc(int CurDong, int CurCot, char matrix[60][60], long MangDiemPhongNgu[7], long MangDiemTanCong[7])
{
	long SoQuanTa = 0;
	long SoQuanDich = 0;
	int TongDiemTanCong;
	int TongDiemPhongThu;
	int TongDiem = 0;
	for (int dem = 0; dem <= 10; dem += 2)
	{
		if (matrix[CurDong + (dem / 2)][CurCot] == char(79))
		{
			SoQuanTa++;
			break;
		}
		else if (matrix[CurDong + (dem / 2)][CurCot] == char(88))
		{
			SoQuanDich++;
		}
		if (matrix[CurDong + (dem / 2)][CurCot] == '_' && dem != 0)
			break;
	}
	for (int dem = 0; dem <= 10; dem += 2)
	{
		if (matrix[CurDong - (dem / 2)][CurCot] == char(79))
		{
			SoQuanTa++;
			break;
		}
		else if (matrix[CurDong - (dem / 2)][CurCot] == char(88))
		{
			SoQuanDich++;
		}
		if (matrix[CurDong - (dem / 2)][CurCot] == '_' && dem != 0)
			break;
	}
	if (SoQuanTa == 2) return 0;
	TongDiemTanCong = MangDiemTanCong[SoQuanTa];
	TongDiemPhongThu = MangDiemPhongNgu[SoQuanDich];
	TongDiem -= TongDiemTanCong;
	TongDiem += TongDiemPhongThu;
	return TongDiem;
}
int PTngang(int CurDong, int CurCot, char matrix[60][60], long MangDiemPhongNgu[7], long MangDiemTanCong[7])
{
	long SoQuanTa = 0;
	long SoQuanDich = 0;
	int TongDiemTanCong;
	int TongDiemPhongThu;
	int TongDiem = 0;
	for (int dem = 0; dem <= 10; dem += 2)
	{
		if (matrix[CurDong][CurCot + dem] == char(79))
		{
			SoQuanTa++;
			break;
		}
		else if (matrix[CurDong][CurCot + dem] == char(88))
		{
			SoQuanDich++;
		}
		if (matrix[CurDong][CurCot + dem] == '_' && dem != 0)
			break;
	}
	for (int dem = 0; dem <= 10; dem += 2)
	{
		if (matrix[CurDong][CurCot - dem] == char(79))
		{
			SoQuanTa++;
			break;
		}
		else if (matrix[CurDong][CurCot - dem] == char(88))
		{
			SoQuanDich++;
		}
		if (matrix[CurDong][CurCot - dem] == '_' && dem != 0)
			break;
	}
	if (SoQuanTa == 2) return 0;
	TongDiemTanCong = MangDiemTanCong[SoQuanTa];
	TongDiemPhongThu = MangDiemPhongNgu[SoQuanDich];
	TongDiem -= TongDiemTanCong;
	TongDiem += TongDiemPhongThu;
	return TongDiem;
}
int PTcheothuan(int CurDong, int CurCot, char matrix[60][60], long MangDiemPhongNgu[7], long MangDiemTanCong[7])
{
	long SoQuanTa = 0;
	long SoQuanDich = 0;
	int TongDiemTanCong;
	int TongDiemPhongThu;
	int TongDiem = 0;
	for (int dem = 0; dem <= 10; dem += 2)
	{
		if (matrix[CurDong - (dem / 2)][CurCot - dem] == char(79))
		{
			SoQuanTa++;
			break;
		}
		else if (matrix[CurDong - (dem / 2)][CurCot - dem] == char(88))
		{
			SoQuanDich++;
		}
		if (matrix[CurDong - (dem / 2)][CurCot - dem] == '_' && dem != 0)
			break;
	}
	for (int dem = 0; dem <= 10; dem += 2)
	{
		if (matrix[CurDong + (dem / 2)][CurCot + dem] == char(79))
		{
			SoQuanTa++;
			break;
		}
		else if (matrix[CurDong + (dem / 2)][CurCot + dem] == char(88))
		{
			SoQuanDich++;
		}
		if (matrix[CurDong + (dem / 2)][CurCot + dem] == '_' && dem != 0)
			break;
	}
	if (SoQuanTa == 2) return 0;
	TongDiemTanCong = MangDiemTanCong[SoQuanTa];
	TongDiemPhongThu = MangDiemPhongNgu[SoQuanDich];
	TongDiem -= TongDiemTanCong;
	TongDiem += TongDiemPhongThu;
	return TongDiem;
}
int PTcheonguoc(int CurDong, int CurCot, char matrix[60][60], long MangDiemPhongNgu[7], long MangDiemTanCong[7])
{
	long SoQuanTa = 0;
	long SoQuanDich = 0;
	int TongDiemTanCong;
	int TongDiemPhongThu;
	int TongDiem = 0;
	for (int dem = 0; dem <= 10; dem += 2)
	{
		if (matrix[CurDong - (dem / 2)][CurCot + dem] == char(79))
		{
			SoQuanTa++;
			break;
		}
		else if (matrix[CurDong - (dem / 2)][CurCot + dem] == char(88))
		{
			SoQuanDich++;
		}
		if (matrix[CurDong - (dem / 2)][CurCot + dem] == '_' && dem != 0)
			break;
	}
	for (int dem = 0; dem <= 10; dem += 2)
	{
		if (matrix[CurDong + (dem / 2)][CurCot - dem] == char(79))
		{
			SoQuanTa++;
			break;
		}
		else if (matrix[CurDong + (dem / 2)][CurCot - dem] == char(88))
		{
			SoQuanDich++;
		}
		if (matrix[CurDong + (dem / 2)][CurCot - dem] == '_' && dem != 0)
			break;
	}
	if (SoQuanTa == 2) return 0;
	TongDiemTanCong = MangDiemTanCong[SoQuanTa];
	TongDiemPhongThu = MangDiemPhongNgu[SoQuanDich];
	TongDiem -= TongDiemTanCong;
	TongDiem += TongDiemPhongThu;
	return TongDiem;
}
void ComVsPlayer(int q, int p, int n, char matrix[60][60], PLAYER nguoichoi[5], char player)
{
	long MangDiemTanCong[7] = { 0, 9, 54, 162, 1458, 13112, 118008 };
	long MangDiemPhongNgu[7] = { 0, 3, 27, 99, 729, 6561, 59049 };
	int out = 0;
	float x = 0, y = 0;
	float i = 0, j = 0;
	int tren = 0, duoi = 0, ngangtrai = 0, ngangphai = 0, cheotrentrai = 0, cheoduoitrai = 0, cheotrenphai = 0, cheoduoiphai = 0;
	while (out == 0)
	{
		char key = _getch();
		switch (key)
		{
		case 'w': {
			j = -0.5;
			i = 0;
			break;
		}
		case 's': {
			j = 0.5;
			i = 0;
			break;
		}
		case 'a': {
			j = 0;
			i = -2;
			break;
		}
		case 'd': {
			j = 0;
			i = 2;
			break;
		}
		case 'k':
		{
			play_er(player);
			if (matrix[int(y)][int(x)] == char(79) || matrix[int(y)][int(x)] == char(88))
			{
				play_er(player);
				break;
			}
			else
			{
				matrix[int(y)][int(x)] = player;
				cout << player;
				int checkduoi = 0, checktren = 0, checktrai = 0, checkphai = 0, checkcheotrentrai = 0, checkcheoduoiphai = 0, checkcheotrenphai = 0, checkcheoduoitrai = 0;
				tren = 0, duoi = 0, ngangtrai = 0, ngangphai = 0, cheotrentrai = 0, cheoduoitrai = 0, cheotrenphai = 0, cheoduoiphai = 0;
				for (int check = 2; check <= 8; check += 2)
				{
					if (matrix[int(y) + check / 2][int(x)] == player && checkduoi == 0) duoi += 1;
					else if (matrix[int(y) + check / 2][int(x)] != player) ++checkduoi;
					if (matrix[int(y) - check / 2][int(x)] == player && checktren == 0) tren += 1;
					else if (matrix[int(y) - check / 2][int(x)] != player) ++checktren;
					if (matrix[int(y)][int(x) + check] == player && checkphai == 0) ngangphai += 1;
					else if (matrix[int(y)][int(x) + check] != player) ++checkphai;
					if (matrix[int(y)][int(x) - check] == player && checktrai == 0) ngangtrai += 1;
					else if (matrix[int(y)][int(x) - check] != player) ++checktrai;
					if (matrix[int(y) - check / 2][int(x) - check] == player && checkcheotrentrai == 0) cheotrentrai += 1;
					else if (matrix[int(y) - check / 2][int(x) - check] != player) ++checkcheotrentrai;
					if (matrix[int(y) + check / 2][int(x) - check] == player && checkcheoduoitrai == 0) cheoduoitrai += 1;
					else if (matrix[int(y) + check / 2][int(x) - check] != player) ++checkcheoduoitrai;
					if (matrix[int(y) - check / 2][int(x) + check] == player && checkcheotrenphai == 0) cheotrenphai += 1;
					else if (matrix[int(y) - check / 2][int(x) + check] != player) ++checkcheotrenphai;
					if (matrix[int(y) + check / 2][int(x) + check] == player && checkcheoduoiphai == 0) cheoduoiphai += 1;
					else if (matrix[int(y) + check / 2][int(x) + check] != player) ++checkcheoduoiphai;
				}
				if (duoi + tren >= 4 || ngangtrai + ngangphai == 4 || cheotrentrai + cheoduoiphai == 4 || cheotrenphai + cheoduoitrai == 4)
				{
					gotoxy(1, p + 2);
					X_Win(1);

					if (n == 1)
					{
						ifstream gamethang, gamechoi;
						gamethang.open("NumOfWonGame1.txt");
						gamethang >> nguoichoi[n - 1].NumOfWonGame;
						gamethang.close();
						++nguoichoi[n - 1].NumOfWonGame;
						gamechoi.open("NumOfPlayedGame1.txt");
						gamechoi >> nguoichoi[n - 1].NumOfPlayedGame;
						gamechoi.close();
						++nguoichoi[n - 1].NumOfPlayedGame;
						ofstream thanggame, choigame;
						thanggame.open("NumOfWonGame1.txt");
						thanggame << nguoichoi[n - 1].NumOfWonGame;
						thanggame.close();
						choigame.open("NumOfPlayedGame1.txt");
						choigame << nguoichoi[n - 1].NumOfPlayedGame;
						choigame.close();
					}
					else if (n == 2)
					{
						ifstream gamethang, gamechoi;
						gamethang.open("NumOfWonGame2.txt");
						gamethang >> nguoichoi[n - 1].NumOfWonGame;
						gamethang.close();
						++nguoichoi[n - 1].NumOfWonGame;
						gamechoi.open("NumOfPlayedGame2.txt");
						gamechoi >> nguoichoi[n - 1].NumOfPlayedGame;
						gamechoi.close();
						++nguoichoi[n - 1].NumOfPlayedGame;
						ofstream thanggame, choigame;
						thanggame.open("NumOfWonGame2.txt");
						thanggame << nguoichoi[n - 1].NumOfWonGame;
						thanggame.close();
						choigame.open("NumOfPlayedGame2.txt");
						choigame << nguoichoi[n - 1].NumOfPlayedGame;
						choigame.close();
					}
					else if (n == 3)
					{
						ifstream gamethang, gamechoi;
						gamethang.open("NumOfWonGame3.txt");
						gamethang >> nguoichoi[n - 1].NumOfWonGame;
						gamethang.close();
						++nguoichoi[n - 1].NumOfWonGame;
						gamechoi.open("NumOfPlayedGame3.txt");
						gamechoi >> nguoichoi[n - 1].NumOfPlayedGame;
						gamechoi.close();
						++nguoichoi[n - 1].NumOfPlayedGame;
						ofstream thanggame, choigame;
						thanggame.open("NumOfWonGame3.txt");
						thanggame << nguoichoi[n - 1].NumOfWonGame;
						thanggame.close();
						choigame.open("NumOfPlayedGame3.txt");
						choigame << nguoichoi[n - 1].NumOfPlayedGame;
						choigame.close();
					}
					else
					{
						ifstream gamethang, gamechoi;
						gamethang.open("NumOfWonGame4.txt");
						gamethang >> nguoichoi[n - 1].NumOfWonGame;
						gamethang.close();
						++nguoichoi[n - 1].NumOfWonGame;
						gamechoi.open("NumOfPlayedGame4.txt");
						gamechoi >> nguoichoi[n - 1].NumOfPlayedGame;
						gamechoi.close();
						++nguoichoi[n - 1].NumOfPlayedGame;
						ofstream thanggame, choigame;
						thanggame.open("NumOfWonGame4.txt");
						thanggame << nguoichoi[n - 1].NumOfWonGame;
						thanggame.close();
						choigame.open("NumOfPlayedGame4.txt");
						choigame << nguoichoi[n - 1].NumOfPlayedGame;
						choigame.close();
					}
					cout << endl;
					system("pause");
					out += 1;
					break;
				}
				int DiemMax = 0;
				int a = 0, b = 0;
				play_er(player);
				for (int checkRow = 0; checkRow < q; checkRow++)
				{
					for (int checkCol = 0; checkCol < p * 2; checkCol += 2)
					{
						if (matrix[checkRow][checkCol] != char(79) && matrix[checkRow][checkCol] != char(88))
						{
							int TotalAttackPoint = TCdoc(checkRow, checkCol, matrix, MangDiemTanCong, MangDiemPhongNgu) + TCngang(checkRow, checkCol, matrix, MangDiemTanCong, MangDiemPhongNgu) + TCcheothuan(checkRow, checkCol, matrix, MangDiemTanCong, MangDiemPhongNgu) + TCcheonguoc(checkRow, checkCol, matrix, MangDiemTanCong, MangDiemPhongNgu);
							int TotalDefensePoint = PTdoc(checkRow, checkCol, matrix, MangDiemPhongNgu, MangDiemTanCong) + PTngang(checkRow, checkCol, matrix, MangDiemPhongNgu, MangDiemTanCong) + PTcheothuan(checkRow, checkCol, matrix, MangDiemPhongNgu, MangDiemTanCong) + PTcheonguoc(checkRow, checkCol, matrix, MangDiemPhongNgu, MangDiemTanCong);
							int DiemTam;
							if (TotalAttackPoint >= TotalDefensePoint)
								DiemTam = TotalAttackPoint;
							else
								DiemTam = TotalDefensePoint;
							if (DiemTam > DiemMax)
							{
								DiemMax = DiemTam;
								a = checkCol;
								b = checkRow;
							}
						}
					}
				}
				matrix[b][a] = player;
				Sleep(500);
				gotoxy(a, b);
				cout << player;
				tren = 0, duoi = 0, ngangtrai = 0, ngangphai = 0, cheotrentrai = 0, cheoduoitrai = 0, cheotrenphai = 0, cheoduoiphai = 0;
				checkduoi = 0, checktren = 0, checktrai = 0, checkphai = 0, checkcheotrentrai = 0, checkcheoduoiphai = 0, checkcheotrenphai = 0, checkcheoduoitrai = 0;
				for (int check = 2; check <= 8; check += 2)
				{
					if (matrix[int(b) + check / 2][int(a)] == player && checkduoi == 0) duoi += 1;
					else if (matrix[int(b) + check / 2][int(a)] != player) ++checkduoi;
					if (matrix[int(b) - check / 2][int(a)] == player && checktren == 0) tren += 1;
					else if (matrix[int(b) - check / 2][int(a)] != player) ++checktren;
					if (matrix[int(b)][int(a) + check] == player && checkphai == 0) ngangphai += 1;
					else if (matrix[int(b)][int(a) + check] != player) ++checkphai;
					if (matrix[int(b)][int(a) - check] == player && checktrai == 0) ngangtrai += 1;
					else if (matrix[int(b)][int(a) - check] != player) ++checktrai;
					if (matrix[int(b) - check / 2][int(a) - check] == player && checkcheotrentrai == 0) cheotrentrai += 1;
					else if (matrix[int(b) - check / 2][int(a) - check] != player) ++checkcheotrentrai;
					if (matrix[int(b) + check / 2][int(a) - check] == player && checkcheoduoitrai == 0) cheoduoitrai += 1;
					else if (matrix[int(b) + check / 2][int(a) - check] != player) ++checkcheoduoitrai;
					if (matrix[int(b) - check / 2][int(a) + check] == player && checkcheotrenphai == 0) cheotrenphai += 1;
					else if (matrix[int(b) - check / 2][int(a) + check] != player) ++checkcheotrenphai;
					if (matrix[int(b) + check / 2][int(a) + check] == player && checkcheoduoiphai == 0) cheoduoiphai += 1;
					else if (matrix[int(b) + check / 2][int(a) + check] != player) ++checkcheoduoiphai;
				}
				if (duoi + tren >= 4 || ngangtrai + ngangphai >= 4 || cheotrentrai + cheoduoiphai >= 4 || cheotrenphai + cheoduoitrai >= 4)
				{
					gotoxy(1, p + 2);
					O_Win(1);
					if (n == 1)
					{
						ifstream load;
						load.open("NumOfPlayedGame1.txt");
						load >> nguoichoi[n - 1].NumOfPlayedGame;
						load.close();
						++nguoichoi[n - 1].NumOfPlayedGame;
						ofstream choigame;
						choigame.open("NumOfPlayedGame1.txt");
						choigame << nguoichoi[n - 1].NumOfPlayedGame;
						choigame.close();
					}
					else if (n == 2)
					{
						ifstream load;
						load.open("NumOfPlayedGame2.txt");
						load >> nguoichoi[n - 1].NumOfPlayedGame;
						load.close();
						++nguoichoi[n - 1].NumOfPlayedGame;
						ofstream choigame;
						choigame.open("NumOfPlayedGame2.txt");
						choigame << nguoichoi[n - 1].NumOfPlayedGame;
						choigame.close();
					}
					else if (n == 3)
					{
						ifstream load;
						load.open("NumOfPlayedGame3.txt");
						load >> nguoichoi[n - 1].NumOfPlayedGame;
						load.close();
						++nguoichoi[n - 1].NumOfPlayedGame;
						ofstream choigame;
						choigame.open("NumOfPlayedGame3.txt");
						choigame << nguoichoi[n - 1].NumOfPlayedGame;
						choigame.close();
					}
					else
					{
						ifstream load;
						load.open("NumOfPlayedGame4.txt");
						load >> nguoichoi[n - 1].NumOfPlayedGame;
						load.close();
						++nguoichoi[n - 1].NumOfPlayedGame;
						ofstream choigame;
						choigame.open("NumOfPlayedGame4.txt");
						choigame << nguoichoi[n - 1].NumOfPlayedGame;
						choigame.close();
					}
					cout << endl;
					system("pause");
					out += 1;
					break;
				}
				break;
			}



		}
		case 'o':
		{
			int l;
			TextColor(7);
			system("cls");
			gotoxy(0, 7);
			cout << setw(68) << "1 - <SAVE FILE 1>\n";
			cout << setw(68) << "2 - <SAVE FILE 2>\n";
			cout << setw(68) << "3 - <SAVE FILE 3>\n";
			cout << setw(68) << "4 - <SAVE FILE 4>\n";
			cout << setw(68) << "Choose your selection: ";
			cin >> l;
			if (l == 1)
			{
				SavePvC1(q, p, n, matrix);
				cout << '\n';
				gotoxy(42, 8);
				system("pause");
				out += 1;
				break;
			}
			else if (l == 2)
			{

				SavePvC2(q, p, n, matrix);
				cout << '\n';
				gotoxy(42, 8);
				system("pause");
				out += 1;
				break;
			}
			else if (l == 3)
			{
				SavePvC3(q, p, n, matrix);
				cout << '\n';
				gotoxy(42, 8);
				system("pause");
				out += 1;
				break;
			}
			else
			{
				SavePvC4(q, p, n, matrix);
				cout << '\n';
				gotoxy(42, 8);
				system("pause");
				out += 1;
				break;
			}
		}
		case 'q':
		{
			TextColor(7);
			out += 1;
		}
		}
		x += i;
		y += j;
		gotoxy(x, y);
	}
}
void gameplay_(int q, int p, char matrix[60][60], int tick, char player, int rule, int turn)
{
	int out = 0;
	float x = 0, y = 0;
	float i = 0, j = 0;
	int tren = 0, duoi = 0, ngangtrai = 0, ngangphai = 0, cheotrentrai = 0, cheoduoitrai = 0, cheotrenphai = 0, cheoduoiphai = 0;
	int quandichdoc, quandichngang, quandichcheothuan, quandichcheoxuoi;
	int check;
	while (out == 0)
	{
		char key = _getch();
		switch (key)
		{
		case 'w': {
			j = -0.5;
			i = 0;
			break;
		}
		case 's': {
			j = 0.5;
			i = 0;
			break;
		}
		case 'a': {
			j = 0;
			i = -2;
			break;
		}
		case 'd': {
			j = 0;
			i = 2;
			break;
		}
		case 'k':
		{
			changeicon(tick, player);
			if (matrix[int(y * 2)][int(x)] == char(79) || matrix[int(y * 2)][int(x)] == char(88))
			{
				changeicon(tick, player);
				break;
			}
			else
			{
				matrix[int(y * 2)][int(x)] = player;
				cout << player;
				TextColor(7);
				tren = 0, duoi = 0, ngangtrai = 0, ngangphai = 0, cheotrentrai = 0, cheoduoitrai = 0, cheotrenphai = 0, cheoduoiphai = 0;
				quandichdoc = 0, quandichngang = 0, quandichcheoxuoi = 0, quandichcheothuan = 0;
				if (rule == 2)
					rule2dau(x, y, tren, duoi, ngangtrai, ngangphai, cheotrentrai, cheoduoitrai, cheotrenphai, cheoduoiphai, quandichdoc, quandichngang, quandichcheothuan, quandichcheoxuoi, matrix, player);
				else
				{
					int checkduoi = 0, checktren = 0, checktrai = 0, checkphai = 0, checkcheotrentrai = 0, checkcheoduoiphai = 0, checkcheotrenphai = 0, checkcheoduoitrai = 0;
					for (int check = 2; check <= 8; check += 2)
					{
						if (matrix[int(y * 2) + check][int(x)] == player && checkduoi == 0) duoi += 1;
						else if (matrix[int(y * 2) + check][int(x)] != player) ++checkduoi;
						if (matrix[int(y * 2) - check][int(x)] == player && checktren == 0) tren += 1;
						else if (matrix[int(y * 2) - check][int(x)] != player) ++checktren;
						if (matrix[int(y * 2)][int(x) + check] == player && checkphai == 0) ngangphai += 1;
						else if (matrix[int(y * 2)][int(x) + check] != player) ++checkphai;
						if (matrix[int(y * 2)][int(x) - check] == player && checktrai == 0) ngangtrai += 1;
						else if (matrix[int(y * 2)][int(x) - check] != player) ++checktrai;
						if (matrix[int(y * 2) - check][int(x) - check] == player && checkcheotrentrai == 0) cheotrentrai += 1;
						else if (matrix[int(y * 2) - check][int(x) - check] != player) ++checkcheotrentrai;
						if (matrix[int(y * 2) + check][int(x) - check] == player && checkcheoduoitrai == 0) cheoduoitrai += 1;
						else if (matrix[int(y * 2) + check][int(x) - check] != player) ++checkcheoduoitrai;
						if (matrix[int(y * 2) - check][int(x) + check] == player && checkcheotrenphai == 0) cheotrenphai += 1;
						else if (matrix[int(y * 2) - check][int(x) + check] != player) ++checkcheotrenphai;
						if (matrix[int(y * 2) + check][int(x) + check] == player && checkcheoduoiphai == 0) cheoduoiphai += 1;
						else if (matrix[int(y * 2) + check][int(x) + check] != player) ++checkcheoduoiphai;
					}
				}

			}
			break;
		}
		case 'o':
		{
			int n;
			system("cls");
			gotoxy(0, 7);
			cout << setw(68) << "1 - <SAVE FILE 1>\n";
			cout << setw(68) << "2 - <SAVE FILE 2>\n";
			cout << setw(68) << "3 - <SAVE FILE 3>\n";
			cout << setw(68) << "4 - <SAVE FILE 4>\n";
			cout << setw(68) << "Choose your selection: ";
			cin >> n;
			if (n == 1)
			{
				system("cls");
				SaveTurn1(player, turn);
				SaveGame1(q, p, matrix, tick, rule);
				cout << '\n';
				gotoxy(42, 8);
				system("pause");
				out += 1;
			}
			else if (n == 2)
			{

				SaveTurn2(player, turn);
				SaveGame2(q, p, matrix, tick, rule);
				cout << '\n';
				gotoxy(42, 8);
				system("pause");
				out += 1;
			}
			else if (n == 3)
			{
				SaveTurn3(player, turn);
				SaveGame3(q, p, matrix, tick, rule);
				cout << '\n';
				gotoxy(42, 8);
				system("pause");
				out += 1;
			}
			else if (n == 4)
			{
				SaveTurn4(player, turn);
				SaveGame4(q, p, matrix, tick, rule);
				cout << '\n';
				gotoxy(42, 8);
				system("pause");
				out += 1;
			}
		}
		case 'q':
		{
			out += 1;
		}
		}
		if (duoi + tren >= 4 && quandichdoc < 2 || ngangtrai + ngangphai >= 4 && quandichngang < 2 || cheotrentrai + cheoduoiphai >= 4 && quandichcheothuan < 2 || cheotrenphai + cheoduoitrai >= 4 && quandichcheoxuoi < 2)
		{
			if (player == 'X')
			{
				gotoxy(1, p + 2);
				X_Win(1);
				cout << endl;
				system("pause");
				out += 1;
			}
			else if (player == 'O')
			{
				gotoxy(1, p + 2);
				O_Win(1);
				cout << endl;
				system("pause");
				out += 1;
			}
			else if (player == '#')
			{
				gotoxy(1, p + 2);
				icon1_Win();
				cout << endl;
				system("pause");
				out += 1;
			}
			else
			{
				gotoxy(1, p + 2);
				icon2_Win();
				cout << endl;
				system("pause");
				out += 1;
			}
		}
		else
		{
			x += i;
			y += j;
			gotoxy(x, y);
		}

	}
}