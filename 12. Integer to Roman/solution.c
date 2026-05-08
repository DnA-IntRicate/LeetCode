char to_numeral(int num)
{
    switch (num)
    {
        case 1: return "I";
        case 5: return "V";
        case 10: return "X";
        case 50: return "L";
        case 100: return "C";
        case 500: return "D";
        case 1000: return "M";
    }

    return "";
}


char* intToRoman(int num)
{
    int len = 0;

}
