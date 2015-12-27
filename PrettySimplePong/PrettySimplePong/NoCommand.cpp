#include "NoCommand.h"
#include "IMovable.h"

NoCommand::NoCommand()
{
}


NoCommand::~NoCommand()
{
}
void NoCommand::execute(IMovable& gameObject)
{
	gameObject.noCommand();
}