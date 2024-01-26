#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
    ifstream inputFS;
    inputFS.open(fileName);

    if (!inputFS.is_open()) {
        return nullptr;
    }

    inputFS >> maxRow;
    inputFS >> maxCol;

    if (maxRow <= 0 || maxCol <= 0 || maxCol >= INT32_MAX / maxRow) {
        return nullptr;
    }

    inputFS >> player.row;
    inputFS >> player.col;

    if (player.row >= maxRow || player.col >= maxCol || player.row < 0 || player.col < 0) {
        return nullptr;
    }
    
    char dummy;
    bool status = false;
    char** map = createMap(maxRow, maxCol);
    if (map == nullptr) {
        return nullptr;
    }
    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < maxCol; j++) {
            if (i == player.row && j == player.col) {
                inputFS >> dummy;
                map[i][j] = TILE_PLAYER;
            }
            else {
                if (!(inputFS >> map[i][j])) {
                    return nullptr;
                }
                if (map[i][j] == TILE_DOOR || map[i][j] == TILE_EXIT) {
                    status = true;
                }
            }
        }
    }
    char extra;
    if (inputFS >> extra) {
        return nullptr;
    }
    if (status == false) {
        return nullptr;
    }
    return map;
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol) {
    if (input == MOVE_UP) {
        nextRow -= 1; 
    }
    if (input == MOVE_DOWN) {
        nextRow += 1; 
    }
    if (input == MOVE_RIGHT) {
        nextCol += 1;
    }
    if (input == MOVE_LEFT) {
        nextCol -= 1;
    }
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) {
    
    if (maxRow > 999 || maxCol > 999) {
        return nullptr;
    }
    
    char** map = new char*[maxRow];
    for (int i = 0; i < maxRow; i++) {
        map[i] = new char[maxCol];
    }

    for (int j = 0; j < maxRow; j++) {
        for (int k = 0; k < maxCol; k++) {
            map[j][k] = TILE_OPEN;
        }
    }
    return map;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) {
    
    if (map != nullptr) {
        for (int i = 0; i < maxRow; i++) {
            delete[] map[i];
        }

        delete[] map;
        map = nullptr;
    }
    maxRow = 0;
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) {
    
    if (map == nullptr) {
        return nullptr;
    }
    if (maxRow <= 0 || maxCol <= 0) {
        return nullptr;
    }

    char** newmap = new char*[2 * maxRow];
    for (int i = 0; i < 2 * maxRow; i++) {
        newmap[i] = new char[2 * maxCol];
    }

    for (int j = 0; j < maxRow; j++) {
        for (int k = 0; k < maxCol; k++) {
            newmap[j][k] = map[j][k];
        }
    }
    for (int a = 0; a < maxRow; a++) {
        for (int b = maxCol; b < 2 * maxCol; b++) {
            if (map[a][b - maxCol] == TILE_PLAYER) {
                newmap[a][b] = TILE_OPEN;
            }
            else {
                newmap[a][b] = map[a][b - maxCol];
            }
        }
    }
    for (int c = maxRow; c < 2 * maxRow; c++) {
        for (int d = 0; d < maxCol; d++) {
            if (map[c - maxRow][d] == TILE_PLAYER) {
                newmap[c][d] = TILE_OPEN;
            }
            else {
                newmap[c][d] = map[c - maxRow][d];
            }
        }
    }
    for (int m = maxRow; m < 2 * maxRow; m++) {
        for (int n = maxCol; n < 2 * maxCol; n++) {
            if (map[m - maxRow][n - maxCol] == TILE_PLAYER) {
                newmap[m][n] = TILE_OPEN;
            }
            else {
                newmap[m][n] = map[m - maxRow][n - maxCol];
            }
        }
    }
    
    for (int i = 0; i < maxRow; i++) {
        delete[] map[i];
    }

    delete[] map;

    map = newmap;
    maxRow *= 2;
    maxCol *= 2;

    return map;
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
    int status = STATUS_MOVE;
    if (nextRow < 0 || nextRow >= maxRow || nextCol < 0 || nextCol >= maxCol || map[nextRow][nextCol] == TILE_PILLAR 
        || map[nextRow][nextCol] == TILE_MONSTER) {
        nextRow = player.row;
        nextCol = player.col;
        status = STATUS_STAY;
    }

    else if (map[nextRow][nextCol] == TILE_TREASURE) {
        player.treasure++;
        status = STATUS_TREASURE;
    }

    else if (map[nextRow][nextCol] == TILE_AMULET) {
        status = STATUS_AMULET;
    }

    else if (map[nextRow][nextCol] == TILE_DOOR) {
        status = STATUS_LEAVE;
    }

    else if (map[nextRow][nextCol] == TILE_EXIT) {
        if (player.treasure > 0) {
            status = STATUS_ESCAPE;
        }
        else {
            nextRow = player.row;
            nextCol = player.col;
            status = STATUS_STAY;
        }
    }

    if (status != STATUS_STAY) {
        map[nextRow][nextCol] = TILE_PLAYER;
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
    }

    return status;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
    for (int i = player.col - 1; i >= 0; i--) {
        if (map[player.row][i] == TILE_PLAYER|| map[player.row][i] == TILE_PILLAR) {
            break;
        }
        if (map[player.row][i] == TILE_MONSTER) {
            map[player.row][i + 1] = TILE_MONSTER;
            map[player.row][i] = TILE_OPEN;
        }
    }

    for (int j = player.col + 1; j < maxCol; j++) {
        if (map[player.row][j] == TILE_PLAYER || map[player.row][j] == TILE_PILLAR) {
            break;
        }
        if (map[player.row][j] == TILE_MONSTER) {
            map[player.row][j - 1] = TILE_MONSTER;
            map[player.row][j] = TILE_OPEN;
        }
    }

    for (int k = player.row - 1; k >= 0; k--) {
        if (map[k][player.col] == TILE_PLAYER || map[k][player.col] == TILE_PILLAR) {
            break;
        }
        if (map[k][player.col] == TILE_MONSTER) {
            map[k + 1][player.col] = TILE_MONSTER;
            map[k][player.col] = TILE_OPEN;
        }
    }

    for (int l = player.row + 1; l < maxRow; l++) {
        if (map[l][player.col] == TILE_PLAYER || map[l][player.col] == TILE_PILLAR) {
            break;
        }
        if (map[l][player.col] == TILE_MONSTER) {
            map[l - 1][player.col] = TILE_MONSTER;
            map[l][player.col] = TILE_OPEN;
        }
    }

    if (map[player.row][player.col] == TILE_MONSTER) {
        return true;
    }
    
    return false;
}
