/**
 * Application start.
 * Here we create the game and start the main loop.
 *
 */

#include <assert.h>
#include <stddef.h>
#include <Engine/Game.h>

/* TODO
    - StateManager holds public references to asset managers, states hold reference to state manager
*/

int main() {

    BW::Game game;
    game.run();
    return 0;

}
