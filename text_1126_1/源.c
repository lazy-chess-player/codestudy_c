#define MAXNUM 1000
#define MAX(a,b) (a)>(b)?(a):(b)
int lengthOfLongestSubstring(char* s)
{
	int len, right, left, i, ret;
	int window[MAXNUM] = { 0 };
	len = strlen(s);
	right = 0; left = 0;
	ret = 0;
	while (right < len)
	{
		i = s[right];
		window[i]++;
		right++;
		while (window[i] > 1)
		{
			int j = s[left];
			window[j]--;
			left++;
		}
		ret = MAX(ret, right - left);
	}
	return ret;
}