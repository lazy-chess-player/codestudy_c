#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <rpcndr.h>
#include <string.h>
#include "tablePrint.h"

// 航班信息结构体
typedef struct Flight {
    char flightNo[10];   // 航班号
    char departure[20];      // 起点站
    char destination[20];    // 终点站
    int flightDay;           // 飞行日（周几）
    char departureTime[6];  // 起飞时间
    char arrivalTime[6];    // 降落时间
    int firstClassSeats;     // 头等舱座位数
    int economyClassSeats; // 经济舱座位数
    double firstClassPrice; // 头等舱票价
    double economyClassPrice; // 经济舱票价
    int fcAvailableSeats; // 头等舱剩余座位数
    int ecAvailableSeats; // 经济舱剩余座位数
    struct Flight* next;     // 指向下一个航班节点的指针
} Flight;

// 航班信息链表
typedef struct {
    Flight* head;  // 链表头指针
    int count;     // 航班数量
} FlightList;

// 用户信息结构体
typedef struct User {
    char tel[20];       // 手机号
    char password[20];       // 密码
    struct User* next;       // 指向下一个用户节点的指针
} User;

// 用户信息链表
typedef struct {
    User* head;  // 链表头指针
    int count;     // 用户数量
} UserList;

// 订单信息结构体
typedef struct Order {
    int orderNumber;    // 订单编号
    char tel[20];       // 电话号码（用户名）
    char flightNo[10];   // 航班号
    char passengerName[30];  // 乘客姓名
    char idNumber[20];       // 乘客身份证号
    int status;              // 订单状态：0-候补中，1-订票成功，2-已退票
    int seatType;            // 座位类型：0-头等舱，1-经济舱
    double price;            // 订单价格
    struct Order* next;      // 指向下一个订单节点的指针
} Order;

// 订单信息链表
typedef struct {
    Order* head;  // 链表头指针
    int count;     // 订单数量
} OrderList;

char userTel[20];
char systemPassword[20];
int orderNumberMax = 0;
FlightList FL;
UserList UL;
OrderList OL;

// 系统提示
void systemMessage(const char* message)
{
    printTableHead(MENU_WIDTH + 10);
    printTableMidInfo(MENU_WIDTH + 10, message);
    printTableTail(MENU_WIDTH + 10);
    system("pause");
}

// 新建系统、修改管理员密码
bool newSystem() {
    char setPassword[20], op;
    while (true) {
        system("cls");
        printf("请输入新管理员密码：");
        scanf(" %s", setPassword);

        printf("密码是否设置正确？（y/n)：");
        scanf(" %c", &op);

        // 处理多余的输入字符
        while (getchar() != '\n');

        if (op == 'y' || op == 'Y') {
            strcpy(systemPassword, setPassword);
            systemPassword[strcspn(systemPassword, "\n")] = '\0';
            break;
        }
        else if (op == 'n' || op == 'N') {
            systemMessage("请重新设置密码！");
        }
        else {
            systemMessage("选项错误，请重试。");
        }
    }

    // 打开文件
    FILE* fp = fopen("adminData.fbs", "w");
    if (fp == NULL)
        return false;

    // 设置管理员密码
    if (fwrite(systemPassword, sizeof(systemPassword), 1, fp) != 1) {
        fclose(fp);
        return false;
    }

    //关闭文件
    fclose(fp);
    return true;
}

// 系统初始化
void systemInit() {
    // 读取数据文件
    FILE* file = fopen("adminData.fbs", "rb");
    if (file == NULL) {
        printf("无法打开管理员文件。是否重新创建系统？（y/n)：");
        char op;
        scanf("%s", &op);
        while (true) {
            if (op == 'y' || op == 'Y') {
                if (newSystem()) {
                    systemMessage("系统创建成功，请重新启动系统");
                    exit(0);
                }
                else {
                    systemMessage("系统创建失败，即将关闭。");
                    exit(-1);
                }
            }
            else if (op == 'n' || op == 'N') {
                systemMessage("系统初始化失败，即将关闭。");
                exit(-1);
            }
            else {
                printf("选项错误，请重试。");
            }
        }
    }

    // 获取管理员密码
    if (fgets(systemPassword, sizeof(systemPassword), file) != NULL) {
        // 去除 systemPassword 末尾的换行符
        systemPassword[strcspn(systemPassword, "\n")] = '\0';
    }
    else
        systemMessage("错误！该管理员文件无管理员密码。");

    // 设置文件指针位置
    fseek(file, sizeof(systemPassword), SEEK_SET);

    //获取航班信息
    //创建临时判断结点
    Flight temp;
    //读一次数据放入临时结点中，如果成功读入，代表文件没有读完，反之则已读完结束循环
    while (fread(&temp, sizeof(Flight), 1, file) == 1) {
        //创建节点
        Flight* pNewNode = (Flight*)malloc(sizeof(Flight));
        pNewNode->next = NULL;

        memcpy(pNewNode, &temp, sizeof(Flight));
        FL.count++;
        //头插法
        if (FL.head == NULL) { //原来没有
            FL.head = pNewNode; //将新创节点作为头
            FL.head->next = NULL;
        }
        else
        {
            pNewNode->next = FL.head;
            FL.head = pNewNode;
        }
    }

    //设置文件指针位置
    fseek(file, sizeof(systemPassword) + sizeof(Flight) * FL.count + 10, SEEK_SET);

    //获取用户信息
    //创建临时判断结点
    User temp1;
    //读一次数据放入临时结点中，如果成功读入，代表文件没有读完，反之则已读完结束循环
    while (fread(&temp1, sizeof(User), 1, file) == 1) {
        //创建节点
        User* pNewNode = (User*)malloc(sizeof(User));
        pNewNode->next = NULL;

        memcpy(pNewNode, &temp1, sizeof(User));
        UL.count++;
        //头插法
        if (UL.head == NULL) { //原来没有
            UL.head = pNewNode; //将新创节点作为头
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

    //获取订单信息
    //创建临时判断结点
    Order temp2;
    //读一次数据放入临时结点中，如果成功读入，代表文件没有读完，反之则已读完结束循环
    while (fread(&temp2, sizeof(Order), 1, file2) == 1) {
        //创建节点
        Order* pNewNode = (Order*)malloc(sizeof(Order));
        pNewNode->next = NULL;

        memcpy(pNewNode, &temp2, sizeof(Order));
        OL.count++;
        //头插法
        if (OL.head == NULL) { //原来没有
            OL.head = pNewNode; //将新创节点作为头
            OL.head->next = NULL;
        }
        else
        {
            pNewNode->next = OL.head;
            OL.head = pNewNode;
        }
    }

    //关闭文件
    fclose(file2);

    //设置控制台窗口
    char cmd[256];
    sprintf(cmd, "mode con lines=%d cols=%d", WIN_HEIGHT, WIN_WIDTH);
    system(cmd);
    system("cls");//清空屏幕
}

// 系统保存
bool systemSave() {
    // 打开文件
    FILE* fp = fopen("adminData.fbs", "wb");
    if (fp == NULL)
        return false;

    // 保存管理员密码
    if (fwrite(systemPassword, sizeof(systemPassword), 1, fp) != 1) {
        fclose(fp);
        return false;
    }

    // 设置文件指针位置
    fseek(fp, sizeof(systemPassword), SEEK_SET);

    // 保存航班信息
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

    // 设置文件指针位置
    fseek(fp, sizeof(systemPassword) + sizeof(Flight) * FL.count + 10, SEEK_SET);

    // 保存用户信息
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

    // 保存订单信息
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

// 安全退出系统
void systemExit() {
    if (systemSave()) {
        systemMessage("系统已安全退出，感谢使用！再见！");
        exit(0);
    }
    else {
        while (true) {
            system("cls");
            printf("系统保存失败，此次运行更改将会丢失，是否确认退出？（y/n)：");
            char op;
            scanf(" %s", &op);

            if (op == 'y' || op == 'Y')
                exit(-1);
            else if (op == 'n' || op == 'N') {
                break;
            }
            else {
                systemMessage("选项错误，请重试。");
            }
        }
    }
}

// 子系统选择
void systemChoose() {
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "航班订票系统 子系统选择");
    printTableMidInfo(MENU_WIDTH, "");
    printTableMidInfo(MENU_WIDTH, "1. 管 理 员 系 统");
    printTableMidInfo(MENU_WIDTH, "2. 客 户 端 系 统");
    printTableMidInfo(MENU_WIDTH, "0. 退 出 此 系 统");
    printTableTail(MENU_WIDTH);
    printMidInfo("请输入所需功能（0-2）：");
}

// 输出航班信息
void linePrintAll(FlightList* printFlightList) {
    if (printFlightList->head == NULL) { //链表为空
        systemMessage("没有符合条件的航班信息，请尝试其他查询方式。");
        return;
    }
    system("cls");
    printf("\n");
    printf("┌───────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│  航班号  │  起点站  │  终点站  │ 飞行日 │ 起飞时间 │ 降落时间 │ 头等舱售价/余票 │ 经济舱售价/余票 │\n");

    //遍历链表
    Flight* p = printFlightList->head;
    while (p != NULL)
    {
        printf("│%-10s│%-10s│%-10s│%-8d│%-10s│%-10s│%-8.2lf/%-8d│%-8.2lf/%-8d│\n",
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
    printf("└───────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    system("pause");
}

// 管理员功能：删除航班信息
void lineDelete(FlightList* FList, Flight* deleteLine) {
    if (deleteLine == NULL) {
        deleteLine = FList->head;
    }
    //判断删除节点是否是头节点
    if (deleteLine == FList->head)
    {
        Flight* p1 = FList->head; //先备份头节点
        FList->head = FList->head->next;//将头节点的下一节点作为头节点
        free(p1);//删除“备份的头节点”，即原来要删除的节点
        FList->count--;
        return;
    }
    else //不是头节点
    {
        Flight* p2;
        p2 = deleteLine->next;
        deleteLine->next = p2->next;
        free(p2);
        FList->count--;
        return;
    }
}

// 验证航班号合法性
bool validateFlightNumber(const char* flightNo, FlightList* list) {
    Flight* currentFlight = list->head;
    while (currentFlight != NULL) {
        if (strcmp(currentFlight->flightNo, flightNo) == 0) {
            return false;  // 航班号已存在
        }
        currentFlight = currentFlight->next;
    }
    return true;  // 航班号通过验证
}

// 将航班信息放入链表
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

// 管理员功能：新增航班信息
void lineAdd() {
    //此函数驱动添加订阅信息功能
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "当前操作 < 新增航班信息 >");
    printTableTail(MENU_WIDTH);
    //创建节点
    Flight* pNewLine = (Flight*)malloc(sizeof(Flight));

    // 信息录入
    char inputFlightNo[10];
    printMidInfo("请输入 < 航班号 > :");
    scanf("%s", inputFlightNo);
    // 航班号合法性验证
    while (!validateFlightNumber(inputFlightNo, &FL)) {
        printMidInfo("航班号已存在，请重新输入!\n");
        scanf("%s", inputFlightNo);
    }
    strcpy(pNewLine->flightNo, inputFlightNo);

    printMidInfo("请输入 < 起点站 > :");
    scanf("%s", pNewLine->departure);
    printMidInfo("请输入 < 终点站 > :");
    scanf("%s", pNewLine->destination);

    while (true)
    {
        printMidInfo("请输入 < 飞行日 > :");
        scanf("%d", &pNewLine->flightDay);
        if (pNewLine->flightDay > 7 || pNewLine < 0) {
            printMidInfo("输入有误，请重新输入!\n");
        }
        else
            break;
    }

    while (true)
    {
        printMidInfo("请输入 < 起飞时间 > :");
        scanf("%s", pNewLine->departureTime);
        if ((pNewLine->departureTime[0] - '0') * 10 + (pNewLine->departureTime[1] - '0') < 0 ||
            (pNewLine->departureTime[0] - '0') * 10 + (pNewLine->departureTime[1] - '0') > 23)
            printMidInfo("输入有误，请重新输入!\n");
        else if ((pNewLine->departureTime[2] - '0') * 10 + (pNewLine->departureTime[3] - '0') < 0 ||
            (pNewLine->departureTime[2] - '0') * 10 + (pNewLine->departureTime[3] - '0') > 59)
            printMidInfo("输入有误，请重新输入!\n");
        else break;
    }

    while (true)
    {
        printMidInfo("请输入 < 降落时间 > :");
        scanf("%s", pNewLine->arrivalTime);
        if ((pNewLine->arrivalTime[0] - '0') * 10 + (pNewLine->arrivalTime[1] - '0') < 0 ||
            (pNewLine->arrivalTime[0] - '0') * 10 + (pNewLine->arrivalTime[1] - '0') > 23)
            printMidInfo("输入有误，请重新输入!\n");
        else if ((pNewLine->arrivalTime[2] - '0') * 10 + (pNewLine->arrivalTime[3] - '0') < 0 ||
            (pNewLine->arrivalTime[2] - '0') * 10 + (pNewLine->arrivalTime[3] - '0') > 59)
            printMidInfo("输入有误，请重新输入!\n");
        else break;
    }

    printMidInfo("请输入 < 头等舱售价 > :");
    scanf("%lf", &pNewLine->firstClassPrice);
    printMidInfo("请输入 < 头等舱座位数 > :");
    scanf("%d", &pNewLine->firstClassSeats);
    pNewLine->fcAvailableSeats = pNewLine->firstClassSeats;
    printMidInfo("请输入 < 经济舱售价 > :");
    scanf("%lf", &pNewLine->economyClassPrice);
    printMidInfo("请输入 < 经济舱座位数 > :");
    scanf("%d", &pNewLine->economyClassSeats);
    pNewLine->ecAvailableSeats = pNewLine->economyClassSeats;

    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "请确认信息是否正确...");
    printTableMidInfo(MENU_WIDTH, "确认录入 Y/y");
    printTableMidInfo(MENU_WIDTH, "重新录入 N/n");
    printTableMidInfo(MENU_WIDTH, "取消录入 B/b");
    printTableMidInfo(MENU_WIDTH, "确认并继续录入... R/r");
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
            printMidInfo("指令错误，请重新输入（确认 Y/y、返回N/n）： \n");
    }
}

// 输出单个航班信息
void linePrint(Flight* line) {
    //通过此函数可以输出参数节点的数据信息
    printf("┌───────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│  航班号  │  起点站  │  终点站  │ 飞行日 │ 起飞时间 │ 降落时间 │ 头等舱售价/余票 │ 经济舱售价/余票 │\n");
    printf("│%-10s│%-10s│%-10s│%-8d│%-10s│%-10s│%-8.2lf/%-8d│%-8.2lf/%-8d│\n",
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
    printf("└───────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}

// 管理员功能：修改航班信息菜单
void lineModifyMenu(Flight* p) {
    system("cls");//清空屏幕
    printf("您正在更改的记录现有值：\n");
    linePrint(p);
    printf("\n");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "您正在修改航班信息...");
    printTableMidInfo(MENU_WIDTH, "");
    const char* subMenus[] = {
            "0. 修改 < 航班号 >",
            "1. 修改 < 起点站 >",
            "2. 修改 < 终点站 >",
            "3. 修改 < 飞行日 >",
            "4. 修改 < 起飞时间 >",
            "5. 修改 < 降落时间 >",
            "6. 修改 < 头等舱座位数 >",
            "7. 修改 < 经济舱座位数 >",
            "8. 修改 < 头等舱票价 >",
            "9. 修改 < 经济舱票价 >",
            "Y. 修改完成   "
    };

    int count = sizeof(subMenus) / sizeof(subMenus[0]);
    for (int i = 0; i < count; i++) {
        printTableMidInfo(MENU_WIDTH, subMenus[i]);
    }
    printTableMidInfo(MENU_WIDTH, "");
    printTableTail(MENU_WIDTH);

    printMidInfo("请输入所需功能（0-9,Y）");
}

// 管理员功能：修改航班信息执行函数
void lineModifyExecute(Flight* p, const char* modifyItemName, void* modifyItem) {
    system("cls");//清空屏幕
    printf("您正在更改的记录现有值：\n");
    linePrint(p);
    printf("\n");
    printTableHead(MENU_WIDTH);
    char info1[40];
    sprintf(info1, "当前操作 < 修改 %s >", modifyItemName);
    printTableMidInfo(MENU_WIDTH, info1);
    printTableTail(MENU_WIDTH);
    char info2[40];
    sprintf(info2, "请输入 < 修改后的 %s > :", modifyItemName);
    printMidInfo(info2);
    if (strcmp(modifyItemName, "航班号") == 0)
    {
        char inputFlightNo[10];
        scanf("%s", inputFlightNo);
        // 航班号合法性验证
        while (!validateFlightNumber(inputFlightNo, &FL)) {
            printMidInfo("航班号已存在，请重新输入：");
            scanf("%s", inputFlightNo);
        }
        strcpy(modifyItem, inputFlightNo);
    }
    else if (strcmp(modifyItemName, "飞行日") == 0)
    {
        while (true)
        {
            int modifyDay;
            scanf("%d", &modifyDay);
            if (modifyDay > 7 || modifyDay < 0) {
                printMidInfo("输入有误，请重新输入：");
            }
            else {
                memcpy(modifyItem, &modifyDay, sizeof(modifyDay));
                break;
            }
        }
    }
    else if (strcmp(modifyItemName, "起飞时间") == 0 || strcmp(modifyItemName, "降落时间") == 0)
    {
        while (true)
        {
            char modifyTime[6];
            scanf("%s", modifyTime);
            if ((modifyTime[0] - '0') * 10 + (modifyTime[1] - '0') < 0 ||
                (modifyTime[0] - '0') * 10 + (modifyTime[1] - '0') > 23)
                printMidInfo("输入有误，请重新输入：");
            else if ((modifyTime[2] - '0') * 10 + (modifyTime[3] - '0') < 0 ||
                (modifyTime[2] - '0') * 10 + (modifyTime[3] - '0') > 59)
                printMidInfo("输入有误，请重新输入：");
            else {
                memcpy(modifyItem, modifyTime, sizeof(modifyTime));
                break;
            }
        }
    }
    //TODO 修改座位数后，余票票量应该随之改变
    else if (strcmp(modifyItemName, "头等舱座位数") == 0 || strcmp(modifyItemName, "经济舱座位数") == 0)
        scanf("%d", modifyItem);
    else if (strcmp(modifyItemName, "头等舱票价") == 0 || strcmp(modifyItemName, "经济舱票价") == 0)
        scanf("%lf", modifyItem);
    else //起点站、终点站
        scanf("%s", modifyItem);
    system("cls");
}

// 管理员功能：修改航班信息向导
void lineModify() {
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "当前操作 < 修改航班信息 >");
    printTableTail(MENU_WIDTH);

    //通过航班号查找要修改的航班
    char lineModifyNo[12];
    printMidInfo("请输入 < 所需修改的航班的 航班号 > :");
    scanf("%s", lineModifyNo);

    Flight* p = FL.head;
    while (p != NULL) //从头开始查找uid
    {
        if (strcmp(p->flightNo, lineModifyNo) == 0)
        {
            linePrint(p);
            printTableHead(MENU_WIDTH);
            printTableMidInfo(MENU_WIDTH, "请确认这是否是您要修改的记录...");
            printTableMidInfo(MENU_WIDTH, "确认 Y/y");
            printTableMidInfo(MENU_WIDTH, "返回 N/n");
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
                    printMidInfo("指令错误，请重新输入（确认 Y/y、返回N/n）： \n");
            }
            while (true)
            {
                lineModifyMenu(p);
                char choice;
                scanf(" %s", &choice);
                switch (choice)
                {
                case '0': lineModifyExecute(p, "航班号", &p->flightNo); break;
                case '1': lineModifyExecute(p, "起点站", &p->departure); break;
                case '2': lineModifyExecute(p, "终点站", &p->destination); break;
                case '3': lineModifyExecute(p, "飞行日", &p->flightDay); break;
                case '4': lineModifyExecute(p, "起飞时间", &p->departureTime); break;
                case '5': lineModifyExecute(p, "降落时间", &p->arrivalTime); break;
                case '6': lineModifyExecute(p, "头等舱座位数", &p->firstClassSeats); break;
                case '7': lineModifyExecute(p, "经济舱座位数", &p->economyClassSeats); break;
                case '8': lineModifyExecute(p, "头等舱票价", &p->firstClassPrice); break;
                case '9': lineModifyExecute(p, "经济舱票价", &p->economyClassPrice); break;
                case 'Y': return;
                default:
                    systemMessage("无效的选项。请重新选择。");
                }
            }
        }
        p = p->next;
    }

    systemMessage("错误：您所输入的航班号不存在，请查正后再试。");
}

// 管理员功能：删除航班信息菜单
void lineDeleteMenu() {
    //此函数驱动删除订阅信息功能
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "当前操作 < 删除订阅信息 >");
    printTableTail(MENU_WIDTH);

    //通过记录的uid查找要修改的记录
    char deleteLineNo[12];
    printMidInfo("请输入 < 所需删除航班的 航班号 > :");
    scanf("%s", deleteLineNo);

    Flight* p = FL.head;
    while (p->next != NULL) //从头开始查找uid
    {
        if (strcmp(p->next->flightNo, deleteLineNo) == 0 || strcmp(p->flightNo, deleteLineNo) == 0) {
            linePrint(p);
            printTableHead(MENU_WIDTH);
            printTableMidInfo(MENU_WIDTH, "请确认这是否是您要删除的记录...");
            printTableMidInfo(MENU_WIDTH, "确认 Y/y");
            printTableMidInfo(MENU_WIDTH, "返回 N/n");
            printTableTail(MENU_WIDTH);
            while (true) {
                char confirm;
                scanf(" %s", &confirm);
                if (confirm == 'Y' || confirm == 'y') {
                    lineDelete(&FL, p);
                    systemMessage("航班信息删除完成！");
                    return;
                }
                else if (confirm == 'N' || confirm == 'n') {
                    systemMessage("航班信息删除操作取消！");
                    return;
                }
                else
                    printMidInfo("指令错误，请重新输入（确认 Y/y、返回N/n）： \n");
            }
        }
        p = p->next;
    }

    systemMessage("错误：您所输入的航班号不存在，请查正后再试。");
}

// 查询航班信息菜单
void lineInquireMenu() {
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "请选择查找方式...");
    printTableMidInfo(MENU_WIDTH, "");
    const char* subMenus[] = {
            "1. 通过 < 航班号 > 查找",
            "2. 通过 < 起点站 > 查找",
            "3. 通过 < 终点站 > 查找",
            "4. 通过 < 起/降站组合 > 查找",
            "0. 结束查找   "
    };

    int count = sizeof(subMenus) / sizeof(subMenus[0]);
    for (int i = 0; i < count; i++) {
        printTableMidInfo(MENU_WIDTH, subMenus[i]);
    }
    printTableMidInfo(MENU_WIDTH, "");
    printTableTail(MENU_WIDTH);

    printMidInfo("请输入所需功能（0-4）");
}

void lineInquireExecute(FlightList* inquireList, char inquireType) {
    //查询航班信息，将inquireList()中不符合条件的结点从链表中删除。
    //此函数驱动查询航班信息功能
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "当前操作 < 查询航班信息 >");
    printTableTail(MENU_WIDTH);
    char inquireInfo[12];
    char inquireInfo2[12];
    Flight* prev = NULL;

    switch (inquireType) //根据 inquireType 的首字母判断查询类型
    {
    case '1':// 通过航班号查找
        printMidInfo("请输入 < 所需查询航班的 航班号 > :");
        scanf("%s", inquireInfo);

        Flight* p = inquireList->head;
        do //使用 do-while 循环代替 while 循环
        {
            if (_strcmpi(p->flightNo, inquireInfo) == 0) {
                linePrint(p);
                system("pause");
                return;
            }
            p = p->next;
        } while (p != NULL);
        systemMessage("错误：您所输入的航班号不存在，请查正后再试。");
        return;
    case '2':// 通过起点站查找
        printMidInfo("请输入 < 所需查询航班的 起点站 > :");
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
    case '3':// 通过终点站查找
        printMidInfo("请输入 < 所需查询航班的 终点站 > :");
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
    case '4':// 通过起/降站组合查找
        printMidInfo("请输入 < 所需查询航班的 起点站 > :");
        scanf("%s", inquireInfo);
        printMidInfo("请输入 < 所需查询航班的 终点站 > :");
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
        systemMessage("错误：您所输入的查询类型无效，请重新输入。");
        return;
    }

    linePrintAll(inquireList);
}

void lineInquire() {
    //新建一个航班信息链表，将FL中的数据复制到新链表中
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
        // 查询过程
        bool flag = true;
        while (true) {
            system("cls");
            lineInquireMenu();
            char choice;
            scanf(" %s", &choice);

            switch (choice) {
            case '1': // 通过航班号查找
                lineInquireExecute(inquireList, '1');
                flag = false;
                break;
            case '2': // 通过起点站查找
                lineInquireExecute(inquireList, '2');
                break;
            case '3': // 通过终点站查找
                lineInquireExecute(inquireList, '3');
                break;
            case '4': // 通过起/降站组合查找
                lineInquireExecute(inquireList, '4');
                break;
            case '0':
                return;
            default:
                systemMessage("无效的选项。请重新选择。");
                flag = false;
                break;
            }

            if (flag)
                break;
        }

        // 询问是否基于原来的结果继续查找
        printTableHead(MENU_WIDTH);
        printTableMidInfo(MENU_WIDTH, "是否基于原来的结果继续查找...");
        printTableMidInfo(MENU_WIDTH, "确认 Y/y");
        printTableMidInfo(MENU_WIDTH, "返回 N/n");
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
                printMidInfo("指令错误，请重新输入（确认 Y/y、返回N/n）： \n");
        }
    }
}

// 管理员菜单
void adminMenu() {

    const char* subMenus[] = {
            "1. 新 增 航 班 信 息",
            "2. 修 改 航 班 信 息",
            "3. 删 除 航 班 信 息",
            "4. 查 询 航 班 信 息",
            "5. 全 部 航 班 信 息",
            "6. 修 改 管 理 密 码",
            "0. 退 出 系 统     "
    };

    while (true) {
        system("cls");
        printTableHead(MENU_WIDTH);
        printTableMidInfo(MENU_WIDTH, "管 理 员 功 能 菜 单");
        printTableMidInfo(MENU_WIDTH, "");
        int count = sizeof(subMenus) / sizeof(subMenus[0]);
        for (int i = 0; i < count; i++) {
            printTableMidInfo(MENU_WIDTH, subMenus[i]);
        }
        printTableMidInfo(MENU_WIDTH, "");
        printTableTail(MENU_WIDTH);

        printMidInfo("请输入所需功能（0-6）：");

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
            systemMessage("无效的选项。请重新选择。");
            break;
        }
    }
}

// 管理员登录验证
bool adminIdentify(const char* password) {
    if (strcmp(password, systemPassword) == 0)
        return true;
    else
        return false;
}

// 管理员登录
void adminLogin() {
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "管 理 员 登 录");
    printTableTail(MENU_WIDTH);

    printMidInfo("请输入管理员密码：");
    char password[20];
    scanf("%s", password);

    if (adminIdentify(password)) {
        systemMessage("管理员身份验证成功");
        adminMenu();
    }
    else
        systemMessage("管理员密码错误，请重试。");
}

// 判断用户是否存在
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
    // 判断用户密码是否正确
    User* p = UL.head;
    while (p != NULL) {
        if (strcmp(p->tel, tel) == 0) {
            char password[20];
            printMidInfo("请输入密码：");
            scanf("%s", password);
            if (strcmp(p->password, password) == 0)
                return true;
            else
                return false;
        }
        p = p->next;
    }
}

// 用户注册
void userRegister(char* tel) {
    // 此函数驱动用户注册功能
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "当前操作 < 用户注册 >");
    printTableTail(MENU_WIDTH);

    // 创建节点
    User* pNewUser = (User*)malloc(sizeof(User));

    // 输入密码并确认密码
    char password[20];
    char confirmPassword[20];
    while (true) {
        printMidInfo("请输入密码：");
        scanf("%s", password);
        printMidInfo("请确认密码：");
        scanf("%s", confirmPassword);
        if (strcmp(password, confirmPassword) == 0)
            break;
        else
            printMidInfo("两次输入的密码不一致，请重新输入。");
    }

    strcpy(pNewUser->tel, tel);
    strcpy(pNewUser->password, password);

    // 将用户信息添加到链表
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

    // 注册成功
    systemMessage("用户注册成功！系统即将关闭。请重启后登录。");

    // 保存信息重启系统
    systemExit();
}

// 用户功能：修改密码
void userPasswordRenew(const char* tel) {
    // 此函数驱动用户修改密码功能
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "当前操作 < 修改密码 >");
    printTableTail(MENU_WIDTH);

    // 输入密码并确认密码
    char password[20];
    char confirmPassword[20];
    while (true) {
        printMidInfo("请输入新密码：");
        scanf("%s", password);
        printMidInfo("请确认新密码：");
        scanf("%s", confirmPassword);
        if (strcmp(password, confirmPassword) == 0)
            break;
        else
            printMidInfo("两次输入的密码不一致，请重新输入。");
    }

    // 修改密码
    User* p = UL.head;
    while (p != NULL) {
        if (strcmp(p->tel, tel) == 0) {
            strcpy(p->password, password);
            break;
        }
        p = p->next;
    }

    // 修改成功
    systemMessage("密码修改成功！系统即将关闭。请重启后登录。");

    // 保存信息重启系统
    systemExit();
}

// 用户功能：订购航班机票
void lineOrder() {
    // 此函数驱动用户订购航班机票功能
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "当前操作 < 订购航班机票 >");
    printTableTail(MENU_WIDTH);

    // 通过航班号查找要订购的航班
    char lineOrderNo[12];
    printMidInfo("请输入 < 所需订购航班的 航班号 > :");
    scanf("%s", lineOrderNo);

    // 通过航班号查找航班
    Flight* p = FL.head;
    while (p != NULL) //从头开始查找航班号
    {
        if (strcmp(p->flightNo, lineOrderNo) == 0)
        {
            linePrint(p);
            printTableHead(MENU_WIDTH);
            printTableMidInfo(MENU_WIDTH, "请确认这是否是您要订购的航班...");
            printTableMidInfo(MENU_WIDTH, "确认 Y/y");
            printTableMidInfo(MENU_WIDTH, "返回 N/n");
            printTableTail(MENU_WIDTH);
            while (true)
            {
                char confirm;
                scanf(" %s", &confirm);
                if (confirm == 'Y' || confirm == 'y')
                    break;
                else if (confirm == 'N' || confirm == 'n')
                {
                    systemMessage("订购航班机票操作取消！");
                    return;
                }
                else
                    printMidInfo("指令错误，请重新输入（确认 Y/y、返回N/n）： \n");
            }
            break;
        }
        p = p->next;
    }

    // 判断是否找到航班
    if (p == NULL) {
        systemMessage("错误：您所输入的航班号不存在，请查正后再试。");
        return;
    }

    // 新建订单
    Order* pNewOrder = (Order*)malloc(sizeof(Order));
    strcpy(pNewOrder->tel, userTel);
    strcpy(pNewOrder->flightNo, lineOrderNo);
    pNewOrder->next = NULL;

    // 用户输入订购者的姓名和身份证号
    printMidInfo("请输入订购者的姓名：");
    scanf("%s", pNewOrder->passengerName);
    printMidInfo("请输入订购者的身份证号：");
    scanf("%s", pNewOrder->idNumber);

    // 判断该乘客是否已经订购过这个航班的票，如果有则不允许预定（用身份证判断）
    Order* q = OL.head;
    while (q != NULL) {
        if (strcmp(q->idNumber, pNewOrder->idNumber) == 0) {
            systemMessage("该乘客已经订购过这个航班的票，不允许重复预定！");
            return;
        }
        q = q->next;
    }

    // 订购航班
    printMidInfo("请输入您要订购的舱位类型（头等舱/经济舱）：");
    char cabinType[10];
    scanf("%s", cabinType);
    if (strcmp(cabinType, "头等舱") == 0) {
        if (p->fcAvailableSeats > 0) {
            p->fcAvailableSeats--;
            pNewOrder->status = 1;
            systemMessage("订购成功！");
        }
        else {
            systemMessage("头等舱余票不足，订购失败！");
            // 询问是否候补
            printTableHead(MENU_WIDTH);
            printTableMidInfo(MENU_WIDTH, "是否候补...");
            printTableMidInfo(MENU_WIDTH, "确认 Y/y");
            printTableMidInfo(MENU_WIDTH, "返回 N/n");
            printTableTail(MENU_WIDTH);
            while (true) {
                char confirm;
                scanf(" %s", &confirm);
                if (confirm == 'Y' || confirm == 'y') {
                    pNewOrder->status = 0;
                    systemMessage("候补成功！");
                    break;
                }
                else if (confirm == 'N' || confirm == 'n') {
                    systemMessage("候补取消！");
                    return;
                }
                else
                    printMidInfo("指令错误，请重新输入（确认 Y/y、返回N/n）： \n");
            }
        }
        pNewOrder->seatType = 0;
        pNewOrder->price = p->firstClassPrice;
    }
    else if (strcmp(cabinType, "经济舱") == 0) {
        if (p->ecAvailableSeats > 0) {
            p->ecAvailableSeats--;
            pNewOrder->status = 1;
            systemMessage("订购成功！");
        }
        else {
            systemMessage("经济舱余票不足，订购失败！");
            // 询问是否候补
            printTableHead(MENU_WIDTH);
            printTableMidInfo(MENU_WIDTH, "是否候补...");
            printTableMidInfo(MENU_WIDTH, "确认 Y/y");
            printTableMidInfo(MENU_WIDTH, "返回 N/n");
            printTableTail(MENU_WIDTH);
            while (true) {
                char confirm;
                scanf(" %s", &confirm);
                if (confirm == 'Y' || confirm == 'y') {
                    pNewOrder->status = 0;
                    systemMessage("候补成功！");
                    break;
                }
                else if (confirm == 'N' || confirm == 'n') {
                    systemMessage("候补取消！");
                    return;
                }
                else
                    printMidInfo("指令错误，请重新输入（确认 Y/y、返回N/n）： \n");
            }
        }
        pNewOrder->seatType = 1;
        pNewOrder->price = p->economyClassPrice;
    }
    else {
        systemMessage("无效的舱位类型，订购失败！");
        return;
    }

    orderNumberMax++;
    pNewOrder->orderNumber = orderNumberMax;
    OL.count++;

    // 将订单信息添加到链表
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

// 打印订单信息
void orderPrint(Order* order) {
    //通过此函数可以输出参数节点的数据信息
    printf("┌───────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│ 订单编号：%d\n", order->orderNumber);
    printf("│ 航班号：%s\n", order->flightNo);
    printf("│ 乘客姓名：%s\n", order->passengerName);
    printf("│ 乘客身份证号：%s\n", order->idNumber);
    printf("│ 订单状态：");
    if (order->status == 1)
        printf("已订购\n");
    else
        printf("候补\n");
    printf("│ 舱位类型：");
    if (order->seatType == 0)
        printf("头等舱\n");
    else
        printf("经济舱\n");
    printf("│ 实付款：%.2lf\n", order->price);
    printf("└───────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}

// 用户功能：退订订单
void lineUnsubscribe(Order* unsubscribeOrder) {
    // 将订单标记为已退款
    unsubscribeOrder->status = 2;

    // 检索当前退款订单对应的航班席位余票是否为 0，如果为 0 则检索是否有候补订单。有候补订单则将其标记为已订购，余票不改变，否则余票加 1。
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


// 用户功能：退订航班机票
void lineUnsubscribeMenu() {
    // 此函数驱动用户退订航班机票功能
    system("cls");
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "当前操作 < 退订航班机票 >");
    printTableTail(MENU_WIDTH);

    // 通过订单编号查找要退订的订单
    int lineUnsubscribeNo;
    printMidInfo("请输入 < 所需退订航班的 订单编号 > :");
    scanf("%d", &lineUnsubscribeNo);

    // 通过订单编号查找订单
    Order* p = OL.head;
    while (p != NULL) //从头开始查找订单编号
    {
        if (p->orderNumber == lineUnsubscribeNo)
        {
            orderPrint(p);
            printTableHead(MENU_WIDTH);
            printTableMidInfo(MENU_WIDTH, "请确认这是否是您要退订的订单...");
            printTableMidInfo(MENU_WIDTH, "确认 Y/y");
            printTableMidInfo(MENU_WIDTH, "返回 N/n");
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
                    systemMessage("退订航班机票操作取消！");
                    return;
                }
                else
                    printMidInfo("指令错误，请重新输入（确认 Y/y、返回N/n）： \n");
            }
        }
        p = p->next;
    }
}

// 打印所有订单信息
void orderPrintAll(OrderList* orderList, const char* tel) {
    if (orderList->head == NULL) { //链表为空
        systemMessage("没有订单信息。");
        return;
    }
    system("cls");
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│  订单号  │  航班号  │  订购人  │   身  份  证  号   │ 舱位类型 │ 实际付款 │ 订单状态 │\n");

    //遍历链表
    Order* p = orderList->head;
    while (p != NULL)
    {
        // 判断是否为当前用户的订单
        if (strcmp(p->tel, tel) == 0) {
            printf("│%-10d│%-10s│%-10s│%-20s│%-10s│%-10.2lf│%-10s│\n",
                p->orderNumber,
                p->flightNo,
                p->passengerName,
                p->idNumber,
                p->seatType == 0 ? "头等舱" : "经济舱",
                p->price,
                p->status == 0 ? "候补" : p->status == 1 ? "已订购" : "已退款"
            );
        }
        p = p->next;
    }
    printf("└────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    system("pause");
}

// 用户功能菜单
void userMenu() {
    const char* subMenus[] = {
            "1. 查 询 航 班 信 息",
            "2. 订 购 航 班 机 票",
            "3. 退 订 航 班 机 票",
            "4. 修 改 用 户 密 码",
            "5. 显 示 所 有 订 单",
            "0. 退 出 系 统     "
    };

    while (true) {
        system("cls");
        printTableHead(MENU_WIDTH);
        printTableMidInfo(MENU_WIDTH, "用 户 功 能 菜 单");
        printTableMidInfo(MENU_WIDTH, "");
        int count = sizeof(subMenus) / sizeof(subMenus[0]);
        for (int i = 0; i < count; i++) {
            printTableMidInfo(MENU_WIDTH, subMenus[i]);
        }
        printTableMidInfo(MENU_WIDTH, "");
        printTableTail(MENU_WIDTH);

        printMidInfo("请输入所需功能（0-4）：");

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
            systemMessage("无效的选项。请重新选择。");
            break;
        }
    }
}

// 用户登录
void userLogin() {
    printTableHead(MENU_WIDTH);
    printTableMidInfo(MENU_WIDTH, "用 户 登 录");
    printTableTail(MENU_WIDTH);

    printMidInfo("请输入手机号：");
    scanf("%s", userTel);

    // 用户验证：验证手机号是否存在
    if (isUserExist(userTel)) {
        // 用户验证：验证密码是否正确
        if (isPasswordCorrect(userTel)) {
            systemMessage("用户身份验证成功");
            userMenu();
        }
        else {
            systemMessage("密码错误，请重试。");
        }
    }
    else {
        while (true) {
            system("cls");
            printTableHead(MENU_WIDTH);
            printTableMidInfo(MENU_WIDTH, "用户不存在，是否注册？");
            char info[50] = "您输入的手机号是：";
            strcat(info, userTel);
            printTableMidInfo(MENU_WIDTH, info);
            printTableTail(MENU_WIDTH);
            printTableMidInfo(MENU_WIDTH, "1.是，请以这个手机号进行注册。");
            printTableMidInfo(MENU_WIDTH, "2.否，是我输入错误，请让我重试。");
            printTableTail(MENU_WIDTH);
            printMidInfo("请输入所需功能（1,2）：");

            char choice;
            scanf(" %s", &choice);

            switch (choice) {
            case '1':
                userRegister(userTel); break;
            case '2':
                userLogin(); return;
            default:
                systemMessage("无效的选项。请重新选择。");
                break;
            }
        }
    }
}