#include "StateMachine.h"

using namespace std;

namespace owner
{
    void StateMachine::AddState(StateRef newState,bool Replacing)
    {
        this->isAdding = true;
        this->isReplacing = Replacing;
        this->newState = move(newState);
    }

    void StateMachine::RemoveState()
    {
        this->isRemoving = true;
    }

    void StateMachine::ProcessStateChanges()
    {
        if(this->isRemoving && !this->states.empty())
        {
            this->states.pop();

            if(!this->states.empty())
            {
                this->states.top()->Resume();
            }

            this->isRemoving = false;
        }

        if(this->isAdding)
        {
            if(!this->states.empty())
            {
                if(this->isReplacing)
                {
                    this->states.pop();
                }
                else
                {
                    this->states.top()->Pause();
                }
            }
            this->states.push(move(this->newState));
            this->states.top()->Init();
            this->isAdding = false;
        }
    }

    StateRef &StateMachine::GetActiveState()
    {
        return this->states.top();
    }
}
