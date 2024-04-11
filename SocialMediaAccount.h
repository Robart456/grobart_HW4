//
// Created by jmrob on 4/10/2024.
//
#ifndef SOCIALMEDIAACCOUNT_H
#define SOCIALMEDIAACCOUNT_H

#include <iostream>
#include <string>
#include <array>

template<typename T>
class SocialMediaAccount {
public:
    SocialMediaAccount(T handler, bool isPrivate = true) : handler(handler), privateAccount(isPrivate), followerCount(0), followedCount(0) {}

    void addFollower(T user) {
        if (followerCount < maxFollowers) {
            followers[followerCount++] = user;
        }
    }

    void addFollowed(T user) {
        if (followedCount < maxFollowed) {
            followed[followedCount++] = user;
        }
    }

    void displayFollowers() const {
        if (!privateAccount) {
            std::cout << "Followers:\n";
            for (int i = 0; i < followerCount; i++) {
                std::cout << followers[i] << std::endl;
            }
        } else {
            std::cout << "Account is protected.\n";
        }
    }

    void displayFollowed() const {
        if (!privateAccount) {
            std::cout << "Followed:\n";
            for (int i = 0; i < followedCount; i++) {
                std::cout << followed[i] << std::endl;
            }
        } else {
            std::cout << "Account is protected.\n";
        }
    }
    void setPrivate(bool isPrivate) { privateAccount = isPrivate; }
    bool isPrivate() const { return privateAccount; }

private:
    T handler;
    static const int maxFollowers = 100;
    static const int maxFollowed = 100;
    T followers[maxFollowers];
    T followed[maxFollowed];
    int followerCount;
    int followedCount;
    bool privateAccount;
};

template<typename T>
class Twitter : public SocialMediaAccount<T> {
public:
    Twitter(T handler, bool isPrivate = true) : SocialMediaAccount<T>(handler, isPrivate), retweetCount(0) {}

    void RT() { retweetCount++; }
    int getRetweetCount() const { return retweetCount; }
    void setRetweetCount(int count) { retweetCount = count; }

private:
    int retweetCount;
};

template<typename T>
class Instagram : public SocialMediaAccount<T> {
public:
    Instagram(T handler, bool isPrivate = true) : SocialMediaAccount<T>(handler, isPrivate), likeCount(0) {}

    void Like() { likeCount++; }
    int getLikeCount() const { return likeCount; }
    void setLikeCount(int count) { likeCount = count; }

private:
    int likeCount;
};

#endif // SOCIALMEDIAACCOUNT_H
