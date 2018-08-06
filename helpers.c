// Helper functions for music

#include <cs50.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int x, y;
    double decimal;

    //convert from ASCII to decimal form
	x = (int) fraction[0] - 48;
	y = (int) fraction[2] - 48;

	decimal = (double ) x / y;

	if (decimal == 0.125)
    {
        return 1;
    }
    else if (decimal == 0.25)
    {
        return 2;
    }
    else if (decimal == 0.375)
    {
        return 3;
    }
    else if (decimal == 0.5)
    {
        return 4;
    }
    else if (decimal == 0.625)
    {
        return 5;
    }
    else if (decimal == 0.75)
    {
        return 6;
    }
    else if (decimal == 0.875)
    {
        return 3;
    }
    else
    {
        return 8;
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double set_frequency, n;

    if (note[0] == 'A')
    {
        set_frequency = 440;
    }
    else if (note[0] == 'B')
    {
        set_frequency = 493.88;
    }
    else if (note[0] == 'C')
    {
        set_frequency = 261.63;
    }
    else if (note[0] == 'D')
    {
        set_frequency = 293.66;
    }
    else if (note[0] == 'E')
    {
        set_frequency =  329.63;
    }
    else if (note[0] == 'F')
    {
        set_frequency = 349.23;
    }
    else if (note[0] == 'G')
    {
        set_frequency = 392.00;
    }

	if (note[1] == '4' || note[2] == '4')
    {
        n = 0;

		if (note[1] == '#')
        {
            n++;
        }
        else if (note[1] == 'b')
        {
            n--;
        }

	    return round((pow(2, n / 12) * set_frequency));
    }

    if (note[1] == '5' || note[1] == '3' || note[2] == '5' || note[2] == '3')
    {
        n = 12;

        if (note[1] == '3' || note[2] == '3')
        {
            n = n * -1;
        }

        if (note[1] == '#' && (note[2] == '5' || note[2] == '3'))
        {
            n++;
        }
        else if (note[1] == 'b' && (note[2] == '5' || note[2] == '3'))
        {
            n--;
        }

        return round((pow(2, n / 12) * set_frequency));
    }

    if (note[1] == '6' || note[1] == '2' || note[2] == '6' || note[2] == '2')
    {
    	n = 24;

        if (note[1] == '2' || note[2] == '2')
        {
            n = n * -1;
        }

        if (note[1] == '#' && (note[2] == '6' || note[2] == '2'))
        {
            n++;
        }
        else if (note[1] == 'b' && (note[2] == '6' || note[2] == '2'))
        {
            n--;
        }

        return round((pow(2, n / 12) * set_frequency));
    }

    if (note[1] == '7' || note[1] == '1' || note[2] == '7' || note[2] == '1')
    {
    	n = 36;

        if (note[1] == '1' || note[2] == '1')
        {
            n = n * -1;
        }

        if (note[1] == '#' && (note[2] == '7' || note[2] == '1'))
        {
            n++;
        }
        else if (note[1] == 'b' && (note[2] == '7' || note[2] == '1'))
        {
            n--;
        }

        return round((pow(2, n / 12) * set_frequency));
    }

    else
    {
        n = 48;

        if (note[1] == '0' || note[2] == '0')
        {
            n = n * -1;
        }

        if (note[1] == '#' && (note[2] == '8' || note[2] == '0'))
        {
            n++;
        }
        else if (note[1] == 'b' && (note[2] == '8' || note[2] == '0'))
        {
            n--;
        }

        return round((pow(2, n / 12) * set_frequency));
    }
}
// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s,""))
    {
        return false;
    }

    else
    {
        return true;
    }
}
