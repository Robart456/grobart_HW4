/*************************************************************************
** Author : Greyson Robart
** Program : hw4, q1
** Date Created : April 10, 2024
** Date Last Modified : April 10, 2024
** Usage : No command line arguments
**
*************************************************************************/

#include <iostream>
#include "SocialMediaAccount.h"

struct Profile {
    int userId;
    std::string username;
    friend std::ostream& operator<<(std::ostream& os, const Profile& profile) {
        return os << profile.userId << ": " << profile.username;
    }
    bool operator==(const Profile& other) const {
        return userId == other.userId;
    }
};

int main() {
    Twitter<std::string> TS("TechNews");
    TS.addFollower("JohnDoe");
    TS.displayFollowers();
    Twitter<Profile> TP(Profile{1, "TechFan"});
    TP.addFollower(Profile{2, "GadgetGuy"});
    TP.displayFollowers();
    Instagram<std::string> IS("NaturePhotos");
    IS.addFollowed("ScenicViews");
    IS.displayFollowed();

    Instagram<Profile> IP(Profile{3, "ArtCollector"});
    IP.addFollowed(Profile{4, "MuseumLover"});
    IP.displayFollowed();

    return 0;
}
