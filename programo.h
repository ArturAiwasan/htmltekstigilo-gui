#ifndef PROGRAMO_H
#define PROGRAMO_H

#include "QString"

QString AldoniCxaretrvenigo (QString el) {
    QString itogteksto;
    QRegExp rega("[\n]");
    QStringList strokalist = el.split(rega);
    foreach (const QString &str, strokalist) {
        itogteksto += str+"<br>\n";
    };
    return itogteksto;
}

#endif // PROGRAMO_H
