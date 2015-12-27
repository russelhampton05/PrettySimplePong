#include "MoveRDCommand.h"
#include "IMovable.h"

MoveRDCommand::MoveRDCommand()
{
}


MoveRDCommand::~MoveRDCommand()
{
}
void MoveRDCommand::execute(IMovable& gameObject)
{
	gameObject.moveRightDown();
}