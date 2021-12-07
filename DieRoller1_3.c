/*-------------------------------------------------------
| Method - Milestone 5: Final Application Release
|
| Purpose: To simulate dice rolling and record
|          character information
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
| Returns: Random numbers simulating die rolls displayed 
|          along with character information as applicable.
*-------------------------------------------------------*/

// Incorporating header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

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
	{
		return 0;
	}
	else
	{
		statDice();
	}
}

// Character information recording structure
struct PlayerChar
{
	char Chclass[20];
	char Chrace[20];
	int Chlevel;
	union
	{
		char Chname[20];
		int iD;
	};
};

struct PlayerChar char1;

// Start main program function
int main(int argc, char *argv[])
{
	// Designate file pointer for output file
	FILE* CharacterData;
	errno_t err;

	// Designate variables
	int s, q;
	char yn;

	// User chooses between character generation and statDice or randomDice
	yn = 'c';
	printf("Would you like to create a character? (y or n) ");
	scanf_s(" %c", &yn, 1);

	if (yn == 'y') 
	{
		// User enters character information
		printf("\nPlease enter your character's class.\n");
		scanf_s("%s", &char1.Chclass, 20);
		printf("\nPlease enter your character's race.\n");
		scanf_s("%s", &char1.Chrace, 20);
		printf("\nPlease enter your character's level.\n");
		scanf_s("%d", &char1.Chlevel);
		yn = 'c';
		printf("Does your character have a name? (y or n) ");
		scanf_s(" %c", &yn, 1);
		char1.iD = 0;

		if (yn == 'y')
		{
			// User enters character name
			printf("\nPlease enter your character's name.\n");
			scanf_s("%s", &char1.Chname, 20);
		}
		else
		{
			char1.iD = char1.iD + 1;
		}

		printf("\nHere are your ability scores...\n");
		statDice();

		// Solicit user decision
		yn = 'c';
		printf("\nWould you like to roll something else? (y or n) ");
		scanf_s(" %c", &yn, 1);

		if (yn == 'n')
		{
			if (char1.iD != 1)
			{
				// Display character name and information
				printf("%s ", char1.Chname);
				printf("level %d %s %s\n", char1.Chlevel, char1.Chrace, char1.Chclass);

				// Send Character information to file
				if ((err = fopen_s(&CharacterData, "CharData.txt", "w")) != 0)
				{
					//File could not be opened.
					fprintf(stderr, "Cannot open file CharData.txt\n");
				}
				else

				fprintf(CharacterData, "%s ", char1.Chname);
				fprintf(CharacterData, "level %d %s %s\n", char1.Chlevel, char1.Chrace, char1.Chclass);
				fclose(CharacterData);

				exit(EXIT_SUCCESS);
			}
			else
			{
				// Display character ID and information
				printf("\nCharacter ID %d: level %d %s %s\n", char1.iD, char1.Chlevel, char1.Chrace, char1.Chclass);

				// Send Character information to file
				if ((err = fopen_s(&CharacterData, "CharData.txt", "w")) != 0)
				{
					//File could not be opened.
					fprintf(stderr, "Cannot open file CharData.txt\n");
				}
				else

				fprintf(CharacterData, "Character ID %d: level %d %s %s\n", char1.iD, char1.Chlevel, char1.Chrace, char1.Chclass);
				fclose(CharacterData);

				exit(EXIT_SUCCESS);
			}
		}
		else
		{
			// Solicit and collect user input
			printf("What type of dice do you wish to roll?\n");
			scanf_s("%d", &s);
			printf("\nHow many dice of that type do you wish to roll?\n");
			scanf_s("%d", &q);

			randomDice(s, q);
		}
			
	}
	else
	{
		// Solicit user decision
		yn = 'c';
		while (yn != 'y')
		{
			printf("\nAre you finished rolling? (y or n) ");
			scanf_s(" %c", &yn, 1);

			if (yn == 'y')
			{
				return 0;
			}
			else
			{
				// Solicit and collect user input
				printf("What type of dice do you wish to roll?\n");
				scanf_s("%d", &s);
				printf("\nHow many dice of that type do you wish to roll?\n");
				scanf_s("%d", &q);

				randomDice(s, q);
			}
		}
	}
	
	// End main program function
	return 0;
}
