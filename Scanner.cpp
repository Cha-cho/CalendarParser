/* CalendarParser
 The goal is to take Google Calendar CSV files and parse the text contained in them
 to a spreadsheet format for data analysis.
 
 This program separates each event into its own token and then the print class determines
 how to output to spreadsheet format (may just give each category its own line in a text file).
 
 
 Created 5/15/14 by Matthew Weser
 */

#include "Scanner.h"

/*
 Idea here is to easily iterate and differentiate between category name and contents
 Divide at colon and \n characters
 After \n is category name, and colon tells that it is the contents
 Set up a case thing to check for the right category name and to skip certain categories
 Can probably do in one main method here.
 
 
 while loop through all lines of the file until EOF
 keep track of current name of calendar by the "cal name" at the beginning
 
 
 */








Scanner::Scanner(ifstream & infile) : fin(infile)
{
//    src_file = source_file;
//    strcpy(src_name, source_name);
//    
//    source_line[0] = '\0';
}
Scanner::~Scanner()
{
	// delete newEvent;
}
bool Scanner::getSourceLine(char source_buffer[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    
    if (fgets(source_buffer, MAX_SOURCE_LINE_LENGTH, src_file) != NULL)
    {
        ++line_number;
        sprintf(print_buffer, "%4d: %s", line_number, source_buffer);
        print.printLine(print_buffer);
        return true;
    }
    else
    {
        return false;
    }
}



/*
 Token* Scanner::getToken()
{
    char ch = '\0'; //This can be the current character you are examining during scanning.
    char token_string[MAX_TOKEN_STRING_LENGTH] = {'\0'}; //Store your token here as you build it.
    char *token_ptr = token_string; //write some code to point this to the beginning of token_string
    
    //1.  Skip past all of the blanks
    if (line_ptr == NULL)
    {
        line_ptr = source_line;
    }
    skipBlanks(source_line);
    ch = *line_ptr;
    
    //2.  figure out which case you are dealing with LETTER, DIGIT, QUOTE, EOF, or special, by examining ch
    switch (char_table[(unsigned char)ch])
    {//3.  Call the appropriate function to deal with the cases in 2.
        case LETTER:
            getWord(token_string, token_ptr);
            break;
        case DIGIT:
            getNumber(token_string, token_ptr);
            break;
        case QUOTE:
            getString(token_string, token_ptr);
            break;
        case EOF_CODE:
            new_token->setCode(END_OF_FILE);
            break;
        default:
            getSpecial(token_string, token_ptr);
            break;
    }
    
    return new_token; //What should be returned here?
}
char Scanner::getChar(char source_buffer[])
{
    /*
     If at the end of the current line (how do you check for that?),
     we should call get source line.  If at the EOF (end of file) we should
     set the character ch to EOF and leave the function.
 
    char ch;
    
    if (*line_ptr == '\0')
    {
        if (!getSourceLine(source_buffer))
        {
            ch = EOF_CHAR;
            return ch;
        }
        line_ptr = source_buffer;
    }
    
    /*
     Write some code to set the character ch to the next character in the buffer
 
    ch = *line_ptr;
    if ((ch == '\n') || (ch == '\t') || (ch == '\r'))
    {
        ch = ' ';
    }
    if (ch == '{')
    {
        skipComment(source_buffer);
    }
    return ch;
}
void Scanner::skipBlanks(char source_buffer[])
{
    /*
     Write some code to skip past the blanks in the program and return a pointer
     to the first non blank character
 
    while (getChar(source_buffer) == ' ' && (*line_ptr != EOF_CHAR))
    {
        line_ptr++;
    }
}
void Scanner::skipComment(char source_buffer[])
{
    /*
     Write some code to skip past the comments in the program and return a pointer
     to the first non blank character.  Watch out for the EOF character.
 
    char ch;
    
    do
    {
        ch = *line_ptr++;
    }
    while ((ch != '}') && (ch != EOF_CHAR));
}
void Scanner::getWord(char *str, char *token_ptr)
{
    /*
     Write some code to Extract the word

    Token* tok = new Token();
    
    char ch = *line_ptr;
    while ((char_table[(unsigned char)ch] == LETTER) || (char_table[(unsigned char)ch] == DIGIT))
    {
        *token_ptr++ = *line_ptr++;
        ch = *line_ptr;
    }
    *token_ptr = '\0';
    
    //Downshift the word, to make it lower case
    downshiftWord(str);
    
    /*
     Write some code to Check if the word is a reserved word.
     if it is not a reserved word its an identifier.


    if (!isReservedWord(str, tok))
    {
        //set token to identifier
    new_token = new Identifier();
    new_token->setCode(IDENTIFIER);
    new_token->setTokenString(str);
    }
    else{
        tok->setTokenString(string(str));
        new_token = tok;
    }
}

*/
