
int main()
{
	int l, n,max,min,x,max2,sotruoc=0;
	int *conkien;
	scanf("%d%d",&l,&n);
	conkien=(int*)malloc(n*sizeof(int));
	min=l;
	max=0;
	max2=0;
	for (int i=0; i<n; i++)
	{
		scanf("%d",&conkien[i]);
		if (conkien[i]>max) max=conkien[i];
		if (conkien[i]<min) min=conkien[i];
	}
	for (int i=0; i<n; i++)
		if (conkien[i]>=min && conkien[i]<max)
			max2=conkien[i];
	printf("%d %d",l-max2,l-min);
	return 0;
	
}

25