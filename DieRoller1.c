/*-------------------------------------------------------
| Method - Milestone 2: Application Release 1
|
| Purpose: To simulate dice rolling
|
| Pre-condition: Neither the number of dice nor the type
|                of dice can be null, or an 
|                IllegalArgumentException will occur.
|
| Post-condition: The die roll(s) will always be
|                 displayed.
|
| Parameters: rollDice function produces a different
|             random number between 1 and the number
|             of sides of the die selected.
|
| Returns: Random numbers that simulate die rolls.
*-------------------------------------------------------*/

// Incorporating header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Start main program function
int main(void)
{
	// Designate variables and constant
	int count = 0;
	const low = 1;
	int s, q;
	time_t t;

	// Solicit and collect user input
	printf("What type of dice do you wish to roll?\n");
	scanf_s("%d", &s);
	printf("\nHow many dice of that type do you wish to roll?\n");
	scanf_s("%d", &q);

	// Seed the random number generator
	srand((unsigned) time(&t));

	// Generate and display random numbers
	for (count = 0; count < q; count++)
	{
		int roll = (rand() %
			(s - low + 1)) + low;
		printf("%d ", roll);
	}

	// End main program function
	return 0;
}
