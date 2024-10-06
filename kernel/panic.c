/* 
 * ---------------------------------------------------------------
 *                            RawBerry
 * (c) RawBerry Team
 * Published on license MIT. Read `/LICENSE` for more details.
 * ---------------------------------------------------------------
*/

#include <stdbool.h>

/**
 * Stops every single process and frozes the system.
 */
void kernel_panic() {
    while (true) {
        // Now do nothing. It only keeps system from restarting. 
    }
}