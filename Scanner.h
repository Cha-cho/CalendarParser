/* CalendarParser
 The goal is to take Google Calendar CSV files and parse the text contained in them
 to a spreadsheet format for data analysis.
 
 This program separates each event into its own token and then the print class determines
 how to output to spreadsheet format (may just give each category its own line in a text file).
 
 
 Created 5/15/14 by Matthew Weser
 */

#ifndef Lab4_Scanner_h
#define Lab4_Scanner_h

#include "common.h"
#include "Print.h"
#include "Identifier.h"

#define CHAR_TABLE_SIZE 256

typedef enum
{
    LETTER, DIGIT, QUOTE, SPECIAL, EOF_CODE,
}
CharCode;

class Scanner
{
private:
    /*********************
     Private Variables for Scanner
     Must be initialized in the constructor.
     *********************/
    Print print;
    FILE *src_file;
    char src_name[MAX_FILE_NAME_LENGTH];
    char todays_date[DATE_STRING_LENGTH];
    CharCode char_table[CHAR_TABLE_SIZE];  // The character table
    char source_line[MAX_SOURCE_LINE_LENGTH];
    char *line_ptr;
    int line_number;
    Token *new_token;
    
    bool getSourceLine(char source_buffer[]);
    char getChar(char source_buffer[]);
    void skipBlanks(char source_buffer[]);
    void skipComment(char source_buffer[]);
    void getWord(char *str, char *token_ptr);
    void getNumber(char *str, char *token_ptr);
    void getString(char *str, char *token_ptr);
    void getSpecial(char *str, char *token_ptr);
    void downshiftWord(char word[]);
    bool isReservedWord(char *str, Token *tok);
    
public:
    Scanner(FILE *source_file, char source_name[], char date[], Print printer);
    ~Scanner();
    Token* getToken();
    int getLineNumber();

};

#endif
