#ifndef MODERATOR_H
#define MODERATOR_H

#include <QByteArray>

/*
 * Moderator:
 *          * the translator
 *          * the communicator
 *          * the encoder/decoder
 */

class Moderator
{
public:
    Moderator();
    QByteArray red();
    QByteArray green();
};

#endif // MODERATOR_H
