#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <rpcndr.h>
#include <string.h>
#include "tablePrint.h"

// ������Ϣ�ṹ��
typedef struct Flight {
    char flightNo[10];   // �����
    char departure[20];      // ���վ
    char destination[20];    // �յ�վ
    int flightDay;           // �����գ��ܼ���
    char departureTime[6];  // ���ʱ��
    char arrivalTime[6];    // ����ʱ��
    int firstClassSeats;     // ͷ�Ȳ���λ��
    int economyClassSeats; // ���ò���λ��
    double firstClassPrice; // ͷ�Ȳ�Ʊ��
    double economyClassPrice; // ���ò�Ʊ��
    int fcAvailableSeats; // ͷ�Ȳ�ʣ����λ��
    int ecAvailableSeats; // ���ò�ʣ����λ��
    struct Flight* next;     // ָ����һ������ڵ��ָ��
} Flight;

// ������Ϣ����
typedef struct {
    Flight* head;  // ����ͷָ��
    int count;     // ��������
} FlightList;

// �û���Ϣ�ṹ��
typedef struct User {
    char tel[20];       // �ֻ���
    char password[20];       // ����
    struct User* next;       // ָ����һ���û��ڵ��ָ��
} User;

// �û���Ϣ����
typedef struct {
    User* head;  // ����ͷָ��
    int count;     // �û�����
} UserList;

// ������Ϣ�ṹ��
typedef struct Order {
    int orderNumber;    // �������
    char tel[20];       // �绰���루�û�����
    char flightNo[10];   // �����
    char passengerName[30];  // �˿�����
    char idNumber[20];       // �˿����֤��
    int status;              // ����״̬��0-���У�1-��Ʊ�ɹ���2-����Ʊ
    int seatType;            // ��λ���ͣ�0-ͷ�Ȳգ�1-���ò�
    double price;            // �����۸�
    struct Order* next;      // ָ����һ�������ڵ��ָ��
} Order;

// ������Ϣ����
typedef struct {
    Order* head;  // ����ͷָ��
    int count;     // ��������
} OrderList;

char userTel[20];
char systemPassword[20];
int orderNumberMax = 0;
FlightList FL;
UserList UL;
OrderList OL;

// ϵͳ��ʾ
void systemMessage(const char* message)
{
    printTableHead(MENU_WIDTH + 10);
    printTableMidInfo(MENU_WIDTH + 10, message);
    printTableTail(MENU_WIDTH + 10);
    system("pause");
}

// �½�ϵͳ���޸Ĺ���Ա����
bool newSystem() {
    char setPassword[20], op;
    while (true) {
        system("cls");
        printf("�������¹���Ա���룺");
        scanf(" %s", setPassword);

        printf("�����Ƿ�������ȷ����y/n)��");
        scanf(" %c", &op);

        // �������������ַ�
        while (getchar() != '\n');

        if (op == 'y' || op == 'Y') {
            strcpy(systemPassword, setPassword);
            systemPassword[strcspn(systemPassword, "\n")] = '\0';
            break;
        }
        else if (op == 'n' || op == 'N') {
            systemMessage("�������������룡");
        }
        else {
            systemMessage("ѡ����������ԡ�");
        }
    }

    // ���ļ�
    FILE* fp = fopen("adminData.fbs", "w");
    if (fp == NULL)
        return false;

    // ���ù���Ա����
    if (fwrite(systemPassword, sizeof(systemPassword), 1, fp) != 1) {
        fclose(fp);
        return false;
    }

    //�ر��ļ�
    fclose(fp);
    return true;
}

// ϵͳ��ʼ��
void systemInit() {
    // ��ȡ�����ļ�
    FILE* file = fopen("adminData.fbs", "rb");
    if (file == NULL) {
        printf("�޷��򿪹���Ա�ļ����Ƿ����´���ϵͳ����y/n)��");
        char op;
        scanf("%s", &op);
        while (true) {
            if (op == 'y' || op == 'Y') {
                if (newSystem()) {
                    systemMessage("ϵͳ�����ɹ�������������ϵͳ");
                    exit(0);
                }
                else {
                    systemMessage("ϵͳ����ʧ�ܣ������رա�");
                    exit(-1);
                }
            }
            else if (op == 'n' || op == 'N') {
                systemMessage("ϵͳ��ʼ��ʧ�ܣ������رա�");
                exit(-1);
            }
            else {
                printf("ѡ����������ԡ�");
            }
        }
    }

    // ��ȡ����Ա����
    if (fgets(systemPassword, sizeof(systemPassword), file) != NULL) {
        // ȥ�� systemPassword ĩβ�Ļ��з�
        systemPassword[strcspn(systemPassword, "\n")] = '\0';
    }
    else
        systemMessage("���󣡸ù���Ա�ļ��޹���Ա���롣");

    // �����ļ�ָ��λ��
    fseek(file, sizeof(systemPassword), SEEK_SET);

    //��ȡ������Ϣ
    //������ʱ�жϽ��
    Flight temp;
    //��һ�����ݷ�����ʱ����У�����ɹ����룬�����ļ�û�ж��꣬��֮���Ѷ������ѭ��
    while (fread(&temp, sizeof(Flight), 1, file) == 1) {
        //�����ڵ�
        Flight* pNewNode = (Flight*)malloc(sizeof(Flight));
        pNewNode->next = NULL;

        memcpy(pNewNode, &temp, sizeof(Flight));
        FL.count++;
        //ͷ�巨
        if (FL.head == NULL) { //ԭ��û��
            FL.head = pNewNode; //���´��ڵ���Ϊͷ
            FL.head->next = NULL;
        }
        else
        {
            pNewNode->next = FL.head;
            FL.head = pNewNode;
        }
    }

    //�����ļ�ָ��λ��
    fseek(file, sizeof(systemPassword) + sizeof(Flight) * FL.count + 10, SEEK_SET);

    //��ȡ�û���Ϣ
    //������ʱ�жϽ��
    User temp1;
    //��һ�����ݷ�����ʱ����У�����ɹ����룬�����ļ�û�ж��꣬��֮���Ѷ������ѭ��
    while (fread(&temp1, sizeof(User), 1, file) == 1) {
        //�����ڵ�
        User* pNewNode = (User*)malloc(sizeof(User));
        pNewNode->next = NULL;

        memcpy(pNewNode, &temp1, sizeof(User));
        UL.count++;
        //ͷ�巨
        if (UL.head == NULL) { //ԭ��û��
            UL.head = pNewNode; //���´��ڵ���Ϊͷ
            UL.head->next = NULL;
        }
        else
        {
            pNewNode->next = UL.head;
            UL.head = pNewNode;
        }
    }

    fclose(file);

    FILE* file2 = fopen("orderData.fbs", "rb");

    //��ȡ������Ϣ
    //������ʱ�жϽ��
    Order temp2;
    //��һ�����ݷ�����ʱ����У�����ɹ����룬�����ļ�û�ж��꣬��֮���Ѷ������ѭ��
    while (fread(&temp2, sizeof(Order), 1, file2) == 1) {
        //�����ڵ�
        Order* pNewNode = (Order*)malloc(sizeof(Order));
        pNewNode->next = NULL;

        memcpy(pNewNode, &temp2, sizeof(Order));
        OL.count++;
        //ͷ�巨
        if (OL.head == NULL) { //ԭ��û��
            OL.head = pNewNode; //���´��ڵ���Ϊͷ
            OL.head->next = NULL;
        }
        else
        {
            pNewNode->next = OL.head;
            OL.head = pNewNode;
        }
    }

    //�ر��ļ�
    fclose(file2);

    //���ÿ���̨����
    char cmd[256];
    sprintf(cmd, "mode con lines=%d cols=%d", WIN_HEIGHT, WIN_WIDTH);
    system(cmd);
    system("cls");//�����Ļ
}

// ϵͳ����
bool systemSave() {
    // ���ļ�
    FILE* fp = fopen("adminData.fbs", "wb");
    if (fp == NULL)
        return false;

    // �������Ա����
    if (fwrite(systemPassword, sizeof(systemPassword), 1, fp) != 1) {
        fclose(fp);
        return false;
    }

    // �����ļ�ָ��λ��
    fseek(fp, sizeof(systemPassword), SEEK_SET);

    // ���溽����Ϣ
    Flight* p = FL.head;
    while (p != NULL)
    {
        if (fwrite(p, sizeof(Flight), 1, fp) != 1)
        {
            fclose(fp);
            return false;
        }
        p = p->next;
    }

    // �����ļ�ָ��λ��
    fseek(fp, sizeof(systemPassword) + sizeof(Flight) * FL.count + 10, SEEK_SET);

    // �����û���Ϣ
    User* p1 = UL.head;
    while (p1 != NULL)
    {
        if (fwrite(p1, sizeof(User), 1, fp) != 1)
        {
            fclose(fp);
            return false;
        }
        p1 = p1->next;
    }

    fclose(fp);

    FILE* fp2 = fopen("orderData.fbs", "wb");

    // ���涩����Ϣ
    Order* p2 = OL.head;
    while (p2 != NULL)
    {
        if (fwrite(p2, sizeof(Order), 1, fp) != 1)
        {
            fclose(fp);
            return false;
        }
        p2 = p2->next;
    }

    fclose(fp2);

    return true;
}

// ��ȫ�˳�ϵͳ
void systemExit() {
    if (systemSave()) {
        systemMessage("ϵͳ�Ѱ�ȫ�˳�����лʹ�ã��ټ���");
        exit(0);
    }
    else {
        while (true) {
            system("cls");
            printf("ϵͳ����ʧ�ܣ��˴����и��Ľ��ᶪʧ���Ƿ�ȷ���˳�����y/n)��");
            char op;
            scanf(" %s", &op);

            if (op == 'y' || op == 'Y')
                exit(-1);
            else if (op == 'n' || op == 'N') {
                break;
            }
            else {
                systemMessage("ѡ����������ԡ�");
            }
        }
    }
}

// ��ϵͳѡ��
void systemChoose() {
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "���ඩƱϵͳ ��ϵͳѡ��");
    printTableMidInfo(MENU_WIDTH, "");
    printTableMidInfo(MENU_WIDTH, "1. �� �� Ա ϵ ͳ");
    printTableMidInfo(MENU_WIDTH, "2. �� �� �� ϵ ͳ");
    printTableMidInfo(MENU_WIDTH, "0. �� �� �� ϵ ͳ");
    printTableTail(MENU_WIDTH);
    printMidInfo("���������蹦�ܣ�0-2����");
}

// ���������Ϣ
void linePrintAll(FlightList* printFlightList) {
    if (printFlightList->head == NULL) { //����Ϊ��
        systemMessage("û�з��������ĺ�����Ϣ���볢��������ѯ��ʽ��");
        return;
    }
    system("cls");
    printf("\n");
    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("��  �����  ��  ���վ  ��  �յ�վ  �� ������ �� ���ʱ�� �� ����ʱ�� �� ͷ�Ȳ��ۼ�/��Ʊ �� ���ò��ۼ�/��Ʊ ��\n");

    //��������
    Flight* p = printFlightList->head;
    while (p != NULL)
    {
        printf("��%-10s��%-10s��%-10s��%-8d��%-10s��%-10s��%-8.2lf/%-8d��%-8.2lf/%-8d��\n",
            p->flightNo,
            p->departure,
            p->destination,
            p->flightDay,
            p->departureTime,
            p->arrivalTime,
            p->firstClassPrice,
            p->fcAvailableSeats,
            p->economyClassPrice,
            p->ecAvailableSeats);
        p = p->next;
    }
    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    system("pause");
}

// ����Ա���ܣ�ɾ��������Ϣ
void lineDelete(FlightList* FList, Flight* deleteLine) {
    if (deleteLine == NULL) {
        deleteLine = FList->head;
    }
    //�ж�ɾ���ڵ��Ƿ���ͷ�ڵ�
    if (deleteLine == FList->head)
    {
        Flight* p1 = FList->head; //�ȱ���ͷ�ڵ�
        FList->head = FList->head->next;//��ͷ�ڵ����һ�ڵ���Ϊͷ�ڵ�
        free(p1);//ɾ�������ݵ�ͷ�ڵ㡱����ԭ��Ҫɾ���Ľڵ�
        FList->count--;
        return;
    }
    else //����ͷ�ڵ�
    {
        Flight* p2;
        p2 = deleteLine->next;
        deleteLine->next = p2->next;
        free(p2);
        FList->count--;
        return;
    }
}

// ��֤����źϷ���
bool validateFlightNumber(const char* flightNo, FlightList* list) {
    Flight* currentFlight = list->head;
    while (currentFlight != NULL) {
        if (strcmp(currentFlight->flightNo, flightNo) == 0) {
            return false;  // ������Ѵ���
        }
        currentFlight = currentFlight->next;
    }
    return true;  // �����ͨ����֤
}

// ��������Ϣ��������
void addFlightToList(FlightList* list, Flight* pNewLine) {
    pNewLine->next = NULL;

    if (list->head == NULL) {
        list->head = pNewLine;
    }
    else {
        Flight* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = pNewLine;
    }
    list->count++;
}

// ����Ա���ܣ�����������Ϣ
void lineAdd() {
    //�˺���������Ӷ�����Ϣ����
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "��ǰ���� < ����������Ϣ >");
    printTableTail(MENU_WIDTH);
    //�����ڵ�
    Flight* pNewLine = (Flight*)malloc(sizeof(Flight));

    // ��Ϣ¼��
    char inputFlightNo[10];
    printMidInfo("������ < ����� > :");
    scanf("%s", inputFlightNo);
    // ����źϷ�����֤
    while (!validateFlightNumber(inputFlightNo, &FL)) {
        printMidInfo("������Ѵ��ڣ�����������!\n");
        scanf("%s", inputFlightNo);
    }
    strcpy(pNewLine->flightNo, inputFlightNo);

    printMidInfo("������ < ���վ > :");
    scanf("%s", pNewLine->departure);
    printMidInfo("������ < �յ�վ > :");
    scanf("%s", pNewLine->destination);

    while (true)
    {
        printMidInfo("������ < ������ > :");
        scanf("%d", &pNewLine->flightDay);
        if (pNewLine->flightDay > 7 || pNewLine < 0) {
            printMidInfo("������������������!\n");
        }
        else
            break;
    }

    while (true)
    {
        printMidInfo("������ < ���ʱ�� > :");
        scanf("%s", pNewLine->departureTime);
        if ((pNewLine->departureTime[0] - '0') * 10 + (pNewLine->departureTime[1] - '0') < 0 ||
            (pNewLine->departureTime[0] - '0') * 10 + (pNewLine->departureTime[1] - '0') > 23)
            printMidInfo("������������������!\n");
        else if ((pNewLine->departureTime[2] - '0') * 10 + (pNewLine->departureTime[3] - '0') < 0 ||
            (pNewLine->departureTime[2] - '0') * 10 + (pNewLine->departureTime[3] - '0') > 59)
            printMidInfo("������������������!\n");
        else break;
    }

    while (true)
    {
        printMidInfo("������ < ����ʱ�� > :");
        scanf("%s", pNewLine->arrivalTime);
        if ((pNewLine->arrivalTime[0] - '0') * 10 + (pNewLine->arrivalTime[1] - '0') < 0 ||
            (pNewLine->arrivalTime[0] - '0') * 10 + (pNewLine->arrivalTime[1] - '0') > 23)
            printMidInfo("������������������!\n");
        else if ((pNewLine->arrivalTime[2] - '0') * 10 + (pNewLine->arrivalTime[3] - '0') < 0 ||
            (pNewLine->arrivalTime[2] - '0') * 10 + (pNewLine->arrivalTime[3] - '0') > 59)
            printMidInfo("������������������!\n");
        else break;
    }

    printMidInfo("������ < ͷ�Ȳ��ۼ� > :");
    scanf("%lf", &pNewLine->firstClassPrice);
    printMidInfo("������ < ͷ�Ȳ���λ�� > :");
    scanf("%d", &pNewLine->firstClassSeats);
    pNewLine->fcAvailableSeats = pNewLine->firstClassSeats;
    printMidInfo("������ < ���ò��ۼ� > :");
    scanf("%lf", &pNewLine->economyClassPrice);
    printMidInfo("������ < ���ò���λ�� > :");
    scanf("%d", &pNewLine->economyClassSeats);
    pNewLine->ecAvailableSeats = pNewLine->economyClassSeats;

    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "��ȷ����Ϣ�Ƿ���ȷ...");
    printTableMidInfo(MENU_WIDTH, "ȷ��¼�� Y/y");
    printTableMidInfo(MENU_WIDTH, "����¼�� N/n");
    printTableMidInfo(MENU_WIDTH, "ȡ��¼�� B/b");
    printTableMidInfo(MENU_WIDTH, "ȷ�ϲ�����¼��... R/r");
    printTableTail(MENU_WIDTH);
    while (true)
    {
        char confirm;
        scanf(" %s", &confirm);
        if (confirm == 'Y' || confirm == 'y')
        {
            addFlightToList(&FL, pNewLine);
            break;
        }
        else if (confirm == 'N' || confirm == 'n')
        {
            free(pNewLine);
            lineAdd(); break;
        }
        else if (confirm == 'B' || confirm == 'b')
        {
            free(pNewLine);
            break;
        }
        else if (confirm == 'R' || confirm == 'r')
        {
            addFlightToList(&FL, pNewLine);
            lineAdd(); break;
        }
        else
            printMidInfo("ָ��������������루ȷ�� Y/y������N/n���� \n");
    }
}

// �������������Ϣ
void linePrint(Flight* line) {
    //ͨ���˺���������������ڵ��������Ϣ
    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("��  �����  ��  ���վ  ��  �յ�վ  �� ������ �� ���ʱ�� �� ����ʱ�� �� ͷ�Ȳ��ۼ�/��Ʊ �� ���ò��ۼ�/��Ʊ ��\n");
    printf("��%-10s��%-10s��%-10s��%-8d��%-10s��%-10s��%-8.2lf/%-8d��%-8.2lf/%-8d��\n",
        line->flightNo,
        line->departure,
        line->destination,
        line->flightDay,
        line->departureTime,
        line->arrivalTime,
        line->firstClassPrice,
        line->fcAvailableSeats,
        line->economyClassPrice,
        line->ecAvailableSeats);
    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\n");
}

// ����Ա���ܣ��޸ĺ�����Ϣ�˵�
void lineModifyMenu(Flight* p) {
    system("cls");//�����Ļ
    printf("�����ڸ��ĵļ�¼����ֵ��\n");
    linePrint(p);
    printf("\n");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "�������޸ĺ�����Ϣ...");
    printTableMidInfo(MENU_WIDTH, "");
    const char* subMenus[] = {
            "0. �޸� < ����� >",
            "1. �޸� < ���վ >",
            "2. �޸� < �յ�վ >",
            "3. �޸� < ������ >",
            "4. �޸� < ���ʱ�� >",
            "5. �޸� < ����ʱ�� >",
            "6. �޸� < ͷ�Ȳ���λ�� >",
            "7. �޸� < ���ò���λ�� >",
            "8. �޸� < ͷ�Ȳ�Ʊ�� >",
            "9. �޸� < ���ò�Ʊ�� >",
            "Y. �޸����   "
    };

    int count = sizeof(subMenus) / sizeof(subMenus[0]);
    for (int i = 0; i < count; i++) {
        printTableMidInfo(MENU_WIDTH, subMenus[i]);
    }
    printTableMidInfo(MENU_WIDTH, "");
    printTableTail(MENU_WIDTH);

    printMidInfo("���������蹦�ܣ�0-9,Y��");
}

// ����Ա���ܣ��޸ĺ�����Ϣִ�к���
void lineModifyExecute(Flight* p, const char* modifyItemName, void* modifyItem) {
    system("cls");//�����Ļ
    printf("�����ڸ��ĵļ�¼����ֵ��\n");
    linePrint(p);
    printf("\n");
    printTableHead(MENU_WIDTH);
    char info1[40];
    sprintf(info1, "��ǰ���� < �޸� %s >", modifyItemName);
    printTableMidInfo(MENU_WIDTH, info1);
    printTableTail(MENU_WIDTH);
    char info2[40];
    sprintf(info2, "������ < �޸ĺ�� %s > :", modifyItemName);
    printMidInfo(info2);
    if (strcmp(modifyItemName, "�����") == 0)
    {
        char inputFlightNo[10];
        scanf("%s", inputFlightNo);
        // ����źϷ�����֤
        while (!validateFlightNumber(inputFlightNo, &FL)) {
            printMidInfo("������Ѵ��ڣ����������룺");
            scanf("%s", inputFlightNo);
        }
        strcpy(modifyItem, inputFlightNo);
    }
    else if (strcmp(modifyItemName, "������") == 0)
    {
        while (true)
        {
            int modifyDay;
            scanf("%d", &modifyDay);
            if (modifyDay > 7 || modifyDay < 0) {
                printMidInfo("�����������������룺");
            }
            else {
                memcpy(modifyItem, &modifyDay, sizeof(modifyDay));
                break;
            }
        }
    }
    else if (strcmp(modifyItemName, "���ʱ��") == 0 || strcmp(modifyItemName, "����ʱ��") == 0)
    {
        while (true)
        {
            char modifyTime[6];
            scanf("%s", modifyTime);
            if ((modifyTime[0] - '0') * 10 + (modifyTime[1] - '0') < 0 ||
                (modifyTime[0] - '0') * 10 + (modifyTime[1] - '0') > 23)
                printMidInfo("�����������������룺");
            else if ((modifyTime[2] - '0') * 10 + (modifyTime[3] - '0') < 0 ||
                (modifyTime[2] - '0') * 10 + (modifyTime[3] - '0') > 59)
                printMidInfo("�����������������룺");
            else {
                memcpy(modifyItem, modifyTime, sizeof(modifyTime));
                break;
            }
        }
    }
    //TODO �޸���λ������ƱƱ��Ӧ����֮�ı�
    else if (strcmp(modifyItemName, "ͷ�Ȳ���λ��") == 0 || strcmp(modifyItemName, "���ò���λ��") == 0)
        scanf("%d", modifyItem);
    else if (strcmp(modifyItemName, "ͷ�Ȳ�Ʊ��") == 0 || strcmp(modifyItemName, "���ò�Ʊ��") == 0)
        scanf("%lf", modifyItem);
    else //���վ���յ�վ
        scanf("%s", modifyItem);
    system("cls");
}

// ����Ա���ܣ��޸ĺ�����Ϣ��
void lineModify() {
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "��ǰ���� < �޸ĺ�����Ϣ >");
    printTableTail(MENU_WIDTH);

    //ͨ������Ų���Ҫ�޸ĵĺ���
    char lineModifyNo[12];
    printMidInfo("������ < �����޸ĵĺ���� ����� > :");
    scanf("%s", lineModifyNo);

    Flight* p = FL.head;
    while (p != NULL) //��ͷ��ʼ����uid
    {
        if (strcmp(p->flightNo, lineModifyNo) == 0)
        {
            linePrint(p);
            printTableHead(MENU_WIDTH);
            printTableMidInfo(MENU_WIDTH, "��ȷ�����Ƿ�����Ҫ�޸ĵļ�¼...");
            printTableMidInfo(MENU_WIDTH, "ȷ�� Y/y");
            printTableMidInfo(MENU_WIDTH, "���� N/n");
            printTableTail(MENU_WIDTH);
            while (true)
            {
                char confirm;
                scanf(" %s", &confirm);
                if (confirm == 'Y' || confirm == 'y')
                    break;
                else if (confirm == 'N' || confirm == 'n')
                {
                    lineModify(); return;
                }
                else
                    printMidInfo("ָ��������������루ȷ�� Y/y������N/n���� \n");
            }
            while (true)
            {
                lineModifyMenu(p);
                char choice;
                scanf(" %s", &choice);
                switch (choice)
                {
                case '0': lineModifyExecute(p, "�����", &p->flightNo); break;
                case '1': lineModifyExecute(p, "���վ", &p->departure); break;
                case '2': lineModifyExecute(p, "�յ�վ", &p->destination); break;
                case '3': lineModifyExecute(p, "������", &p->flightDay); break;
                case '4': lineModifyExecute(p, "���ʱ��", &p->departureTime); break;
                case '5': lineModifyExecute(p, "����ʱ��", &p->arrivalTime); break;
                case '6': lineModifyExecute(p, "ͷ�Ȳ���λ��", &p->firstClassSeats); break;
                case '7': lineModifyExecute(p, "���ò���λ��", &p->economyClassSeats); break;
                case '8': lineModifyExecute(p, "ͷ�Ȳ�Ʊ��", &p->firstClassPrice); break;
                case '9': lineModifyExecute(p, "���ò�Ʊ��", &p->economyClassPrice); break;
                case 'Y': return;
                default:
                    systemMessage("��Ч��ѡ�������ѡ��");
                }
            }
        }
        p = p->next;
    }

    systemMessage("������������ĺ���Ų����ڣ�����������ԡ�");
}

// ����Ա���ܣ�ɾ��������Ϣ�˵�
void lineDeleteMenu() {
    //�˺�������ɾ��������Ϣ����
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "��ǰ���� < ɾ��������Ϣ >");
    printTableTail(MENU_WIDTH);

    //ͨ����¼��uid����Ҫ�޸ĵļ�¼
    char deleteLineNo[12];
    printMidInfo("������ < ����ɾ������� ����� > :");
    scanf("%s", deleteLineNo);

    Flight* p = FL.head;
    while (p->next != NULL) //��ͷ��ʼ����uid
    {
        if (strcmp(p->next->flightNo, deleteLineNo) == 0 || strcmp(p->flightNo, deleteLineNo) == 0) {
            linePrint(p);
            printTableHead(MENU_WIDTH);
            printTableMidInfo(MENU_WIDTH, "��ȷ�����Ƿ�����Ҫɾ���ļ�¼...");
            printTableMidInfo(MENU_WIDTH, "ȷ�� Y/y");
            printTableMidInfo(MENU_WIDTH, "���� N/n");
            printTableTail(MENU_WIDTH);
            while (true) {
                char confirm;
                scanf(" %s", &confirm);
                if (confirm == 'Y' || confirm == 'y') {
                    lineDelete(&FL, p);
                    systemMessage("������Ϣɾ����ɣ�");
                    return;
                }
                else if (confirm == 'N' || confirm == 'n') {
                    systemMessage("������Ϣɾ������ȡ����");
                    return;
                }
                else
                    printMidInfo("ָ��������������루ȷ�� Y/y������N/n���� \n");
            }
        }
        p = p->next;
    }

    systemMessage("������������ĺ���Ų����ڣ�����������ԡ�");
}

// ��ѯ������Ϣ�˵�
void lineInquireMenu() {
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "��ѡ����ҷ�ʽ...");
    printTableMidInfo(MENU_WIDTH, "");
    const char* subMenus[] = {
            "1. ͨ�� < ����� > ����",
            "2. ͨ�� < ���վ > ����",
            "3. ͨ�� < �յ�վ > ����",
            "4. ͨ�� < ��/��վ��� > ����",
            "0. ��������   "
    };

    int count = sizeof(subMenus) / sizeof(subMenus[0]);
    for (int i = 0; i < count; i++) {
        printTableMidInfo(MENU_WIDTH, subMenus[i]);
    }
    printTableMidInfo(MENU_WIDTH, "");
    printTableTail(MENU_WIDTH);

    printMidInfo("���������蹦�ܣ�0-4��");
}

void lineInquireExecute(FlightList* inquireList, char inquireType) {
    //��ѯ������Ϣ����inquireList()�в����������Ľ���������ɾ����
    //�˺���������ѯ������Ϣ����
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "��ǰ���� < ��ѯ������Ϣ >");
    printTableTail(MENU_WIDTH);
    char inquireInfo[12];
    char inquireInfo2[12];
    Flight* prev = NULL;

    switch (inquireType) //���� inquireType ������ĸ�жϲ�ѯ����
    {
    case '1':// ͨ������Ų���
        printMidInfo("������ < �����ѯ����� ����� > :");
        scanf("%s", inquireInfo);

        Flight* p = inquireList->head;
        do //ʹ�� do-while ѭ������ while ѭ��
        {
            if (_strcmpi(p->flightNo, inquireInfo) == 0) {
                linePrint(p);
                system("pause");
                return;
            }
            p = p->next;
        } while (p != NULL);
        systemMessage("������������ĺ���Ų����ڣ�����������ԡ�");
        return;
    case '2':// ͨ�����վ����
        printMidInfo("������ < �����ѯ����� ���վ > :");
        scanf("%s", inquireInfo);

        Flight* q = inquireList->head;
        while (q != NULL)
        {
            if (_strcmpi(q->departure, inquireInfo) != 0) {
                lineDelete(inquireList, prev);
                if (prev == NULL) {
                    q = inquireList->head;
                }
                else {
                    q = prev->next;
                }
            }
            else {
                prev = q;
                q = q->next;
            }
        }
        break;
    case '3':// ͨ���յ�վ����
        printMidInfo("������ < �����ѯ����� �յ�վ > :");
        scanf("%s", inquireInfo);

        Flight* r = inquireList->head;
        while (r != NULL)
        {
            if (_strcmpi(r->destination, inquireInfo) != 0) {
                lineDelete(inquireList, prev);
                if (prev == NULL) {
                    r = inquireList->head;
                }
                else {
                    r = prev->next;
                }
            }
            else {
                prev = r;
                r = r->next;
            }
        }
        break;
    case '4':// ͨ����/��վ��ϲ���
        printMidInfo("������ < �����ѯ����� ���վ > :");
        scanf("%s", inquireInfo);
        printMidInfo("������ < �����ѯ����� �յ�վ > :");
        scanf("%s", inquireInfo2);

        Flight* s = inquireList->head;
        while (s != NULL)
        {
            if (_strcmpi(s->departure, inquireInfo) != 0 || _strcmpi(s->destination, inquireInfo2) != 0) {
                lineDelete(inquireList, prev);
                if (prev == NULL) {
                    s = inquireList->head;
                }
                else {
                    s = prev->next;
                }
            }
            else {
                prev = s;
                s = s->next;
            }
        }
        break;
    default:
        systemMessage("������������Ĳ�ѯ������Ч�����������롣");
        return;
    }

    linePrintAll(inquireList);
}

void lineInquire() {
    //�½�һ��������Ϣ������FL�е����ݸ��Ƶ���������
    FlightList* inquireList = (FlightList*)malloc(sizeof(FlightList*));
    inquireList->head = NULL;
    inquireList->count = 0;
    Flight* p = FL.head;
    while (p != NULL) {
        Flight* pNewLine = (Flight*)malloc(sizeof(Flight));
        memcpy(pNewLine, p, sizeof(Flight));
        addFlightToList(inquireList, pNewLine);
        p = p->next;
    }

    while (true) {
        // ��ѯ����
        bool flag = true;
        while (true) {
            system("cls");
            lineInquireMenu();
            char choice;
            scanf(" %s", &choice);

            switch (choice) {
            case '1': // ͨ������Ų���
                lineInquireExecute(inquireList, '1');
                flag = false;
                break;
            case '2': // ͨ�����վ����
                lineInquireExecute(inquireList, '2');
                break;
            case '3': // ͨ���յ�վ����
                lineInquireExecute(inquireList, '3');
                break;
            case '4': // ͨ����/��վ��ϲ���
                lineInquireExecute(inquireList, '4');
                break;
            case '0':
                return;
            default:
                systemMessage("��Ч��ѡ�������ѡ��");
                flag = false;
                break;
            }

            if (flag)
                break;
        }

        // ѯ���Ƿ����ԭ���Ľ����������
        printTableHead(MENU_WIDTH);
        printTableMidInfo(MENU_WIDTH, "�Ƿ����ԭ���Ľ����������...");
        printTableMidInfo(MENU_WIDTH, "ȷ�� Y/y");
        printTableMidInfo(MENU_WIDTH, "���� N/n");
        printTableTail(MENU_WIDTH);
        while (true) {
            char confirm;
            scanf(" %s", &confirm);
            if (confirm == 'Y' || confirm == 'y') {
                break;
            }
            else if (confirm == 'N' || confirm == 'n') {
                return;
            }
            else
                printMidInfo("ָ��������������루ȷ�� Y/y������N/n���� \n");
        }
    }
}

// ����Ա�˵�
void adminMenu() {

    const char* subMenus[] = {
            "1. �� �� �� �� �� Ϣ",
            "2. �� �� �� �� �� Ϣ",
            "3. ɾ �� �� �� �� Ϣ",
            "4. �� ѯ �� �� �� Ϣ",
            "5. ȫ �� �� �� �� Ϣ",
            "6. �� �� �� �� �� ��",
            "0. �� �� ϵ ͳ     "
    };

    while (true) {
        system("cls");
        printTableHead(MENU_WIDTH);
        printTableMidInfo(MENU_WIDTH, "�� �� Ա �� �� �� ��");
        printTableMidInfo(MENU_WIDTH, "");
        int count = sizeof(subMenus) / sizeof(subMenus[0]);
        for (int i = 0; i < count; i++) {
            printTableMidInfo(MENU_WIDTH, subMenus[i]);
        }
        printTableMidInfo(MENU_WIDTH, "");
        printTableTail(MENU_WIDTH);

        printMidInfo("���������蹦�ܣ�0-6����");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            lineAdd(); break;
        case 2:
            lineModify(); break;
        case 3:
            lineDeleteMenu(); break;
        case 4:
            lineInquire(); break;
        case 5:
            linePrintAll(&FL); break;
        case 6:
            newSystem(); break;
        case 0:
            systemExit();
            return;
        default:
            systemMessage("��Ч��ѡ�������ѡ��");
            break;
        }
    }
}

// ����Ա��¼��֤
bool adminIdentify(const char* password) {
    if (strcmp(password, systemPassword) == 0)
        return true;
    else
        return false;
}

// ����Ա��¼
void adminLogin() {
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "�� �� Ա �� ¼");
    printTableTail(MENU_WIDTH);

    printMidInfo("���������Ա���룺");
    char password[20];
    scanf("%s", password);

    if (adminIdentify(password)) {
        systemMessage("����Ա�����֤�ɹ�");
        adminMenu();
    }
    else
        systemMessage("����Ա������������ԡ�");
}

// �ж��û��Ƿ����
bool isUserExist(const char* tel) {
    User* p = UL.head;
    while (p != NULL) {
        if (strcmp(p->tel, tel) == 0)
            return true;
        p = p->next;
    }
    return false;
}

bool isPasswordCorrect(const char* tel) {
    // �ж��û������Ƿ���ȷ
    User* p = UL.head;
    while (p != NULL) {
        if (strcmp(p->tel, tel) == 0) {
            char password[20];
            printMidInfo("���������룺");
            scanf("%s", password);
            if (strcmp(p->password, password) == 0)
                return true;
            else
                return false;
        }
        p = p->next;
    }
}

// �û�ע��
void userRegister(char* tel) {
    // �˺��������û�ע�Ṧ��
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "��ǰ���� < �û�ע�� >");
    printTableTail(MENU_WIDTH);

    // �����ڵ�
    User* pNewUser = (User*)malloc(sizeof(User));

    // �������벢ȷ������
    char password[20];
    char confirmPassword[20];
    while (true) {
        printMidInfo("���������룺");
        scanf("%s", password);
        printMidInfo("��ȷ�����룺");
        scanf("%s", confirmPassword);
        if (strcmp(password, confirmPassword) == 0)
            break;
        else
            printMidInfo("������������벻һ�£����������롣");
    }

    strcpy(pNewUser->tel, tel);
    strcpy(pNewUser->password, password);

    // ���û���Ϣ��ӵ�����
    pNewUser->next = NULL;
    if (UL.head == NULL) {
        UL.head = pNewUser;
    }
    else {
        User* current = UL.head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = pNewUser;
    }

    UL.count++;

    // ע��ɹ�
    systemMessage("�û�ע��ɹ���ϵͳ�����رա����������¼��");

    // ������Ϣ����ϵͳ
    systemExit();
}

// �û����ܣ��޸�����
void userPasswordRenew(const char* tel) {
    // �˺��������û��޸����빦��
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "��ǰ���� < �޸����� >");
    printTableTail(MENU_WIDTH);

    // �������벢ȷ������
    char password[20];
    char confirmPassword[20];
    while (true) {
        printMidInfo("�����������룺");
        scanf("%s", password);
        printMidInfo("��ȷ�������룺");
        scanf("%s", confirmPassword);
        if (strcmp(password, confirmPassword) == 0)
            break;
        else
            printMidInfo("������������벻һ�£����������롣");
    }

    // �޸�����
    User* p = UL.head;
    while (p != NULL) {
        if (strcmp(p->tel, tel) == 0) {
            strcpy(p->password, password);
            break;
        }
        p = p->next;
    }

    // �޸ĳɹ�
    systemMessage("�����޸ĳɹ���ϵͳ�����رա����������¼��");

    // ������Ϣ����ϵͳ
    systemExit();
}

// �û����ܣ����������Ʊ
void lineOrder() {
    // �˺��������û����������Ʊ����
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "��ǰ���� < ���������Ʊ >");
    printTableTail(MENU_WIDTH);

    // ͨ������Ų���Ҫ�����ĺ���
    char lineOrderNo[12];
    printMidInfo("������ < ���趩������� ����� > :");
    scanf("%s", lineOrderNo);

    // ͨ������Ų��Һ���
    Flight* p = FL.head;
    while (p != NULL) //��ͷ��ʼ���Һ����
    {
        if (strcmp(p->flightNo, lineOrderNo) == 0)
        {
            linePrint(p);
            printTableHead(MENU_WIDTH);
            printTableMidInfo(MENU_WIDTH, "��ȷ�����Ƿ�����Ҫ�����ĺ���...");
            printTableMidInfo(MENU_WIDTH, "ȷ�� Y/y");
            printTableMidInfo(MENU_WIDTH, "���� N/n");
            printTableTail(MENU_WIDTH);
            while (true)
            {
                char confirm;
                scanf(" %s", &confirm);
                if (confirm == 'Y' || confirm == 'y')
                    break;
                else if (confirm == 'N' || confirm == 'n')
                {
                    systemMessage("���������Ʊ����ȡ����");
                    return;
                }
                else
                    printMidInfo("ָ��������������루ȷ�� Y/y������N/n���� \n");
            }
            break;
        }
        p = p->next;
    }

    // �ж��Ƿ��ҵ�����
    if (p == NULL) {
        systemMessage("������������ĺ���Ų����ڣ�����������ԡ�");
        return;
    }

    // �½�����
    Order* pNewOrder = (Order*)malloc(sizeof(Order));
    strcpy(pNewOrder->tel, userTel);
    strcpy(pNewOrder->flightNo, lineOrderNo);
    pNewOrder->next = NULL;

    // �û����붩���ߵ����������֤��
    printMidInfo("�����붩���ߵ�������");
    scanf("%s", pNewOrder->passengerName);
    printMidInfo("�����붩���ߵ����֤�ţ�");
    scanf("%s", pNewOrder->idNumber);

    // �жϸó˿��Ƿ��Ѿ���������������Ʊ�������������Ԥ���������֤�жϣ�
    Order* q = OL.head;
    while (q != NULL) {
        if (strcmp(q->idNumber, pNewOrder->idNumber) == 0) {
            systemMessage("�ó˿��Ѿ���������������Ʊ���������ظ�Ԥ����");
            return;
        }
        q = q->next;
    }

    // ��������
    printMidInfo("��������Ҫ�����Ĳ�λ���ͣ�ͷ�Ȳ�/���òգ���");
    char cabinType[10];
    scanf("%s", cabinType);
    if (strcmp(cabinType, "ͷ�Ȳ�") == 0) {
        if (p->fcAvailableSeats > 0) {
            p->fcAvailableSeats--;
            pNewOrder->status = 1;
            systemMessage("�����ɹ���");
        }
        else {
            systemMessage("ͷ�Ȳ���Ʊ���㣬����ʧ�ܣ�");
            // ѯ���Ƿ��
            printTableHead(MENU_WIDTH);
            printTableMidInfo(MENU_WIDTH, "�Ƿ��...");
            printTableMidInfo(MENU_WIDTH, "ȷ�� Y/y");
            printTableMidInfo(MENU_WIDTH, "���� N/n");
            printTableTail(MENU_WIDTH);
            while (true) {
                char confirm;
                scanf(" %s", &confirm);
                if (confirm == 'Y' || confirm == 'y') {
                    pNewOrder->status = 0;
                    systemMessage("�򲹳ɹ���");
                    break;
                }
                else if (confirm == 'N' || confirm == 'n') {
                    systemMessage("��ȡ����");
                    return;
                }
                else
                    printMidInfo("ָ��������������루ȷ�� Y/y������N/n���� \n");
            }
        }
        pNewOrder->seatType = 0;
        pNewOrder->price = p->firstClassPrice;
    }
    else if (strcmp(cabinType, "���ò�") == 0) {
        if (p->ecAvailableSeats > 0) {
            p->ecAvailableSeats--;
            pNewOrder->status = 1;
            systemMessage("�����ɹ���");
        }
        else {
            systemMessage("���ò���Ʊ���㣬����ʧ�ܣ�");
            // ѯ���Ƿ��
            printTableHead(MENU_WIDTH);
            printTableMidInfo(MENU_WIDTH, "�Ƿ��...");
            printTableMidInfo(MENU_WIDTH, "ȷ�� Y/y");
            printTableMidInfo(MENU_WIDTH, "���� N/n");
            printTableTail(MENU_WIDTH);
            while (true) {
                char confirm;
                scanf(" %s", &confirm);
                if (confirm == 'Y' || confirm == 'y') {
                    pNewOrder->status = 0;
                    systemMessage("�򲹳ɹ���");
                    break;
                }
                else if (confirm == 'N' || confirm == 'n') {
                    systemMessage("��ȡ����");
                    return;
                }
                else
                    printMidInfo("ָ��������������루ȷ�� Y/y������N/n���� \n");
            }
        }
        pNewOrder->seatType = 1;
        pNewOrder->price = p->economyClassPrice;
    }
    else {
        systemMessage("��Ч�Ĳ�λ���ͣ�����ʧ�ܣ�");
        return;
    }

    orderNumberMax++;
    pNewOrder->orderNumber = orderNumberMax;
    OL.count++;

    // ��������Ϣ��ӵ�����
    pNewOrder->next = NULL;
    if (OL.head == NULL) {
        OL.head = pNewOrder;
    }
    else {
        Order* current = OL.head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = pNewOrder;
    }
}

// ��ӡ������Ϣ
void orderPrint(Order* order) {
    //ͨ���˺���������������ڵ��������Ϣ
    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("�� ������ţ�%d\n", order->orderNumber);
    printf("�� ����ţ�%s\n", order->flightNo);
    printf("�� �˿�������%s\n", order->passengerName);
    printf("�� �˿����֤�ţ�%s\n", order->idNumber);
    printf("�� ����״̬��");
    if (order->status == 1)
        printf("�Ѷ���\n");
    else
        printf("��\n");
    printf("�� ��λ���ͣ�");
    if (order->seatType == 0)
        printf("ͷ�Ȳ�\n");
    else
        printf("���ò�\n");
    printf("�� ʵ���%.2lf\n", order->price);
    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\n");
}

// �û����ܣ��˶�����
void lineUnsubscribe(Order* unsubscribeOrder) {
    // ���������Ϊ���˿�
    unsubscribeOrder->status = 2;

    // ������ǰ�˿����Ӧ�ĺ���ϯλ��Ʊ�Ƿ�Ϊ 0�����Ϊ 0 ������Ƿ��к򲹶������к򲹶���������Ϊ�Ѷ�������Ʊ���ı䣬������Ʊ�� 1��
    Flight* p = FL.head;
    while (p != NULL) {
        if (strcmp(p->flightNo, unsubscribeOrder->flightNo) == 0) {
            if (unsubscribeOrder->seatType == 0) {
                if (p->fcAvailableSeats == 0) {
                    Order* q = OL.head;
                    while (q != NULL) {
                        if (strcmp(q->flightNo, unsubscribeOrder->flightNo) == 0 && q->status == 0 && q->seatType == 0) {
                            q->status = 1;
                            break;
                        }
                        q = q->next;
                    }
                }
                else {
                    p->fcAvailableSeats++;
                }
            }
            else {
                if (p->ecAvailableSeats == 0) {
                    Order* q = OL.head;
                    while (q != NULL) {
                        if (strcmp(q->flightNo, unsubscribeOrder->flightNo) == 0 && q->status == 0 && q->seatType == 1) {
                            q->status = 1;
                            break;
                        }
                        q = q->next;
                    }
                }
                else {
                    p->ecAvailableSeats++;
                }
            }
            break;
        }
        p = p->next;
    }
}


// �û����ܣ��˶������Ʊ
void lineUnsubscribeMenu() {
    // �˺��������û��˶������Ʊ����
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "��ǰ���� < �˶������Ʊ >");
    printTableTail(MENU_WIDTH);

    // ͨ��������Ų���Ҫ�˶��Ķ���
    int lineUnsubscribeNo;
    printMidInfo("������ < �����˶������ ������� > :");
    scanf("%d", &lineUnsubscribeNo);

    // ͨ��������Ų��Ҷ���
    Order* p = OL.head;
    while (p != NULL) //��ͷ��ʼ���Ҷ������
    {
        if (p->orderNumber == lineUnsubscribeNo)
        {
            orderPrint(p);
            printTableHead(MENU_WIDTH);
            printTableMidInfo(MENU_WIDTH, "��ȷ�����Ƿ�����Ҫ�˶��Ķ���...");
            printTableMidInfo(MENU_WIDTH, "ȷ�� Y/y");
            printTableMidInfo(MENU_WIDTH, "���� N/n");
            printTableTail(MENU_WIDTH);
            while (true)
            {
                char confirm;
                scanf(" %s", &confirm);
                if (confirm == 'Y' || confirm == 'y') {
                    lineUnsubscribe(p);
                    return;
                }
                else if (confirm == 'N' || confirm == 'n')
                {
                    systemMessage("�˶������Ʊ����ȡ����");
                    return;
                }
                else
                    printMidInfo("ָ��������������루ȷ�� Y/y������N/n���� \n");
            }
        }
        p = p->next;
    }
}

// ��ӡ���ж�����Ϣ
void orderPrintAll(OrderList* orderList, const char* tel) {
    if (orderList->head == NULL) { //����Ϊ��
        systemMessage("û�ж�����Ϣ��");
        return;
    }
    system("cls");
    printf("\n");
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("��  ������  ��  �����  ��  ������  ��   ��  ��  ֤  ��   �� ��λ���� �� ʵ�ʸ��� �� ����״̬ ��\n");

    //��������
    Order* p = orderList->head;
    while (p != NULL)
    {
        // �ж��Ƿ�Ϊ��ǰ�û��Ķ���
        if (strcmp(p->tel, tel) == 0) {
            printf("��%-10d��%-10s��%-10s��%-20s��%-10s��%-10.2lf��%-10s��\n",
                p->orderNumber,
                p->flightNo,
                p->passengerName,
                p->idNumber,
                p->seatType == 0 ? "ͷ�Ȳ�" : "���ò�",
                p->price,
                p->status == 0 ? "��" : p->status == 1 ? "�Ѷ���" : "���˿�"
            );
        }
        p = p->next;
    }
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    system("pause");
}

// �û����ܲ˵�
void userMenu() {
    const char* subMenus[] = {
            "1. �� ѯ �� �� �� Ϣ",
            "2. �� �� �� �� �� Ʊ",
            "3. �� �� �� �� �� Ʊ",
            "4. �� �� �� �� �� ��",
            "5. �� ʾ �� �� �� ��",
            "0. �� �� ϵ ͳ     "
    };

    while (true) {
        system("cls");
        printTableHead(MENU_WIDTH);
        printTableMidInfo(MENU_WIDTH, "�� �� �� �� �� ��");
        printTableMidInfo(MENU_WIDTH, "");
        int count = sizeof(subMenus) / sizeof(subMenus[0]);
        for (int i = 0; i < count; i++) {
            printTableMidInfo(MENU_WIDTH, subMenus[i]);
        }
        printTableMidInfo(MENU_WIDTH, "");
        printTableTail(MENU_WIDTH);

        printMidInfo("���������蹦�ܣ�0-4����");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            lineInquire(); break;
        case 2:
            lineOrder(); break;
        case 3:
            lineUnsubscribeMenu(); break;
        case 4:
            userPasswordRenew(userTel); break;
        case 5:
            orderPrintAll(&OL, userTel); break;
        case 0:
            systemExit();
            return;
        default:
            systemMessage("��Ч��ѡ�������ѡ��");
            break;
        }
    }
}

// �û���¼
void userLogin() {
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "�� �� �� ¼");
    printTableTail(MENU_WIDTH);

    printMidInfo("�������ֻ��ţ�");
    scanf("%s", userTel);

    // �û���֤����֤�ֻ����Ƿ����
    if (isUserExist(userTel)) {
        // �û���֤����֤�����Ƿ���ȷ
        if (isPasswordCorrect(userTel)) {
            systemMessage("�û������֤�ɹ�");
            userMenu();
        }
        else {
            systemMessage("������������ԡ�");
        }
    }
    else {
        while (true) {
            system("cls");
            printTableHead(MENU_WIDTH);
            printTableMidInfo(MENU_WIDTH, "�û������ڣ��Ƿ�ע�᣿");
            char info[50] = "��������ֻ����ǣ�";
            strcat(info, userTel);
            printTableMidInfo(MENU_WIDTH, info);
            printTableTail(MENU_WIDTH);
            printTableMidInfo(MENU_WIDTH, "1.�ǣ���������ֻ��Ž���ע�ᡣ");
            printTableMidInfo(MENU_WIDTH, "2.����������������������ԡ�");
            printTableTail(MENU_WIDTH);
            printMidInfo("���������蹦�ܣ�1,2����");

            char choice;
            scanf(" %s", &choice);

            switch (choice) {
            case '1':
                userRegister(userTel); break;
            case '2':
                userLogin(); return;
            default:
                systemMessage("��Ч��ѡ�������ѡ��");
                break;
            }
        }
    }
}