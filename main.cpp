/* CalendarParser
 The goal is to take Google Calendar CSV files and parse the text contained in them
 to a spreadsheet format for data analysis.
 
 This program separates each event into its own token and then the print class determines
 how to output to spreadsheet format (may just give each category its own line in a text file).
 
 
 Created 5/15/14 by Matthew Weser
 */

#include <iostream>
#include <typeinfo>
#include "common.h"
#include "Print.h"
#include "Scanner.h"
#include "Date.h"
#include "Event.h"

FILE *init_lister(const char *name, char source_file_name[], char dte[]);
void quit_scanner(FILE *src_file, Token *list);

int main(int argc, const char * argv[])
{
    Token *token = NULL;
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];
    FILE *source_file = init_lister(argv[1], source_name, date);
    Print print(source_name, date);
    Scanner scanner(source_file, source_name, date, print);
    IdentifierBinaryTree tree;
    
    do
	{
	number_type = false;
	token = scanner.getToken();
        print.printToken(token);
        if (token->getCode() == IDENTIFIER)
	    {
	    tree.addIdentifier((Identifier*) token, scanner.getLineNumber());
	    }
        else if (token->getCode() != PERIOD && token->getCode() != END_OF_FILE)
	    {
	    delete token;
	    }
	}
    while (token->getCode() != PERIOD && token->getCode() != END_OF_FILE);
    
    print.printTree(tree.getTreeRoot());
    delete token;
    fclose(source_file);
    return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file;
    strcpy(source_file_name, name);
    file = fopen(source_file_name, "r");
    time(&timer);
    strcpy(dte, asctime(localtime(&timer)));
    return file;
}

