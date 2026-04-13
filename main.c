#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

char keywords[32][10] = {"auto","break","case","char","const","continue","default",
                        "do","double","else","enum","extern","float","for","goto",
                        "if","int","long","register","return","short","signed",
                        "sizeof","static","struct","switch","typedef","union",
                        "unsigned","void","volatile","while"};

int isKeyword(char *str){
    for(int i=0;i<32;i++)
        if(strcmp(str,keywords[i])==0) 
            return 1;
    return 0;
}

int isOperator(char ch){
    char op[]="+-*/%=<>!";
    for(int i=0;i<strlen(op);i++){
        if(ch==op[i])
            return 1;
    }
    return 0;
}

int isSeparator(char ch){
    char sep[] = " \t\n(){}[],;#<>\"'";
    for(int i=0;i<strlen(sep);i++){
        if(ch==sep[i])
            return 1;
    }
    return 0;
}

int isDigit(char *str){
    for(int i=0;str[i]!='\0';i++){
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}

int isFloat(char *str){
    int dot=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='.')
            dot++;
        else if(!isdigit(str[i]))
            return 0;
    }
    return dot==1;;
}

int main(){
    FILE *fptr=fopen("code.c","r");
    if(fptr==NULL){
        printf("File not found\n");
        return 0;
    }

    char ch,buffer[100];
    int j=0;

    while((ch=fgetc(fptr))!=EOF){
        if(isalnum(ch) || ch == '.' || ch == '_' || ch == '"' || ch == '\'')
        {
            buffer[j++] = ch;
        }
        else
        {
            if(j != 0)
            {
                buffer[j] = '\0';
                j = 0;

                if(isKeyword(buffer))
                    printf("%-20s : Keyword\n", buffer);

                else if(isFloat(buffer))
                    printf("%-20s : Floating Constant\n", buffer);

                else if(isDigit(buffer))
                    printf("%-20s : Integer Constant\n", buffer);

                else
                    printf("%-20s : Identifier\n", buffer);
            }

            if(isOperator(ch))
                printf("%-20c : Operator\n", ch);

            else if(isSeparator(ch))
                ;
        }
    }

    fclose(fptr);
    return 0;
}
