#pragma once

class Base
{
private:
	/* data */
public:
	virtual ~Base();
	Base* generate(void);
	void identify(Base *p);
	void identify(Base &p);
};


