// Implementation for State class

#include "state.h"

State::State() { }

State::State(string ab, string sn, string cap, int pop, int yr, int con)
{ abr = ab; statename = sn; capital = cap; population = pop; year = yr; congress = con; }

State::~State() { }

void State::setStatename(string sn)
{ statename = sn; }

void State::setAbr(string ab)
{ abr = ab; }

void State::setCapital(string cap)
{ capital = cap; }

void State::setPopulation(int pop)
{ population = pop; }

void State::setYear(int yr)
{ year = yr; }

void State::setCongress(int con)
{ congress = con; }

string State::getStatename()
{ return statename; }

string State::getAbr()
{ return abr; }

string State::getCapital()
{ return capital; }

int State::getPopulation()
{ return population;  }

int State::getYear()
{ return year; }

int State::getCongress()
{ return congress; }
