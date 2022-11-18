#ifndef STATESMANAGER_H
#define STATESMANAGER_H

#include "State.h"
#include <memory>
#include <stack>
// game backbone

/**
 * @class MachineStates
 * @author Phetolo Malele
 * @date 30/10/2022
 * @file StatesManager.h
 * @brief class used to manage execution of all states,putting them in stack
 */

using state_ptr = std::unique_ptr<State>; // unique pointer

class StatesManager
{
public:
    /**
     * @brief Function used to add a new state to the stack of states
     * @param new_state The state that is being added, a unique pointer of type State
     * @param replacing specifying if the current state is being replaced, boolean type
     */

    void adding_state(state_ptr new_state, bool replacing = true);
    /**
     * @brief function to remove a particular state from the stack of states
     */
    void removing_state();
    /**
     * @brief function to update changes to a particular state
     */
    void updating_state();
    /**
     * @brief function to get the current running state
     * @return returns a pointer to the current state by reference
     */
    state_ptr& get_current_state(); // get_current_state returns a pointer to the current state

    StatesManager()
    {
    }
    ~StatesManager()
    {
    }

private:
    bool removing, adding, replacing; // tracks what we're doing to the states
    std::stack<state_ptr> all_states; // stack of all present states

    state_ptr current_state;
};
#endif // STATESMANAGER_H
