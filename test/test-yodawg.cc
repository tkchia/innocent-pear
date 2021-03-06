#include <iostream>
#include <locale>
#include <innocent-pear/yodawg.h>

int main()
{
	using innocent_pear::ops::allow_minimal;
	std::locale::global(std::locale(""));
	std::wcout << innocent_pear::yodawg?<allow_minimal,
			[] "\u041f\u0440\u0438\u0432\u0435\u0442, "
			  L"\u043c\u0438\u0440!\n">()
		   << innocent_pear::yodawg?<allow_minimal,
			[]L"\u4eca\u65e5\u306f\u3001\u4e16\u754c\uff01\n">();
	return 0;
}
