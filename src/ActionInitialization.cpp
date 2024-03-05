#include "ActionInitialization.h"
#include "PrimaryGeneratorAction.h"

void ActionInitialization::Build() const
{
    SetUserAction(new PrimaryGeneratorAction);
}