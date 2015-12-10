#include "MoveLeftCommand.h"

#include "IMovable.h"
MoveLeftCommand::MoveLeftCommand()
{
}


MoveLeftCommand::~MoveLeftCommand()
{

}


void MoveLeftCommand::execute(IMovable& gameObject)
{
	gameObject.moveLeft();
}