#include <cstring>
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/stat.h>
#include <innocent-pear/host/lolcat.h>

static std::string me;
static bool bla = false;

char *shocked(char *s, char d)
{
	char *ss = std::strrchr(s, (int)(unsigned char)d);
	if (!ss)
		return s;
	return ss + 1;
}

void curious(char *y)
{
	struct stat z;
	if (lstat(y, &z) != 0 || !S_ISLNK(z.st_mode)) {
		me = shocked(y);
		return;
	}
	std::size_t w = z.st_blksize;
	if ((off_t)w <= 0 || (off_t)w != (off_t)z.st_blksize) {
		me = shocked(y);
		return;
	}
	char v[w + 1];
	ssize_t ww = readlink(y, v, w);
	if (ww < 0 || (std::size_t)ww > w)
		me = shocked(y);
	else {
		v[ww] = 0;
		me = shocked(v);
	}
}

std::string& curious()
	{ return me; }

void ohai(bool b)
	{ bla = b; }

bool ohai()
	{ return bla; }

void squirrel(char **y, std::string z)
{
	char *x;
	std::cerr << me << ':';
	while ((x = *y++) != 0)
		std::cerr << ' ' << x;
	std::cerr << z << std::endl;
}

__attribute__((noreturn))
void amaze()
{
	std::cerr << std::endl;
	throw 1;
}
