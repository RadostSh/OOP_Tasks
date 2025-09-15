#include "Playlist.h"

#include <cstring>
#include <iostream>

Playlist::Playlist(Song* songs) : songs(songs)
{
}

Playlist::Playlist(const Playlist& other)
{
    copyFrom(other);
}

Playlist& Playlist::operator=(const Playlist& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Playlist::~Playlist()
{
    free();
}

Song* Playlist::getSong() const
{
    return songs;
}

void Playlist::setSong(Song* song)
{
    if (!song)
    {
        return;
    }

    songs = song;
}

const Song* Playlist::operator[](int index) const
{
    Song* currsong = songs;
    int currindex = 0;
    while (currindex != index)
    {
        currsong = currsong->getNextSong();
        currindex++;
    }
    return currsong;
}

Song* Playlist::operator[](int index)
{
    Song* currsong = songs;
    int currindex = 0;
    while (currindex != index)
    {
        currsong = currsong->getNextSong();
        currindex++;
    }
    return currsong;
}

const Song* Playlist::operator[](const char* name) const
{
    if (!name)
    {
        return nullptr;
    }
    Song* currsong = songs;
    while (strcmp(currsong->getName(), name) != 0)
    {
        currsong = currsong->getNextSong();
    }
    return currsong;
}

Song* Playlist::operator[](const char* name)
{
    if (!name)
    {
        return nullptr;
    }
    Song* currsong = songs;
    while (strcmp(currsong->getName(), name) != 0)
    {
        currsong = currsong->getNextSong();
    }
    return currsong;
}

Playlist& Playlist::operator+=(Song* song)
{
    Song* currsong = songs;
    while (currsong->getNextSong() != nullptr)
    {
        currsong = currsong->getNextSong();
    }
    currsong->setNextSong(song);
    return *this;
}

int Playlist::findSongIndex(const Song& song)
{
    int index = 0;

    if (strcmp(songs->getName(), song.getName()) == 0)
        return index;

    Song* nextSong = songs;

    while (strcmp(songs->getName(), song.getName()) != 0 && nextSong != nullptr)
    {
        nextSong = nextSong->getNextSong();
        index++;
    }

    return index ? index : -1;
}

Playlist& Playlist::operator-=(Song* song)
{
    int foundIndex = findSongIndex(*song);
    if (foundIndex == -1)
    {
        return *this;
    }

    Song* current = operator[](foundIndex);
    Song* next = current->getNextSong();

    while (next != nullptr)
    {
        if (strcmp(songs->getName(), current->getName()) == 0)
        {
            songs = next;
        }
        else
        {
            current = next;
        }

        next = next->getNextSong();
    }

    return *this;

}

Playlist::operator bool() const
{
    return songs == nullptr;
}

void Playlist::operator()() const
{
    Song* currsong = songs;
    while (currsong != nullptr)
    {
        currsong->print();
        currsong = currsong->getNextSong();
    }
}

int Playlist::maxTimePlaylist() const
{
    Song* currsong = songs;
    int res = 0;
    while (currsong != nullptr)
    {
        res = currsong->getTime();
        currsong = currsong->getNextSong();
    }
    return res;
}

int Playlist::countSongs() const
{
    Song* currsong = songs;
    int res = 0;
    while (currsong != nullptr)
    {
        res++;
        currsong = currsong->getNextSong();
    }
    return res;
}

void Playlist::copyFrom(const Playlist& other)
{
    songs = other.songs;
}

void Playlist::free()
{
    delete songs;
}
