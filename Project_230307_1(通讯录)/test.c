#include"contact.h"
//ͨѶ¼
//1����Ϣ�洢������1000���˵���Ϣ���������֣����䣬��ַ���Ա𣬵绰
//2���½���ϵ�ˣ����ͨѶ¼�е���Ա��Ϣ
//3��ɾ����ϵ��
//4���޸���ϵ����Ϣ
//5��������ϵ��



int main()
{
	//���ٿռ�
	Contact con;

	//��ʼ��
	InitContact(&con);
	//���˵�ѡ�����
	int cmd_f = 0;
	do
	{
		menu();
		scanf("%d", &cmd_f);
		switch (cmd_f)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SERACH:
			Serach(&con);
			break;
		case MODIFY:
			Modify(&con);
			break;
		case PRINT:
			Print(&con);
			break;
		case EXIT:
			printf("�˳�");
			break;
		default:
			printf("��Чָ�����������->");
			break;
		};
	} while (cmd_f);
	return 0;
}
