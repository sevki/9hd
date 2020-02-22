typedef	struct	Text Text;

char	riffing;
char    debug;

typedef void (*rifffunc)(Text*, Rune);
rifffunc next;

void 
riffmode(Text *t, Rune r);
void 
selectmode(Text *t, Rune r);