/*-------------------------------------------------------
| Method - Milestone 3: Application Release 2
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
| Parameters: randomDice function produces a different
|             random number between 1 and the number
|             of sides of the die selected. statDice
|             function adds the highest of three of
|             four six-sided die rolls, six times.
|
| Returns: Random numbers that simulate die rolls.
*-------------------------------------------------------*/

// Incorporating header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Die randomizing function
void randomDice(int s, int q)
{
	// Designate variables and constant
	int count = 0;
	const low = 1;
	time_t t;

	// Seed the random number generator
	srand((unsigned)time(&t));

	// Generate and display random numbers
	for (count = 0; count < q; count++)
	{
		int roll = (rand() %
			(s - low + 1)) + low;
		printf("%d ", roll);
	}
}

// Ability statistics generation function
int statDice()
{
	// Designate variables
	int dRoll = 0, d6[4];
	int setIncr = 0, zeroInc = 0, d6Inc = 0, lowInc = 0, totInc = 0;
	int totRoll = 0;
	int lowDie = 0;
	int* lowPtr;
	char yn = 'c';
	time_t t;

	// Seed the random number generator
	srand((unsigned)time(&t));

	// Generate and display random numbers
	// This FOR loop creates six sets of stats.
	for (setIncr = 0; setIncr < 6; setIncr++)
	{
		// This FOR loop simulates rolling 4 six-sided dice and
		// populates the d6 array with the values.
		for (d6Inc = 0; d6Inc < 4; d6Inc++)
		{
			int dRoll = (rand() %
				(6 - 1 + 1)) + 1;
			d6[d6Inc] = dRoll;
			dRoll = 0;
		}

		// This FOR loop assigns the value of the lowest roll of
		// the four values in the d6 array to the lowDie variable.
		lowDie = d6[0];
		lowPtr = &lowDie;
		for (lowInc = 0; lowInc < 4; lowInc++)
		{
			if (d6[lowInc] < lowDie)
				lowPtr = &d6[lowInc];
		}

		// This FOR loop totals the 4 six-sided die rolls.
		for (totInc = 0; totInc < 4; totInc++)
		{
			totRoll = totRoll + d6[totInc];
		}

		// This command subtrancts the value of the lowest roll,
		// leaving an ability score value between 3 and 18. The
		// values for each of the 6 sets are then displayed.
		totRoll = totRoll - lowDie;
		printf("%d ", totRoll);
		
		// Variables are reinitialized, including the array d6.
		totRoll = 0;
		lowDie = 0;
		for (zeroInc = 0; zeroInc < 4; zeroInc++)
		{
			d6[zeroInc] = 0;
		}
	}

	// Solicit user decision
	yn = 'c';
	printf("\nWould you like to roll again? (y or n) ");
	scanf_s(" %c", &yn, 1);

	if (yn == 'n')
		exit(EXIT_SUCCESS);
	else
		statDice();
}

// Start main program function
int main()
{
	// Designate variables
	int s, q;
	char yn;

	// User chooses between statDice or randomDice
	yn = 'c';
	printf("Would you like to generate ability scores (4d6 drop the low die)? (y or n) ");
	scanf_s(" %c", &yn, 1);

	if (yn == 'y')
		statDice();
	else
		yn = 'c';
		printf("Would you like to roll something else? (y or n) ");
		scanf_s(" %c", &yn, 1);

			if (yn == 'n')
			exit(EXIT_SUCCESS);

	// Solicit and collect user input
	printf("What type of dice do you wish to roll?\n");
	scanf_s("%d", &s);
	printf("\nHow many dice of that type do you wish to roll?\n");
	scanf_s("%d", &q);

	randomDice(s, q);

	// End main program function
	return 0;
}
