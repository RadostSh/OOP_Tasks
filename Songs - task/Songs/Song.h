#pragma once
#pragma warning (disable : 4996)

enum class Genre
{
    NONE,
    JAZZ,
    ROCK,
    POP,
    RAP
};

class Song
{
public:
    Song() = default;
    Song(const char* name, Genre genre, int time);
    Song(const char* name, Genre genre, int time, Song* next);
    Song(const Song& other);
    Song& operator=(const Song& other);
    ~Song();

    const char* getName() const;
    const char* getGenreString() const;
    Genre getGenre() const;
    int getTime() const;

    Song* getNextSong() const;

    void setName(const char* newName);
    void setGenre(Genre newGenre);
    void setTime(int newTime);

    void setNextSong(Song* next);

    void print() const;
private:
    char* name = nullptr;
    Genre genre = Genre::NONE;
    int time = 0;

    Song* next = nullptr;

    void copyFrom(const Song& other);
    void free();
};