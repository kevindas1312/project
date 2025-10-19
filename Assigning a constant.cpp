#include <iostream>
#include <cmath>
using namespace std;

int main(){
    string user;
    cout << "Insert name of user (not less than 5 characters):";
    cin >> user;
    cout << endl << "Welcome " << user << " to ...";
    cout << endl << "\n\n\n******************************Overview************************************";
    cout << endl << user << " is an amateur swordfighter from the land of Ravenshire.";
    cout << endl << user << " has had the dream since young be the best swordfighter since he was young.";
    cout << endl << "To achieve this, "<< user << " has to embark on a journey to obtain the greatest sword there ever is, (The Bloodpetal)";
    cout << endl << "However, to obtain the sword,"<< user << " has to pass through 3 levels.";
    
    cout << endl <<  "\n\n\nIn Level 1, to get pass this level, you need to defeat The Keeper of Frostmere in the North of Greystone.";
    cout << endl << "The Keeper of Frostmere will be guarding the The Crimson Blade.";
    cout <<endl << "You need to obtain The Crimson Blade to defeat the next level.";

    cout <<endl << "\n\n\nIn Level 2, to advance further, you must defeat The Warden of Blackhollow, located in the Northern reaches of Ashvale.";
    cout <<endl << "The Warden of Blackhollow guards The Obsidian Edge, a blade of immense power.";
    cout <<endl << "You must obtain The Obsidian Edge to conquer the next level.";
    
    cout << endl << "\n\n\nAnd for the final level, you must defeat The Sentinel of Ironreach, found in the Northern Highlands of Valemont.";
    cout << endl << "The Sentinel of Ironreach guards The Bloodpetal, a legendary sword of unmatched sharpness.";
    cout << endl << "P.S. Good luck claiming The Bloodpetal as no one has ever defeated the The Sentinel of Ironreach.";

    int user_health, the_keeper_of_frostmere_health, the_warden_of_blackhollow_health, the_sentinel_of_ironreach, crimson_blade, obsidian_edge, the_bloodpetal, starter_sword;

    cout << endl << "\nList of Default swords";
    cout << endl << "Wooden Beak (1)";
    cout << endl << "Stick of Styx (2)";
    cout << endl << "Dawnbreaker (3)";
    cout << "You may now choose your default sword (1/2/3):";
    cin >> starter_sword;
    if (starter_sword == 1){
        
    }
}