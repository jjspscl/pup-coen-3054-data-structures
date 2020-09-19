#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, string argv[])
{
    if (argc == 2)
    {

        int argv1 = strlen(argv[1]) - 1;
        int x = argv1;                               // get length
        bool status = true;
        while (x >= 0)                              // see if it is an alphabet, disregard if not
        {
            if (isalpha(argv[1][x]))
            {

            }
            else
            {
                status = false;
            }
            x--;
        }
        if (status == 1)                            // start
        {

            int y = strlen(argv[1]);
            int z[100];
            int counter = 0;
            while (y > counter)                                                // converting a-z to 0-25 from left to right
            {
                if (islower(argv[1][counter]))
                {
                    z[counter] = ((int) argv[1][counter]) % 97;                          // converted value

                }
                else if (isupper(argv[1][counter]))
                {
                    z[counter] = ((int) argv[1][counter]) % 65;                          // converted value

                }
                counter++;
            }

            string plain = get_string("plaintext: ");
            int p = strlen(plain);
            int counterp = 0;
            int n = 0;
            while (counterp < p)
            {

                if (islower(plain[counterp]) || isupper(plain[counterp]))       // check if not special character || or if lower case or upper case
                {
                    if (n == (argv1 + 1))
                    {
                        n = 0;
                    }
                    if (islower(plain[counterp]))                                // add the key
                    {
                        plain[counterp] = plain[counterp] + z[n] - 32;
                        plain[counterp] = ((int) plain[counterp] % 91);
                        if (plain[counterp] < 'A')
                        {
                            plain[counterp] = plain[counterp] + 97;                 // manipulation depends if char is capital or small
                        }
                        else                                                        // also depends on ASCII CODE
                        {
                            plain[counterp] = plain[counterp] + 32;
                        }
                    }
                    else if (isupper(plain[counterp]))
                    {
                        plain[counterp] = plain[counterp] + z[n];
                        plain[counterp] = ((int) plain[counterp] % 91);
                        if (plain[counterp] < 'A')
                        {
                            plain[counterp] = plain[counterp] + 65;
                        }
                    }


                    n++;
                }

                counterp++;
            }
            printf("ciphertext: %s\n", plain);
            return 0;

        }
        else
        {
            printf("Usage: %s k", argv[0]);
            return 1;
        }
    }
    else
    {
        printf("Usage: %s k", argv[0]);
        return 1;
    }
}