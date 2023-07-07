%{
#include <stdio.h>
#include <stdlib.h>
int id = 0, num = 0, key = 0, op = 0;
%}

%token DIGIT ID KEY OP

%%
input:
    expression input
    | expression
    ;

expression:
    DIGIT { num++; }
    | ID { id++; }
    | KEY { key++; }
    | OP { op++; }
    ;

%%

#include <stdio.h>
extern int yylex();
extern int yyparse();
extern FILE* yyin;

int main()
{
    FILE* myfile = fopen("sam_input.c", "r");
    if (!myfile)
    {
        printf("I can't open sam_input.c!\n");
        return -1;
    }

    yyin = myfile;

    do
    {
        yyparse();
    } while (!feof(yyin));

    printf("Numbers = %d\nKeywords = %d\nIdentifiers = %d\nOperators = %d\n",
           num, key, id, op);

    return 0;
}

void yyerror(const char* s)
{
    printf("EEK, parse error! Message: %s\n", s);
}
