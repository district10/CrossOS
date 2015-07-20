#include "moderator.h"

Moderator::Moderator()
{

}

QByteArray Moderator::red() // these bytes means set pushButton to Red color
{
    QByteArray ba;
    ba.append(0x23); ba.append(0x45); // red
    ba.append(0xFF); ba.append('\0');
    return ba;
}

QByteArray Moderator::green() // these bytes means set pushButton to Green color
{
    QByteArray ba;
    ba.append(0x23); ba.append(0x45); // green
    ba.append('\0'); ba.append('\0');
    return ba;
}
