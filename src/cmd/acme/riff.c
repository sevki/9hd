#include <u.h>
#include <libc.h>
#include <mouse.h>
#include <keyboard.h>
#include <complete.h>
#include "dat.h"
#include "fns.h"

enum {
	Rstart	= KF|0x0D,
	Rselect	= 0x73, // s
	Rblock	= 0x62, // b
	Rline	= 0x6c, // l
	Rword	= 0x77, // w
	Rexec	= 0x65, // e
	Rsnarf	= 0x63, // c
	Rpaste	= 0x76, // v
	Rcut	= 0x78, // x
};

void
riffmode(Text *t, Rune r)
{
	switch(r){
	case Kesc:
	case Rstart:
		t->next = &typemodeselect;
		return;
	case Rselect:
		t->next = &riffselect;
		return;
	}
}

void
riffselect(Text *t, Rune r)
{
	switch(r){
	case Kesc:
	case Rstart:
		t->next = &typemodeselect;
		return;
	case Rselect:
		return;
	}
}

uint
searchback(Text *t, Rune r)
{

}