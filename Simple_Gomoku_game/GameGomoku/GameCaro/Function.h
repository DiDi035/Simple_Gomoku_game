#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include<iostream>
#include<stdlib.h>
#include"windows.h"
#include<fstream>
#include<string>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
using namespace std;
struct PLAYER;
void TextColor(int color);
void gotoxy(int x, int y);
void loading();
void SplashScreen();
void AboutScreen();
void draw(int height, int width, char matrix[60][60]);
void changeicon(int tick, char &player);
void play_er(char &player);
void setup(int height, int width, char matrix[60][60]);
int X_Win(int check);
int O_Win(int check);
void icon1_Win();
void icon2_Win();
void SaveGame1(int sa, int ve, char matrix[60][60], int tick, int rule);
void SaveTurn1(char player, int turn);
void LoadTurn1(char &player);
void load1(char matrix[60][60], int &dai, int &rong);
void LoadGame1(int lo, int ad, int &tick, int &rule);
void SaveGame2(int sa, int ve, char matrix[60][60], int tick, int rule);
void SaveTurn2(char player, int turn);
void LoadTurn2(char &player);
void load2(char matrix[60][60], int &dai, int &rong);
void LoadGame2(int lo, int ad, int &tick, int &rule);
void SaveGame3(int sa, int ve, char matrix[60][60], int tick, int rule);
void SaveTurn3(char player, int turn);
void LoadTurn3(char &player);
void load3(char matrix[60][60], int &dai, int &rong);
void LoadGame3(int lo, int ad, int &tick, int &rule);
void SaveGame4(int sa, int ve, char matrix[60][60], int tick, int rule);
void SaveTurn4(char player, int turn);
void LoadTurn4(char &player);
void load4(char matrix[60][60], int &dai, int &rong);
void LoadGame4(int lo, int ad, int &tick, int &rule);
void SavePvC1(int sa, int ve, int n, char matrix[60][60]);
void loadCom1(char matrix[60][60], int &dai, int &rong);
void LoadPvC1(int lo, int ad, int &NumPlayer, PLAYER nguoichoi[5]);
void SavePvC2(int sa, int ve, int n, char matrix[60][60]);
void loadCom2(char matrix[60][60], int &dai, int &rong);
void LoadPvC2(int lo, int ad, int &NumPlayer, PLAYER nguoichoi[5]);
void SavePvC3(int sa, int ve, int n, char matrix[60][60]);
void loadCom3(char matrix[60][60], int &dai, int &rong);
void LoadPvC3(int lo, int ad, int &NumPlayer, PLAYER nguoichoi[5]);
void SavePvC4(int sa, int ve, int n, char matrix[60][60]);
void loadCom4(char matrix[60][60], int &dai, int &rong);
void LoadPvC4(int lo, int ad, int &NumPlayer, PLAYER nguoichoi[5]);
void rule2dau(int x, int y, int &tren, int &duoi, int &ngangtrai, int &ngangphai, int &cheotrentrai, int &cheoduoitrai, int &cheotrenphai, int &cheoduoiphai, int &quandichdoc, int &quandichngang, int &quandichcheothuan, int &quandichcheoxuoi, char matrix[60][60], char player);
int ReturnOrNot();
int TCdoc(int CurDong, int CurCot, char matrix[60][60], long MangDiemTanCong[7], long MangDiemPhongNgu[7]);
int TCngang(int CurDong, int CurCot, char matrix[60][60], long MangDiemTanCong[7], long MangDiemPhongNgu[7]);
int TCcheothuan(int CurDong, int CurCot, char matrix[60][60], long MangDiemTanCong[7], long MangDiemPhongNgu[7]);
int TCcheonguoc(int CurDong, int CurCot, char matrix[60][60], long MangDiemTanCong[7], long MangDiemPhongNgu[7]);
int PTdoc(int CurDong, int CurCot, char matrix[60][60], long MangDiemPhongNgu[7], long MangDiemTanCong[7]);
int PTngang(int CurDong, int CurCot, char matrix[60][60], long MangDiemPhongNgu[7], long MangDiemTanCong[7]);
int PTcheothuan(int CurDong, int CurCot, char matrix[60][60], long MangDiemPhongNgu[7], long MangDiemTanCong[7]);
int PTcheonguoc(int CurDong, int CurCot, char matrix[60][60], long MangDiemPhongNgu[7], long MangDiemTanCong[7]);
void ComVsPlayer(int q, int p, int n, char matrix[60][60], PLAYER nguoichoi[5], char player);
void gameplay_(int q, int p, char matrix[60][60], int tick, char player, int rule, int turn);
#endif
