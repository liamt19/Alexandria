

#include "Board.h"
#include "stdio.h"
#include "stdlib.h"
#ifdef _WIN64
#include "windows.h"
#include <io.h>
#else
#include "string.h"
#include "sys/select.h"
#include "sys/time.h"
#include "unistd.h"
#endif
#include "io.h"
#include "perft.h"
#include "search.h"

int GetTimeMs() {
#ifdef WIN32
	return GetTickCount64();
#else
	struct timeval t;
	gettimeofday(&t, NULL);
	return t.tv_sec * 1000 + t.tv_usec / 1000;
#endif
}

const char* getfield(char* line, int num) {
	const char* tok;
	for (tok = strtok(line, ";"); tok && *tok; tok = strtok(NULL, ";")) {
		if (!--num)
			return tok;
	}
	return NULL;
}

/*
void runtestpositions(FILE* file, int depth) {
	char line[1024];
	char position[100];
	unsigned long long expectednodes;
	unsigned long long actualnodes;
	S_Board pos[1];
	while (fgets(line, 1024, file))
	{
		char* tmp = _strdup(line);
		char* tmp2 = _strdup(line);
		strcpy(position, getfield(tmp, 1));

		printf("position: %s ", position);


		char* nodesfield = getfield(tmp2, depth + 1);
		strtok(nodesfield, " ");
		char* nodestoken = strtok(NULL, " ");


		expectednodes = strtoull(nodestoken, '\0', 10);
		printf(" expected nodes: %llu ", expectednodes);



		parse_fen(position, pos);
		actualnodes = perft_test(depth, pos);
		if (expectednodes != actualnodes) {
			printf("PERFT ERROR\n");
			printf("expected nodes differ from actual nodes %llu != %llu",
expectednodes, actualnodes); return;
		}

		free(tmp);
		free(tmp2);


	}
}


*/
