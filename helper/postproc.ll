%{
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>
#include <boost/random/mersenne_twister.hpp>

static boost::mt19937_64 generator;

extern "C"
int yywrap()
{
	return 1;
}
%}

ws		([ \f\n\r\t\v]*)

%%

"?"{ws}"<"		{
				char v[21];
				int n = std::snprintf(v, sizeof v,
				    "<0x%" PRIx64 ",", generator());
				if (n <= 0 || (size_t)n >= sizeof v) {
					std::cerr << "lolwut?!?!?\n";
					return 1;
				}
				if (write(1, v, (size_t)n) != n)
					return 1;
				if (write(1, yytext + 1, yyleng - 2)
				    != yyleng - 2)
					return 1;
			}
"?"{ws}			|
[^\"\'#?]+		|
^{ws}"#".*		|
.			{
				if (write(1, yytext, yyleng) != yyleng)
					return 1;
			}

%%

int main(int argc, char **argv)
{
	switch (argc) {
	    case 1:
		generator.seed(std::time(0) << 12 ^ getpid());  break;
	    case 2:
		generator.seed((uint64_t)std::strtoumax(argv[1], 0, 0));
		break;
	    default:
		std::cerr << "usage: " << argv[0] << " [(seed)]\n";
		return 1;
	}
	return yylex();
}
