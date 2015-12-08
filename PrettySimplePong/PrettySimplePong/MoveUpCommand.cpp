#include "MoveUpCommand.h"
#include "IUpdatable.h"

MoveUpCommand::MoveUpCommand()
{
}


MoveUpCommand::~MoveUpCommand()
{
}

void MoveUpCommand::execute(IUpdatable& gameObject)
{
	gameObject.moveUp();
}

