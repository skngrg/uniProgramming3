#pragma once

class MyException
{
protected:

	char* info = nullptr;

public:

	MyException(const char* msg)
	{
		int i;
		for (i = 0; msg[i] != '\0'; i++);
		info = new char[++i];
		for (i = 0; msg[i] != '\0'; i++)
			info[i] = msg[i];
		info[i] = '\0';
	}

	~MyException()
	{
		delete[] info;
	}

	char* what()
	{
		return info;
	}

};

class aut_of_range : public MyException
{
private:

	char name[13] = "aut_of_range";

public:

	aut_of_range(const char* msg) : MyException(msg)
	{
		
	}

	char* get_name()
	{
		return name;
	}

};

class deque_exception : public MyException
{
private:

	char name[16] = "deque_exception";

public:

	deque_exception(const char* msg) : MyException(msg)
	{

	}

	char* get_name()
	{
		return name;
	}

};

class file_exception : public MyException
{
private:

	char name[15] = "file_exception";

public:

	file_exception(const char* msg) : MyException(msg)
	{

	}

	char* get_name()
	{
		return name;
	}

};