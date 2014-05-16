/* CalendarParser
 The goal is to take Google Calendar CSV files and parse the text contained in them
 to a spreadsheet format for data analysis.
 
 This program separates each event into its own token and then the print class determines
 how to output to spreadsheet format (may just give each category its own line in a text file).
 
 
 Created 5/15/14 by Matthew Weser
 */

#ifndef __Lab4__IdentifierBinaryTree__
#define __Lab4__IdentifierBinaryTree__

#include <iostream>
#include "Event.h"
#include "Date.h"

    // can still use this class to sort events from many calendars into one chronological order

class IdentifierBinaryTree
{
private: 
    Identifier *treeRoot;
    void depthFirstDeleteTree(Identifier *tok);
    
public:
    IdentifierBinaryTree();
    ~IdentifierBinaryTree();
    void setTreeRoot(Identifier *root);
    Identifier *getTreeRoot();
    bool addIdentifier(Identifier *tok, int lineNum);
};

#endif /* defined(__Lab4__IdentifierBinaryTree__) */
