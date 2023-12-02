#include <stdio.h>

int no_of_candidates;
int no_of_voters;
int candidates_count = 0;
char symbols[25] = {'!', '@', '#', '$', '%', '^', '&', '*', '+', '=', '|', '~', '?'};
int symbol_no[25] = {0}; // Initialize to zeros

struct candidates
{
    char name[100];
    char symbol;
    int votes;
};

struct voters
{
    char names[100];
    int age;
};

struct candidates a[1000];
struct voters b[10000];

int choices()
{
    int choice;
    printf("1. Add candidates.\n");
    printf("2. Show candidates.\n");
    printf("3. Vote.\n");
    printf("4. Result.\n");
    printf("5. Exit.\n");
    printf("Enter choice number: ");
    scanf("%d", &choice);
    return choice;
}

void add_candidates(int no_of_candidates)
{
    int symbol_num;
    for (int i = 0; i < no_of_candidates; i++)
    {
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", a[candidates_count].name);

        printf("Available Symbols: \n");
        for (int j = 0; j < 13; j++)
        {
            if (symbol_no[j] == 1)
                continue;
            printf("%d %c\n", j + 1, symbols[j]);
        }

        int num = 0;
        printf("Enter the symbol number of candidate %d: ", i + 1);
        scanf("%d", &num);

        if (num <= 0 || num > 13 || symbol_no[num - 1] == 1)
        {
            printf("This Symbol is not available. Please choose from the available symbols\n");
            num = 0;
            printf("Available Symbols: \n");
            for (int j = 0; j < 13; j++)
            {
                if (symbol_no[j] == 1)
                    continue;
                printf("%d. %c\n", j + 1, symbols[j]);
            }

            printf("Enter the symbol number of candidate %d: ", i + 1);
            scanf("%d", &num);
        }

        symbol_no[num - 1] = 1;
        a[candidates_count].symbol = symbols[num - 1];
        candidates_count++;
    }
}

void show_candidates()
{
    for (int i = 0; i < candidates_count; i++)
    {
        printf("\nName of candidate number %d: %s\n", i + 1, a[i].name);
        printf("Symbol of candidate number %d: %c\n", i + 1, a[i].symbol);
    }
}

void voting(int no_of_voters)
{
    for (int i = 0; i < no_of_voters; i++)
    {
        printf("Enter name of voter %d: ", i + 1);
        scanf("%s", b[i].names);
        printf("Enter age: ");
        scanf("%d", &b[i].age);

        if (b[i].age < 18)
        {
            printf("You are not eligible to vote\n");
        }
        else if (b[i].age == 0 || b[i].age < 0)
        {
            printf("Invalid age\n");
        }
        else
        {
            show_candidates();
            printf("Voter %d, please enter your choice (1-%d): ", i + 1, candidates_count);
            int choice;
            scanf("%d", &choice);

            if (choice >= 1 && choice <= candidates_count)
            {
                a[choice - 1].votes++;
            }
            else
            {
                printf("Invalid choice! Please vote again.\n");
                show_candidates();
                printf("Voter %d, please enter your choice (1-%d): ", i + 1, candidates_count);
                scanf("%d", &choice);

                if (choice >= 1 && choice <= candidates_count)
                {
                    a[choice - 1].votes++;
                }
            }
        }
    }
}

void show_result()
{
    int max_votes = 0;
    int maxvotes_index = -1;
    int winners = 0;

    for (int i = 0; i < candidates_count; i++)
    {
        if (a[i].votes > max_votes)
        {
            max_votes = a[i].votes;
            maxvotes_index = i;
        }
    }

    for (int i = 0; i < candidates_count; i++)
    {
        if (a[i].votes == max_votes)
        {
            winners++;
        }
    }

    if (winners > 1)
    {
        printf("No candidate has majority votes\n");
    }
    else if (maxvotes_index != -1)
    {
        printf("Candidate %s with symbol %c won with %d votes\n", a[maxvotes_index].name, a[maxvotes_index].symbol, a[maxvotes_index].votes);
    }
    else
    {
        printf("No winner\n");
    }
}

int main()
{
    int choice;

    do
    {
        choice = choices();

        switch (choice)
        {
        case 1:
            printf("Enter the number of candidates: ");
            scanf("%d", &no_of_candidates);
            add_candidates(no_of_candidates);
            break;
        case 2:
            if (candidates_count > 0)
                show_candidates();
            else
                printf("No Candidates available\n");
            break;
        case 3:
            if (candidates_count > 0)
            {
                printf("Enter the number of voters: ");
                scanf("%d", &no_of_voters);
                voting(no_of_voters);
            }
            else
            {
                printf("Add Candidates first\n");
            }
            break;
        case 4:
            show_result();
            break;
        case 5:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}
