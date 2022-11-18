#ifndef STATE_H
#define STATE_H

/**
 * @class State
 * @author Phetolo Malele
 * @date 30/09/2022
 * @file States.h
 * @brief pure virtual class which models every state of the game
 */


class State
{

public:
    /**
     * @brief function to initialise every state conditions
     */
    virtual void initial_state() = 0; // initialises the state
    /**
    * @brief Function that keeps track of all changes in a state
    */
    virtual void state_update() = 0;  // updates the state
     /**
      * @brief Function that communicates with user and responds to their inputs
      */
    virtual void input_handler() = 0; // handles all input on that state
     /**
     * @brief Function to draw changes to the screen
       */
    virtual void draw_State() = 0;    // draw the new state
    /**
    * @brief Function used to pause the current state
    */

    virtual void pause()
    {
        return;
    }
    /**
     * @brief Function used to resume the current state of the game
     */
    virtual void resume()
    {
        return;
    }

protected:
    /**
     * @brief function used to create screen with respect to state changes
     */
    virtual void Create_Screen() = 0;
    /**
     * @brief checks for keyboard input at that state
     */
    virtual void CheckForInput() = 0;
};

#endif // STATE_H
