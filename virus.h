#ifndef _VIRUS_H_
#define _VIRUS_H_

typedef struct
{
	char * name;

	float spreading_rate;
	float research_rate;
} virus_t ;

extern virus_t * virus_creer(char name);

#endif

