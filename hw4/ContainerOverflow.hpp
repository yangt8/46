#ifndef CONTAINEROVERFLOW_HPP
#define CONTAINEROVERFLOW_HPP
using namespace std;	

class ContainerOverflow
{
public:
	explicit ContainerOverflow(const string& msg)  //O(1)
	     :message{msg}
	{}

	string get_message() const //O(1)
	{
		return message;
	}
private:
	string message;
};

#endif