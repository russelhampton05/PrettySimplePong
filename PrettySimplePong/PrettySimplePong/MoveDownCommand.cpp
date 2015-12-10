#include "MoveDownCommand.h"
#include "IMovable.h"

MoveDownCommand::MoveDownCommand()
{
}


MoveDownCommand::~MoveDownCommand()
{

}

void MoveDownCommand::execute(IMovable& gameObject)
{
	gameObject.moveDown();
}