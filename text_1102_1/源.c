#include <stdio.h>
#include <string.h>
int lengthOfLongestSubstring(char* s)
{

    //类似于hash的思想
    //因为字符ASCII的最大值为127
    int hash[127] = { 0 };
    //双指针思想 维护2个窗口
    int left = 0;
    int right = 0;
    int max = 0;

    //循环遍历整个数组
    while (s[right])
    {
        if (hash[s[right]] && left < hash[s[right]])
        {
            //右侧重复出现
            //左指针向前移动
            left = hash[s[right]];
        }
        //记录当前
        //保存如果出现重复原始时，下标指向的位置
        hash[s[right]] = right + 1;
        max = max < (right - left + 1) ? (right - left + 1) : max;
        right++;//右指针每次都要加一。
    }
    return max;
}
void main()
{
	char* str = "achavgivio";
	printf("%d", lengthOfLongestSubstring(str));
}