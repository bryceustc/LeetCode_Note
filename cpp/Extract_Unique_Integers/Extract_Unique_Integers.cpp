#include <stdio.h>
int main()
{
    int input;
    scanf("%d", &input);
    int res = 0;
    int m[10] = {0};
    int n = 0;
    while(input)
    {
        n = input%10;
        if (m[n]==0)
        {
            m[n]++;
            res = res*10 + n;
        }
        input/=10;
    }
    printf("%d",res);
    return 0;
}
