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

char *strcat0(char *a,const char *b){
	char *p=a;
	while(*p!='\0') p++;
	while(*p++=*b++);
	return a;
}
