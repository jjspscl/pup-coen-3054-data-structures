#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    int sum = 0, counter = 0;
    if (argc == 2)
    {

        int x = strlen(argv[1]) - 1;                      //get string of number per digit
        while (x >= 0)
        {
            int y = (int) argv[1][x] - 48;               // convert each digit to ascii then -48
            int z = x, k = counter;
            while (z >= 0)
            {
                while (k > 0)
                {
                    y = y * 10;
                    k--;
                }
                z--;
            }
            sum = sum + y;                                  // sum for crypto

            counter++;
            x--;
        }
        sum = sum % 26;                                   // mod 26 to get remainder, keep cryp 1-26 == key
        string inp = get_string("plaintext: ");             // == message
        int q = strlen(inp) - 1;
        while (q >= 0)                                     // insert key unless its space or null
        {
            if (islower(inp[q]))
            {
                inp[q] = (inp[q] + sum) - 32;

                inp[q] = ((int) inp[q] % 91);

                if (inp[q] < 'A')
                {
                    inp[q] = inp[q] + 97;

                }
                else
                {
                    inp[q] = inp[q] + 32;
                }



            }
            else if (isupper(inp[q]))
            {
                inp[q] = (inp[q] + sum) ;

                inp[q] = ((int) inp[q] % 91);

                if (inp[q] < 'A')
                {
                    inp[q] = inp[q] + 65;

                }

            }
            q--;
        }
        printf("ciphertext: %s\n", inp); // == crypted
        return 0;
    }
    else
    {
        printf("Usage: %s k\n", argv[0]);
        return 1;
    }

}