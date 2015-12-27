#include "MoveRUCommand.h"
#include "IMovable.h"

MoveRUCommand::MoveRUCommand()
{
}


MoveRUCommand::~MoveRUCommand()
{
}

void MoveRUCommand::execute(IMovable& gameObject)
{
	gameObject.moveRightUp();
}