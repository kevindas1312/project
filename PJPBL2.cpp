#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//introduction
void introduction(string &name){
    cout << endl << "Welcome " << name << " to Ravenshire";
    cout << endl << "\n\n\n*Overview*";
    cout << endl << name << " is an amateur swordfighter from the land of Ravenshire.";
    cout << endl << name << " has had the dream since young to be the best swordfighter.";
    cout << endl << "To achieve this, " << name << " has to embark on a journey to obtain the greatest sword there ever is (The Bloodpetal).";
    cout << endl << "However, to obtain the sword, " << name << " has to pass through 3 levels.";

    cout << endl <<  "\n\n\nIn Level 1, to get past this level, you need to defeat The Keeper of Frostmere in the North of Greystone.";
    cout << endl << "The Keeper of Frostmere will be guarding The Crimson Blade.";
    cout << endl << "You need to obtain The Crimson Blade to defeat the next level.";

    cout << endl << "\n\n\nIn Level 2, to advance further, you must defeat The Warden of Blackhollow, located in the Northern reaches of Ashvale.";
    cout << endl << "The Warden of Blackhollow guards The Obsidian Edge, a blade of immense power.";
    cout << endl << "You must obtain The Obsidian Edge to conquer the next level.";

    cout << endl << "\n\n\nAnd for the final level, you must defeat The Sentinel of Ironreach, found in the Northern Highlands of Valemont.";
    cout << endl << "The Sentinel of Ironreach guards The Bloodpetal, a legendary sword of unmatched sharpness.";
    cout << endl << "P.S. Good luck claiming The Bloodpetal as no one has ever defeated The Sentinel of Ironreach.";
}

//function to choose swords
void swords_choice(int &startersword, int &att){
    do{
        cout << endl << "\nList of Default swords";
        cout << endl << "Wooden Beak (1)";
        cout << endl << "Stick of Styx (2)";
        cout << endl << "Dawnbreaker (3)";
        cout << "\nYou may now choose your default sword (1/2/3): ";
        cin >> startersword;
    }
    while (startersword != 1 && startersword != 2 && startersword != 3);

    if (startersword == 1) {
        cout << "You will begin your adventure with Wooden Beak!";
        att = 5;
    } else if (startersword == 2) {
        cout << "Stick of Styx, a wise choice...";
        att = 6; 
    } else {
        cout << "Dawnbreaker will be thy trusty companion throughout your journey...";
        att = 7;
    }
}

//function to exit the game
void endgame(int &userheal){
    if (userheal <= 0) {
        cout << "You have been defeated. Game over!";
        exit(0);
    }
}

//function to display boss health and user health
void health_display(int &user_heal2, int &boss_heal, string &bossname){
    cout << "\n----------------------------------------";
    cout << "\nYour Health: " << user_heal2 << " | " << bossname <<": " << boss_heal;
    cout << "\n----------------------------------------\n";
}

//function that allows the user to battle the boss
void battle_mechanism(int &bonus, int &player_Choice, int &boss_heal2, int &att2, int &boss_Choice, int &boss_damage, int &user_heal3){
    if (bonus > 0) {
        cout << "You have " << bonus << " BONUS MOVE";
        if (bonus > 1) cout << "S";
        cout << "! (Boss does NOTHING during these.)\n";

        cout << "[Bonus Move] Choose your action (1 = Attack, 2 = Defend): ";
        cin >> player_Choice;

        if (player_Choice == 1) {
            boss_heal2 = boss_heal2 - att2;
            if (boss_heal2 < 0) boss_heal2 = 0;
            cout << "Free strike! You deal " << att2 << " damage.\n";
        } else {
            cout << "You defend, but the boss is idle—nothing happens.\n";
        }

        bonus--;
        } else { // Normal gameplay
        cout << "Choose your action (1 = Attack, 2 = Defend): ";
        cin >> player_Choice;

        boss_Choice = (rand() % 3) + 1; // 1=Attack, 2=Defend, 3=Nothing

        if (boss_Choice == 1) {
            cout << "BOSS decides to ATTACK!\n";
        } else if (boss_Choice == 2) {
             cout << "BOSS DEFENDS!\n";
        }else {
            cout << "BOSS does NOTHING.\n";
        }

        if (player_Choice == 1 && boss_Choice == 1) {
            boss_heal2 = boss_heal2 - att2;
            if (boss_heal2 < 0) boss_heal2 = 0;
            user_heal3 = user_heal3 - boss_damage;
            if (user_heal3 < 0) user_heal3 = 0;
            cout << "Clash! You deal " << att2 << " and take " << boss_damage << " in return.\n";
        } else if (player_Choice == 1 && boss_Choice == 2) {
            cout << "Your strike is blocked. No damage dealt.\n";
        } else if (player_Choice == 1 && boss_Choice == 3) {
            boss_heal2 = boss_heal2 - att2;
            if (boss_heal2 < 0) boss_heal2 = 0;
            cout << "Clean hit! You deal " << att2 << " damage.\n";
        } else if (player_Choice == 2 && boss_Choice == 1) {
            cout << "You block the attack. No damage taken.\n";
        } else if (player_Choice == 2 && boss_Choice == 2) {
            cout << "Both defend. Nothing happens.\n";
        } else if (player_Choice == 2 && boss_Choice == 3) {
            bonus++;
            cout << "You gain 1 BONUS MOVE!\n";
        }
    }
}

int main(){
    srand(time(0));
    string user;
    cout << "Insert name of user (not more than 10 characters):";
    getline(cin,user);
    while (user.size() > 10) {
        cout << "Name too long. Please enter not more than 10 characters: ";
        cin >> user;
    }

    introduction(user);

    int user_health = 80;                 // Your HP (changes over levels)
    int attack = 0;                        // Your attack damage (set by weapon)
    int bonusMoves = 0;                    // 2 bonus moves if you Defend & boss does Nothing
    int playerChoice = 0, bossChoice = 0;

    int boss_healths[3] = {50,75,100}; //array used to store boss' health
    int boss_damages[3] = {3,10,20}; //array used to store boss' damages
    string names[3] = {"Keeper", "Warden", "Sentinel"}; //array used to store boss' names
    int blade[3] = {30,40,110}; //array used to store each blade damage

    int* current_boss_hp;
    current_boss_hp = &boss_healths[0]; //pointer initialized with the keeper's health (ensuring a common variable for the program)

    // player Choose their Starter Sword
    int starter_sword;
    swords_choice(starter_sword,attack);

    // level 1
    cout << endl << "\n\n\n*Level 1*";
    cout << endl << "You have arrived at Frostmere in the North of Greystone.";
    cout << endl << "The Keeper of Frostmere emerges from the shadows!";

    while (user_health > 0 && *current_boss_hp > 0) {
        health_display(user_health, *current_boss_hp, names[0]);

        // for bonus move
        battle_mechanism(bonusMoves, playerChoice, *current_boss_hp, attack, bossChoice, boss_damages[0], user_health);
        
        endgame(user_health);
        if (*current_boss_hp <= 0) {
            cout << "\nYou have defeated The Keeper of Frostmere!";
            cout << "\nYou obtained The Crimson Blade!";
            attack = blade[0];
            bonusMoves = 0; // reset between bosses
        }
    }

    endgame(user_health); // failsafe
    current_boss_hp = &boss_healths[1]; //pointer initialized with the warden's health

    // level 2
    cout << endl << "\n\n\n*Level 2*";
    cout << endl << "You have arrived at Blackhollow in the Northern reaches of Ashvale.";
    cout << endl << "The Warden of Blackhollow stands before you!";

    while (user_health > 0 && *current_boss_hp > 0) {
        health_display(user_health, *current_boss_hp, names[1]);

        battle_mechanism(bonusMoves, playerChoice, *current_boss_hp, attack, bossChoice, boss_damages[1], user_health);

        endgame(user_health);
        if (*current_boss_hp <= 0) {
            cout << "\nYou have defeated The Warden of Blackhollow!";
            cout << "\nYou obtained The Obsidian Edge!";
            attack = blade[1];
            bonusMoves = 0;
        }
    }

    endgame(user_health);
    current_boss_hp = &boss_healths[2]; //pointer initialized with the sentinel's health

    // level 3
    cout << endl << "\n\n\n*Level 3*";
    cout << endl << "You have arrived at Ironreach in the Northern Highlands of Valemont.";
    cout << endl << "The Sentinel of Ironreach, the ultimate guardian, appears!";

    while (user_health > 0 && *current_boss_hp > 0) {
        health_display(user_health, *current_boss_hp, names[2]);

        battle_mechanism(bonusMoves, playerChoice, *current_boss_hp, attack, bossChoice, boss_damages[2], user_health);

        if (user_health <= 0) {
            cout << "\nYou have been defeated by The Sentinel of Ironreach...";
            cout << "\nLike many before you, you could not claim The Bloodpetal.";
            cout << "\nGame Over.";
            return 0;
        }
        if (*current_boss_hp <= 0) {
            cout << endl << "\n*Victory!*";
            cout << endl << "You have defeated The Sentinel of Ironreach!";
            cout << endl << "You obtained The Bloodpetal, the legendary sword (+" << blade[2] << " attack)!";
            cout << endl << user << " has become the greatest swordfighter in all of Ravenshire!";
            cout << endl << "Congratulations on completing your journey!";
        }
    }

    return 0;
}