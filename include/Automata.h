#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include<string>
#include <map>
enum class STATES {
	OFF, WAIT, ACCEPT, CHECK, COOK
};

class Automata {
private:
	float cash;
	std::map<std::string, int> menu;;
	STATES state;
	void check(std::string);
	void cook(std::string);
	void finish();

public:
	Automata();
	~Automata();
	void on();
	void off();
	void coin(int);
	void getMenu();
	STATES getState();
	void choice(std::string);
	void cancel();
	int getBalance();
};
#endif