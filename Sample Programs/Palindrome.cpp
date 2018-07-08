bool checkPalindrome(string& str, int start, int end)
{
    int len= end-start+1;
    
    for(int i=start; i< start+(len/2) ; i++)
    {
        if(str[i] != str[end-(i-start)])
            return false;
    }
    
    return true;
}