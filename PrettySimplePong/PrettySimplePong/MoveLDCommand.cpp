#include "MoveLDCommand.h"
#include "IMovable.h"

MoveLDCommand::MoveLDCommand()
{
}


MoveLDCommand::~MoveLDCommand()
{
}


void MoveLDCommand::execute(IMovable& gameObject)
{
	gameObject.moveLeftDown();
}