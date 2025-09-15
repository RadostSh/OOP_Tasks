#include "Song.h"
#include "Playlist.h"

int main()
{
    Song* s1 = new Song("Song1", Genre::JAZZ, 206);
    Song* s2 = new Song("Song2", Genre::POP, 300);
    Song* s3 = new Song("Song3", Genre::ROCK, 100);

    Playlist p(s2);
    p += s3;
}
