#include <u.h>
#include <libc.h>
#include <draw.h>
#include <thread.h>
#include <cursor.h>
#include <mouse.h>
#include <keyboard.h>
#include <frame.h>
#include <fcall.h>
#include <plumb.h>
#include <libsec.h>
#include <complete.h>
#include "dat.h"
#include "fns.h"


void
riffmode(Text *t, Rune r)
{
	switch(r){
	case Kesc:
	case Rstart:
		t->next = &texttypemode;
		return;
	case Rselect:
		t->next = &riffselect;
		return;
	case Rexec:
		riffexecute(t);
	}
}

void
riffselect(Text *t, Rune r)
{
	switch(r){
	case Kesc:
	case Rstart:
		t->next = &texttypemode;
		return;
	case Rselect:
		return;
	case Rword:
		riffselectword(t);
		t->next = &riffmode;
		return;
	case Rline:
		riffselectline(t);
		t->next = &riffmode;
		return;
	case Rtag:
		rifftag(t);
	default:
		t->next = &texttypemode;
	}
}

void
riffselectword(Text *t)
{
	Expand e; 
	expand(t, t->q0, t->q1, &e);
	textsetselect(t, e.q0, e.q1);
	t->next = &riffmode;
}

void
riffselectline(Text *t)
{
	uint q0 = textbacknl(t, t->q0, 1);
	uint q1 = textnl(t, t->q0);
	textsetselect(t, q0, q1);
	t->next = &riffmode;
}


void
riffexecute(Text *t)
{
	uint q0, q1;
	
	q0 = t->q0;
	q1 = t->q1;

	execute(t, q0, q1, FALSE, NULL);
	t->next = &texttypemode;
}

void
rifftag(Text *t)
{
	
}