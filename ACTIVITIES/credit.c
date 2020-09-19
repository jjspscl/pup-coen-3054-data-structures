// Validate if credit card is legitimate

#include <stdio.h>
#include <cs50.h>


void checksum();
long long number;
long long take = 0;
int status, sum;
int main(void)
{
// get input
    number = get_long_long("Number: ");
// see if more than 16
    take = (number % 100000000000000000) / 10000000000000000;
    if (take == 0)
    {
// see if 16 digits
        take = (number % 10000000000000000) / 1000000000000000;

        if (take == 4 || take == 5)
        {
            if (take == 4)
            {
                status = 1;
                checksum();

            }
            else if (take == 5)
            {
                take = (number % 1000000000000000) / 100000000000000;
                if (take >= 1 && take <= 5)
                {
                    status = 2;
                    checksum();
                }
                else
                {
                    printf("INVALID\n");
                }
            }
        }
        else if (take == 0)
        {
// see if 15 digits
            take = (number % 1000000000000000) / 100000000000000;

            if (take == 3)
            {
                take = (number % 100000000000000) / 10000000000000;
                if (take == 4 || take == 7)
                {
                    status = 3;
                    checksum();
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else if (take == 0)
            {
//see if 13 digits
                take = (number % 10000000000000) / 1000000000000;


                if (take == 4)
                {
                    status = 4;
                    checksum();
                }
                else
                {
                    printf("INVALID\n");
                }

            }
            else
            {
                printf("INVALID\n");
            }


        }
    }

    else
    {
        printf("INVALID\n");
    }
}
void checksum()
{
    long long m1 = 100, d1 = 10, m2 = 10, d2 = 1;
    long long x[8];
    switch (status)
    {
        case 1:                                             // 16 digit VISA
            for (int n = 0; n <= 7; n++)
            {
                x[n] = ((number % m1) / d1) * 2;             // get 2nd digit from right, then every other digit
                m1 = m1 * 100;
                d1 = d1 * 100;
            }

            for (int z = 0; z <= 7; z++)
            {
                sum = sum + (x[z] / 10) + (x[z] % 10);      // sum of every digit multiplied by 2
            }

            for (int n = 0; n <= 7; n++)                    // get digit not used
            {
                x[n] = ((number % m2) / d2);
                m2 = m2 * 100;
                d2 = d2 * 100;
            }

            for (int z = 0; z <= 7; z++)                    // sum up
            {
                sum = sum + x[z] ;
            }
            sum = sum % 10;
            if (sum == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
            break;

        case 2:                                                 // MASTERCARD
            for (int n = 0; n <= 7; n++)                        // get 2nd digit from right to left, every other digit
            {
                x[n] = ((number % m1) / d1) * 2;
                m1 = m1 * 100;
                d1 = d1 * 100;
            }

            for (int z = 0; z <= 7; z++)                        // sum of each digit
            {
                sum = sum + (x[z] / 10) + (x[z] % 10);
            }

            for (int n = 0; n <= 7; n++)                        // get other digits that weren't used
            {
                x[n] = ((number % m2) / d2);
                m2 = m2 * 100;
                d2 = d2 * 100;
            }

            for (int z = 0; z <= 7; z++)                        // sum every digit you have
            {
                sum = sum + x[z] ;
            }
            sum = sum % 10;
            if (sum == 0)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }

            break;

        case 3:                                                     // AMERICAN EXPRESS

            for (int n = 0; n < 7; n++)                             // get 2nd digit from right to left, every other digit
            {
                x[n] = ((number % m1) / d1) * 2;
                m1 = m1 * 100;
                d1 = d1 * 100;
            }

            for (int z = 0; z < 7; z++)                             // sum of each digit
            {
                sum = sum + (x[z] / 10) + (x[z] % 10);
            }

            for (int n = 0; n <= 7; n++)                            // get other digits that weren't used
            {
                x[n] = ((number % m2) / d2);
                m2 = m2 * 100;
                d2 = d2 * 100;
            }

            for (int z = 0; z <= 7; z++)                            // sum every digit you have
            {
                sum = sum + x[z] ;
            }
            sum = sum % 10;

            if (sum == 0)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
            break;

        case 4:                                                 // 13 DIGIT VISA
            for (int n = 0; n <= 6; n++)                        // get 2nd digit from right to left, every other digit
            {
                x[n] = ((number % m1) / d1) * 2;
                m1 = m1 * 100;
                d1 = d1 * 100;
            }

            for (int z = 0; z <= 6; z++)                        // sum of each digit
            {
                sum = sum + (x[z] / 10) + (x[z] % 10);
            }

            for (int n = 0; n <= 6; n++)                        // get other digits that weren't used
            {
                x[n] = ((number % m2) / d2);
                m2 = m2 * 100;
                d2 = d2 * 100;
            }

            for (int z = 0; z <= 6; z++)                         // sum every digit you have
            {
                sum = sum + x[z] ;
            }
            sum = sum % 10;

            if (sum == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
            break;
    }

    return;

}