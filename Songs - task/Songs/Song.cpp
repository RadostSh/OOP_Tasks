#include "Song.h"

#include <cstring>
#include <iostream>
#include <stdexcept>

Song::Song(const char* name, Genre genre, int time)
{
    setName(name);
    setGenre(genre);
    setTime(time);
}

Song::Song(const char* name, Genre genre, int time, Song* next)
{
    setName(name);
    setGenre(genre);
    setTime(time);
    this->next = next;
}

Song::Song(const Song& other)
{
    copyFrom(other);
}

Song& Song::operator=(const Song& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Song::~Song()
{
    free();
}

const char* Song::getName() const
{
    return name;
}

const char* Song::getGenreString() const
{
    switch (genre)
    {
    case Genre::JAZZ : return "Jazz";
    case Genre::POP : return "Pop";
    case Genre::RAP: return "Rap";
    case Genre::ROCK: return "Rock";
        default: return "";
    }
    return nullptr;
}

Genre Song::getGenre() const
{
    return genre;
}

int Song::getTime() const
{
    return time;
}

Song* Song::getNextSong() const
{
    return next;
}

void Song::setName(const char* newName)
{
    if (!newName || name == newName)
    {
        throw std::invalid_argument("Song name cannot be empty");
    }
    delete [] name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}

void Song::setGenre(Genre newGenre)
{
    genre = newGenre;
}

void Song::setTime(int newTime)
{
    if (newTime > 600)
    {
        throw std::invalid_argument("Song time cannot be greater than 600");
    }
    time = newTime;
}

void Song::setNextSong(Song* next)
{
    this->next = next;
}

void Song::print() const
{
    std::cout << "Name" << getName() << " - " << getGenreString() << " - " << getTime() << std::endl;
}

void Song::copyFrom(const Song& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    next = other.next;
    genre = other.genre;
    time = other.time;
}

void Song::free()
{
    delete [] name;
    delete next;
}