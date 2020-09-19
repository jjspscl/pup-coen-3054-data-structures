#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Ask how much, invalid if negative
    float owed, converted;
    int tf = 0, t = 0, f = 0, c = 0, total = 0;
    do
    {
        owed = get_float("How much change owed: ");
    }
    while (owed < 0);
    //Round off up to 2 decimal places, convert dollar to cents
    converted = (owed + 0.005) * 100;
    //25 cents, how many
    tf = converted / 25;
    // subtract
    converted = converted - (25 * tf);
    //10 cents
    t = converted / 10;
    // subtract
    converted = converted - (10 * t);
    //5 cents
    f = converted / 5;
    //subtract
    converted = converted - (5 * f);
    //cent
    c = converted / 1;
    total = tf + t + f + c;
    printf("%i", total);
}