class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str==NULL || length<0)
            return;
        int newlength,spaceNum=0;
        int oldlength=0;
        for(int i=0;str[i]!='\0';i++)
        {
            oldlength++;
            if(str[i]==' ')
                spaceNum++;            
        }
        newlength=oldlength+spaceNum*2;
        if(length<newlength)
            return;
        int i=oldlength;
        int j=newlength;
        while(i>=0)
        {
            if(str[i]!=' ')  str[j--]=str[i--];
            else{
                i--;
                str[j--]='0';
                str[j--]='2';
                str[j--]='%';
            }
        }
    }
};

//注意字符串末尾的'\0'也要复制过来