#include "MoveRightCommand.h"

#include "IMovable.h"
MoveRightCommand::MoveRightCommand()
{
}


MoveRightCommand::~MoveRightCommand()
{
}


void MoveRightCommand::execute(IMovable& gameObject)
{
	gameObject.moveRight();
}