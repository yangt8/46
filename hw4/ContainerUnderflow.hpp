#ifndef CONTAINERUNDERFLOW_HPP
#define CONTAINERUNDERFLOW_HPP
using namespace std;	

class ContainerUnderflow
{
public:
	explicit ContainerUnderflow(const string& msg)   //O(1)
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