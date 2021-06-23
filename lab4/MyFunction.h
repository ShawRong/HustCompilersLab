void itoa(int i,char* string)
{
    int power,j;
    j=i;
    for(power=1;j>=10;j/=10)
        power*=10;
    for(;power>0;power/=10)
    {
        *string++='0'+i/power;
        i%=power;
    }
    *string='\0';
}

char *strcat0(char *s1, char *s2)
{
	char* result = (char*)malloc(20 * sizeof(char));
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}
