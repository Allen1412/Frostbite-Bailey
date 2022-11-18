#include "StatesManager.h"

void StatesManager::adding_state(state_ptr new_state, bool replacing)
{
    adding = true;
    this->replacing = replacing;
    current_state = std::move(new_state);
}
void StatesManager::removing_state()
{
    removing = true;
}
void StatesManager::updating_state()
{
    if(adding) {
        if(!all_states.empty()) {

            if(replacing)
                all_states.pop();
            else
                all_states.top()->pause();
        }
        all_states.push(std::move(current_state));
        all_states.top()->initial_state();
        adding = false;
    }

    if(removing && !all_states.empty()) {

        all_states.pop();

        if(!all_states.empty())
            all_states.top()->resume();
        removing = false;
    }
}
state_ptr& StatesManager::get_current_state()
{
    return all_states.top();
}
