#pragma once
#include "Song.h"

class Playlist
{
public:
    Playlist() = default;
    Playlist(Song* songs);
    Playlist(const Playlist& other);
    Playlist& operator=(const Playlist& other);
    ~Playlist();

    Song* getSong() const;
    void setSong(Song* song);

    const Song* operator[](int index) const;
    Song* operator[](int index);

    const Song* operator[](const char* name) const;
    Song* operator[](const char* name);

    Playlist& operator+=(Song* song);
    Playlist& operator-=(Song* song);

    operator bool() const;
    void operator()() const;

    int maxTimePlaylist() const;
    int countSongs() const;

private:
    Song* songs = nullptr;

    int findSongIndex(const Song& song);

    void copyFrom(const Playlist& other);
    void free();
};
