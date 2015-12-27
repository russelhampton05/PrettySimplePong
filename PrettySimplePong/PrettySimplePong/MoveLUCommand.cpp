#include "MoveLUCommand.h"

#include "IMovable.h"
MoveLUCommand::MoveLUCommand()
{
}


MoveLUCommand::~MoveLUCommand()
{
}
void MoveLUCommand::execute(IMovable& gameObject)
{
	gameObject.moveLeftUp();
}