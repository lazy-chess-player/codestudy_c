#define _CRT_SECURE_NO_WARNINGS

// 窗口宽度
#define WIN_WIDTH 120
// 窗口高度
#define WIN_HEIGHT 100

#define TABLE_WIDTH 78

#define MENU_WIDTH  60
#define COL_LEN_MAX 128

void printTableHead(int tableWidth);
void printTableTail(int tableWidth);
void printTableRow(int tableWidth, char cols[][COL_LEN_MAX], int n);
void printTableMidLine(int tableWidth, int cols);
void printTableMidInfo(int tableWidth, const char* str);
void printMidInfo(const char* str);