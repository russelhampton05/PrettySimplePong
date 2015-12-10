#include "MoveUpCommand.h"
#include "IMovable.h"

MoveUpCommand::MoveUpCommand()
{
}


MoveUpCommand::~MoveUpCommand()
{
}

void MoveUpCommand::execute(IMovable& gameObject)
{
	gameObject.moveUp();
}

