int lengthOfLongestSubstring(char * s){
    int len = strlen(s);
    if(len <= 1)
        return len;
    int maxlen = 1, i = 0, j = 0;
    bool hashtable[128] = {false};
    while(i < len && j < len)
    {
        if(hashtable[s[i]] == false)    //若未出现过
        {
            hashtable[s[i]] = true; //加入集合
            int currentlen = i - j + 1;
            if(currentlen > maxlen)
                maxlen = currentlen;
            i++;
        }
        else    //当出现过，则将其去除，并让后指针移动
        {
            hashtable[s[j]] = false;
            j++;
        }
    }
    return maxlen;
}