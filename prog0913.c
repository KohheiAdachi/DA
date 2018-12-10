/* prog0913.c */

#include <stdio.h>

struct DATA {
	int max;
	int min;
	double avg;
};

struct DATA eval( int p[] )
{
	struct DATA result;
	int max=0,min=100,sum=0;
	double avg;
	int i=0;
	while(p[i] != -1){
		if(max < p[i]){
			max = p[i];
		}
		if(min > p[i]){
			min = p[i];
		}
		sum += p[i];
		i++;
	}
	avg = (double)sum/i;
	result.min = min;
	result.max = max;
	result.avg = avg;
	return result;
}

void output(struct DATA *s)
{
	printf("mib:%d,max:%d,avg:%.1f\n",s->min,s->max,s->avg);
}

int main( void )
{
	struct DATA seiseki;
	int score[] = { 77, 85, 56, 71, 48, 63, 94, 37, 52, 79, -1 };

	seiseki = eval( score );

	output( &seiseki );
	return 0;
}
