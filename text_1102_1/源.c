#include <stdio.h>
#include <string.h>
int lengthOfLongestSubstring(char* s)
{

    //������hash��˼��
    //��Ϊ�ַ�ASCII�����ֵΪ127
    int hash[127] = { 0 };
    //˫ָ��˼�� ά��2������
    int left = 0;
    int right = 0;
    int max = 0;

    //ѭ��������������
    while (s[right])
    {
        if (hash[s[right]] && left < hash[s[right]])
        {
            //�Ҳ��ظ�����
            //��ָ����ǰ�ƶ�
            left = hash[s[right]];
        }
        //��¼��ǰ
        //������������ظ�ԭʼʱ���±�ָ���λ��
        hash[s[right]] = right + 1;
        max = max < (right - left + 1) ? (right - left + 1) : max;
        right++;//��ָ��ÿ�ζ�Ҫ��һ��
    }
    return max;
}
void main()
{
	char* str = "achavgivio";
	printf("%d", lengthOfLongestSubstring(str));
}