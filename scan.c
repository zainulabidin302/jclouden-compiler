#include "globals.h"
#include "util.h"
#include "scan.h"

typedef	/*! \enum 
 *
 * states in scanner DFA 
 */
enum {  START, INASSIGN, INCOMMENT, INNUM, INID, DONE} StateType;

char tokenString[MAXTOKENLEN+1];

#define BUFLEN 256;

static char lineBuf[BUFLEN];
static int linepos = 0;
static int bufsize = 0;


static char getNextChar(void)
{
	if (!(linepos < bufsize)) {
		lineno++;
		if (fgets(lineBuf, BUFLEN-1, source)) {

			if (EchoSource)
				fprintf(listing, "%d: %s", lineno, lineBuf);
			bufsize = strlen(lineBuf);
			linepos =  0;
			return lineBuf[linepos++];
		}
		else return EOF;
	} 
	else return lineBuf[linepos++];
	
}
static void ungetNextChar(void)
{
linepos--;
}


static struct {
	char * str;
	TokenType tok;
} reservedWords[MAXRESERVED] = { {"if", IF}, {"then", THEN}, 
	{"else", ELSE}, {"end", END}, {"repeat", REPEAT},
	{"until", UNTIL}, {"read", READ}, {"write", WRITE}};

static TokenType reservedLookup (char * s)
{

	int i;
	for (i = 0; i < MAXRESERVED; ++i) {
		if (!strcmp(s, reservedWords[i].str))
			return reservedWords[i].tok;
		
		return ID;

}

TokenType getToken(void) {

	int tokenStringIndex = 0;
	TokenType currentToken;
	StateType state = START;

	while (state != DONE) {

		char c = getNextChar();
		save = TRUE;

		switch(state) {
			case START:
				if (isdigit(c))
					state = INNUM;
				else if (isalpha(c))
					state = INID;
				else if (c == ':')
