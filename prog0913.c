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














	return result;
}

void output(struct DATA *s)
{




}

int main( void )
{
	struct DATA seiseki;
	int score[] = { 77, 85, 56, 71, 48, 63, 94, 37, 52, 79, -1 };

	seiseki = eval( score );

	output( &seiseki );
	return 0;
}
