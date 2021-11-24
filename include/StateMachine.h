#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <memory>
#include <stack>

#include "State.h"

using namespace std;

namespace owner
{
    typedef unique_ptr <State> StateRef;

    class StateMachine
    {
        public:

            StateMachine() {}
            virtual ~StateMachine() {}

            void AddState(StateRef newState,bool Replacing = true);
            void RemoveState();

            void ProcessStateChanges();

            StateRef &GetActiveState();

        private :

            stack <StateRef> states;
            StateRef newState;

            bool isRemoving;
            bool isAdding;
            bool isReplacing;
    };

}

#endif // STATEMACHINE_H
