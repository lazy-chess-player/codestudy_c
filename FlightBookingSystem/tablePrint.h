#define _CRT_SECURE_NO_WARNINGS

// ���ڿ��
#define WIN_WIDTH 120
// ���ڸ߶�
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