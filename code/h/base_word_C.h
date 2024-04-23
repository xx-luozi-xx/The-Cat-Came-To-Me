#pragma once

class base_word {
public:
	int id;
	const char* name;

	bool passable;//可通过
	bool breakable;//可破坏
	bool interactive;//可互动（空格）
	bool visible;//可见

	base_word(int num = 0);
	base_word& operator=(const base_word&) = default;
	base_word& operator=(int num);

	operator int();
};

void swap(base_word& lhs, base_word& rhs);