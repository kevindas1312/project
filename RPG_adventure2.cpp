#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // starting
    srand(time(0));
    string user;
    cout << "Insert name of user (not more than 7 characters):";
    cin >> user;
    while (user.size() > 7) {
        cout << "Name too long. Please enter not more than 7 characters: ";
        cin >> user;
    }

    cout << endl << "Welcome " << user << " to ...";
    cout << endl << "\n\n\n*Overview*";
    cout << endl << user << " is an amateur swordfighter from the land of Ravenshire.";
    cout << endl << user << " has had the dream since young to be the best swordfighter.";
    cout << endl << "To achieve this, " << user << " has to embark on a journey to obtain the greatest sword there ever is (The Bloodpetal).";
    cout << endl << "However, to obtain the sword, " << user << " has to pass through 3 levels.";

    cout << endl <<  "\n\n\nIn Level 1, to get past this level, you need to defeat The Keeper of Frostmere in the North of Greystone.";
    cout << endl << "The Keeper of Frostmere will be guarding The Crimson Blade.";
    cout << endl << "You need to obtain The Crimson Blade to defeat the next level.";

    cout << endl << "\n\n\nIn Level 2, to advance further, you must defeat The Warden of Blackhollow, located in the Northern reaches of Ashvale.";
    cout << endl << "The Warden of Blackhollow guards The Obsidian Edge, a blade of immense power.";
    cout << endl << "You must obtain The Obsidian Edge to conquer the next level.";

    cout << endl << "\n\n\nAnd for the final level, you must defeat The Sentinel of Ironreach, found in the Northern Highlands of Valemont.";
    cout << endl << "The Sentinel of Ironreach guards The Bloodpetal, a legendary sword of unmatched sharpness.";
    cout << endl << "P.S. Good luck claiming The Bloodpetal as no one has ever defeated The Sentinel of Ironreach.";

    // Player & Enemy Stats
    int user_health = 150;                 // Your HP (persists through levels)
    int attack = 0;                        // Your attack damage (set by weapon)
    int bonusMoves = 0;                    // 2 bonus moves if you Defend & boss does Nothing

    int the_keeper_of_frostmere_health = 50;
    int the_warden_of_blackhollow_health = 75;
    int the_sentinel_of_ironreach = 100;

    int keeper_damage = 5;
    int warden_damage = 10;
    int sentinel_damage = 20;

    int crimson_blade = 12;
    int obsidian_edge = 15;
    int the_bloodpetal = 110; 

    // player Choose their Starter Sword
    int starter_sword;
    cout << endl << "\nList of Default swords";
    cout << endl << "Wooden Beak (1)";
    cout << endl << "Stick of Styx (2)";
    cout << endl << "Dawnbreaker (3)";
    cout << "\nYou may now choose your default sword (1/2/3): ";
    while (!(cin >> starter_sword) || (starter_sword < 1 || starter_sword > 3)) {
        cout << "Invalid option (choose 1, 2 or 3), restart the game";
        return(0);
    }

    if (starter_sword == 1) {
        cout << "You will begin your adventure with Wooden Beak!";
        attack = 4;
    } else if (starter_sword == 2) {
        cout << "Stick of Styx, a wise choice...";
        attack = 4; 
    } else {
        cout << "Dawnbreaker will be thy trusty companion throughout your journey...";
        attack = 5;
    }

    // level 1
    cout << endl << "\n\n\n*Level 1*";
    cout << endl << "You have arrived at Frostmere in the North of Greystone.";
    cout << endl << "The Keeper of Frostmere emerges from the shadows!";

    while (user_health > 0 && the_keeper_of_frostmere_health > 0) {
        cout << "\n----------------------------------------";
        cout << "\nYour Health: " << user_health << " | Keeper Health: " << the_keeper_of_frostmere_health;
        cout << "\n----------------------------------------\n";

        // for bonus move
        if (bonusMoves > 0) {
            cout << "You have " << bonusMoves << " BONUS MOVE";
            if (bonusMoves > 1) cout << "S";
            cout << "! (Boss does NOTHING during these.)\n";

            int playerChoice;
            cout << "[Bonus Move] Choose your action (1 = Attack, 2 = Defend): ";
            cin >> playerChoice;

            if (playerChoice == 1) {
                the_keeper_of_frostmere_health = the_keeper_of_frostmere_health - attack;
                if (the_keeper_of_frostmere_health < 0) the_keeper_of_frostmere_health = 0;
                cout << "Free strike! You deal " << attack << " damage.\n";
            } else {
                cout << "You defend, but the boss is idle—nothing happens.\n";
            }

            bonusMoves = bonusMoves - 1;
        } else {
            // Normal gameplay
            int playerChoice;
            cout << "Choose your action (1 = Attack, 2 = Defend): ";
            cin >> playerChoice;

            int bossChoice = (rand() % 3) + 1; // 1=Attack, 2=Defend, 3=Nothing

            if (bossChoice == 1) {
                cout << "The Keeper decides to ATTACK!\n";
            } else if (bossChoice == 2) {
                cout << "The Keeper DEFENDS!\n";
            } else {
                cout << "The Keeper does NOTHING.\n";
            }

            if (playerChoice == 1 && bossChoice == 1) {
                the_keeper_of_frostmere_health = the_keeper_of_frostmere_health - attack;
                if (the_keeper_of_frostmere_health < 0) the_keeper_of_frostmere_health = 0;
                user_health = user_health - keeper_damage;
                if (user_health < 0) user_health = 0;
                cout << "Clash! You deal " << attack << " and take " << keeper_damage << " in return.\n";
            } else if (playerChoice == 1 && bossChoice == 2) {
                cout << "Your strike is blocked. No damage dealt.\n";
            } else if (playerChoice == 1 && bossChoice == 3) {
                the_keeper_of_frostmere_health = the_keeper_of_frostmere_health - attack;
                if (the_keeper_of_frostmere_health < 0) the_keeper_of_frostmere_health = 0;
                cout << "Clean hit! You deal " << attack << " damage.\n";
            } else if (playerChoice == 2 && bossChoice == 1) {
                cout << "You block the attack. No damage taken.\n";
            } else if (playerChoice == 2 && bossChoice == 2) {
                cout << "Both defend. Nothing happens.\n";
            } else if (playerChoice == 2 && bossChoice == 3) {
                bonusMoves = bonusMoves + 2;
                cout << "You gain 2 BONUS MOVES!\n";
            }
        }

        if (user_health <= 0) {
            cout << "You have been defeated...\nGame Over.";
            return 0;
        }
        if (the_keeper_of_frostmere_health <= 0) {
            cout << "\nYou have defeated The Keeper of Frostmere!";
            cout << "\nYou obtained The Crimson Blade!";
            attack = crimson_blade;
            bonusMoves = 0; // reset between bosses
        }
    }

    if (user_health <= 0) return 0; // fail-safe

    // level 2
    cout << endl << "\n\n\n*Level 2*";
    cout << endl << "You have arrived at Blackhollow in the Northern reaches of Ashvale.";
    cout << endl << "The Warden of Blackhollow stands before you!";

    while (user_health > 0 && the_warden_of_blackhollow_health > 0) {
        cout << "\n----------------------------------------";
        cout << "\nYour Health: " << user_health << " | Warden Health: " << the_warden_of_blackhollow_health;
        cout << "\n----------------------------------------\n";

        if (bonusMoves > 0) {
            cout << "You have " << bonusMoves << " BONUS MOVE";
            if (bonusMoves > 1) cout << "S";
            cout << "! (Boss does NOTHING during these.)\n";

            int playerChoice;
            cout << "[Bonus Move] Choose your action (1 = Attack, 2 = Defend): ";
            cin >> playerChoice;

            if (playerChoice == 1) {
                the_warden_of_blackhollow_health = the_warden_of_blackhollow_health - attack;
                if (the_warden_of_blackhollow_health < 0) the_warden_of_blackhollow_health = 0;
                cout << "Free strike! You deal " << attack << " damage.\n";
            } else {
                cout << "You defend, but nothing happens.\n";
            }

            bonusMoves = bonusMoves - 1;
        } else {
            int playerChoice;
            cout << "Choose your action (1 = Attack, 2 = Defend): ";
            cin >> playerChoice;

            int bossChoice = (rand() % 3) + 1;

            if (bossChoice == 1) {
                cout << "The Warden decides to ATTACK!\n";
            } else if (bossChoice == 2) {
                cout << "The Warden DEFENDS!\n";
            } else {
                cout << "The Warden does NOTHING.\n";
            }

            if (playerChoice == 1 && bossChoice == 1) {
                the_warden_of_blackhollow_health = the_warden_of_blackhollow_health - attack;
                if (the_warden_of_blackhollow_health < 0) the_warden_of_blackhollow_health = 0;
                user_health = user_health - warden_damage;
                if (user_health < 0) user_health = 0;
                cout << "Clash! You deal " << attack << " and take " << warden_damage << ".\n";
            } else if (playerChoice == 1 && bossChoice == 2) {
                cout << "Your strike is blocked. No damage dealt.\n";
            } else if (playerChoice == 1 && bossChoice == 3) {
                the_warden_of_blackhollow_health = the_warden_of_blackhollow_health - attack;
                if (the_warden_of_blackhollow_health < 0) the_warden_of_blackhollow_health = 0;
                cout << "Clean hit! You deal " << attack << " damage.\n";
            } else if (playerChoice == 2 && bossChoice == 1) {
                cout << "You block the attack. No damage taken.\n";
            } else if (playerChoice == 2 && bossChoice == 2) {
                cout << "Both defend. Nothing happens.\n";
            } else if (playerChoice == 2 && bossChoice == 3) {
                bonusMoves = bonusMoves + 2;
                cout << "You gain 2 BONUS MOVES!\n";
            }
        }

        if (user_health <= 0) {
            cout << "You have been defeated...\nGame Over.";
            return 0;
        }
        if (the_warden_of_blackhollow_health <= 0) {
            cout << "\nYou have defeated The Warden of Blackhollow!";
            cout << "\nYou obtained The Obsidian Edge!";
            attack = obsidian_edge;
            bonusMoves = 0;
        }
    }

    if (user_health <= 0) return 0;

    // level 3
    cout << endl << "\n\n\n*Level 3*";
    cout << endl << "You have arrived at Ironreach in the Northern Highlands of Valemont.";
    cout << endl << "The Sentinel of Ironreach, the ultimate guardian, appears!";

    while (user_health > 0 && the_sentinel_of_ironreach > 0) {
        cout << "\n----------------------------------------";
        cout << "\nYour Health: " << user_health << " | Sentinel Health: " << the_sentinel_of_ironreach;
        cout << "\n----------------------------------------\n";

        if (bonusMoves > 0) {
            cout << "You have " << bonusMoves << " BONUS MOVE";
            if (bonusMoves > 1) cout << "S";
            cout << "! (Boss does NOTHING during these.)\n";

            int playerChoice;
            cout << "[Bonus Move] Choose your action (1 = Attack, 2 = Defend): ";
            cin >> playerChoice;

            if (playerChoice == 1) {
                the_sentinel_of_ironreach = the_sentinel_of_ironreach - attack;
                if (the_sentinel_of_ironreach < 0) the_sentinel_of_ironreach = 0;
                cout << "Free strike! You deal " << attack << " damage.\n";
            } else {
                cout << "You defend, but nothing happens.\n";
            }

            bonusMoves = bonusMoves - 1;
        } else {
            int playerChoice;
            cout << "Choose your action (1 = Attack, 2 = Defend): ";
            cin >> playerChoice;

            int bossChoice = (rand() % 3) + 1;

            if (bossChoice == 1) {
                cout << "The Sentinel decides to ATTACK!\n";
            } else if (bossChoice == 2) {
                cout << "The Sentinel DEFENDS!\n";
            } else {
                cout << "The Sentinel does NOTHING.\n";
            }

            if (playerChoice == 1 && bossChoice == 1) {
                the_sentinel_of_ironreach = the_sentinel_of_ironreach - attack;
                if (the_sentinel_of_ironreach < 0) the_sentinel_of_ironreach = 0;
                user_health = user_health - sentinel_damage;
                if (user_health < 0) user_health = 0;
                cout << "Clash! You deal " << attack << " and take " << sentinel_damage << ".\n";
            } else if (playerChoice == 1 && bossChoice == 2) {
                cout << "Your strike is blocked. No damage dealt.\n";
            } else if (playerChoice == 1 && bossChoice == 3) {
                the_sentinel_of_ironreach = the_sentinel_of_ironreach - attack;
                if (the_sentinel_of_ironreach < 0) the_sentinel_of_ironreach = 0;
                cout << "Clean hit! You deal " << attack << " damage.\n";
            } else if (playerChoice == 2 && bossChoice == 1) {
                cout << "You block the attack. No damage taken.\n";
            } else if (playerChoice == 2 && bossChoice == 2) {
                cout << "Both defend. Nothing happens.\n";
            } else if (playerChoice == 2 && bossChoice == 3) {
                bonusMoves = bonusMoves + 2;
                cout << "You gain 2 BONUS MOVES!\n";
            }
        }

        if (user_health <= 0) {
            cout << "\nYou have been defeated by The Sentinel of Ironreach...";
            cout << "\nLike many before you, you could not claim The Bloodpetal.";
            cout << "\nGame Over.";
            return 0;
        }
        if (the_sentinel_of_ironreach <= 0) {
            cout << endl << "\n*Victory!*";
            cout << endl << "You have defeated The Sentinel of Ironreach!";
            cout << endl << "You obtained The Bloodpetal, the legendary sword (+" << the_bloodpetal << " attack)!";
            cout << endl << user << " has become the greatest swordfighter in all of Ravenshire!";
            cout << endl << "Congratulations on completing your journey!";
        }
    }

    return 0;
}

