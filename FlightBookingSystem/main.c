#define _CRT_SECURE_NO_WARNINGS 1
#include "flight_booking_system.h"

int main() {
    char choice;

    systemInit();
    while (true) {
        systemChoose();
        scanf("%s", &choice);

        switch (choice) {
        case '1': adminLogin(); break;
        case '2': userLogin(); break;
        case '0':
            systemExit();
            return 0;
        default:
            systemMessage("无效的选项。请重新选择。");
            break;
        }
    }
}
